// Pass by Pointer:
// In pass by pointer, the address of the variable is passed to the function. Modifications to the parameter inside the function affect the original variable through dereferencing.

#include <iostream>

// Swap function using pass by pointer
void swapByPointer(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 5, b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    swapByPointer(&a, &b);

    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}

// **Explanation**:
// - In `swapByPointer`, `x` and `y` are pointers to `a` and `b` respectively. Dereferencing `x` and `y` allows us to modify the values of `a` and `b` in `main`.
// - After calling `swapByPointer`, the values of `a` and `b` are swapped.