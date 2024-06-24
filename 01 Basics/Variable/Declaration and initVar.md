## Declaration and Initialization

In C++, declaration and initialization are fundamental concepts with distinct purposes and implications.

### Declaration

- **Declaration** introduces the variable to the compiler, specifying its type and name.
- It's initial value is garbage value, and memory allocation may not occur immediately.

```cpp
typename declared_only; // Declares an `typename` variable 'declared_only' without initializing it
```

### Initialization

- **Initialization** assigns an initial value to the variable at the time of declaration.
- It ensures the variable has a defined value from the start, allocating memory and storing the initial value in that memory.

```cpp
// Declaration with Initialization
typename value1 = 10; // Copy initialization
typename value2(20);  // Direct initialization
typename value3{30};  // List initialization
typename zero_init{}; // Zero initialization
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

4. **Zero Initialization**
   - Uses empty curly braces to initialize the variable to zero.
   - Example: `int d{};`

```cpp
    // Zero Initialization
    int d{};
    std::cout << "Zero Initialization: d = " << d << std::endl;
```

---

### Complete Code

```cpp
#include <iostream>
struct my_struct
{
    int i;
    char c;
};

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

    // Zero Initialization

    int d{};
    // zero-initialized to 0

    static float f1;
    // zero-initialized to 0.000000000

    double d{};
    // zero-initialized to 0.00000000000000000

    int *ptr{};
    // initialized to nullptr

    char s_array[3]{'a', 'b'};     // the third char is initialized to '\0'
    int int_array[5] = {8, 9, 10}; // the fourth and fifth ints are initialized to 0

    my_struct a_struct{};
    // i = 0, c = '\0'
    std::cout << "Zero Initialization: d = " << d << std::endl;

    return 0;
}
```
