echo off
set CCPATH=C:\cc65\bin
set LIBFILE=C:\cc65\lib\nes.lib

set SRCFILE1=startup
set SRCFILE2=main
set SRCFILE3=fcsub
set NESFILE=mapper3test.nes
set CFGFILE=build.cfg

%CCPATH%\cl65 -t none -o %SRCFILE1%.o -c %SRCFILE1%.asm
if %errorlevel% neq 0 goto owari

%CCPATH%\cl65 -t none -o %SRCFILE2%.o -c -O %SRCFILE2%.c
if %errorlevel% neq 0 goto owari

%CCPATH%\cl65 -t none -o %SRCFILE3%.o -c -O %SRCFILE3%.c
if %errorlevel% neq 0 goto owari

%CCPATH%\ld65 -o %NESFILE% --config %CFGFILE% --obj %SRCFILE1%.o %SRCFILE2%.o %SRCFILE3%.o --lib %LIBFILE%
if %errorlevel% neq 0 goto owari

exit /b
:owari
pause
