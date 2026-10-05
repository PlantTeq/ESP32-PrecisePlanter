#ifndef CANBUS_H
#define CANBUS_H

#include <stdint.h>

// Laatst ontvangen waarden van de controller.
struct CanData
{
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

// Leest de foutteller en busstatus van de CAN-module uit in CanRx.
void canUpdateStatus();

#endif
