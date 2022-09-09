@echo off
rem
cd ..
@echo on
.\T100Assembly.exe -l=work/os .\work\os\rom\rom.txt .\build\rom.bin
@echo off
pause
