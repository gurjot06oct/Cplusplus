#include <iostream>

int main()
{
    int a = 10, b = 5, c = 2;

    // Initial values
    std::cout << "Initial values:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

    // += operator
    a += b; // a = a + b -> a = 10 + 5 = 15
    std::cout << "\na += b -> a = " << a << std::endl;

    // -= operator
    b -= c; // b = b - c -> b = 5 - 2 = 3
    std::cout << "b -= c -> b = " << b << std::endl;

    // *= operator
    c *= 3; // c = c * 3 -> c = 2 * 3 = 6
    std::cout << "c *= 3 -> c = " << c << std::endl;

    // /= operator
    a /= c; // a = a / c -> a = 15 / 6 = 2 (integer division)
    std::cout << "a /= c -> a = " << a << std::endl;

    // %= operator
    b %= 2; // b = b % 2 -> b = 3 % 2 = 1
    std::cout << "b %= 2 -> b = " << b << std::endl;

    // <<= operator
    a <<= 1; // a = a << 1 -> a = 2 << 1 = 4
    std::cout << "a <<= 1 -> a = " << a << std::endl;

    // >>= operator
    b >>= 1; // b = b >> 1 -> b = 1 >> 1 = 0
    std::cout << "b >>= 1 -> b = " << b << std::endl;

    // &= operator
    c &= 4; // c = c & 4 -> c = 6 & 4 = 4
    std::cout << "c &= 4 -> c = " << c << std::endl;

    // ^= operator
    a ^= 3; // a = a ^ 3 -> a = 4 ^ 3 = 7
    std::cout << "a ^= 3 -> a = " << a << std::endl;

    // |= operator
    b |= 2; // b = b | 2 -> b = 0 | 2 = 2
    std::cout << "b |= 2 -> b = " << b << std::endl;

    return 0;
}
