cmake_minimum_required(VERSION 3.10)
project(BleuIO-Library VERSION 1.0 LANGUAGES CXX)

# Set the library source files
add_library(BleuIO STATIC src/BleuIO.cpp)


# Specify include directories, including the Homebrew directory
target_include_directories(BleuIO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include /opt/homebrew/include)

# Link with libserialport from Homebrew path
find_library(SERIALPORT_LIB NAMES serialport REQUIRED PATHS /opt/homebrew/lib)
target_link_libraries(BleuIO ${SERIALPORT_LIB})

# Install targets (make the library installable)
install(TARGETS BleuIO DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Add examples and tests
add_executable(example examples/main.cpp)
target_link_libraries(example BleuIO)

add_executable(test tests/test_bleuio.cpp)
target_link_libraries(test BleuIO)

# Include CPack module
include(CPack)

# Minimal CPack setup
set(CPACK_PACKAGE_NAME "BleuIO-Library")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A C++ library for interacting with the BleuIO BLE USB dongle via serial communication.")
set(CPACK_PACKAGE_CONTACT "sheikh@smartsensordevices.com")
set(CPACK_PACKAGE_LICENSE "MIT")

# Define the source directories to include in the package
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")  # Generates compressed tarballs or zip files

# Install library and header files for packaging
install(TARGETS BleuIO DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Include CPack to generate tarball or zip
include(CPack)
