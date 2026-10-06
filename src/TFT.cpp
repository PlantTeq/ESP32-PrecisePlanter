#include "TFT.h"

#include <Arduino.h>
#include "defines.h"
#include "image.h"

TFT_eSPI tft = TFT_eSPI();

namespace
{
void draw_icon64(int StartX, int StartY, const unsigned short Icon[], int Width, int Height)
{
  int BufferIndex = 0;
  for (int Row = StartY; Row < StartY + Height; ++Row)
  {
    for (int Col = StartX; Col < StartX + Width; ++Col)
    {
      tft.drawPixel(Col, Row, pgm_read_word(Icon + BufferIndex++));
    }
  }
}

void draw_logo(int StartX, int StartY)
{
  int BufferIndex = 0;
  for (int Row = StartY; Row < StartY + 100; ++Row)
  {
    for (int Col = StartX; Col < StartX + 300; ++Col)
    {
      tft.drawPixel(Col, Row, pgm_read_word(logo + BufferIndex++));
    }
  }
}

void drawMenuButton(int X, int Y, const unsigned short Icon[])
{
  tft.drawRoundRect(X, Y, MEDIUMBUTTON_W, MEDIUMBUTTON_H, 5, TFT_WHITE);
  tft.drawRoundRect(X + 1, Y + 1, MEDIUMBUTTON_W - 2, MEDIUMBUTTON_H - 2, 5, TFT_WHITE);
  draw_icon64(X + 20, Y + 7, Icon, 55, 55);
}

void drawScreenFrame()
{
  tft.fillScreen(TFT_BLACK);
  tft.drawRoundRect(0, 0, 320, 240, 5, TFT_WHITE);
  tft.drawRoundRect(1, 1, 318, 238, 5, TFT_WHITE);
}
}

void tft_init()
{
  tft.init();
  tft.setRotation(1);
}

void drawStartup()
{
  tft.fillScreen(TFT_BLACK);
  draw_logo(10, 25);
  tft.drawRoundRect(5, 5, 315, 235, 5, TFT_WHITE);
  tft.drawRoundRect(6, 6, 313, 233, 5, TFT_WHITE);
  tft.setFreeFont(FF18);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(20, 190);
  tft.println("SemiPlanter Display");
}

void drawHome()
{
  tft.fillScreen(TFT_BLACK);
  tft.drawRoundRect(5, 5, 315, 175, 5, TFT_WHITE);
  tft.drawRoundRect(6, 6, 313, 173, 5, TFT_WHITE);

  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(FF19);

  // speed row
  draw_icon64(20, 7, speed, 55, 55);
  tft.setCursor(190, 47);
  tft.print(" km/h");

  // plant spacing row, same icon as used on ZAPControl
  draw_icon64(20, 60, plant, 55, 55);
  tft.setCursor(190, 100);
  tft.print(" cm");

  // NumberOfGrippers, temporarily reusing the plant spacing icon until its own symbol exists
  draw_icon64(20, 113, klem, 55, 55);

  // hectare counter
  draw_icon64(138, 113, ha_icon, 55, 55);

  drawEnable(false, true);
}

void drawMenu()
{
  drawScreenFrame();
  // PlantSpacing, top-left
  drawMenuButton(MENUBUTTON1_X, MENUBUTTON1_Y, plant);
  // NumberOfGrippers, top-middle
  drawMenuButton(MENUBUTTON2_X, MENUBUTTON2_Y, klem);
  // return to home, bottom-left
  drawMenuButton(MENUBUTTON7_X, MENUBUTTON7_Y, back);
  // Advanced menu, bottom-right
  drawMenuButton(MENUBUTTON9_X, MENUBUTTON9_Y, settings55x55);
}

void drawAdvancedScreen()
{
  drawScreenFrame();
  // NumberRows, top-left
  drawMenuButton(MENUBUTTON1_X, MENUBUTTON1_Y, rows);
  // RowDistance, top-middle
  drawMenuButton(MENUBUTTON2_X, MENUBUTTON2_Y, plant_height);
  // Debug screen, top-right
  drawMenuButton(MENUBUTTON3_X, MENUBUTTON3_Y, debugIcon);
  // return to main menu, bottom-left
  drawMenuButton(MENUBUTTON7_X, MENUBUTTON7_Y, back);
}

void drawDebugScreen()
{
  tft.fillScreen(TFT_BLACK);
  tft.drawRoundRect(0, 0, 320, 240, 5, TFT_WHITE);
  tft.drawRoundRect(1, 1, 318, 238, 5, TFT_WHITE);

  // return button, top-right, same position/style as Rijenstrooier's debug screen back button
  tft.drawRoundRect(DEBUGBACK_X, DEBUGBACK_Y, DEBUGBACK_W, DEBUGBACK_H, 3, TFT_WHITE);
  tft.drawRoundRect(DEBUGBACK_X + 1, DEBUGBACK_Y + 1, DEBUGBACK_W - 2, DEBUGBACK_H - 2, 3, TFT_WHITE);
  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(FF18);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("return", DEBUGBACK_X + DEBUGBACK_W / 2, DEBUGBACK_Y + DEBUGBACK_H / 2);
  tft.setTextDatum(TL_DATUM);

  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(FF17);
  tft.setCursor(10, 32);
  tft.print("Debug");

  tft.setCursor(10, 70);
  tft.print("PlantWheelSpeed:");
  tft.setCursor(255, 70);
  tft.print("RPM");
}

