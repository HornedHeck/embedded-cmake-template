file(GLOB CORE_SRC ${CMAKE_CURRENT_LIST_DIR}/Src/*.c)

set(CORE_INC ${CMAKE_CURRENT_LIST_DIR}/Inc)

set(LINKER_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/STM32L432KCUx_FLASH.ld)

set(HAL_SRC
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_cortex.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_exti.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_flash_ramfunc.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim.c
    ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim_ex.c
)

set(HAL_INC ${CMAKE_CURRENT_LIST_DIR}/Drivers/STM32L4xx_HAL_Driver/Inc
            ${CMAKE_CURRENT_LIST_DIR}/Drivers/CMSIS/Device/ST/STM32L4xx/Include)

set(CMSIS_INC ${CMAKE_CURRENT_LIST_DIR}/Drivers/CMSIS/Include
              ${CMAKE_CURRENT_LIST_DIR}/Drivers/CMSIS/Core/Include)

add_library(HAL_CMSIS STATIC)

target_sources(HAL_CMSIS PRIVATE ${CORE_SRC} ${HAL_SRC} ${LINKER_SCRIPT})

target_include_directories(HAL_CMSIS SYSTEM PUBLIC ${CORE_INC} ${HAL_INC}
                                                   ${CMSIS_INC})

target_compile_options(HAL_CMSIS PUBLIC ${COMPILE_OPTIONS})
target_compile_definitions(HAL_CMSIS PUBLIC ${COMPILE_DEFINITIONS})
target_link_options(HAL_CMSIS PUBLIC ${LINK_OPTIONS})
