# `printf` utils targeted on STM32 series MCUs
This project maintains redirecting the `printf()` function to an UART. Also, it supports printing debug messages depending on the debug verbose level (`DEBUG_LEVEL`).
#### Features
- `printf()` UART redirection
- Printing debug messages depending on the verbose level
#### Dependencies
- STM32 HAL library

## How to use `printf()`
1. In order to use this feature, copy all `*.c` and `*.h` files into your project or add the repository as submodule.
```bash
git submodule add https://github.com/NyankoTear/printf-utils.git
```

2. Of course, you must activate at least one UART peripheral.

3. The `printf_config.h` needs `usart.h`, Check `Generate peripheral initalization as a pair of '.c/.h' files per peripheral` in Project Manager -> Code Generator -> Generated files from a STM32CubeMX application.
> **Note**: If you don't want to use this option or not using the STM32CubeMX, make sure that `printf_config.h` includes `UART_HandleTypeDef` and `HAL_UART_Transmit()`.
4. Include all paths.
5. Initialize the UART handler calling `initialize_uart_printf()`.
6. You can finally use `printf()`.
## How to use the debug messages (`DEBUG_V`, `DEBUG_VV`, and `DEBUG_VVV`)
1. First, you must redirect the `printf()` function to the UART. Please follow the guideline: [How to use `printf()`](#how-to-use-printf).
2. Add a preprocessor symbol: `DEBUG_LEVEL=<verbose level>`
3. Depending on your debug verbose level, the `<verbose level>` can be set from 0 to 3.
##### Examples
```C
DEBUG_LEVEL=0 // Deactivates all debug messages.
DEBUG_LEVEL=1 // Only activates DEBUG_V(). DEBUG_VV() and DEBUG_VVV() doesn't print anything.
DEBUG_LEVEL=2 // Activates DEBUG_V() and DEBUG_VV().
DEBUG_LEVEL=3 // Activates all debug messages.
```

## Troubleshooting
### I configured the UART peripheral correctly, but it prints nothing.
You may coded like this:
```C
printf("Print something");
```
`stdout` is line buffered by default. Therefore, it doesn't prompt the text on the screen until a new line escape sequence (`\n`) met. Adding the `\n` at the end of the string resolves the issue.
```C
printf("Print something\n");
```
However, the solution from the above forces to move the cursor to the next line. If you not happy with it, there is a great [link](https://stackoverflow.com/a/1716621) that explains about `stdout` and how to print immediately. I would recommend 2 possible ways from it.

- Using `fflush`
```C
printf("Print immediately");
fflush(stdout);
```
- Make `stdout` to 'no buffering'
```C
setvbuf(stdout, NULL, _IONBF, 0); 
printf("Print immediately");
```
### It doesn't print float values. Where are my floating points?
#### STM32CubeIDE
Simply check `Use float with printf from newlib-nano (-u _printf_float)` option in the project properties.
#### Makefile
You must add `-u _printf_float` to the linker options (`LDFLAGS`) in the `Makefile`.
