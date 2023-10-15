#ifndef BSP_BOARD_STM32L4XX_INCLUDE_PIN_MAPPER
#define BSP_BOARD_STM32L4XX_INCLUDE_PIN_MAPPER

/* Includes */

#include "basic_operations.h"
#include "stm32l4xx_hal.h"

typedef struct {
    GPIO_TypeDef* group;
    uint16_t pin;
} PinPair;

PinPair MapToInternal(Pin pin);

#endif /* BSP_BOARD_STM32L4XX_INCLUDE_PIN_MAPPER */
