cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH "/home/pepe/pico/pico-sdk")
include(pico_sdk_import.cmake)

project(led)
pico_sdk_init()

add_executable(${PROJECT_NAME} main.c)
pico_add_extra_outputs(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_pwm)
