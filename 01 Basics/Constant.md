## Using Constants in C++

This code demonstrates how to define and use constants in C++ using the `const` keyword. Constants are variables whose values cannot be changed after initialization.

### Defining Constants

```cpp
#include <iostream>

// Define constants using 'const' keyword
const int MAX_STUDENTS = 50;
const float PI = 3.14159;
const std::string GREETING = "Hello, world!";
```

Constants are defined using the `const` keyword. They are initialized with a value that cannot be modified later in the program.

### Main Function and Usage of Constants

```cpp
int main()
{
    // Using constants
    int students[MAX_STUDENTS];         // Array with a constant size
    float circleArea = PI * 5 * 5;      // Calculating circle area using PI
    std::cout << GREETING << std::endl; // Outputting a greeting message
```

In the `main` function, constants are used in various contexts:

- `MAX_STUDENTS` is used to define the size of an array.
- `PI` is used to calculate the area of a circle.
- `GREETING` is used to output a greeting message to the console.

### Attempt to Modify a Constant

```cpp
    // Attempting to modify a constant (will result in a compilation error)
    // MAX_STUDENTS = 60;

    return 0;
}
```

Attempting to modify a constant will result in a compilation error. The line `// MAX_STUDENTS = 60;` is commented out to indicate that such an operation is invalid.
