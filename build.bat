@echo off

set CC=g++
set CFLAGS=-Wall -std=c++17 -Wl,--no-as-needed -lstdc++ -mthreads -mwindows  
set OUTPUT=RA-TestBuild.exe

rmdir /s /q build

echo %CC%
echo %CFLAGS%

taskkill /f /im RA-TestBuild.exe

if exist RA-TestBuild.exe del RA-TestBuild.exe

if not exist build mkdir build

:: Compile all .cpp files from the src directory and its subdirectories
echo Compiling source files...

:: Compile source files from each folder
%CC% %CFLAGS% -c src\main.cpp -o build\main.o

%CC% %CFLAGS% -c src\console\console.cpp -o build\console.o

%CC% %CFLAGS% -c src\movement\movement.cpp -o build\movement.o

%CC% %CFLAGS% -c src\cmd\cmd.cpp -o build\cmds.o

%CC% %CFLAGS% -c src\common\com.cpp -o build\com.o

%CC% %CFLAGS% -c src\chat\chat.cpp -o build\chat.o

%CC% %CFLAGS% -c src\entities\entities.cpp -o build\entities.o

%CC% %CFLAGS% -c src\cvar\cvar.cpp -o build\cvar.o

%CC% %CFLAGS% -c src\client\cl_main.cpp -o build\client.o
%CC% %CFLAGS% -c src\client\cl_commands.cpp -o build\cl_commands.o

%CC% %CFLAGS% -c src\math\math.cpp -o build\math.o

%CC% %CFLAGS% -c src\server\sv_main.cpp -o build\sv_main.o
%CC% %CFLAGS% -c src\server\sv_commands.cpp -o build\sv_cmds.o

%CC% %CFLAGS% -c src\worldmap\world.cpp -o build\world.o

%CC% %CFLAGS% -c src\renderer\renderer.cpp -o build\renderer.o
%CC% %CFLAGS% -c src\cinematic\cinematic.cpp -o build\cinematic.o
%CC% %CFLAGS% -c src\renderer\fps.cpp -o build\fps.o

%CC% %CFLAGS% -c src\color\codes.cpp -o build\codes.o


rem %CC% %CFLAGS% -c src\weapons\weapons.cpp -o build\weapons.o
rem %CC% %CFLAGS% -c src\lib\qvsnprintf.c -o build\qvsnprintf.o
rem %CC% %CFLAGS% -c src\srd\srd.cpp -o build\srd.o
rem %CC% %CFLAGS% -c src\textures\texture_loader.cpp -o build\textures.o
rem %CC% %CFLAGS% -c src\network\network.cpp -o build\network.o
rem %CC% %CFLAGS% -c src\bsp\bsp.cpp -o build\bsp.o
rem %CC% %CFLAGS% -c src\sounds\sounds.cpp -o build\sounds.o
rem %CC% %CFLAGS% -c src\free_look\free_look.cpp -o build\free_look.o

echo Linking object files...
%CC% %CFLAGS% -o %OUTPUT% build\*.o -lSDL2main -lSDL2 -lSDL2_image


echo Build complete.

