#include "stm32l4xx_iface.h"

void HAL_MspInit(void) {
    /* USER CODE BEGIN MspInit 0 */

    /* USER CODE END MspInit 0 */

    __HAL_RCC_SYSCFG_CLK_ENABLE();  // NOLINT
    __HAL_RCC_PWR_CLK_ENABLE();     // NOLINT

    /* System interrupt init*/

    /* Peripheral interrupt init */
    /* RCC_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(RCC_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(RCC_IRQn);

    /* USER CODE BEGIN MspInit 1 */

    /* USER CODE END MspInit 1 */
}
