@echo off

cd /d %~dp0
set CYGWIN_BIN=%CYGWIN_HOME%/bin
set PATH=%CYGWIN_BIN%;%PATH%

g++ -shared -o ge.dll ge.cpp
if %ERRORLEVEL% equ 0 (
    g++ -mwin32 -o run run.cpp
    if %ERRORLEVEL% equ 0 (
        call .\run.exe
    )
)