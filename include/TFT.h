#ifndef TFT_H
#define TFT_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "CanBus.h"

extern TFT_eSPI tft;

void tft_init();
void drawStartup();
void drawHome();
void drawMenu();
void drawAdvancedScreen();
void drawHAResetScreen();
void drawDebugScreen();
void updateDebugPlantWheelRpm(float Rpm, bool Force);
void updateDebugCan(const CanData &Data, bool Force);
void updateHomeValue(int Id, int X, int Y, float NewValue, const GFXfont *Font, int Decimals, bool Force);
void updateHectareCounter(float Hectares, bool Force);
void drawEnable(bool Enabled, bool Force);
void drawInputScreen(const char *ItemName, const char *Unit, const String &Text);
void drawInputHeader(const char *ItemName, const char *Unit, const String &Text);

#endif