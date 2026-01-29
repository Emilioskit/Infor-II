# Infor-II
Ejercicios y cosas en C++

## Compile & Run (VS Code)

### macOS
Make sure `g++` is installed (Xcode Command Line Tools).

Compile:
```bash
g++ main.cpp -g -o app
# with multiple files
g++ main.cpp other.cpp -g -o app
```
Run
```bash
./app
```

## windows
Make sure g++ is installed (MinGW-w64 or MSYS2) and added to PATH.

Compile:
```bash
g++ main.cpp -g -o app.exe
# with multiple files
g++ main.cpp other.cpp -g -o app.exe

```
Run
```bash
app.exe
```

### notes:
g++ compiles C++ source files
-g enables debugging
-o sets the output file name


