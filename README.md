# ft_printf

**ft_printf** is a custom implementation of the standard C `printf` function. This project focuses on understanding variadic functions, type formatting, and output buffering, while complying with strict coding rules and performance constraints.

## 💡 Overview

- 🛠️ Recreates the behavior of `printf` from the C standard library
- 📦 Supports a wide range of format specifiers
- 🔍 Handles variable arguments using `stdarg.h`
- 🚫 No use of standard `printf`, `sprintf`, or related functions

## 🧰 Features

- Supported format specifiers:
  - `%c` – Character
  - `%s` – String
  - `%p` – Pointer (in hexadecimal)
  - `%d` / `%i` – Signed decimal integer
  - `%u` – Unsigned decimal integer
  - `%%` – Literal percent sign
- Proper handling of:
  - Field width and padding
  - NULL strings
  - Edge cases like `INT_MIN`, empty strings, etc.
- Modular and readable code structure
- Full support for writing to standard output only (`stdout`)

## 🚀 Getting Started

### Build
```bash
make
```
Builds the libftprintf.a static library.

### How To Use
```
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "world", 42);
    return 0;
}
```
