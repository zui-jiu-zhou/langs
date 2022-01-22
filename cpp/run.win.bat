@echo off

cd /d %~dp0

set MSVC_HOME=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.29.30133\bin\HostX64\x64
set PATH=%MSVC_HOME%;%PATH%

call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat"

cl.exe /D UNICODE /EHsc /c ge.cpp
if %ERRORLEVEL% equ 0 (
    link.exe -DLL -out:ge.dll ge.obj
    if %ERRORLEVEL% equ 0 (
        del ge.lib
        del ge.obj
        del ge.exp
        cl.exe /D UNICODE /EHsc run.cpp
        if %ERRORLEVEL% equ 0 (
            del run.obj
            if exist run.exp (
                del  run.exp
            )
            if exist run.lib (
                del  run.lib
            )
            if exist run.exe.stackdump (
                del  run.exe.stackdump
            )
            call .\run.exe
        )
    )
)


