#include "pin_mapper.h"

#include "stm32l4xx_iface.h"

PinPair MapToInternal(Pin pin) {
    PinPair res = {.group = 0, .pin = 0};
    switch (pin) {
        case LED:
            res.group = LD3_GPIO_Port; //NOLINT
            res.pin = LD3_Pin;
            break;
    }
    return res;
}