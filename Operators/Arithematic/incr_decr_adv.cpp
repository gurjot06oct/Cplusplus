#include <iostream>

int main()
{
    int a = 5, b = 6, c = 3;
    std::cout << "Initial value of a: " << a << std::endl; // Output: 5
    std::cout << "Initial value of b: " << b << std::endl; // Output: 6
    std::cout << "Initial value of c: " << c << std::endl; // Output: 3

    // Demonstrating postfix + prefix increment (++a++)
    // int b = ++a++;  // This syntax is invalid and will generate a syntax error

    // Using the comma operator
    int d = (a++, b--, c++);

    std::cout << "Value of a after comma expression: " << a << std::endl; // Output: 6
    std::cout << "Value of b after comma expression: " << b << std::endl; // Output: 5
    std::cout << "Value of c after comma expression: " << c << std::endl; // Output: 4
    std::cout << "Value of d: " << d << std::endl;                        // Output: 3

    return 0;
}
