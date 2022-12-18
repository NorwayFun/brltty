@echo off

setlocal EnableDelayedExpansion
set programDirectory=%~dp0
call %programDirectory%setvars-brltty

if exist "%pidFile%" (
   set /P pid= < "%pidFile%"

   if "!pid!" NEQ "" (
      taskkill /PID "!pid!" /F /T
      exit /B %ERRORLEVEL%
   )
)

exit /B 0
