## Overloading Input and Output Operators (`<<` and `>>`)

In C++, overloading the input (`>>`) and output (`<<`) operators for user-defined types typically requires the use of friend functions because these operators inherently require two operands: the stream object (`std::istream` for `>>` and `std::ostream` for `<<`) and the object being read from or written to the stream.

### Why Friend Functions are Required:

1. **Two-Operand Requirement**:

   - The `>>` and `<<` operators are binary operators by nature, meaning they operate on two operands. For example, `std::cin >> obj` involves `std::cin` as the left operand (the input stream) and `obj` as the right operand (the object being read into).
   - Similarly, `std::cout << obj` has `std::cout` as the left operand (the output stream) and `obj` as the right operand (the object being written out).

2. **Class Object on the Right:**

   - The standard convention in C++ is that the class object (e.g., `MyClass` object) should be on the right-hand side of the `>>` and `<<` operators.
   - Member function overloading inside the class (`MyClass`) for `<<` or `>>` would attempt to treat the object itself (`this`) as the left operand. However, this conflicts with the expected usage where the stream (`std::ostream` or `std::istream`) must be on the left side.

3. **Access to Private Members**:
   - Inside a class, the `>>` and `<<` operators typically need to access private members of the class they are overloaded for (e.g., accessing private `value` member of `MyClass` for output).
   - Making these operators friend functions allows them to access private members of the class, maintaining encapsulation while enabling streamlined input and output operations.

### Overloading Output Operator (`<<`)

The `operator<<` is declared as a friend outside the class `MyClass`, allowing it to access the private `value` member for output.

```cpp
#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Declare friend function for non-member overload
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
};

// Define friend function outside the class
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << obj.value;
    return os;
}
```

#### Using Overloaded `<<`

```cpp
std::cout << "Object contents: " << obj1 << std::endl;
```

1. **`std::cout << "Object contents: "`**

   - This part of the statement outputs the text "Object contents: " to `std::cout`.

2. **`<< obj1`**

   - The overloaded `<<` operator is used here to output the contents of `obj1` to `std::cout`.
   - Inside the overloaded `<<` operator for `MyClass`, `obj1.value` (the `value` member of `obj1`) is formatted and sent to `std::cout`.

### Overloading Input Operator (`>>`)

The `operator>>` is declared as a friend outside the class `MyClass`, allowing it to modify the private `value` member with input data.

```cpp
#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Declare friend function for non-member overload
    friend std::istream& operator>>(std::istream& is, MyClass& obj);
};

// Define friend function outside the class
std::istream& operator>>(std::istream& is, MyClass& obj) {
    is >> obj.value;
    return is;
}
```

#### Using Overloaded `>>`

```cpp
std::cout << "Enter a value for MyClass object: ";
std::cin >> obj1;
```

1. **`std::cout << "Enter a value for MyClass object: ";`**

   - This line uses `std::cout` to output the message "Enter a value for MyClass object: " to the standard output (typically the console).

2. **`std::cin >> obj1;`**
   - Here, `std::cin` is used along with the overloaded `>>` operator to read input from the standard input (typically the user typing on the console).
   - `obj1` is an instance of `MyClass`, and the overloaded `>>` operator is invoked to perform the input operation. This operator reads data from the input stream (`std::cin`) and assigns it to the `value` member of `obj1`.
