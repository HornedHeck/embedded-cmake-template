#ifndef BSP_BOARD_INCLUDE_BASIC_OPERATIONS
#define BSP_BOARD_INCLUDE_BASIC_OPERATIONS

/* Includes */

#include <stdint.h>

/* Types */

typedef enum { LED } Pin;

/* Functions */

void TogglePin(Pin pin);

void Delay(uint32_t milis);

#endif /* BSP_BOARD_INCLUDE_BASIC_OPERATIONS */
