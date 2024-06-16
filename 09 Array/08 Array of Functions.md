## Arrays of Functions in C++

In C++, arrays of functions are a powerful feature that allows you to create a collection of functions, enabling dynamic function calls. This is particularly useful for implementing callbacks, event handlers, and state machines.

### Defining Functions with a Common Signature

To work with arrays of function pointers, first, define functions that share the same signature. Here are three simple functions for basic arithmetic operations:

```cpp
#include <iostream>

void add(int a, int b) {
    std::cout << "Addition: " << (a + b) << std::endl;
}

void subtract(int a, int b) {
    std::cout << "Subtraction: " << (a - b) << std::endl;
}

void multiply(int a, int b) {
    std::cout << "Multiplication: " << (a * b) << std::endl;
}
```

Each of these functions takes two integers as parameters and returns `void`.

### Declaring and Initializing an Array of Function Pointers

To declare an array of function pointers, use the following syntax:

```cpp
void (*funcArray[3])(int, int);
```

This declares `funcArray` as an array of three pointers to functions that take two integers and return `void`.

Initialize the array with the addresses of the functions:

```cpp
funcArray[0] = add;
funcArray[1] = subtract;
funcArray[2] = multiply;
```

### Calling Functions Through the Array

You can call each function through the array of function pointers using a loop:

```cpp
int x = 10, y = 5;

for (int i = 0; i < 3; ++i) {
    funcArray[i](x, y); // Call each function
}
```

This loop iterates through the array and calls each function, passing `x` and `y` as arguments.

### Using `typedef` for Simplicity

To make the code more readable, you can use `typedef` or `using` to define a function pointer type:

```cpp
typedef void (*FuncPtr)(int, int);
// or
using FuncPtr = void (*)(int, int);
```

Now, you can declare and initialize the array more succinctly:

```cpp
FuncPtr funcArray[3] = {add, subtract, multiply};
```

### Passing an Array of Function Pointers to Another Function

You can pass the array of function pointers to another function to perform operations dynamically:

```cpp
void callFunctions(FuncPtr funcs[], int size, int x, int y) {
    for (int i = 0; i < size; ++i) {
        funcs[i](x, y); // Call each function
    }
}

// Call functions through the array by passing it to another function
callFunctions(funcArray, 3, 10, 5);
```

This function iterates through the array of function pointers and calls each function with the given arguments.
