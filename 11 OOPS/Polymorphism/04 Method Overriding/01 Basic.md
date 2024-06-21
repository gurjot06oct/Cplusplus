### Method Overriding

Method overriding is an object-oriented programming concept where a subclass provides a specific implementation of a method that is already defined in its superclass. The method in the subclass must have the same name, return type, and parameters as the method in the superclass. This allows a subclass to customize or completely replace the behavior of the superclass method.

#### Key Points of Method Overriding:

1. **Same Signature**: The overridden method in the subclass must have the same signature (name and parameters) as the method in the superclass.
2. **Inheritance**: Method overriding occurs in the context of inheritance. The subclass inherits methods from the superclass and then overrides the relevant ones.
3. **Virtual Functions (in C++)**: In languages like C++, for a method to be overridden, it must be declared as `virtual` in the base class.
4. **Dynamic Binding**: Overridden methods are resolved at runtime based on the actual object type, enabling polymorphism.

### Static Binding (Early Binding)

Static binding occurs at compile time. The function to be called is resolved by the compiler based on the type of the object.

#### Without Virtual Function

When we do not use virtual functions, the function calls are resolved at compile time based on the type of the pointer or reference used to make the call, not the type of the object being pointed to.

Example:

```cpp
#include <iostream>

class Base {
public:
    void show() { // Non-virtual function
        std::cout << "Base::show() called" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() { // Non-virtual function
        std::cout << "Derived::show() called" << std::endl;
    }
};

int main() {
    Base* b;      // Base class pointer
    Derived d;    // Derived class object
    b = &d;

    b->show();    // Calls Base::show() due to static binding
    return 0;
}
```

In this example, `b->show()` calls `Base::show()` even though `b` is pointing to a `Derived` object because the function is not virtual, and the call is resolved based on the type of the pointer `b` (which is `Base*`).

### Dynamic Binding (Late Binding)

Dynamic binding occurs at runtime. The function to be called is resolved at runtime based on the type of the object being pointed to. This is achieved using virtual functions.

#### With Virtual Function

When we use virtual functions, the function calls are resolved at runtime based on the actual type of the object, not the type of the pointer or reference.

Example:

```cpp
#include <iostream>

class Base {
public:
    virtual void show() { // Virtual function
        std::cout << "Base::show() called" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Override Base's virtual function
        std::cout << "Derived::show() called" << std::endl;
    }
};

int main() {
    Base* b;      // Base class pointer
    Derived d;    // Derived class object
    b = &d;

    b->show();    // Calls Derived::show() due to dynamic binding
    return 0;
}
```

In this example, `b->show()` calls `Derived::show()` because `show()` is a virtual function, and the call is resolved at runtime based on the actual type of the object `d` (which is `Derived`).

### Key Differences:

- **Static Binding**:

  - Occurs at compile time.
  - Resolved based on the type of the pointer/reference.
  - Non-virtual functions.
  - Example: `b->show()` calls `Base::show()` if `show()` is not virtual.

- **Dynamic Binding**:
  - Occurs at runtime.
  - Resolved based on the actual type of the object.
  - Virtual functions.
  - Example: `b->show()` calls `Derived::show()` if `show()` is virtual in the base class and overridden in the derived class.

Using virtual functions allows for more flexible and dynamic behavior in object-oriented programs, enabling polymorphism, where the correct function implementation is chosen based on the actual object type at runtime.
