#include <iostream>
using namespace std;

int main()
{
    int a = 40;                 // a = 40, which is 101000 in binary
    int result_rshift = a >> 3; // Right shift 'a' by 3 positions: 101000 >> 3 becomes 000101
    // Right shifting a number by n positions is equivalent to dividing it by 2^n.
    // 40 >> 3 means 40 / (2^3) = 40 / 8 = 5
    // Binary: 101000 becomes 000101 (which is 5 in decimal)
    cout << "Result of 40>>3: " << result_rshift << endl; // Output: 5 (binary: 000101)

    a = -120; // a = -120, which is represented as two's complement in 32-bit binary: 11111111 11111111 11111111 10001000
    // Note: The representation starts with 1s because it's a negative number.
    result_rshift = a >> 3; // Right shift '-120' by 3 positions: 11111111 11111111 11111111 10001000 >> 3
    // Arithmetic right shifting keeps the sign bit (most significant bit) the same.
    // Shifting right by 3 positions, we get: 11111111 11111111 11111111 11110001
    // This is the binary representation of -15 in 32-bit two's complement.
    // In decimal, this is equivalent to -120 / (2^3) = -120 / 8 = -15
    cout << "Result of -120>>3: " << result_rshift << endl; // Output: -15 (binary: 11111111 11111111 11111111 11110001)

    return 0;
}
