# Lab 3 : Zuzana Czmelová

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/Zuzanaczm/Digital_electronics_2/tree/main/Labs/03-gpio](https://github.com/Zuzanaczm/Digital_electronics_2/tree/main/Labs/03-gpio)

## Preparation tasks (done before the lab at home)

1. Fill in the following table and enter the number of bits and numeric range for the selected data types defined by C.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   | 8 | -128, -127 ... 127 | Signed 8-bit Integer |
| `uint16_t` | 16 | 0, 1, ..., 65535 | Unsigned 16-bit integer |
| `int16_t`  | 16 | −32768, −32767, ... 32767 | Signed 16-bit integer |
| `float`    | 32 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     | 0 | 0 | No return type for function / generic pointer |

2. Any function in C contains a declaration (function prototype), a definition (block of code, body of the function); each declared function can be executed (called)

```C
#include <avr/io.h>

// Function declaration (prototype)
uint16_t calculate(uint8_t, ...    );

int main(void)
{
    uint8_t a = 156;
    uint8_t b = 14;
    uint16_t c;

    // Function call
    c = ...      (a, b);

    while (1)
    {
    }
    return 0;
}

// Function definition (body)
...      calculate(uint8_t x, uint8_t y)
{
    uint16_t result;    // result = x^2 + 2xy + y^2

    result = x*x;
    ...
    ...
    return result;
}
```
