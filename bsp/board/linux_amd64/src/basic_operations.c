#include "basic_operations.h"

#include "stdio.h"
#include "unistd.h"

void TogglePin(Pin pin) { printf("Toggle pin %d\n", pin); }

void Delay(uint32_t milis) {
    usleep(milis * 1000);  // NOLINT
}