# 🖨️ ft_printf — Printf Reimplementation

> Reimplementation of the C `printf` function using variadic arguments.

![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen?style=flat-square)
![Language](https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white)
![School](https://img.shields.io/badge/School-42-000000?style=flat-square)

---

## 📌 Overview

`ft_printf` replicates the behavior of the standard C `printf` function, handling multiple format specifiers and variadic arguments. This project deepens understanding of how format strings work — a concept directly tied to **format string vulnerabilities** in cybersecurity.

---

## ✅ Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address (hex) |
| `%d` / `%i` | Signed integer |
| `%u` | Unsigned integer |
| `%x` / `%X` | Hexadecimal (lower / upper) |
| `%%` | Literal percent sign |

---

## 🛠️ Usage

```bash
git clone https://github.com/Fazejli/ft_printf.git
cd ft_printf
make
```

Include in your project:
```c
#include "ft_printf.h"

ft_printf("Hello %s! You are %d years old.\n", "world", 42);
ft_printf("Address: %p\n", ptr);
ft_printf("Hex: %x\n", 255); // Output: ff
```

---

## 📁 Project Structure

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
└── ft_printf_utils.c
```

---

## 🧠 Key Concepts

- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- Format string parsing
- Base conversion (decimal → hexadecimal)
- Understanding of **format string vulnerabilities** (`%x`, `%p` leaking stack data)
