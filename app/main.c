#include "main.h"

#include "basic_operations.h"
#include "init_board.h"

int main() {
    InitBoard();
    while (1) {
        TogglePin(LED);
        Delay(100); //NOLINT
    }
    return 0;
}
