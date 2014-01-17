@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by LIBRARY.HPJ. >"hlp\Library.hm"
echo. >>"hlp\Library.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Library.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Library.hm"
echo. >>"hlp\Library.hm"
echo // Prompts (IDP_*) >>"hlp\Library.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Library.hm"
echo. >>"hlp\Library.hm"
echo // Resources (IDR_*) >>"hlp\Library.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Library.hm"
echo. >>"hlp\Library.hm"
echo // Dialogs (IDD_*) >>"hlp\Library.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Library.hm"
echo. >>"hlp\Library.hm"
echo // Frame Controls (IDW_*) >>"hlp\Library.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Library.hm"
REM -- Make help for Project LIBRARY


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Library.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Library.hlp" goto :Error
if not exist "hlp\Library.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Library.hlp" Debug
if exist Debug\nul copy "hlp\Library.cnt" Debug
if exist Release\nul copy "hlp\Library.hlp" Release
if exist Release\nul copy "hlp\Library.cnt" Release
echo.
goto :done

:Error
echo hlp\Library.hpj(1) : error: Problem encountered creating help file

:done
echo.
