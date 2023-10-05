#include <stdint.h>

// Defines
#define NONE 0
#define UART 1
#define SPI  2

// Typedef
struct communication_handle {
    uint8_t type;
    uint8_t number;
} communication_handle;

// Funtions

void toggle_pin() {}