## Unary Operator Overloading

Overloading unary operators in C++ allows you to define custom behaviors for operators when they are applied to objects of your own classes. Unary operators are operators that operate on a single operand. Here's an explanation of how you can overload each of these unary operators using member functions and non-member (friend) functions:

### 1. Unary Plus (`+`)

- **Member Function Overloading**: Unary plus (`+`) can be overloaded as a member function of your class. It typically doesn't change the object's value and returns a copy of the object.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Member function for unary plus (+)
    MyClass operator+() const {
        return MyClass(+value); // Usually returns a copy of the object
    }
};
```

- **Non-Member Function Overloading**: It's less common to overload unary plus as a non-member function since it typically doesn't require access to private members. However, it can be done similarly.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for unary plus (+)
    friend MyClass operator+(const MyClass& obj) {
        return MyClass(+obj.value); // Returns a copy of the object
    }
};
```

```cpp
 // Unary Plus (+)
 MyClass i1(10);
 MyClass i2;
 i2 = +i1;
 i2.print(); // Output: 10
```

### 2. Unary Minus (`-`)

- **Member Function Overloading**: Unary minus (`-`) changes the sign of the object's value and returns a copy of the object.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Member function for unary minus (-)
    MyClass operator-() const {
        return MyClass(-value); // Returns a copy of the object with negated value
    }
};
```

- **Non-Member Function Overloading**: Similar to member function overloading, but defined as a friend function if access to private members is needed.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for unary minus (-)
    friend MyClass operator-(const MyClass& obj) {
        return MyClass(-obj.value); // Returns a copy of the object with negated value
    }
};
```

```cpp
 // Unary Minus (-)
 MyClass i3(15);
 MyClass i4;
 i4 = -i3;
 i4.print(); // Output: -15
```

### 3. Prefix and Postfix Increment (`++`)

- **Member Function Overloading**: Both prefix (`++obj`) and postfix (`obj++`) increment operators can be overloaded as member functions. Prefix returns a reference to the modified object, while postfix returns a copy of the original object's value before incrementing.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Prefix increment operator (++obj)
    MyClass& operator++() {
        ++value;
        return *this; // Returns reference to the modified object
    }

    // Postfix increment operator (obj++)
    MyClass operator++(int) {
        MyClass temp(*this); // Create a copy of current object
        ++value; // Increment the object itself
        return temp; // Return the copy (original value)
    }
};
```

```cpp
 // Prefix Increment (++)
 MyClass i5(20);
 ++i5;
 i5.print(); // Output: 21

 // Postfix Increment (i5++)
 MyClass i6 = i5++;
 i6.print(); // Output: 21
 i5.print(); // Output: 22
```

### 4. Prefix and Postfix Decrement (`--`)

- **Member Function Overloading**: Both prefix (`--obj`) and postfix (`obj--`) decrement operators can be overloaded similarly to increment operators.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Prefix decrement operator (--obj)
    MyClass& operator--() {
        --value;
        return *this; // Returns reference to the modified object
    }

    // Postfix decrement operator (obj--)
    MyClass operator--(int) {
        MyClass temp(*this); // Create a copy of current object
        --value; // Decrement the object itself
        return temp; // Return the copy (original value)
    }
};
```

```cpp
 // Prefix Decrement (--)
 MyClass i7(25);
 --i7;
 i7.print(); // Output: 24

 // Postfix Decrement (i7--)
 MyClass i8 = i7--;
 i8.print(); // Output: 24
 i7.print(); // Output: 23
```

### 5. Dereference (`*`)

- **Member Function Overloading**: Dereference operator (`*`) is typically used for smart pointers or proxy objects. It returns a reference to the object it points to.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Dereference operator (*)
    int& operator*() {
        return value; // Returns reference to value member
    }
};
```

- **Non-Member Function Overloading**: It's less common to overload dereference as a non-member function, but it can be done similarly if needed.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for dereference operator (*)
    friend int& operator*(MyClass& obj) {
        return obj.value; // Returns reference to value member
    }
};
```

```cpp
 // Dereference (*)
 MyClass i9(30);
 int& value = *i9;
 std::cout << value << std::endl; // Output: 30
```

### 6. Address Of (`&`)

- **Member Function Overloading**: Address of operator (`&`) returns the address of the object. It's typically overloaded as a member function.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Address of operator (&)
    int* operator&() {
        return &value; // Returns address of value member
    }
};
```

- **Non-Member Function Overloading**: Overloading address of as a non-member function is not possible because it conflicts with the built-in behavior of the operator.

```cpp
 // Address Of (&)
 MyClass i10(35);
 int* ptr = &i10;
 std::cout << *ptr << std::endl; // Output: 35
```

### 7. Logical NOT (`!`)

- **Member Function Overloading**: Logical NOT (`!`) operator returns `true` if the object is zero, `false` otherwise. It's typically overloaded as a member function.

```cpp
class MyClass {
private:
    bool flag;

public:
    MyClass(bool f = false) : flag(f) {}

    // Logical NOT operator (!)
    bool operator!() const {
        return !flag; // Returns logical NOT of flag member
    }
};
```

- **Non-Member Function Overloading**: Similar to member function overloading, but defined as a friend function if access to private members is needed.

```cpp
class MyClass {
private:
    bool flag;

public:
    MyClass(bool f = false) : flag(f) {}

    // Friend function for logical NOT operator (!)
    friend bool operator!(const MyClass& obj) {
        return !obj.flag; // Returns logical NOT of flag member
    }
};
```

```cpp
 // Logical NOT (!)
 MyClass i11(false);
 bool result = !i11;
 std::cout << std::boolalpha << result << std::endl; // Output: true
```

### 8. Bitwise NOT (`~`)

- **Member Function Overloading**: Bitwise NOT (`~`) operator inverts all bits of the object. It's typically overloaded as a member function.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Bitwise NOT operator (~)
    MyClass operator~() const {
        return MyClass(~value); // Returns bitwise NOT of value member
    }
};
```

- **Non-Member Function Overloading**: Similar to member function overloading, but defined as a friend function if access to private members is needed.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Friend function for bitwise NOT operator (~)
    friend MyClass operator~(const MyClass& obj) {
        return MyClass(~obj.value); // Returns bitwise NOT of value member
    }
};
```

```cpp
 // Bitwise NOT (~)
 MyClass i12(40);
 MyClass i13;
 i13 = ~i12;
 i13.print(); // Output: bitwise NOT of 40
```
