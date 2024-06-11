#include <iostream>

int main()
{
    int a = 5;

    // Demonstrating postfix increment (a++)
    std::cout << "Initial value of a: " << a << std::endl; // Output: 5
    int b = a++;                                           // b is assigned the value of a (5), then a is incremented to 6
    std::cout << "Value after postfix increment (a++):" << std::endl;
    std::cout << "a: " << a << std::endl; // Output: 6
    std::cout << "b: " << b << std::endl; // Output: 5

    // Resetting a for the next demonstration
    a = 5;

    // Demonstrating prefix increment (++a)
    std::cout << "\nReset value of a: " << a << std::endl; // Output: 5
    int c = ++a;                                           // a is incremented to 6, then c is assigned the value of a (6)
    std::cout << "Value after prefix increment (++a):" << std::endl;
    std::cout << "a: " << a << std::endl; // Output: 6
    std::cout << "c: " << c << std::endl; // Output: 6

    return 0;
}