static float DebugPlantWheelRpmCache = NAN;

void updateDebugPlantWheelRpm(float Rpm, bool Force)
{
  if (DebugPlantWheelRpmCache == Rpm && !Force)
    return;

  tft.setFreeFont(FF17);
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(165, 70);
  if (!isnan(DebugPlantWheelRpmCache))
    tft.print(DebugPlantWheelRpmCache, 1);

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(165, 70);
  tft.print(Rpm, 1);

  DebugPlantWheelRpmCache = Rpm;
}

// Wist en tekent één debugregel, alleen als de tekst gewijzigd is.
static void drawDebugLine(int Index, int Y, const String &Text, bool Force)
{
  static String Cache[4];
  if (Cache[Index] == Text && !Force)
    return;

  tft.setFreeFont(FF17);
  tft.fillRect(10, Y - 18, 300, 24, TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10, Y);
  tft.print(Text);
  Cache[Index] = Text;
}

void updateDebugCan(const CanData &Data, bool Force)
{
  char Id[12];
  snprintf(Id, sizeof(Id), "%lX", (unsigned long)Data.LastId);

  drawDebugLine(0, 100, "Frames: " + String((unsigned long)Data.FrameCount), Force);
  drawDebugLine(1, 130, String("Last ID: ") + (Data.FrameCount ? Id : "-") + (Data.LastIdExtended ? " ext" : " std"), Force);
  drawDebugLine(2, 160, "Err RX:" + String(Data.RxErrorCount) + " TX:" + String(Data.TxErrorCount), Force);
  drawDebugLine(3, 190, Data.BusOff ? "BUS OFF" : "Bus ok", Force);
}

void drawHAResetScreen()
{
  tft.fillScreen(TFT_BLACK);
  tft.drawRoundRect(0, 0, 320, 240, 5, TFT_WHITE);
  tft.drawRoundRect(1, 1, 318, 238, 5, TFT_WHITE);

  tft.setFreeFont(FF19);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(20, 90);
  tft.print("Reset ha counter?");

  // return button
  tft.drawRoundRect(HARESET_RETURN_X, HARESET_BTN_Y, HARESET_BTN_W, HARESET_BTN_H, 5, TFT_WHITE);
  tft.drawRoundRect(HARESET_RETURN_X + 1, HARESET_BTN_Y + 1, HARESET_BTN_W - 2, HARESET_BTN_H - 2, 5, TFT_WHITE);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("Return", HARESET_RETURN_X + HARESET_BTN_W / 2, HARESET_BTN_Y + HARESET_BTN_H / 2 - 2);

  // yes button
  tft.drawRoundRect(HARESET_YES_X, HARESET_BTN_Y, HARESET_BTN_W, HARESET_BTN_H, 5, TFT_WHITE);
  tft.drawRoundRect(HARESET_YES_X + 1, HARESET_BTN_Y + 1, HARESET_BTN_W - 2, HARESET_BTN_H - 2, 5, TFT_WHITE);
  tft.drawString("Yes", HARESET_YES_X + HARESET_BTN_W / 2, HARESET_BTN_Y + HARESET_BTN_H / 2 - 2);
  tft.setTextDatum(TL_DATUM);
}

static float HomeValueCache[3] = {NAN, NAN, NAN};
static float HomeHectareCache = NAN;

// Redraws a home screen value only when it changed, avoiding flicker on every refresh.
void updateHomeValue(int Id, int X, int Y, float NewValue, const GFXfont *Font, int Decimals, bool Force)
{
  if (HomeValueCache[Id] == NewValue && !Force)
    return;

  tft.setFreeFont(Font);
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(X, Y);
  tft.print(HomeValueCache[Id], Decimals);

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(X, Y);
  tft.print(NewValue, Decimals);

  HomeValueCache[Id] = NewValue;
}

void updateHectareCounter(float Hectares, bool Force)
{
  if (HomeHectareCache == Hectares && !Force)
    return;

  tft.setFreeFont(FF19);
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(196, 152);
  tft.print(HomeHectareCache, 2);
  tft.print(" ha");

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(196, 152);
  tft.print(Hectares, 2);
  tft.print(" ha");

  HomeHectareCache = Hectares;
}

static int LastDrawnEnabled = -1;

