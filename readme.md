# TaxCalculator

A simple C++ tax calculator application with unit tests using Google Test.

## Folder Structure

```
TaxCalculator/
├── build/              # Build will be created with the mkdir command
├── include/            # Header files
│   └── tax_calculator.h
├── src/                # Source files
│   ├── main.cpp
│   └── tax_calculator.cpp
├── tests/              # Unit tests
│   └── TaxCalculatorTest.cpp
└── CMakeLists.txt
```

---

## \:computer: Windows 🪟

### Prerequisites:

- Install Visual Studio with C++ development tools.
- Install CMake (https\://cmake.org/download/).

### Build & Run Application:

```powershell
cd path\to\TaxCalculator
mkdir build  #(if you have already done this ( its not your first time running and already have a build folder) skip mkdir build)
cd build 
cmake ..
cmake --build . --config Debug
.\Debug\TaxCalculatorApp.exe
```

### Build & Run Tests:

```powershell
cd path\to\TaxCalculator
mkdir build #(if you have already done this ( its not your first time running and already have a build folder) skip mkdir build)
cd build
cmake ..
cmake --build . --config Debug
.\Debug\TaxCalculatorTests.exe
```

---

## 🐧 Linux

### Prerequisites:

- Install g++: `sudo apt install build-essential`
- Install CMake: `sudo apt install cmake`

### Build & Run Application:

```bash
cd path/to/TaxCalculator
mkdir build #(if you have already done this ( its not your first time running and already have a build folder) skip mkdir build)
cd build
cmake ..
make
./TaxCalculatorApp
```

### Build & Run Tests:

```bash
cd path/to/TaxCalculator/build
mkdir build #(if you have already done this ( its not your first time running and already have a build folder) skip mkdir build)
cd build
cmake ..
make
./TaxCalculatorTests

```

---

## Notes:

- On Windows, Visual Studio solutions are auto-generated in the `build` folder.
- On Linux, `make` will create the binaries directly.
- Test results will appear in the terminal after running `ctest`.

---

Feel free to contribute or improve this project!

