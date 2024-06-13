### Different Parameter Passing Concepts in C++

#### Pass by Value

In pass by value, a copy of the variable is passed to the function. Any modifications made to the parameter inside the function do not affect the original variable.

```cpp
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
```

**Explanation**:

- In `swapByValue`, `x` and `y` are local variables initialized with copies of `a` and `b` respectively.
- Modifications to `x` and `y` inside `swapByValue` do not affect `a` and `b` in `main`.
- After calling `swapByValue`, `a` and `b` remain unchanged.

#### Pass by Reference

In pass by reference, a reference to the original variable is passed to the function. Modifications to the parameter inside the function directly affect the original variable.

```cpp
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
```

**Explanation**:

- In `swapByReference`, `x` and `y` are references to `a` and `b` respectively. Any modifications made to `x` and `y` inside the function directly modify `a` and `b` in `main`.
- After calling `swapByReference`, the values of `a` and `b` are swapped.

#### Pass by Pointer

In pass by pointer, the address of the variable is passed to the function. Modifications to the parameter inside the function affect the original variable through dereferencing.

```cpp
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
```

**Explanation**:

- In `swapByPointer`, `x` and `y` are pointers to `a` and `b` respectively. Dereferencing `x` and `y` allows us to modify the values of `a` and `b` in `main`.
- After calling `swapByPointer`, the values of `a` and `b` are swapped.