void drawEnable(bool Enabled, bool Force)
{
  if (Enabled == LastDrawnEnabled && !Force)
    return;

  tft.fillRect(ENABLEBUTTON_X, ENABLEBUTTON_Y, ENABLEBUTTON_W, ENABLEBUTTON_H, TFT_BLACK);

  uint16_t Color = Enabled ? TFT_DARKGREEN : TFT_RED;
  tft.fillRoundRect(ENABLEBUTTON_X, ENABLEBUTTON_Y, ENABLEBUTTON_W, ENABLEBUTTON_H, 5, Color);
  tft.drawRoundRect(ENABLEBUTTON_X - 2, ENABLEBUTTON_Y - 2, ENABLEBUTTON_W + 4, ENABLEBUTTON_H + 4, 5, TFT_WHITE);
  tft.drawRoundRect(ENABLEBUTTON_X - 1, ENABLEBUTTON_Y - 1, ENABLEBUTTON_W + 2, ENABLEBUTTON_H + 2, 5, TFT_WHITE);

  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(FF19);
  tft.setCursor(145, 215);
  tft.print(Enabled ? "on" : "off");

  LastDrawnEnabled = Enabled;
}

// top box showing the item name, typed value and unit, same layout as Rijenstrooier's tftUI_drawInput
void drawInputHeader(const char *ItemName, const char *Unit, const String &Text)
{
  tft.fillRect(10, 10, 300, 40, TFT_BLACK);
  tft.drawRect(10, 10, 300, 40, TFT_WHITE);

  const int TextY = 30;
  tft.setTextDatum(ML_DATUM);

  // value is placed right after the name instead of at a fixed x, so long names never overlap it
  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(FF18);
  String Label = String(ItemName) + ": ";
  tft.drawString(Label, 14, TextY);
  int ValueX = 14 + tft.textWidth(Label);

  tft.setTextColor(TFT_GREEN);
  tft.setFreeFont(FF19);
  tft.drawString(Text, ValueX, TextY);

  tft.setTextColor(TFT_WHITE);
  tft.setFreeFont(FF18);
  tft.drawString(Unit, 240, TextY);

  tft.setTextDatum(TL_DATUM);
}

// replaces the header with a message, the next key press redraws the normal header
void drawInputError(const String &Message)
{
  tft.fillRect(10, 10, 300, 40, TFT_BLACK);
  tft.drawRect(10, 10, 300, 40, TFT_RED);
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_RED);
  tft.setFreeFont(FF18);
  tft.drawString(Message, 160, 30);
  tft.setTextDatum(TL_DATUM);
}

// numeric keypad (1-9, ., 0, backspace) plus return/save buttons, same grid as Rijenstrooier's tftUI_drawKeyboard
static void drawNumericKeypad()
{
  const int Cols = 3;
  const int Rows = 5;
  const int Margin = 5;
  const int StartY = 60;

  int ButtonW = (tft.width() - Margin * (Cols + 1)) / Cols;
  int ButtonH = (tft.height() - StartY - Margin * (Rows + 1)) / Rows;

  String Labels[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
  tft.setFreeFont(FF18);
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_WHITE);

  int Index = 0;
  for (int Row = 0; Row < 3; ++Row)
  {
    int Y = StartY + Row * (ButtonH + Margin);
    for (int Col = 0; Col < Cols; ++Col)
    {
      int X = Margin + Col * (ButtonW + Margin);
      tft.fillRoundRect(X, Y, ButtonW, ButtonH, 8, TFT_BLACK);
      tft.drawRoundRect(X, Y, ButtonW, ButtonH, 8, TFT_WHITE);
      tft.drawString(Labels[Index], X + ButtonW / 2, Y + ButtonH / 2);
      ++Index;
    }
  }

  // fourth row: ., 0, backspace
  int Row3Y = StartY + 3 * (ButtonH + Margin);
  String Row3Labels[3] = {".", "0", "<"};
  for (int Col = 0; Col < Cols; ++Col)
  {
    int X = Margin + Col * (ButtonW + Margin);
    tft.fillRoundRect(X, Row3Y, ButtonW, ButtonH, 8, TFT_BLACK);
    tft.drawRoundRect(X, Row3Y, ButtonW, ButtonH, 8, TFT_WHITE);
    tft.drawString(Row3Labels[Col], X + ButtonW / 2, Row3Y + ButtonH / 2);
  }

  // bottom row: return and save, split into two equal buttons
  int Row4Y = StartY + 4 * (ButtonH + Margin);
  int HalfW = (tft.width() - Margin * 3) / 2;
  int ReturnX = Margin;
  int SaveX = Margin * 2 + HalfW;

  tft.fillRoundRect(ReturnX, Row4Y, HalfW, ButtonH, 8, TFT_BLACK);
  tft.drawRoundRect(ReturnX, Row4Y, HalfW, ButtonH, 8, TFT_WHITE);
  tft.drawString("return", ReturnX + HalfW / 2, Row4Y + ButtonH / 2);

  tft.fillRoundRect(SaveX, Row4Y, HalfW, ButtonH, 8, TFT_BLACK);
  tft.drawRoundRect(SaveX, Row4Y, HalfW, ButtonH, 8, TFT_WHITE);
  tft.drawString("save", SaveX + HalfW / 2, Row4Y + ButtonH / 2);

  tft.setTextDatum(TL_DATUM);
}

void drawInputScreen(const char *ItemName, const char *Unit, const String &Text)
{
  tft.fillScreen(TFT_BLACK);
  drawInputHeader(ItemName, Unit, Text);
  drawNumericKeypad();
}