## Operator Overloading in C++

Operator overloading in C++ is a form of compile-time polymorphism that allows you to redefine the meaning of operators for user-defined types without changing their original meaning for built-in types.

### What is Operator Overloading?

C++ allows you to provide custom implementations for operators for user-defined types (classes or structs). This process is known as operator overloading. For example, you can overload the `+` operator to concatenate two `String` objects or to add two `Complex` numbers.

#### Example:

```cpp
int a;
float b, sum;
sum = a + b;
```

Here, variables `a` and `b` are of types `int` and `float`, which are built-in data types. The addition operator `+` is predefined to add these built-in types.

### Why Use Operator Overloading?

Consider a class `Complex`:

```cpp
class Complex {
    int real, imag;
    // ...
};

int main() {
    Complex a1, a2, a3;
    a3 = a1 + a2; // Error: `+` not defined for `Complex`
    return 0;
}
```

Without operator overloading, attempting to use `+` on `Complex` objects results in an error because the `+` operator is not defined for user-defined types. To add two `Complex` objects, you need to overload the `+` operator.

#### Example of Operator Overloading:

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& obj) const {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void print() const { cout << real << " + i" << imag << '\n'; }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;
    c3.print(); // Output: 12 + i9
}
```

### Difference Between Operator Functions and Normal Functions

Operator functions are similar to normal functions but have a special syntax. The name of an operator function is always the keyword `operator` followed by the symbol of the operator being overloaded.

### Operators that Can be Overloaded

1. **Unary Operators**:

   - `+` (unary plus)
   - `-` (unary minus)
   - `++` (prefix and postfix increment)
   - `--` (prefix and postfix decrement)
   - `*` (dereference)
   - `&` (address of)
   - `!` (logical NOT)
   - `~` (bitwise NOT)

2. **Binary Arithmetic Operators**:

   - `+` (addition)
   - `-` (subtraction)
   - `*` (multiplication)
   - `/` (division)
   - `%` (modulus)

3. **Assignment Operators**:

   - `=`
   - `+=`, `-=`, `*=`, `/=`, `%=`
   - `&=`, `|=`, `^=`
   - `<<=`, `>>=`

4. **Comparison Operators**:

   - `==` (equality)
   - `!=` (inequality)
   - `<` (less than)
   - `<=` (less than or equal to)
   - `>` (greater than)
   - `>=` (greater than or equal to)

5. **Logical Operators**:

   - `&&` (logical AND)
   - `||` (logical OR)

6. **Bitwise Operators**:

   - `&` (bitwise AND)
   - `|` (bitwise OR)
   - `^` (bitwise XOR)
   - `<<` (left shift)
   - `>>` (right shift)

7. **Function Call Operator** (`()`)

8. **Subscript Operator** (`[]`)

9. **Comma Operator** (`,`)
10. **Other Operators**:
    - Type Conversion Conversion Operator (`operator typename()`)
    - De-referencing (`->`)
    - Dynamic memory allocation (`new`, `delete`)
    - Input/Output Operator (`>>`,`<<`)

### Criteria/Rules for Defining Operators and the Order of Operands

1. **Non-static Member Functions:**
   - **Member Function Overloading**: Provides a natural syntax where the object itself is the operand.
   - **Binary Operators:** Defined with only one argument. These operators are used when the expression has the class as the first operand, followed by the operation and the argument, which can be of any type, including the class itself.
   - **Unary Operators:** Defined with no arguments.
   - These operators are defined within the class and typically have the class instance as the left operand in binary operations. Binary operators take one additional argument, while unary operators do not take any arguments.
2. **Friend Functions:**
   - **Non-Member Function Overloading**: Useful when the operator does not need direct access to private members or when you want to define a symmetric operation between different types.
   - **Binary Operators:** Defined with two arguments. These operators are used when the expression can involve operands of any type, with the class as one of them, in the format `class classname` operation `args` or `args` operation `class classname`.
   - **Unary Operators:** Defined with one argument.
   - These operators are declared as friends of the class and are not members of the class. Binary operators take two arguments, allowing more flexibility in operand types.Class instance can be the left operand or the right operand. Unary operators take one argument.
3. **Operators not Overloadable as Friend Functions:**
   - `()`, `[]`, `->`
   - Assignment Operators:
     - `=`
     - `+=`, `-=`, `*=`, `/=`, `%=`
     - `&=`, `|=`, `^=`
     - `<<=`, `>>=`

## Advantages of Non-Member Function Overloading in C++ Operator Definitions

Overloading operators with non-member functions (often declared as friend functions) in C++ offers several advantages and use cases that complement or extend the capabilities of member function overloading. Here are the main reasons and benefits for using non-member function overloading:

### 1. Symmetry and Consistency

Non-member function overloading allows you to define binary operators that involve different types on either side of the operator. This symmetry makes your code more intuitive and consistent, especially when dealing with arithmetic operations or comparisons between different types.

For example, consider adding a custom `MyClass` type with an `int`:

- ### Addition of `int` and `MyClass` Objects

  **Class Definition (`MyClass`)**

  A class `MyClass` encapsulates a single integer value and provides operations on it:

  ```cpp
  class MyClass {
  private:
     int value;

  public:
     MyClass(int v = 0) : value(v) {}

     // Member function for addition with another MyClass object
     MyClass operator+(const MyClass& rhs) const {
        return MyClass(value + rhs.value);
     }
  };
  ```

  **Operator Overloading: Addition of `int` and `MyClass`**

  Operator overloading in C++ allows custom behaviors for operators like `+`. Here, we overload `+` to handle addition of an `int` and a `MyClass` object:

  ```cpp
  // Non-member function declaration for addition of int and MyClass
  MyClass operator+(int lhs, const MyClass& rhs);

  // Definition of non-member function for addition of int and MyClass
  MyClass operator+(int lhs, const MyClass& rhs) {
     return MyClass(lhs + rhs.getValue());
  }
  ```

  **Usage Example**

  In a program, you can use both member and non-member overloads to add an `int` and a `MyClass` object:

  ```cpp
  int main() {
     MyClass obj(5);
     int intValue = 10;

     // Adding int and MyClass using member function
     MyClass result1 = obj + intValue;

     // Adding int and MyClass using non-member function
     MyClass result2 = intValue + obj;

     return 0;
  }
  ```

  #### Explanation

  - **Scalar (`int`)**: Represents a single integer value.
  - **Class Definition (`MyClass`)**: Defines a class encapsulating an integer value and overloads the `+` operator as a member function to add two `MyClass` objects.
  - **Non-Member Function Overloading**: Extends operator overloading to handle addition where an `int` is on the left-hand side and a `MyClass` object is on the right-hand side.
  - **Usage Example**: Demonstrates how both member and non-member function overloads are used to add an `int` and a `MyClass` object, showcasing the flexibility and symmetry achieved through operator overloading in C++.

### 2. Access to Private Members

Friend functions, which are typically used for non-member overloads, have access to the private and protected members of a class. This can be advantageous when implementing operators that need to manipulate or access private data members of your class.

### 3. Avoiding Implicit Conversions

Non-member overloads can prevent unintended implicit conversions by controlling the order of operand types explicitly. This can be particularly useful to enforce type safety and prevent ambiguous or unintended behavior in complex class hierarchies.

### 4. Encapsulation and Modularity

By defining non-member function overloads outside the class definition, you can keep your class interface clean and focused on its core functionality. This separation of concerns improves code readability, modularity, and maintainability.

### Constraints and Limitations

1. **New Operators**: You cannot define new operators or change the precedence and associativity of operators.

2. **Conditional Operator (`?:`)**:

3. **sizeof Operator (`sizeof`)**:

4. **Scope Resolution Operator (`::`)**:
5. **Dot Operator (`.`)**:

### Important Points:

1. **At least one operand must be a user-defined type**.
2. **Assignment Operator**: The compiler provides a default assignment operator for each class.
