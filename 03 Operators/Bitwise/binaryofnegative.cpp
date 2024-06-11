#include <iostream>
using namespace std;

int main()
{
    int a = -1;
    // Binary representation of 1 in 4 bits: 0001
    // Binary representation of -1 in 4 bits (using two's complement):
    // 1. Invert all bits of 1 (one's complement): 1110
    // 2. Add 1 to the result: 1110 + 1 = 1111
    // Thus, binary representation of -1 is 1111 in 4 bits.
    // In general, in a typical 32-bit integer representation:
    // Binary representation of 1: 00000000 00000000 00000000 00000001
    // Binary representation of -1: 11111111 11111111 11111111 11111111

    // Note: The first bit (most significant bit) is the sign bit in two's complement representation.
    // If the sign bit is 1, the number is negative.
    // To get the absolute value of a negative number, you can perform two's complement again:
    // 1. Invert all bits.
    // 2. Add 1 to the result.

    // Example of binary operations on a negative value:
    int b = a & 0xF; // Perform bitwise AND operation with 0xF (0000 1111 in binary)
    // b = 1111 & 00001111 = 00001111 = 15 in decimal

    // If you need to interpret the result as a signed value, remember that bitwise operations
    // on negative values yield results in two's complement form.
    // To convert the result back to its absolute value, you can apply two's complement again.

    // For instance:
    int c = -15; // Binary representation of -15 in 4 bits is 10001 (two's complement)
    // In a typical 32-bit integer: 11111111 11111111 11111111 11110001

    // Performing bitwise NOT operation on -15:
    int d = ~c; // Binary representation of ~(-15) is 00000000 00000000 00000000 00001110 (invert all bits)
    // To interpret d as a signed value, it's positive and equals 14.

    // Note: The examples above assume a 4-bit representation for simplicity, but actual
    // representation in C++ will use 32 bits for an int.

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    return 0;
}
