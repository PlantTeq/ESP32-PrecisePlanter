@echo off
setlocal EnableExtensions

rem ============================================================
rem CAN protocol updater
rem
rem Put this BAT file in the firmware project's src folder.
rem Edit CAN_GENERATOR_DIR below to point to the central
rem CANbusVariables folder on this PC.
rem
rem You can also override the path when starting the BAT:
rem   update_can_files.bat "D:\Path\To\CANbusVariables"
rem ============================================================

set "CAN_GENERATOR_DIR=Z:\Software\CANbusVariables"

if not "%~1"=="" set "CAN_GENERATOR_DIR=%~1"

echo.
echo ============================================
echo   CAN protocol local update
echo ============================================
echo.
echo Generator folder:
echo   %CAN_GENERATOR_DIR%
echo.

if not exist "%CAN_GENERATOR_DIR%\version.txt" (
    echo ERROR: version.txt not found:
    echo   %CAN_GENERATOR_DIR%\version.txt
    echo.
    pause
    exit /b 1
)

if not exist "%CAN_GENERATOR_DIR%\generated\can_messages.h" (
    echo ERROR: generated\can_messages.h not found.
    echo.
    pause
    exit /b 1
)

if not exist "%CAN_GENERATOR_DIR%\generated\can_messages.c" (
    echo ERROR: generated\can_messages.c not found.
    echo.
    pause
    exit /b 1
)

rem This BAT is in src, so the destination is simply the current folder.
set "TARGET_DIR=%~dp0"

echo Central generated version:
set /p CENTRAL_VERSION=<"%CAN_GENERATOR_DIR%\version.txt"
echo   %CENTRAL_VERSION%

echo.
echo Updating local CAN files...

copy /Y "%CAN_GENERATOR_DIR%\generated\can_messages.h" "%TARGET_DIR%can_messages.h" >nul
if errorlevel 1 (
    echo ERROR: could not copy can_messages.h
    pause
    exit /b 1
)

copy /Y "%CAN_GENERATOR_DIR%\generated\can_messages.c" "%TARGET_DIR%can_messages.c" >nul
if errorlevel 1 (
    echo ERROR: could not copy can_messages.c
    pause
    exit /b 1
)

echo.
echo ============================================
echo   Update successful
echo ============================================
echo.
echo Local firmware files now use:
findstr /C:"#define CAN_PROTOCOL_VERSION" "%TARGET_DIR%can_messages.h"
findstr /C:"#define CAN_PROTOCOL_DATE" "%TARGET_DIR%can_messages.h"
findstr /C:"#define CAN_PROTOCOL_TIME" "%TARGET_DIR%can_messages.h"
echo.
pause
endlocal
