#include <iostream>
using namespace std;

int main()
{
    int a = 5;                  // a = 5, which is 0101 in binary
    int result_lshift = a << 3; // Left shift 'a' by 3 positions: 0101 << 3 becomes 0101000
    // Left shifting a number by n positions is equivalent to multiplying it by 2^n.
    // 5 << 3 means 5 * (2^3) = 5 * 8 = 40
    // Binary: 0101 becomes 0101000 (which is 40 in decimal)
    cout << "Result of 5<<3: " << result_lshift << endl; // Output: 40 (binary: 101000)

    a = -15; // a = -15, which is represented as two's complement in 32-bit binary: 11111111 11111111 11111111 11110001
    // Note: The representation starts with 1s because it's a negative number.
    result_lshift = a << 3; // Left shift '-15' by 3 positions: 11111111 11111111 11111111 11110001 << 3
    // Shifting left by 3 positions, we get: 11111111 11111111 11111111 10001000 (remaining bits are filled with 0)
    // This is the binary representation of -120 in 32-bit two's complement.
    // In decimal, this is equivalent to -15 * (2^3) = -15 * 8 = -120
    cout << "Result of -15<<3: " << result_lshift << endl; // Output: -120 (binary: 10001000 in 32-bit two's complement)

    return 0;
}
