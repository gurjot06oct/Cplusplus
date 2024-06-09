// Pass by Reference:
// In pass by reference, a reference to the original variable is passed to the function. Modifications to the parameter inside the function affect the original variable.

#include <iostream>

// Swap function using pass by reference
void swapByReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 5, b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    swapByReference(a, b);

    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}

// **Explanation **:
// - In `swapByReference`, `x` and `y` are references to `a` and `b` respectively. Any changes made to `x` and `y` inside the function directly affect `a` and `b` in `main`.
// - After calling `swapByReference`, the values of `a` and `b` are swapped.