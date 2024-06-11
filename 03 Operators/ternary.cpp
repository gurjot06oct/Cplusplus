#include <iostream>

// Function definitions
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main()
{
    // Basic ternary operator
    int a = 10;
    int b = 20;
    int x = 5;
    int y = 10;
    int maxBasic = (a > b) ? a : b;
    std::cout << "Basic Ternary: The maximum value is " << maxBasic << std::endl;

    // Nested ternary operator
    int c = 15;
    int maxNested = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    std::cout << "Nested Ternary: The maximum value is " << maxNested << std::endl;

    // Ternary operator with function calls
    bool shouldAdd = true;
    int resultFunc = shouldAdd ? add(x, y) : subtract(x, y);
    std::cout << "Ternary with Functions: The result is " << resultFunc << std::endl;

    // Combining ternary with other control structures
    std::cout << "Combining with Loops:" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " is " << (i % 2 == 0 ? "even" : "odd") << std::endl;
    }

    return 0;
}
