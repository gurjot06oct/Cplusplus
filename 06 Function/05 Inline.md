### Inline Functions in C++

In C++, inline functions are a specialized feature that advises the compiler to substitute the function call directly with its body at the call site. This can potentially enhance performance by reducing the overhead associated with function calls, particularly for small and frequently used functions.

#### Inline Function Declaration

An inline function is declared using the `inline` keyword. This informs the compiler to inline the function's code wherever it is called, rather than executing a regular function call.

```cpp
inline int add(int a, int b)
{
    return a + b;
}
```

#### Example Usage

Let's explore how an inline function works in practice:

```cpp
#include <iostream>

int main()
{
    int x = 5, y = 10;
    int result = add(x, y);

    std::cout << "Result of add(x, y): " << result << std::endl;

    return 0;
}
```

#### Explanation

- **Inline Function Declaration**: Defines an inline function `add(int a, int b)` that computes the sum of two integers `a` and `b`.

- **Example Usage**: In the `main()` function, `add(x, y)` calculates the sum of `x` and `y`, and the result is printed to the console.

This example demonstrates how inline functions can be used to efficiently handle small functions directly within the caller's code, potentially improving performance by avoiding the overhead of function call mechanisms.
