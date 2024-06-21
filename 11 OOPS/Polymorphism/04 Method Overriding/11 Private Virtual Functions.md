## Can Virtual Functions be Private in C++?

In C++, virtual functions can indeed be private. While access control is enforced, C++ does not enforce visibility control, meaning that private virtual functions can still be overridden in derived classes. However, they can only be called within the base class or through an interface provided by the base class.

### Example of Private Virtual Functions

Here is a revised example demonstrating how a virtual function can be private:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base class constructor\n";
    }

    virtual ~Base() {
        cout << "Base class destructor\n";
    }

    void show() {
        cout << "show() called on Base class\n";
    }

    virtual void print() {
        cout << "print() called on Base class\n";
    }
};

class Derived : public Base {
public:
    Derived() : Base() {
        cout << "Derived class constructor\n";
    }

    virtual ~Derived() {
        cout << "Derived class destructor\n";
    }

private:
    virtual void print() override {
        cout << "print() called on Derived class\n";
    }
};

int main() {
    cout << "Printing with base class pointer\n";
    Base* basePtr = new Derived();

    basePtr->show();
    basePtr->print();

    delete basePtr;
    return 0;
}
```

**Output:**

```
Printing with base class pointer
Base class constructor
Derived class constructor
show() called on Base class
print() called on Derived class
Derived class destructor
Base class destructor
```

### Explanation

- **Base Class Pointer:** A pointer of type `Base` points to an object of type `Derived`. When `basePtr->print()` is called, the `print()` function of `Derived` is executed despite being private. This is because `print()` is declared virtual in the `Base` class and overridden in the `Derived` class.
- **Virtual Function Call:** Even though `print()` is private in `Derived`, it can still be accessed via the base class pointer because the base class defines a public interface for this virtual function.

### Key Points

1. **Access Control vs Visibility Control:** C++ enforces access control, but not visibility control. Virtual functions can be private and still be overridden in derived classes.
2. **Public Interface:** The base class provides a public interface for the virtual function, which can be used to call the overridden function in the derived class, even if it is private in the derived class.
3. **Destructor Calls:** The destructors are called in the reverse order of class inheritance. First, the `Derived` class destructor is called, followed by the `Base` class destructor.

### Conclusion

This example demonstrates that virtual functions can be private in C++, and they can be overridden in derived classes. The overridden function can be called using a base class pointer, ensuring proper polymorphic behavior while maintaining encapsulation in the derived class.
