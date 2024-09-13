cmake_minimum_required(VERSION 3.10)
project(visualverse)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Tesseract package
find_package(PkgConfig)

pkg_check_modules(leptonica IMPORTED_TARGET lept)
pkg_check_modules(tesseract4 IMPORTED_TARGET tesseract)

# Add your source files here
add_executable(visualverse main.cxx)

target_link_libraries(visualverse
  PkgConfig::leptonica
  PkgConfig::tesseract4
)

