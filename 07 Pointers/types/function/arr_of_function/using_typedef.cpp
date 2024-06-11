#include <iostream>

typedef void (*FuncPtr)(int, int);

// `using` can also be used
// using FuncPtr = void (*)(int);

// Define some functions
void add(int a, int b)
{
    std::cout << "Addition: " << (a + b) << std::endl;
}

void subtract(int a, int b)
{
    std::cout << "Subtraction: " << (a - b) << std::endl;
}

void multiply(int a, int b)
{
    std::cout << "Multiplication: " << (a * b) << std::endl;
}

int main()
{
    // Declare an array of function pointers using typedef
    FuncPtr funcArray[3] = {add, subtract, multiply};

    // Call functions through the array
    int x = 10, y = 5;
    for (int i = 0; i < 3; ++i)
    {
        funcArray[i](x, y); // Call each function
    }

    return 0;
}
