cmake_minimum_required(VERSION 3.10)
project(BleuIO-Library VERSION 1.0 LANGUAGES CXX)

# Set the library source files
add_library(BleuIO STATIC src/BleuIO.cpp)

# Specify include directories
# Replace "/opt/homebrew/include" with the actual path where libserialport.h is located
target_include_directories(BleuIO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include /usr/local/include /opt/homebrew/include)

# Link with libserialport
find_library(SERIALPORT_LIB NAMES serialport REQUIRED PATHS /usr/local/lib /opt/homebrew/lib)
target_link_libraries(BleuIO ${SERIALPORT_LIB})

# Install targets (make the library installable)
install(TARGETS BleuIO DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# Add examples and tests
add_executable(example examples/main.cpp)
target_link_libraries(example BleuIO)

add_executable(test tests/test_bleuio.cpp)
target_link_libraries(test BleuIO)
