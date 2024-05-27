cmake_minimum_required(VERSION 3.10)

# Nazwa, język programowania
project(ProjektCPP VERSION 1.0 LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# plik executable
add_executable(main main.cpp)

# Dołącz katalog zawierający pliki nagłówkowe
target_include_directories(main PRIVATE lib)

# pliki .cpp z folderu lib
file(GLOB LIB_SOURCES "lib/*.cpp")

# Linkuj pliki źródłowe biblioteki z plikiem executable
target_sources(main PRIVATE ${LIB_SOURCES})

