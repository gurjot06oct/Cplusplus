#include <iostream>
int main()
{
    int x = 10;
    auto lambda = [&x]()
    {
        std::cout << "Captured value by reference: " << x << std::endl;
        x = 30; // Modifying x
    };
    lambda();                                               // Output: Captured value by reference: 10
    std::cout << "Modified value of x: " << x << std::endl; // Output: Modified value of x: 30
    return 0;
}
