#include <iostream>
int main()
{
    int x = 10;
    int y = 20;
    auto lambda_explicit = [x, &y]()
    {
        // Capture 'x' by value and 'y' by reference
        std::cout << "Captured x: " << x << std::endl;
        std::cout << "Captured y by reference: " << y << std::endl;
        // x++; // Error: Cannot modify 'x' captured by value
        y++; // Modifying 'y' captured by reference
    };
    lambda_explicit();                                      // Output: Captured x: 10, Captured y by reference: 20
    std::cout << "Modified value of y: " << y << std::endl; // Output: Modified value of y: 21

    x = 10;
    y = 20;
    auto lambda_implicit = [&]()
    {
        // Capture all variables by reference
        std::cout << "Captured x by reference: " << x << std::endl;
        std::cout << "Captured y by reference: " << y << std::endl;
        x++; // Modifying 'x' captured by reference
        y++; // Modifying 'y' captured by reference
    };
    lambda_implicit();                                                   // Output: Captured x by reference: 10, Captured y by reference: 20
    std::cout << "Modified values: x=" << x << ", y=" << y << std::endl; // Output: Modified values: x=11, y=21

    x = 10;
    y = 20;
    auto lambda_all = [=]()
    {
        // 'x' and 'y' are captured by value
        std::cout << "Captured x: " << x << std::endl;
        std::cout << "Captured y: " << y << std::endl;
        // x++; // Error: Cannot modify 'x' captured by value
        // y++; // Error: Cannot modify 'y' captured by value
    };
    lambda_all(); // Output: Captured x: 10, Captured y: 20
    return 0;
}
