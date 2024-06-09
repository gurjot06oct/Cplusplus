#include <iostream>

// Inline function declaration
// Declaring a function as inline suggests to the compiler to substitute the function call with its body at the call site.
inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 5, y = 10;

    // Calling the inline function
    // When add() is called, the function's body will be substituted directly into the main function.
    int result = add(x, y);

    std::cout << "Result of add(x, y): " << result << std::endl;

    return 0;
}
