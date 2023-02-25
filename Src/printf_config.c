/**
 * @file printf_config.c
 * @author Donghyun Ko
 * @brief Redirect the printf function to an UART
 * @version 1.0
 * @date 2023
 * 
 * @copyright MIT License
 * 
 */
#include "printf_config.h"

/** @addtogroup UART_Redirection UART I/O Redirection
 * @{
*/

/** @addtogroup UART_Redirection_Group1 Private variables
 * @{
*/

static UART_HandleTypeDef *_huart = NULL;  /// Private UART handler.

/**
 * @}
 */

/** @addtogroup UART_Redirection_Group2 Initialization and de-initalization
 * @{
*/

/**
 * @brief Initialize UART handler.
 * 
 * @param huart Pointer to UART handler.
 */
void initialize_uart_printf(UART_HandleTypeDef *huart)
{
    _huart = huart;
}

/**
 * @brief De-initialize UART handler.
 * 
 */
void deinitialize_uart_printf(void)
{
    _huart = NULL;
}

/**
 * @}
 */

/** @addtogroup UART_Redirection_Group3 Private functions
 * @{
*/

/**
 * @brief Redirects the printf function to the UART.
 * 
 * @param fd File descriptor of file.
 * @param ptr Pointer to the character array to be wrtten.
 * @param len Number of bytes.
 * @return Number of bytes written.
 */
int _write(int fd, char* ptr, int len) {

    if (!_huart) {
        return -1;
    }

    HAL_UART_Transmit(_huart, (uint8_t *)ptr, len, HAL_MAX_DELAY);

    return len;
}

/**
 * @}
 */

/**
 * @}
 */