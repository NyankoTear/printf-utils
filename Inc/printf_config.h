/**
 * @file printf_config.h
 * @author Donghyun Ko
 * @brief Redirect the printf function to an UART
 * @version 1.0
 * @date 2023
 * 
 * @copyright MIT License
 * 
 */
#ifndef __PRINTF_CONFIG_H__
#define __PRINTF_CONFIG_H__

#include <stdio.h>
#include "usart.h"

void initialize_uart_printf(UART_HandleTypeDef *huart);
void deinitialize_uart_printf(void);

#endif /* __PRINTF_CONFIG_H__ */