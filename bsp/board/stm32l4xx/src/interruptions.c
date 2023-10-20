#include "interruptions.h"

#include "stm32l4xx.h"

void SysTickHandler() { HAL_IncTick(); }
