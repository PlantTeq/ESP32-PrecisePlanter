#include <Arduino.h>
#include "CanBus.h"
#include "driver/twai.h"

extern "C"
{
#include "can_messages.h"
}

static const gpio_num_t CanTxPin = GPIO_NUM_14;
static const gpio_num_t CanRxPin = GPIO_NUM_13;
static const uint32_t RecoveryIntervalMs = 500;
static const uint32_t ConfigRequestIntervalMs = 500;
static const float MmPerSecToKmh = 0.0036f;

CanData CanRx;

static uint32_t LastRecoveryMs = 0;

void canInit()
{
  twai_general_config_t GeneralConfig = TWAI_GENERAL_CONFIG_DEFAULT(CanTxPin, CanRxPin, TWAI_MODE_NORMAL);
  GeneralConfig.rx_queue_len = 20;
  const twai_timing_config_t TimingConfig = TWAI_TIMING_CONFIG_250KBITS();
  const twai_filter_config_t FilterConfig = TWAI_FILTER_CONFIG_ACCEPT_ALL();

  twai_driver_uninstall();
  if (twai_driver_install(&GeneralConfig, &TimingConfig, &FilterConfig) != ESP_OK)
    return;
  twai_start();
}

// Herstelt de bus na bus-off of een gestopte driver, zoals in ZAPcontrol.
void canUpdateStatus()
{
  twai_status_info_t Status = {};
  if (twai_get_status_info(&Status) != ESP_OK)
    return;

  CanRx.RxErrorCount = Status.rx_error_counter;
  CanRx.TxErrorCount = Status.tx_error_counter;
  CanRx.BusOff = Status.state == TWAI_STATE_BUS_OFF;

  uint32_t Now = millis();
  if (Now - LastRecoveryMs < RecoveryIntervalMs)
    return;

  if (Status.state == TWAI_STATE_BUS_OFF)
  {
    LastRecoveryMs = Now;
    twai_initiate_recovery();
  }
  else if (Status.state == TWAI_STATE_STOPPED)
  {
    LastRecoveryMs = Now;
    twai_start();
  }
}

bool CanMessages_Transmit(uint32_t Id, bool Extended, const uint8_t *Data, uint8_t Dlc)
{
  twai_message_t Frame = {};
  Frame.extd = Extended ? 1 : 0;
  Frame.identifier = Id;
  Frame.data_length_code = Dlc;
  memcpy(Frame.data, Data, Dlc);
  return twai_transmit(&Frame, 0) == ESP_OK;
}

bool canSendPlantSpacing(uint16_t SpacingMm)
{
  MsgPlantSpacingCommand_t Command = {SpacingMm};
  return MsgPlantSpacingCommand_send(&Command);
}

void canRequestMissingConfig()
{
  static uint32_t LastRequestMs = 0;
  if (CanRx.PlantSpacingMm.Valid || millis() - LastRequestMs < ConfigRequestIntervalMs)
    return;
  LastRequestMs = millis();

  MsgConfigRequest_t Request = {CONFIGGROUP_ALL};
  MsgConfigRequest_send(&Request);
}

// Zet de gedecodeerde protocolberichten om naar de eenheden die de UI gebruikt.
static void copyReceivedMessages()
{
  if (CanMsgs.SpeedStatus.Updated)
  {
    CanMsgs.SpeedStatus.Updated = false;
    CanRx.SpeedKmh = CanMsgs.SpeedStatus.Data.SpeedActual * MmPerSecToKmh;
  }

  if (CanMsgs.PlantWheelSpeed.Updated)
  {
    CanMsgs.PlantWheelSpeed.Updated = false;
    CanRx.PlantWheelRpm = CanMsgs.PlantWheelSpeed.Data.PlantwheelSpeed;
  }

  if (CanMsgs.PlantSpacingConfig.Updated)
  {
    CanMsgs.PlantSpacingConfig.Updated = false;
    const MsgPlantSpacingConfig_t &Config = CanMsgs.PlantSpacingConfig.Data;
    CanRx.PlantSpacingMm.Current = Config.PlantSpacingCurrent;
    CanRx.PlantSpacingMm.Default = Config.PlantSpacingDefault;
    CanRx.PlantSpacingMm.Min = Config.PlantSpacingMin;
    CanRx.PlantSpacingMm.Max = Config.PlantSpacingMax;
    CanRx.PlantSpacingMm.Valid = true;
  }
}

bool canReceive()
{
  bool Updated = false;
  twai_message_t Frame;

  while (twai_receive(&Frame, 0) == ESP_OK)
  {
    CanRx.FrameCount++;
    CanRx.LastId = Frame.identifier;
    CanRx.LastIdExtended = Frame.extd != 0;

    if (Frame.rtr)
      continue;

    if (CanMessages_Receive(Frame.identifier, Frame.extd != 0, Frame.data, Frame.data_length_code))
      Updated = true;
  }

  copyReceivedMessages();
  return Updated;
}