### Virtual Inheritance in Derived Classes in C++

Virtual functions enable dynamic polymorphism in C++, allowing derived classes to override base class methods. Once a function is declared as virtual in a base class, it remains virtual in all derived classes, ensuring that the appropriate overridden function is called based on the actual object type, even when accessed through a base class pointer or reference.

#### Inheritance of Virtual Functions

When a member function is declared as virtual in a base class, it inherits its virtual nature in all derived classes. This means that it is not necessary to use the `virtual` keyword again in the derived class's function declaration. The compiler understands that the function is meant to override the base class's virtual function.

### Example

Consider the following program, which demonstrates this concept:

```cpp
#include <iostream>
using namespace std;

class A {
public:
    virtual void fun() { cout << "\nA::fun() called"; }
};

class B : public A {
public:
    void fun() { cout << "\nB::fun() called"; }
};

class C : public B {
public:
    void fun() { cout << "\nC::fun() called"; }
};

int main() {
    // An object of class C
    C c;

    // A pointer of class B pointing to the memory location of c
    B* b = &c;

    // This line prints "C::fun() called"
    b->fun();

    getchar(); // Waits for a character input
    return 0;
}
```

### Output

```
C::fun() called
```

### Explanation

- **Base Class A**: Declares a virtual function `fun()`.
- **Derived Class B**: Overrides `fun()` without using the `virtual` keyword. Despite not repeating `virtual`, `B::fun()` is a virtual function because `A::fun()` is virtual.
- **Derived Class C**: Further overrides `fun()` without the `virtual` keyword. `C::fun()` remains virtual due to its inheritance from `A::fun()`.

In `main()`, a `B` class pointer (`b`) is used to point to an object of class `C` (`c`). When `b->fun()` is called, the `C` class version of `fun()` is executed because the function call is resolved at runtime based on the actual type of the object, which is `C`.

### Key Points

1. **Automatic Inheritance of Virtuality**: Once a function is declared virtual in a base class, all overrides of that function in derived classes are automatically virtual.
2. **Runtime Polymorphism**: Virtual functions support runtime polymorphism, allowing the correct function to be called based on the actual object type.
3. **No Need to Repeat `virtual`**: It is not necessary to use the `virtual` keyword in derived classes when overriding a virtual function. The virtual nature is inherited from the base class.

### Important Note

- **Virtual Functions in Constructors/Destructors**: Avoid calling virtual functions from constructors or destructors. During construction and destruction, the type of the object is not fully determined, and the base class version of the virtual function may be called instead of the derived class version.

This behavior of virtual functions simplifies the design and maintenance of polymorphic class hierarchies, ensuring that the correct overridden function is always called based on the actual object type, promoting more flexible and extensible code.
