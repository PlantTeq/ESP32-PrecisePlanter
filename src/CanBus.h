#ifndef CANBUS_H
#define CANBUS_H

#include <stdint.h>

// Instelwaarde zoals de controller die doorgeeft, in de ruwe eenheid van het bericht.
// Valid wordt als laatste gezet, zodat de UI-taak nooit een half bijgewerkte set leest.
struct ParamLimits
{
  uint16_t Current = 0;
  uint16_t Default = 0;
  uint16_t Min = 0;
  uint16_t Max = 0;
  volatile bool Valid = false;
};

// Laatst ontvangen waarden van de controller.
struct CanData
{
  ParamLimits PlantSpacingMm;

  float SpeedKmh = 0.0f;
  float PlantWheelRpm = 0.0f;

  // Diagnose: alle frames die de driver heeft ontvangen, ook onbekende.
  uint32_t FrameCount = 0;
  uint32_t LastId = 0;
  bool LastIdExtended = false;
  uint8_t RxErrorCount = 0;
  uint8_t TxErrorCount = 0;
  bool BusOff = false;
};

extern CanData CanRx;

// Start de CAN-driver (250 kbps, TX = GPIO 14, RX = GPIO 13).
void canInit();

// Leest alle wachtende frames uit de RX-queue en werkt CanRx bij.
// Geeft true terug als er minstens één bekend bericht is verwerkt.
bool canReceive();

// Stuurt de gewenste plantafstand (mm) naar de controller. De controller toetst en slaat op.
bool canSendPlantSpacing(uint16_t SpacingMm);

// Vraagt de configuratie van de controller op, elke 500 ms zolang die nog niet binnen is.
void canRequestMissingConfig();

// Leest de foutteller en busstatus van de CAN-module uit in CanRx.
void canUpdateStatus();

#endif
