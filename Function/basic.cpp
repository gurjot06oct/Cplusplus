#include <iostream>

// Functions in C++ are a fundamental aspect of the language, providing a way to encapsulate code into reusable blocks. Here is a detailed explanation of the basics of functions in C++, including parameters, return types, and other important aspects.

// Function Declaration (Prototyping)
// Before a function is used, it can be declared (prototyped) to inform the compiler about its existence and signature.
int add(int, int); // function prototype

// Function definition: Adds two integers and returns the result
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Calling the add function
    int result = add(3, 4);
    std::cout << "Result of add(3, 4): " << result << std::endl; // Outputs: Result: 7

    return 0;
}
