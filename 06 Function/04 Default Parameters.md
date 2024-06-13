## Default Parameters in C++

In C++, default parameters provide a convenient way to define a default value for a function parameter. This allows the caller to omit certain arguments, leading to more flexible and readable code.

### Default Parameters with Complex Types

Using complex types (such as arrays, structures, and classes) as default parameter values is possible but requires caution. This approach can lead to unexpected behavior due to object slicing. Object slicing occurs when an object of a derived class is assigned to an object of a base class, potentially losing some data specific to the derived class.

### Default Parameters and Function Pointers

While default parameters cannot directly use function pointers, you can achieve similar functionality using function overloading or default arguments with lambda functions in C++11 and later. This provides more flexibility and avoids the limitations associated with function pointers.

### Basic Example of Default Parameters

The following example demonstrates a simple usage of default parameters in C++:

```cpp
#include <iostream>
using namespace std;

void printMessage(string message = "Hello, World!") {
    cout << message << endl;
}

int main() {
    printMessage();               // Outputs: Hello, World!
    printMessage("Goodbye!");     // Outputs: Goodbye!
    return 0;
}
```

In this example, the `printMessage` function has a default parameter value of `"Hello, World!"`. When called without any arguments, it prints the default message. If a specific argument is provided, such as `"Goodbye!"`, it prints the provided message instead.

### Rules for Default Parameters

When using default parameters, certain rules must be followed to ensure the correct functioning of the code:

- All parameters with default values must be at the end of the parameter list.
- You cannot skip default parameters in the middle of the parameter list without assigning a default value to subsequent parameters.

Consider the following examples:

```cpp
// Invalid: Default argument missing for parameter 'c'
void example(int a, int b = 5, int c) {}

// Valid: All parameters with default values are at the end
void example(int a, int b = 5, int c = 10) {}

// Invalid: Default argument missing for parameters 'b' and 'c'
void example(int a = 0, int b, int c) {}
```

### Replacing Default Parameters with Function Overloading

Function overloading can be used as an alternative to default parameters. This technique allows you to define multiple versions of a function with different numbers of parameters, providing similar functionality without using default parameters.

Here is an example demonstrating function overloading to replace default parameters:

```cpp
#include <iostream>
using namespace std;

// Overloaded function without parameters
void printMessage() {
    cout << "Hello, World!" << endl;
}

// Overloaded function with one parameter
void printMessage(string message) {
    cout << message << endl;
}

int main() {
    printMessage();               // Outputs: Hello, World!
    printMessage("Goodbye!");     // Outputs: Goodbye!
    return 0;
}
```

In this example, two versions of the `printMessage` function are defined: one without any parameters and one with a single string parameter. This approach achieves the same effect as using default parameters but through function overloading.
