#include <iostream>

int main()
{
    int a = 5;

    // Demonstrating postfix decrement (a--)
    std::cout << "Initial value of a: " << a << std::endl; // Output: 5
    int b = a--;                                           // b is assigned the value of a (5), then a is decremented to 4
    std::cout << "Value after postfix decrement (a--):" << std::endl;
    std::cout << "a: " << a << std::endl; // Output: 4
    std::cout << "b: " << b << std::endl; // Output: 5

    // Resetting a for the next demonstration
    a = 5;

    // Demonstrating prefix decrement (--a)
    std::cout << "\nReset value of a: " << a << std::endl; // Output: 5
    int c = --a;                                           // a is decremented to 4, then c is assigned the value of a (4)
    std::cout << "Value after prefix decrement (--a):" << std::endl;
    std::cout << "a: " << a << std::endl; // Output: 4
    std::cout << "c: " << c << std::endl; // Output: 4

    return 0;
}
