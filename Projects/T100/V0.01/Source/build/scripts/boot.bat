@echo off
rem
cd ..
@echo on
.\T100Assembly.exe -l=work/os/boot .\work\os\boot\boot.txt .\build\boot.bin
@echo off
pause