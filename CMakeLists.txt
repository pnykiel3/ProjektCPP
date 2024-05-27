# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and the programming language
project(CzyJestesMadrzejszy VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable for the main program
add_executable(main main.cpp)

# Include the directory containing the header files
target_include_directories(main PRIVATE lib)

# Add the source files from the 'lib' directory
file(GLOB LIB_SOURCES "lib/*.cpp")

# Link the library source files to the main executable
target_sources(main PRIVATE ${LIB_SOURCES})

