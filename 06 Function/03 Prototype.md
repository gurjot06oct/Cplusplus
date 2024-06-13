## Function Prototyping in C++

In C++, function prototyping is a critical concept that allows you to declare functions before defining them, ensuring the compiler understands their signature and can correctly process calls to these functions throughout the code.

#### Function Prototyping Basics

Function prototyping involves declaring a function's signature—its return type, name, and parameters—before providing its actual implementation. This informs the compiler about the function's existence and how it should handle calls to the function before it's fully defined.

### Function Declaration (Prototyping)

```cpp
bool even(int);
```

- This line declares a function named `even` that returns a `bool` (boolean) value and takes an `int` parameter `n`.
- The function is declared here to inform the compiler about its existence and signature before it is defined later in the code.

### Function definition: Checks if a number is odd

```cpp
bool odd(int n)
{
    // Base case: If n is 0, it is not odd
    if (n == 0)
        return false;
    else
        // Recursively calls 'even' function with n - 1
        return even(n - 1);
}
```

- This block defines a function named `odd` that checks if a given integer `n` is odd.
- If `n` equals `0`, it returns `false`, indicating that `0` is not an odd number.
- Otherwise, it recursively calls the `even` function with `n - 1`, checking the previous number's parity.

### Function definition: Checks if a number is even

```cpp
bool even(int n)
{
    // Base case: If n is 0, it is even
    if (n == 0)
        return true;
    else
        // Recursively calls 'odd' function with n - 1
        return odd(n - 1);
}
```

- This segment defines the `even` function, which determines if a given integer `n` is even.
- When `n` equals `0`, it returns `true`, indicating that `0` is an even number.
- Otherwise, it recursively calls the `odd` function with `n - 1`, continuing to check the previous number's parity.
