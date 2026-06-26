@echo off
setlocal

if "%~1"=="" (
    echo Usage: run_c filename.c
    exit /b
)

set "source=%~1"

if not exist "%source%" (
    echo Error: File "%source%" not found.
    exit /b
)

set "exe=%~n1.exe"

echo.
echo Compiling %source%...
gcc "%source%" -o "%exe%"

if errorlevel 1 (
    echo.
    echo Compilation failed.
    exit /b
)

echo.
echo Running %exe%...
echo ----------------------------
"%exe%"
echo ----------------------------

pause