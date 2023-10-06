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

file(GLOB APP_SRC
    ${CMAKE_SOURCE_DIR}/app/src/*.c
)

set(APP_INC
    ${CMAKE_SOURCE_DIR}/app/inc
)

file(GLOB CORE_SRC
    ${CMAKE_SOURCE_DIR}/BSP/board/generated/Src/*.c
)

set(CORE_INC
    ${CMAKE_SOURCE_DIR}/BSP/board/generated/Inc
)

set(CMSIS_INC
    ${CMAKE_SOURCE_DIR}/BSP/board/generated/CMSIS/Include
    ${CMAKE_SOURCE_DIR}/BSP/board/generated/CMSIS/Core/Include
)


set(HAL_SRC
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_cortex.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_exti.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash_ex.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash_ramfunc.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_gpio.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr_ex.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc_ex.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim.c"
    "${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim_ex.c"
    "${CMAKE_SOURCE_DIR}/BSP//board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_uart.c"
    "${CMAKE_SOURCE_DIR}/BSP//board/generated/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_uart_ex.c"
)

set(HAL_INC
    ${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L4xx_HAL_Driver/Inc
    ${CMAKE_SOURCE_DIR}/BSP/board/generated/CMSIS/Device/ST/STM32L4xx/Include
)

# Board
set(BOARD_INC
    ${CMAKE_SOURCE_DIR}/BSP/board/inc/
    ${CMAKE_SOURCE_DIR}/BSP/board/stm32l4xx/inc
)

file(GLOB BOARD_SRC
    ${CMAKE_SOURCE_DIR}/BSP/board/stm32l4xx/src/*.c
)


# Network
set(NETWORK_INC
    ${CMAKE_SOURCE_DIR}/BSP/network/inc/
)

file(GLOB NETWORK_SRC
    ${CMAKE_SOURCE_DIR}/BSP/network/src/*.c
)

set(STARTUP_SRC ${CMAKE_SOURCE_DIR}/BSP/board/generated/startup_stm32l432xx.s)
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L432KCUx_FLASH.ld)

add_executable(${TARGET_NAME}
    ${APP_SRC}
    ${CORE_SRC}
    ${HAL_SRC}
    ${BOARD_SRC}
    ${NETWORK_SRC}
    ${STARTUP_SRC}
    ${LINKER_SCRIPT}
)

target_include_directories(${TARGET_NAME} PRIVATE
    ${APP_INC}
    ${CORE_INC}
    ${CMSIS_INC}
    ${BOARD_INC}
    ${NETWORK_INC}
    ${HAL_INC}
)

target_compile_options(${TARGET_NAME} PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard

    -fdata-sections
    -ffunction-sections

    -Wall

    $<$<CONFIG:Debug>:-Og>
)

target_compile_definitions(${TARGET_NAME} PRIVATE
    STM32L432xx
    USE_HAL_DRIVER
)

target_link_options(${TARGET_NAME} PRIVATE
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


add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.bin
    BYPRODUCTS ${TARGET_NAME}.bin
)