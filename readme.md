# TaxCalculator

A simple C++ tax calculator application with unit tests using Google Test.

## Folder Structure

```
TaxCalculator/
├── build/              # Build directory created with mkdir
├── extern/             # External libraries
│   ├── imgui/          # ImGui source and headers
│   ├── sdl2/           # SDL2 includes and libs
│   └── glad/           # GLAD OpenGL loader
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
cd path\to\TaxCalculator #(set the current directory to the cloned repo)
mkdir build  #(skip if you have already done this (already have a build folder)
cd build  #(set your current directory to be inside the build folder)
cmake ..  #(run the cmake file)
cmake --build . --config Debug  #(build)
.\Debug\TaxCalculatorApp.exe  #(run the app)
```

### Build & Run Tests:

```powershell
cd path\to\TaxCalculator #(set the current directory to the cloned repo)
mkdir build #(skip if you have already done this (already have a build folder)
cd build #(set your current directory to be inside the build folder)
cmake .. #(run the cmake file)
cmake --build . --config Debug  #(build)
.\Debug\TaxCalculatorTests.exe #(run the tests)
```

---

## 🐧 Linux

### Prerequisites:

- Install g++: `sudo apt install build-essential`
- Install CMake: `sudo apt install cmake`

### Build & Run Application:

```bash
cd path/to/TaxCalculator #(set the current directory to the cloned repo)
mkdir build #(skip if you have already done this (already have a build folder)
cd build  #(set your current directory to be inside the build folder)
cmake .. #(run the cmake file)
make     #(build)
./TaxCalculatorApp #(run the app)
```

### Build & Run Tests:

```bash
cd path/to/TaxCalculator #(set the current directory to the cloned repo)
mkdir build #(skip if you have already done this (already have a build folder)
cd build #(set your current directory to be inside the build folder)
cmake .. #(run the cmake file)
make     #(build)
./TaxCalculatorTests #(run the tests)

```

---

## Notes:

- On Windows, Visual Studio solutions are auto-generated in the `build` folder.
- On Linux, `make` will create the binaries directly.
- Test results will appear in the terminal after running `ctest`.

---

Feel free to contribute or improve this project!

