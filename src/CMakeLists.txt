# - Set CMake requirments for the declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)


# - Don't allow C++ Compiler Vendor Extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Use standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -pedantic -Wshadow")

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/ProcessCommandLine.cpp
    MPAGSCipher/RunCaesarCipher.cpp
)

target_include_directories(mpags-cipher 
    PRIVATE MPAGSCipher
)

target_compile_features(mpags-cipher PRIVATE cxx_std_11 cxx_auto_type cxx_range_for cxx_uniform_initialization)