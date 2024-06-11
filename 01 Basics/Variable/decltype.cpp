#include <iostream>

int main()
{
    // Initial variables
    int x = 42;
    double y = 3.14;
    char c = 'A';

    // Using decltype to declare new variables with the same type as existing variables
    decltype(x) a;     // 'a' has the same type as 'x', which is int
    decltype(y) b = y; // 'b' has the same type as 'y', which is double
    decltype(c) d;     // 'd' has the same type as 'c', which is char

    // Initialize 'a' and 'd'
    a = x * 2; // a = 42 * 2 = 84
    d = 'B';   // d is assigned the character 'B'

    // Output the values
    std::cout << "x (int): " << x << std::endl;
    std::cout << "a (same type as x, int): " << a << std::endl;
    std::cout << "y (double): " << y << std::endl;
    std::cout << "b (same type as y, double): " << b << std::endl;
    std::cout << "c (char): " << c << std::endl;
    std::cout << "d (same type as c, char): " << d << std::endl;

    return 0;
}
