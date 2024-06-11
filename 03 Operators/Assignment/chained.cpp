#include <iostream>

int main()
{
    int a = 10, b = 5, c = 2;

    // Initial values
    std::cout << "Initial values:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

    // Chained assignment
    int x, y, z;
    x = y = z = 10;
    std::cout << "\nx = y = z = 10 -> x = " << x << ", y = " << y << ", z = " << z << std::endl;

    // Mixed chained assignment example
    x -= y += z;
    // y += z; // y = y + z -> y = 10 + 10 = 20
    // x -= y; // x = x - y -> x = 10 - 20 = -10
    std::cout << "\nx -= y += z -> x = " << x << ", y = " << y << ", z = " << z << std::endl;

    a += b *= c;
    // b = b * c -> b = 5 * 2 = 10;
    // a = a + b -> a = 10 + 10 = 20
    std::cout << "\na += b *= c -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    b /= c -= 1;
    // c = c - 1 -> c = 2 - 1 = 1;
    // b = b / c -> b = 10 / 1 = 10
    std::cout << "\nb /= c -= 1 -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    a %= b |= 1;
    // b = b | 1 -> b = 10 | 1 = 11;
    // a = a % b -> a = 20 % 11 = 9
    std::cout << "\na %= b |= 1 -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    return 0;
}
