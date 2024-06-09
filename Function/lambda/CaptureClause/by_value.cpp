#include <iostream>
int main()
{
    int x = 10;
    auto lambda = [x]()
    {
        std::cout << "Captured value: " << x << std::endl;
    };
    x = 20;   // Changing x after capturing
    lambda(); // Output: Captured value: 10
    return 0;
}
