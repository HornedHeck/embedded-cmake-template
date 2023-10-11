cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arm-none-eabi-toolchain.cmake)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
message("Build type: " ${CMAKE_BUILD_TYPE})

project(
    "o-kawai-koto"
    LANGUAGES C ASM
    VERSION 0.1.0
)

set(TARGET_NAME ${CMAKE_PROJECT_NAME})


set(COMPILE_OPTIONS 
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -fdata-sections
    -ffunction-sections
    -Wall
    -Wno-unused-command-line-argument
    $<$<CONFIG:Debug>:-Og>
)


set(COMPILE_DEFINITIONS 
    STM32L432xx
    USE_HAL_DRIVER
)

set(LINK_OPTIONS
    -T${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L432KCUx_FLASH.ld
    -mcpu=cortex-m4
    # -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    # -specs=nano.specs
    # -lc
    # -lm
    # -lnosys
    # -Wl,-Map=${PROJECT_NAME}.map,--cref
    # -Wl,--gc-sections
)

file(GLOB APP_SRC
    ${CMAKE_SOURCE_DIR}/app/src/*.c
)

set(APP_INC
    ${CMAKE_SOURCE_DIR}/app/inc
)


add_subdirectory(${CMAKE_SOURCE_DIR}/BSP)

add_executable(${TARGET_NAME}
    ${APP_SRC}
    ${BOARD_SRC}
)

target_include_directories(${TARGET_NAME} PRIVATE
    ${APP_INC}
    ${BOARD_INC}
)

target_link_libraries(${TARGET_NAME} PRIVATE BOARD)
target_link_libraries(${TARGET_NAME} PRIVATE NETWORK)

target_compile_options(${TARGET_NAME} PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(${TARGET_NAME} PRIVATE ${COMPILE_DEFINITIONS})
target_link_options(${TARGET_NAME} PRIVATE ${LINK_OPTIONS})

set_target_properties(
    ${TARGET_NAME}
    PROPERTIES
    C_CLANG_TIDY "clang-tidy"
)


add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.bin
    BYPRODUCTS ${TARGET_NAME}.bin
)