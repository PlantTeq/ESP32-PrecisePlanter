#include <Arduino.h>
#include "CanBus.h"
#include "ESP32CAN.h"
#include "can_regdef.h"

extern "C"
{
#include "can_messages.h"
}

static const gpio_num_t CanTxPin = GPIO_NUM_14;
static const gpio_num_t CanRxPin = GPIO_NUM_13;
static const int CanRxQueueLength = 10;
static const float MmPerSecToKmh = 0.0036f;

CAN_device_t CAN_cfg;
CanData CanRx;

void canInit()
{
  CAN_cfg.speed = CAN_SPEED_250KBPS;
  CAN_cfg.tx_pin_id = CanTxPin;
  CAN_cfg.rx_pin_id = CanRxPin;
  CAN_cfg.rx_queue = xQueueCreate(CanRxQueueLength, sizeof(CAN_frame_t));
  ESP32Can.CANInit();
}

void canUpdateStatus()
{
  CanRx.RxErrorCount = MODULE_CAN->RXERR.U;
  CanRx.TxErrorCount = MODULE_CAN->TXERR.U;
  CanRx.BusOff = MODULE_CAN->SR.B.BS != 0;
}

bool canReceive()
{
  bool Updated = false;
  CAN_frame_t Frame;

  while (xQueueReceive(CAN_cfg.rx_queue, &Frame, 0) == pdTRUE)
  {
    CanRx.FrameCount++;
    CanRx.LastId = Frame.MsgID;
    CanRx.LastIdExtended = Frame.FIR.B.FF == CAN_frame_ext;

    if (Frame.FIR.B.FF != CAN_frame_ext || Frame.FIR.B.RTR == CAN_RTR)
      continue;

    if (Frame.MsgID == MSGSPEEDSTATUS_CAN_ID)
    {
      MsgSpeedStatus_t SpeedMsg;
      if (MsgSpeedStatus_decode(Frame.data.u8, Frame.FIR.B.DLC, &SpeedMsg))
      {
        CanRx.SpeedKmh = SpeedMsg.SpeedActual * MmPerSecToKmh;
        Updated = true;
      }
    }
    else if (Frame.MsgID == MSGPLANTWHEELSPEED_CAN_ID)
    {
      MsgPlantWheelSpeed_t WheelMsg;
      if (MsgPlantWheelSpeed_decode(Frame.data.u8, Frame.FIR.B.DLC, &WheelMsg))
      {
        CanRx.PlantWheelRpm = WheelMsg.PlantwheelSpeed;
        Updated = true;
      }
    }
  }

  return Updated;
}
