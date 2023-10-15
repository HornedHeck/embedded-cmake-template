#include "basic_operations.h"

#include "pin_mapper.h"
#include "stm32l4xx_hal.h"

void TogglePin(Pin pin) {
    PinPair tmp = MapToInternal(pin);
    HAL_GPIO_TogglePin(tmp.group, tmp.pin);
}

void Delay(uint32_t milis) {
    HAL_Delay(milis);
}