#include <iostream>

// ### Float Characteristics:
// - **Size**: Typically 4 bytes (32 bits).
// - **Precision**: Approximately 6-9 decimal digits.
// - **Range**: About 1.2E-38 to 3.4E+38.

// ### Memory Representation:
// - A `float` is represented in memory according to the IEEE 754 standard, which divides the 32 bits into three parts:
//   - 1 bit for the sign
//   - 8 bits for the exponent
//   - 23 bits for the mantissa (fraction)

int main()
{
    float number = 3.14f; // the 'f' suffix indicates a float literal
    std::cout << "Value of number: " << number << std::endl;
    return 0;
}
