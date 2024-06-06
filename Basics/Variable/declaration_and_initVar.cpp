#include <iostream>

// ### Key Differences

// 1. **Declaration**:
//    - Introduces the variable to the compiler.
//    - Specifies the variable's type and name.
//    - Does not assign any initial value.
//    - Memory allocation may not occur immediately.

// 2. **Initialization**:
//    - Assigns an initial value to the variable at the time of declaration.
//    - Ensures the variable has a defined value from the start.
//    - Allocates memory and stores the initial value in that memory.

int main()
{
    // Declaration
    int declared_only; // Declares an integer variable 'a' without initializing it

    // Declaration with Initialization
    int value1 = 10; // Variable for copy initialization
    int value2(20);  // Variable for direct initialization
    int value3{30};  // Variable for list initialization
    int zero_init{}; // Zero Initialization

    // Copy Initialization:
    // Uses the assignment operator to initialize the variable.
    // Here, 'a' is initialized with the value of 'value1'.
    int a = value1;
    std::cout << "Copy Initialization: a = " << a << std::endl;

    // Direct Initialization:
    // Uses parentheses to directly initialize the variable.
    // Here, 'b' is initialized with the value of 'value2'.
    int b(value2);
    std::cout << "Direct Initialization: b = " << b << std::endl;

    // List Initialization (Uniform Initialization):
    // Uses curly braces to initialize the variable.
    // Here, 'c' is initialized with the value of 'value3'.
    // This method prevents narrowing conversions and is considered safer.
    int c{value3};
    std::cout << "List Initialization: c = " << c << std::endl;

    return 0;
}
