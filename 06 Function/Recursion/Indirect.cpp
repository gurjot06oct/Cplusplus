// Indirect Recursion:
// Indirect recursion occurs when one function calls another function, which in turn calls the first function, creating a loop of function calls.

#include <iostream>
void function1(int n)
{
    if (n > 0)
    {
        std::cout << n << " ";
        function2(n - 1);
    }
}

void function2(int n)
{
    if (n > 1)
    {
        std::cout << n << " ";
        function1(n / 2);
    }
}