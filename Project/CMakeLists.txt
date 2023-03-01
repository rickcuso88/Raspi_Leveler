cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(Project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(level src/level.cpp libraries/LIS3DH.cpp libraries/neomatrix.cpp libraries/ws2812.pio.h) #potentially doesn't need libraries

#pico_generate_pio_header(level ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

pico_enable_stdio_usb(level 1)
pico_enable_stdio_uart(level 1)

pico_add_extra_outputs(level)

target_link_libraries(level pico_stdlib hardware_i2c hardware_pio hardware_clocks) # pio_ws2812 ws2812.pio




