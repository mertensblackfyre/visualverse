cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(cli VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(LEPT REQUIRED lleptonica)
pkg_check_modules(TESSERACT REQUIRED tesseract)

# Include directories for Leptonica and Tesseract
include_directories(${LEPT_INCLUDE_DIRS})
include_directories(${TESSERACT_INCLUDE_DIRS})

# Set the library directories for Leptonica and Tesseract
link_directories(${LEPT_LIBRARY_DIRS})
link_directories(${TESSERACT_LIBRARY_DIRS})

# Add the source files
add_executable(main main.cxx)

# Link the required libraries
target_link_libraries(main ${LEPT_LIBRARIES} ${TESSERACT_LIBRARIES})

# Optionally, print the found packages for debugging
message(STATUS "Leptonica include dirs: ${LEPT_INCLUDE_DIRS}")
message(STATUS "Leptonica libraries: ${LEPT_LIBRARIES}")
message(STATUS "Tesseract include dirs: ${TESSERACT_INCLUDE_DIRS}")
message(STATUS "Tesseract libraries: ${TESSERACT_LIBRARIES}")

