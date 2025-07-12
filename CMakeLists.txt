cmake_minimum_required(VERSION 3.10)
project(TaxCalculator)

set(CMAKE_CXX_STANDARD 17)

# Force static runtime on Windows to fix GoogleTest runtime mismatch
if(MSVC)
  foreach(flag_var
          CMAKE_C_FLAGS_DEBUG
          CMAKE_CXX_FLAGS_DEBUG
          CMAKE_C_FLAGS_RELEASE
          CMAKE_CXX_FLAGS_RELEASE)
    string(REPLACE "/MDd" "/MTd" ${flag_var} "${${flag_var}}")
    string(REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
  endforeach()
endif()

# Include directories
include_directories(include)
include_directories(extern/imgui)
include_directories(extern/imgui/backends)
include_directories(extern/sdl2/include)
include_directories(extern/glad/include)
include_directories(extern/glad/include/glad)

# Source files
set(IMGUI_SOURCES
    extern/imgui/imgui.cpp
    extern/imgui/imgui_demo.cpp
    extern/imgui/imgui_draw.cpp
    extern/imgui/imgui_tables.cpp
    extern/imgui/imgui_widgets.cpp
    extern/imgui/backends/imgui_impl_sdl2.cpp
    extern/imgui/backends/imgui_impl_opengl3.cpp
)
set(GLAD_SOURCE extern/glad/src/gl.c)

# Define executable
add_executable(TaxCalculatorApp
    src/main.cpp
    src/tax_calculator.cpp
    ${IMGUI_SOURCES}
    ${GLAD_SOURCE}
)

# Add SDL_MAIN_HANDLED to avoid SDL2main.lib dependency if you want
target_compile_definitions(TaxCalculatorApp PRIVATE SDL_MAIN_HANDLED)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Manually set SDL2 library directories and libs for Windows
if(WIN32)
    # Adjust this path to where you extracted SDL2 development libs
    set(SDL2_DIR "${CMAKE_SOURCE_DIR}/extern/sdl2")

    target_link_directories(TaxCalculatorApp PRIVATE "${SDL2_DIR}/lib/x64")

    # Link SDL2 and SDL2main explicitly on Windows
    target_link_libraries(TaxCalculatorApp PRIVATE 
        ${CMAKE_DL_LIBS} 
        OpenGL::GL 
        SDL2main 
        SDL2
    )

    # Post-build: copy SDL2.dll next to executable
    add_custom_command(TARGET TaxCalculatorApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_DIR}/lib/x64/SDL2.dll"
            $<TARGET_FILE_DIR:TaxCalculatorApp>
        COMMENT "Copying SDL2.dll to output directory"
    )
else()
    # On Linux/macOS, just link SDL2 dynamically (assumes SDL2 is installed)
    find_package(SDL2 REQUIRED)
    target_include_directories(TaxCalculatorApp PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(TaxCalculatorApp PRIVATE ${SDL2_LIBRARIES} OpenGL::GL ${CMAKE_DL_LIBS})
endif()

# GoogleTest setup (unchanged)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

add_executable(TaxCalculatorTests
    tests/TaxCalculatorTest.cpp
    src/tax_calculator.cpp
)
target_include_directories(TaxCalculatorTests PRIVATE include)
target_link_libraries(TaxCalculatorTests gtest gtest_main)

add_test(NAME TaxCalculatorTests COMMAND TaxCalculatorTests)
