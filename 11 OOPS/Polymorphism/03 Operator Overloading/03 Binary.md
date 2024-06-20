## Binary Arithmetic Operators

Overloading binary arithmetic operators in C++ allows you to define custom behaviors for operators when they are applied to objects of your own classes. Binary arithmetic operators are operators that operate on two operands. Here's an explanation of how you can overload each of these binary arithmetic operators using member functions and non-member (friend) functions:

### 1. Addition (`+`)

- **Member Function Overloading**: Addition (`+`) operator can be overloaded as a member function of your class. It typically takes another object of the same type as a parameter and returns a new object representing the sum.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Member function for addition (+)
    MyClass operator+(const MyClass& rhs) const {
        return MyClass(value + rhs.value);
    }
};
```

- **Non-Member Function Overloading**: Addition operator can also be overloaded as a non-member function. It takes two objects of your class type as parameters and returns a new object representing the sum.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for addition (+)
    friend MyClass operator+(const MyClass& lhs, const MyClass& rhs) {
        return MyClass(lhs.value + rhs.value);
    }
};
```

### 2. Subtraction (`-`)

- **Member Function Overloading**: Subtraction (`-`) operator can be overloaded as a member function of your class. It typically takes another object of the same type as a parameter and returns a new object representing the difference.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Member function for subtraction (-)
    MyClass operator-(const MyClass& rhs) const {
        return MyClass(value - rhs.value);
    }
};
```

- **Non-Member Function Overloading**: Subtraction operator can also be overloaded as a non-member function. It takes two objects of your class type as parameters and returns a new object representing the difference.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for subtraction (-)
    friend MyClass operator-(const MyClass& lhs, const MyClass& rhs) {
        return MyClass(lhs.value - rhs.value);
    }
};
```

### 3. Multiplication (`*`)

- **Member Function Overloading**: Multiplication (`*`) operator can be overloaded as a member function of your class. It typically takes another object of the same type as a parameter and returns a new object representing the product.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Member function for multiplication (*)
    MyClass operator*(const MyClass& rhs) const {
        return MyClass(value * rhs.value);
    }
};
```

- **Non-Member Function Overloading**: Multiplication operator can also be overloaded as a non-member function. It takes two objects of your class type as parameters and returns a new object representing the product.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for multiplication (*)
    friend MyClass operator*(const MyClass& lhs, const MyClass& rhs) {
        return MyClass(lhs.value * rhs.value);
    }
};
```

### 4. Division (`/`)

- **Member Function Overloading**: Division (`/`) operator can be overloaded as a member function of your class. It typically takes another object of the same type as a parameter and returns a new object representing the division result.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Member function for division (/)
    MyClass operator/(const MyClass& rhs) const {
        if (rhs.value != 0) {
            return MyClass(value / rhs.value);
        } else {
            // Handle division by zero error
            // For simplicity, returning a default object here
            return MyClass();
        }
    }
};
```

- **Non-Member Function Overloading**: Division operator can also be overloaded as a non-member function. It takes two objects of your class type as parameters and returns a new object representing the division result.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for division (/)
    friend MyClass operator/(const MyClass& lhs, const MyClass& rhs) {
        if (rhs.value != 0) {
            return MyClass(lhs.value / rhs.value);
        } else {
            // Handle division by zero error
            // For simplicity, returning a default object here
            return MyClass();
        }
    }
};
```

### 5. Modulus (`%`)

- **Member Function Overloading**: Modulus (`%`) operator can be overloaded as a member function of your class. It typically takes another object of the same type as a parameter and returns a new object representing the remainder of the division.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Member function for modulus (%)
    MyClass operator%(const MyClass& rhs) const {
        if (rhs.value != 0) {
            return MyClass(value % rhs.value);
        } else {
            // Handle modulus by zero error
            // For simplicity, returning a default object here
            return MyClass();
        }
    }
};
```

- **Non-Member Function Overloading**: Modulus operator can also be overloaded as a non-member function. It takes two objects of your class type as parameters and returns a new object representing the remainder of the division.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for modulus (%)
    friend MyClass operator%(const MyClass& lhs, const MyClass& rhs) {
        if (rhs.value != 0) {
            return MyClass(lhs.value % rhs.value);
        } else {
            // Handle modulus by zero error
            // For simplicity, returning a default object here
            return MyClass();
        }
    }
};
```

### Usage

```cpp
 // Addition (+)
 MyClass i1(10);
 MyClass i2(20);
 MyClass i3;
 i3 = i1 + i2;
 i3.print(); // Output: Result of addition of i1 and i2

 // Subtraction (-)
 MyClass i4(30);
 MyClass i5(15);
 MyClass i6;
 i6 = i4 - i5;
 i6.print(); // Output: Result of subtraction of i4 and i5

 // Multiplication (*)
 MyClass i7(5);
 MyClass i8(6);
 MyClass i9;
 i9 = i7 * i8;
 i9.print(); // Output: Result of multiplication of i7 and i8

 // Division (/)
 MyClass i10(50);
 MyClass i11(10);
 MyClass i12;
 i12 = i10 / i11;
 i12.print(); // Output: Result of division of i10 by i11

 // Modulus (%)
 MyClass i13(17);
 MyClass i14(5);
 MyClass i15;
 i15 = i13 % i14;
 i15.print(); // Output: Result of modulus of i13 by i14
```
