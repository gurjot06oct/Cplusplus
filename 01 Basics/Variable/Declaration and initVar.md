## Declaration and Initialization

In C++, declaration and initialization are fundamental concepts with distinct purposes and implications.

### Declaration

- **Declaration** introduces the variable to the compiler, specifying its type and name.
- It does not assign any initial value, and memory allocation may not occur immediately.

```cpp
int declared_only; // Declares an integer variable 'declared_only' without initializing it
```

### Initialization

- **Initialization** assigns an initial value to the variable at the time of declaration.
- It ensures the variable has a defined value from the start, allocating memory and storing the initial value in that memory.

```cpp
// Declaration with Initialization
int value1 = 10; // Copy initialization
int value2(20);  // Direct initialization
int value3{30};  // List initialization
int zero_init{}; // Zero initialization
```

### Types of Initialization

1. **Copy Initialization**
   - Uses the assignment operator to initialize the variable.
   - Example: `int a = value1;`

```cpp
    // Copy Initialization
    int a = value1;
    std::cout << "Copy Initialization: a = " << a << std::endl;
```

2. **Direct Initialization**
   - Uses parentheses to directly initialize the variable.
   - Example: `int b(value2);`

```cpp
    // Direct Initialization
    int b(value2);
    std::cout << "Direct Initialization: b = " << b << std::endl;
```

3. **List Initialization (Uniform Initialization)**
   - Uses curly braces to initialize the variable.
   - This method prevents narrowing conversions and is considered safer.
   - Example: `int c{value3};`

```cpp
    // List Initialization
    int c{value3};
    std::cout << "List Initialization: c = " << c << std::endl;
```

---

### Complete Code

```cpp
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
    int declared_only; // Declares an integer variable 'declared_only' without initializing it

    // Declaration with Initialization
    int value1 = 10; // Variable for copy initialization
    int value2(20);  // Variable for direct initialization
    int value3{30};  // Variable for list initialization
    int zero_init{}; // Zero initialization

    // Copy Initialization
    int a = value1;
    std::cout << "Copy Initialization: a = " << a << std::endl;

    // Direct Initialization
    int b(value2);
    std::cout << "Direct Initialization: b = " << b << std::endl;

    // List Initialization
    int c{value3};
    std::cout << "List Initialization: c = " << c << std::endl;

    return 0;
}
```
