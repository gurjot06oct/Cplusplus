#include <iostream>

// ### Basic Characteristics

// - **Size**: Typically 8 bytes (64 bits).
// - **Precision**: Approximately 15-17 decimal digits.
// - **Range**: About 1.7E-308 to 1.7E+308.

// ### Memory Representation

// A `double` is represented in memory according to the IEEE 754 standard, which divides the 64 bits into three parts:
// - 1 bit for the sign
// - 11 bits for the exponent
// - 52 bits for the mantissa (fraction)

int main()
{
    double number = 3.141592653589793;
    std::cout << "Value of number: " << number << std::endl;
    return 0;
}
