# tests

local Windows commands at PowerShell

```
Download and install MSYS2
https://www.msys2.org/

Run
Start-Process rundll32.exe sysdm.cpl,EditEnvironmentVariables -verb RunAs
add C:\msys64\mingw64\bin to system Path

Install Toolchain
Run
pacman -S mingw-w64-ucrt-x86_64-toolchain

Install OpenCV https://opencv.org/
Run
pacman -S mingw64/mingw-w64-x86_64-opencv

Run
echo 'Running in MSYS2!';echo 'SYSTEM INFO'; systeminfo;echo 'DX DIAG'; dxdiag /dontskip /whql:off /64bit /t ./dxdiag.txt;while (!(Test-Path "./dxdiag.txt")) { Start-Sleep 10 }; cat ./dxdiag.txt;g++ --version;pkg-config --cflags --libs opencv4;g++ ./code/test.cpp -o ./out.exe -IC:\\msys64\\mingw64\\include\\opencv4 -lopencv_core;echo 'PWD'; pwd;echo 'LS'; ls;echo 'OUT'; ./out.exe >> data.txt

or just compile
g++ ./code/test.cpp -o ./out.exe -IC:\\msys64\\mingw64\\include\\opencv4 -lopencv_core

Install vcpkg
Run
git clone https://github.com/microsoft/vcpkg
.\vcpkg\bootstrap-vcpkg.bat

Install PCL https://pointclouds.org/
Run
.\vcpkg\vcpkg install pcl:x64-windows

Run
.\vcpkg\vcpkg search pcl

Run
.\vcpkg\vcpkg integrate install

Run
g++ ./code/test.cpp -o ./out.exe -IC:\\msys64\\mingw64\\include\\opencv4 -IC:\\vcpkg\\installed\\x64-windows\\include -lopencv_core

HAVE FUN

```

job

```
name: MSYS2
on: [push]

jobs:
  msys2-ucrt64:
    runs-on: windows-latest
    defaults:
      run:
        shell: msys2 {0}
    steps:
      - uses: actions/checkout@v3
      - uses: msys2/setup-msys2@v2
        with:
          msystem: UCRT64
          update: true
          install: git mingw-w64-ucrt-x86_64-toolchain
          # mingw-w64-ucrt-x86_64-gcc 
          # mingw-w64-i686-opencv
      - name: CI-Build
        run: |
          echo 'Running in MSYS2!'
          echo 'XDG_DATA_DIRS=' $XDG_DATA_DIRS
          export XDG_DATA_DIRS="/D/a/_temp/msys64/mingw64/share:$XDG_DATA_DIRS"
          yes | LC_ALL=en_US.UTF-8 pacman -S mingw-w64-x86_64-gtk3
          yes | LC_ALL=en_US.UTF-8 pacman -S mingw64/mingw-w64-x86_64-opencv
          echo 'SYSTEM INFO'; systeminfo
          echo 'DX DIAG'; dxdiag /dontskip /whql:off /64bit /t ./dxdiag.txt
          while (!(Test-Path "./dxdiag.txt")) { Start-Sleep 10 }; cat ./dxdiag.txt
          g++ --version
          pkg-config --cflags --libs opencv4
          g++ ./code/test.cpp -o ./out.exe -IC:\\msys64\\mingw64\\include\\opencv4 -lopencv_core
          echo 'PWD'; pwd
          echo 'LS'; ls
          echo 'OUT'; ./out.exe
```
Exit code 141 (maybe GPU related)