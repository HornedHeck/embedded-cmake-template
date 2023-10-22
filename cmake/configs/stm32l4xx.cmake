set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/tool/arm_none_eabi_toolchain.cmake)

set(COMPILE_OPTIONS
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -fdata-sections
    -ffunction-sections
    -Wall
    -Wno-unused-command-line-argument
    $<$<CONFIG:Debug>:-Og>)

set(COMPILE_DEFINITIONS STM32L432xx USE_HAL_DRIVER)

set(LINK_OPTIONS
    -T${CMAKE_SOURCE_DIR}/drivers/STM32L432KCUx_FLASH.ld
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    # -specs=nano.specs -lc -lm -lnosys
    -Wl,-Map=${PROJECT_NAME}.map,--cref
    # -Wl,--gc-sections
)