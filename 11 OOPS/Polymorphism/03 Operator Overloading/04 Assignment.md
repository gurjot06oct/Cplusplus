### Assignment Operators in C++ with Operator Overloading

Operator overloading in C++ allows you to define custom behaviors for assignment operators (`=`, `+=`, `-=`, etc.) when they are used with objects of your own classes. They are not overloadable as friend functions. Here's an explanation of how each assignment operator can be overloaded:

#### 1. Simple Assignment (`=`)

The simple assignment operator (`=`) assigns one object to another of the same type.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Assignment operator overloading (=)
    MyClass& operator=(const MyClass& rhs) {
        if (this != &rhs) { // Avoid self-assignment
            value = rhs.value;
        }
        return *this;
    }
    void print() {
        cout << value << endl;
    }
};
```

```cpp
MyClass i1(10);
MyClass i2;
i2 = i1;
i2.print(); // Output: 10
```

#### 2. Arithmetic Assignment (`+=`, `-=`, `*=`, `/=`, `%=`)

Arithmetic assignment operators modify the left operand (`*this`) using the right operand.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Arithmetic assignment operators (+=, -=, *=, /=, %=)
    MyClass& operator+=(const MyClass& rhs) {
        value += rhs.value;
        return *this;
    }

    MyClass& operator-=(const MyClass& rhs) {
        value -= rhs.value;
        return *this;
    }

    MyClass& operator*=(const MyClass& rhs) {
        value *= rhs.value;
        return *this;
    }

    MyClass& operator/=(const MyClass& rhs) {
        if (rhs.value != 0) {
            value /= rhs.value;
        } else {
            // Handle division by zero error
        }
        return *this;
    }

    MyClass& operator%=(const MyClass& rhs) {
        if (rhs.value != 0) {
            value %= rhs.value;
        } else {
            // Handle modulus by zero error
        }
        return *this;
    }
};
```

#### 3. Bitwise Assignment (`&=`, `|=`, `^=`)

Bitwise assignment operators perform bitwise AND (`&=`), OR (`|=`), and XOR (`^=`) operations between the left and right operands.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Bitwise assignment operators (&=, |=, ^=)
    MyClass& operator&=(const MyClass& rhs) {
        value &= rhs.value;
        return *this;
    }

    MyClass& operator|=(const MyClass& rhs) {
        value |= rhs.value;
        return *this;
    }

    MyClass& operator^=(const MyClass& rhs) {
        value ^= rhs.value;
        return *this;
    }
};
```

#### 4. Shift Assignment (`<<=`, `>>=`)

Shift assignment operators (`<<=`, `>>=`) perform left and right shifts on the left operand (`*this`) by the number of positions specified by the right operand.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Shift assignment operators (<<=, >>=)
    MyClass& operator<<=(int shift) {
        value <<= shift;
        return *this;
    }

    MyClass& operator>>=(int shift) {
        value >>= shift;
        return *this;
    }
};
```

### Usage

```cpp
// Assignment Operators (=, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=)
MyClass i35(50);
MyClass i36(25);
i35 += i36;
i35.print(); // Output: Result of i35 after += operation
// Do same for Others
```
