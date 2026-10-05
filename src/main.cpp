#include <Arduino.h>
#include "TFT.h"
#include "defines.h"
#include "CanBus.h"


enum class Screen
{
  Home,
  MainMenu,
  AdvancedMenu,
  HectareReset,
  NumericInput,
  Debug
};

uint16_t TouchCalibration[] = {377, 3271, 499, 2972, 7};
Screen CurrentScreen = Screen::Home;

// placeholder home screen values, data fetching will be wired up later
float CurrentSpeedKmh = 0.0f;
float PlantSpacingCm = 0.0f;
float NumberOfGrippers = 0.0f;
float HectareCounter = 0.0f;
float NumberRows = 0.0f;
float RowDistanceCm = 0.0f;

struct EditableValue
{
  const char *Name;
  const char *Unit;
  float *Value;
  int Decimals;
};

EditableValue PlantSpacingSetting = {"Plant spacing", "cm", &PlantSpacingCm, 1};
EditableValue NumberOfGrippersSetting = {"# Grippers", "", &NumberOfGrippers, 0};
EditableValue NumberRowsSetting = {"Rows", "", &NumberRows, 0};
EditableValue RowDistanceSetting = {"row distance", "cm", &RowDistanceCm, 1};

EditableValue *ActiveSetting = nullptr;
Screen InputReturnScreen = Screen::MainMenu;
String InputString;
bool ClearOnNextKey = false;

bool TouchInButton(uint16_t TouchX, uint16_t TouchY, int ButtonX, int ButtonY, int ButtonWidth, int ButtonHeight)
{
  return TouchX > ButtonX && TouchX < ButtonX + ButtonWidth &&
         TouchY > ButtonY && TouchY <= ButtonY + ButtonHeight;
}

void refreshHomeScreen(bool Force)
{
  updateHomeValue(0, 105, 50, CurrentSpeedKmh, FF19, 2, Force);
  updateHomeValue(1, 105, 100, PlantSpacingCm, FF19, 1, Force);
  updateHomeValue(2, 90, 150, NumberOfGrippers, FF19, 0, Force);
  updateHectareCounter(HectareCounter, Force);
}

void openInputScreen(EditableValue *Setting, Screen ReturnScreen)
{
  ActiveSetting = Setting;
  InputReturnScreen = ReturnScreen;
  InputString = String(*Setting->Value, Setting->Decimals);
  ClearOnNextKey = true;
  CurrentScreen = Screen::NumericInput;
  drawInputScreen(Setting->Name, Setting->Unit, InputString);
}

void drawInputReturnScreen()
{
  if (InputReturnScreen == Screen::AdvancedMenu)
    drawAdvancedScreen();
  else
    drawMenu();
}

void handleNumericInputTouch(uint16_t TouchX, uint16_t TouchY)
{
  const int Cols = 3;
  const int Margin = 5;
  const int StartY = 60;
  int ButtonW = (tft.width() - Margin * (Cols + 1)) / Cols;
  int ButtonH = (tft.height() - StartY - Margin * 6) / 5;

  String Labels[12] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", ".", "0", "<"};

  for (int Row = 0; Row < 4; ++Row)
  {
    int Y = StartY + Row * (ButtonH + Margin);
    for (int Col = 0; Col < Cols; ++Col)
    {
      int X = Margin + Col * (ButtonW + Margin);
      if (!TouchInButton(TouchX, TouchY, X, Y, ButtonW, ButtonH))
        continue;

      String Label = Labels[Row * Cols + Col];
      if (Label == "<")
      {
        if (InputString.length() > 0)
          InputString.remove(InputString.length() - 1);
      }
      else if (Label == ".")
      {
        if (ClearOnNextKey)
        {
          InputString = "";
          ClearOnNextKey = false;
        }
        if (InputString.indexOf('.') == -1)
          InputString += ".";
      }
      else
      {
        if (ClearOnNextKey)
        {
          InputString = "";
          ClearOnNextKey = false;
        }
        InputString += Label;
      }
      drawInputHeader(ActiveSetting->Name, ActiveSetting->Unit, InputString);
      return;
    }
  }

  int Row4Y = StartY + 4 * (ButtonH + Margin);
  int HalfW = (tft.width() - Margin * 3) / 2;
  int ReturnX = Margin;
  int SaveX = Margin * 2 + HalfW;

  if (TouchInButton(TouchX, TouchY, ReturnX, Row4Y, HalfW, ButtonH))
  {
    CurrentScreen = InputReturnScreen;
    drawInputReturnScreen();
  }
  else if (TouchInButton(TouchX, TouchY, SaveX, Row4Y, HalfW, ButtonH))
  {
    *ActiveSetting->Value = InputString.length() ? InputString.toFloat() : 0.0f;
    CurrentScreen = InputReturnScreen;
    drawInputReturnScreen();
  }
}

