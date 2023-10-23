#include "interruptions.h"

#include "stm32l4xx.h"

void SysTick_Handler() {
    HAL_IncTick();
}
