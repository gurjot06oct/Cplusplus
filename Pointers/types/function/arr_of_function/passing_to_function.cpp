#include <iostream>

typedef void (*FuncPtr)(int, int);

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

void callFunctions(FuncPtr funcs[], int size, int x, int y)
{
    for (int i = 0; i < size; ++i)
    {
        funcs[i](x, y); // Call each function
    }
}

int main()
{
    // Declare an array of function pointers using typedef
    FuncPtr funcArray[3] = {add, subtract, multiply};

    // Call functions through the array by passing it to another function
    callFunctions(funcArray, 3, 10, 5);

    return 0;
}
