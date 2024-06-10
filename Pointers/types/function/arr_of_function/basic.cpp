#include <iostream>

// Define some functions that match the same signature
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
    // Step 1: Declare an array of function pointers
    void (*funcArray[3])(int, int);

    // Step 2: Initialize the array with function pointers
    funcArray[0] = add;
    funcArray[1] = subtract;
    funcArray[2] = multiply;

    // Step 3: Call functions through the array of function pointers
    int x = 10, y = 5;

    for (int i = 0; i < 3; ++i)
    {
        funcArray[i](x, y); // Call each function
    }

    return 0;
}