void setup()
{
  tft_init();
  tft.setTouch(TouchCalibration);
  drawStartup();
  delay(1500);
  drawHome();
  refreshHomeScreen(true);
  canInit();
}

void loop()
{
  // Vóór de touch-afhandeling, zodat de RX-queue ook zonder aanraking leegloopt.
  bool CanUpdated = canReceive();
  if (CanUpdated)
    CurrentSpeedKmh = CanRx.SpeedKmh;

  if (CurrentScreen == Screen::Home && CanUpdated)
  {
    refreshHomeScreen(false);
  }
  else if (CurrentScreen == Screen::Debug)
  {
    canUpdateStatus();
    updateDebugPlantWheelRpm(CanRx.PlantWheelRpm, false);
    updateDebugCan(CanRx, false);
  }

  uint16_t TouchX;
  uint16_t TouchY;
  if (!tft.getTouch(&TouchX, &TouchY))
  {
    return;
  }

  if (CurrentScreen == Screen::Home)
  {
    if (TouchInButton(TouchX, TouchY, HACOUNTERBUTTON_X, HACOUNTERBUTTON_Y, HACOUNTERBUTTON_W, HACOUNTERBUTTON_H))
    {
      CurrentScreen = Screen::HectareReset;
      drawHAResetScreen();
    }
    else
    {
      CurrentScreen = Screen::MainMenu;
      drawMenu();
    }
  }
  else if (CurrentScreen == Screen::HectareReset)
  {
    if (TouchInButton(TouchX, TouchY, HARESET_RETURN_X, HARESET_BTN_Y, HARESET_BTN_W, HARESET_BTN_H))
    {
      CurrentScreen = Screen::Home;
      drawHome();
      refreshHomeScreen(true);
    }
    else if (TouchInButton(TouchX, TouchY, HARESET_YES_X, HARESET_BTN_Y, HARESET_BTN_W, HARESET_BTN_H))
    {
      HectareCounter = 0.0f;
      CurrentScreen = Screen::Home;
      drawHome();
      refreshHomeScreen(true);
    }
  }
  else if (CurrentScreen == Screen::MainMenu)
  {
    if (TouchInButton(TouchX, TouchY, MENUBUTTON1_X, MENUBUTTON1_Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H))
    {
      openInputScreen(&PlantSpacingSetting, Screen::MainMenu);
    }
    else if (TouchInButton(TouchX, TouchY, MENUBUTTON2_X, MENUBUTTON2_Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H))
    {
      openInputScreen(&NumberOfGrippersSetting, Screen::MainMenu);
    }
    else if (TouchInButton(TouchX, TouchY, MENUBUTTON9_X, MENUBUTTON9_Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H))
    {
      CurrentScreen = Screen::AdvancedMenu;
      drawAdvancedScreen();
    }
    else
    {
      CurrentScreen = Screen::Home;
      drawHome();
      refreshHomeScreen(true);
    }
  }
  else if (CurrentScreen == Screen::NumericInput)
  {
    handleNumericInputTouch(TouchX, TouchY);
  }
  else if (CurrentScreen == Screen::AdvancedMenu)
  {
    if (TouchInButton(TouchX, TouchY, MENUBUTTON1_X, MENUBUTTON1_Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H))
    {
      openInputScreen(&NumberRowsSetting, Screen::AdvancedMenu);
    }
    else if (TouchInButton(TouchX, TouchY, MENUBUTTON2_X, MENUBUTTON2_Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H))
    {
      openInputScreen(&RowDistanceSetting, Screen::AdvancedMenu);
    }
    else if (TouchInButton(TouchX, TouchY, MENUBUTTON3_X, MENUBUTTON3_Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H))
    {
      CurrentScreen = Screen::Debug;
      drawDebugScreen();
      updateDebugPlantWheelRpm(CanRx.PlantWheelRpm, true);
      canUpdateStatus();
      updateDebugCan(CanRx, true);
    }
    else if (TouchInButton(TouchX, TouchY, MENUBUTTON7_X, MENUBUTTON7_Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H))
    {
      CurrentScreen = Screen::MainMenu;
      drawMenu();
    }
  }
  else if (CurrentScreen == Screen::Debug)
  {
    if (TouchInButton(TouchX, TouchY, DEBUGBACK_X, DEBUGBACK_Y, DEBUGBACK_W, DEBUGBACK_H))
    {
      CurrentScreen = Screen::AdvancedMenu;
      drawAdvancedScreen();
    }
  }

  delay(250);
}