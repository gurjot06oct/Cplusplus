### Pure Virtual Destructors

A pure virtual destructor in C++ can be declared, but it must have a body. This requirement stems from the way destructors are called during the destruction of derived class instances. Destructors are invoked in the reverse order of class inheritance, meaning the derived class's destructor is called first, followed by the base class's destructor. If the base class's destructor is pure virtual, it still needs a function body to be called correctly.

### Why Use a Pure Virtual Destructor?

When you delete an instance of a derived class using a pointer to the base class, a virtual destructor ensures that the derived class's destructor is called first, properly releasing all allocated resources.

### Important Notes

- Only destructors can be declared virtual.
- Constructors cannot be virtual because they are not inherited and are called in the order of inheritance.

### Example of a Pure Virtual Destructor

#### Incorrect Usage (Without Definition)

This code will produce a linker error because the pure virtual destructor `~Base` is declared but not defined:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() = 0; // Pure virtual destructor
};

class Derived : public Base {
public:
    ~Derived() { cout << "~Derived() is executed"; }
};

int main() {
    Base* b = new Derived();
    delete b;
    return 0;
}
```

**Error:**

```
undefined reference to `Base::~Base()'
```

#### Correct Usage (With Definition)

To fix this, you must provide a definition for the pure virtual destructor:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() = 0; // Pure virtual destructor
};

Base::~Base() {
    cout << "Pure virtual destructor is called\n";
}

class Derived : public Base {
public:
    ~Derived() { cout << "~Derived() is executed\n"; }
};

int main() {
    Base* b = new Derived();
    delete b;
    return 0;
}
```

**Output:**

```
~Derived() is executed
Pure virtual destructor is called
```

### Explanation

- **Destructors Call Order:** Destructors are called from the most derived class up the inheritance hierarchy. When `delete b` is called, `~Derived` executes first, followed by `~Base`.
- **Virtual Table (vtable):** The vtable maintains pointers to the virtual functions, ensuring the correct destructor is called at runtime.

### Abstract Class with Pure Virtual Destructor

A class with a pure virtual destructor is considered abstract and cannot be instantiated directly. For example:

```cpp
#include <iostream>
using namespace std;

class AbstractClass {
public:
    virtual ~AbstractClass() = 0; // Pure virtual destructor
};

AbstractClass::~AbstractClass() {
    cout << "Pure virtual destructor is called\n";
}

int main() {
    // AbstractClass obj; // Error: cannot declare variable 'obj' to be of abstract type 'AbstractClass'
    return 0;
}
```
