@echo off
echo Hello, I'm going to automatically move the .dll files and the configuration file (.suo) to the appropriate places.

echo ------------------------------------------------------------------------------------------------------------------------
echo Moving dll files to Debug and Release folders so the .exe will be able to load them at runtime.
xcopy /Y /s ".\external_libraries\dlls\*.dll" ".\Debug\"
xcopy /Y /s ".\external_libraries\dlls\*.dll" ".\Release\"

echo ------------------------------------------------------------------------------------------------------------------------
echo Moving .suo file with configurations for linker, includes, and library files to hidden location .vs\proj_name\v15\.suo
echo F | del /F /A:H ".\.vs\scaling-octo-tribble\v15\.suo"
echo F | xcopy /I /Y /s ".\configuration_files\.suo" ".\.vs\scaling-octo-tribble\v15\.suo"