
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


set(STARTUP_SRC ${CMAKE_SOURCE_DIR}/BSP/board/generated/startup_stm32l432xx.s)
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/BSP/board/generated/STM32L432KCUx_FLASH.ld)

add_library(HAL_CMSIS STATIC
    ${CORE_SRC}
    ${HAL_SRC}
    ${STARTUP_SRC}
    ${LINKER_SCRIPT}
)

target_include_directories(HAL_CMSIS SYSTEM PUBLIC
    ${CORE_INC}
    ${HAL_INC}
    ${CMSIS_INC}
)


target_compile_options(HAL_CMSIS PRIVATE ${COMPILE_OPTIONS})
target_compile_definitions(HAL_CMSIS PRIVATE ${COMPILE_DEFINITIONS})
target_link_options(HAL_CMSIS PRIVATE ${LINK_OPTIONS})