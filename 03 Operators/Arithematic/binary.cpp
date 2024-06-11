#include <iostream>

int main()
{
    // Addition
    int a = 3, b = 6, d = -13, e = 7;
    int c = a + b; // c = 9
    std::cout << "Addition: " << c << std::endl;

    // Subtraction
    a = 9;
    b = 6;
    c = a - b; // c = 3
    std::cout << "Subtraction: " << c << std::endl;

    // Multiplication
    a = 3;
    b = 6;
    c = a * b; // c = 18
    std::cout << "Multiplication: " << c << std::endl;

    // Division
    a = 12;
    b = 6;
    c = a / b; // c = 2
    std::cout << "Division: " << c << std::endl;

    // Modulo Operation
    a = 8;
    b = 6;
    c = a % b; // c = 2
    std::cout << "Modulo Operation(positive number x%n ): " << c << std::endl;
    int f = d % e; // f = -6
    std::cout << "Modulo Operation(negative number x%n = -(-x)%n ): " << f << std::endl;

    return 0;
}
