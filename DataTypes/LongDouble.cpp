#include <iostream>
#include <cfloat> // for LDBL_MIN and LDBL_MAX

// ### Basic Characteristics:
// - **Size**: Typically 16 bytes (128 bits), though this can vary depending on the platform and compiler.
// - **Precision**: Higher precision compared to `double`, typically offering more than 17 decimal digits.
// - **Range**: Extended range compared to `double`, but specifics can vary across implementations.

// ### Memory Representation:
// - A `long double` is also represented in memory according to the IEEE 754 standard, similar to `double` and `float`, but with an extended size.
//   - 1 bit for the sign
//   - 15 bits for the exponent (on some platforms)
//   - Up to 112 bits for the mantissa (fraction)

int main()
{
    std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
    std::cout << "Minimum long double value: " << LDBL_MIN << std::endl;
    std::cout << "Maximum long double value: " << LDBL_MAX << std::endl;

    return 0;
}
