### Functions in C++

Functions in C++ allow you to encapsulate code into reusable blocks. They are essential for modular programming, promoting code organization and reusability. Here’s a detailed explanation of the basics of functions in C++, including parameters, return types, and function declaration.

#### Function Declaration and Definition

Functions in C++ are typically declared and defined in two separate steps. The declaration (or prototype) informs the compiler about the function's existence, while the definition provides the implementation.

```cpp
#include <iostream>
using namespace std;

// Function Declaration (Prototyping)
int add(int, int); // Function prototype

// Function Definition: Adds two integers and returns the result
int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Calling the add function
    int result = add(3, 4);
    cout << "Result of add(3, 4): " << result << endl; // Outputs: Result: 7

    return 0;
}
```

#### Explanation

- **Function Declaration**: Before a function is used, it can be declared using a function prototype. This informs the compiler about the function’s name, return type, and parameter types. It typically ends with a semicolon.

- **Function Definition**: Defines the actual implementation of the function. It includes the function header (return type, function name, and parameters in parentheses) and the function body enclosed in curly braces `{}`.

#### Calling a Function

In the `main` function, functions are called using their names followed by arguments enclosed in parentheses. Here, `add(3, 4)` calls the `add` function with arguments `3` and `4`, and stores the returned result in the variable `result`.

Functions are integral to structured programming in C++, allowing code to be organized into manageable units. They enhance code readability, reusability, and maintainability by separating concerns and promoting modular design.
