#include <stdint.h>

// Defines
#define NONE 0
#define UART 1
#define SPI  2

// Typedef
typedef struct InterfaceHandle {
    uint8_t type;
    uint8_t number;
} InterfaceHandle;

typedef struct CommunicationHandle {
    InterfaceHandle interface;
    uint16_t request_size;
    uint8_t *request_data;
    uint16_t initial_size;
    uint8_t *buffer;
    uint16_t (*callback)(void);
} CommunicationHandle;

// Funtions
void TogglePin() {}
