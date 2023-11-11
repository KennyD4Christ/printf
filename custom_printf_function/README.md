# Custom printf Function

A simple implementation of _printf, a custom printf function in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project provides a basic implementation of _printf, a custom_printf function in the C programming language. The standard printf function in C is a powerful and widely used function for formatted output. This custom implementation aims to provide a simplified version, showcasing the underlying principles of how printf works.

## Features

- **Format Specifiers:** Supports basic format specifiers such as `%d`, `%s`, `%c`, etc.
- **Variable Arguments:** Handles variable arguments using the `stdarg.h` library.
- **Customization:** Easy to customize and extend for specific use cases.

## Usage

To use the custom printf function in your C program, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/KennyD4Christ/printf.git
    ```

2. Include the main.h header file in your C source code.

3. Use the _printf function in your code as you would with the standard printf.

4. Compile your program, ensuring that _printf.c is part of the compilation.

    ```bash
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *_printf.c
    ```

5. Run your compiled program:

    ```bash
    ./my_program
    ```

## Example

```c
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int main() {
    _printf("Hello, %s! The answer is %d.\n", "User", 42);
    return 0;
}

