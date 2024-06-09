#include <iostream>
using namespace std;

int main()
{
    int a = 5; // 0101 in binary
    int b = 3; // 0011 in binary

    // Bitwise AND
    int result_and = a & b;
    cout << "Result of 5 & 3: " << result_and << endl; // Output: 1 (0001)

    // Bitwise OR
    int result_or = a | b;
    cout << "Result of bitwise OR: " << result_or << endl; // Output: 7 (0111)

    // Bitwise XOR
    int result_xor = a ^ b;
    cout << "Result of bitwise XOR: " << result_xor << endl; // Output: 6 (0110)

    return 0;
}
