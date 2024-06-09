// Pass by Value:
// In pass by value, a copy of the variable is passed to the function. Any modifications made to the parameter inside the function do not affect the original variable.

#include <iostream>

// Swap function using pass by value
void swapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 5, b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    swapByValue(a, b);

    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}

// **Explanation**:
// - In `swapByValue`, `x` and `y` are local variables, and any changes made to them inside the function do not affect `a` and `b` in `main`.
// - After calling `swapByValue`, `a` and `b` remain unchanged in `main`.