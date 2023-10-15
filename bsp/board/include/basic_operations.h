#ifndef BOARD_INCLUDE_BASIC_OPERATIONS
#define BOARD_INCLUDE_BASIC_OPERATIONS

/* Includes */

#include <stdint.h>

/* Types */

typedef enum { LED } Pin;

/* Functions */

void TogglePin(Pin pin);

void Delay(uint32_t milis);

#endif /* BOARD_INCLUDE_BASIC_OPERATIONS */
