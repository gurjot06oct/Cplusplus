## Method Overriding

### Compile-time Method Overriding

Compile-time method overriding, also known as static method binding or early binding, occurs when the compiler determines which function to call based on the type of the pointer or reference at compile time. This is typical when the function in the derived class has the same signature (name and parameters) as the function in the base class.

#### Example of Compile-time Method Overriding:

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
    void display() {
        cout << "Display function of Parent class" << endl;
    }
};

class Child : public Parent {
public:
    void display() {
        cout << "Display function of Child class" << endl;
    }
};

int main() {
    Child obj;
    obj.display();  // Calls Child's display() method
    return 0;
}
```

**Explanation**:

- In the example above, both `Parent` and `Child` classes have a method named `display()`.
- When `obj.display()` is called in `main()`, the compiler binds this call to `Child` class's `display()` method because `obj` is of type `Child`.
- This demonstrates compile-time method overriding because the decision of which `display()` method to call is made statically by the compiler based on the type of `obj`.

**Output**:

```
Display function of Child class
```

### Runtime Polymorphism using Virtual Functions

Runtime polymorphism in C++ is achieved using virtual functions and dynamic dispatch. Virtual functions enable the function call to be resolved at runtime, based on the actual type of object pointed to or referenced, rather than the type of the pointer or reference itself.

#### Example of Runtime Polymorphism using Virtual Functions:

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void display() {
        cout << "Display function of Parent class" << endl;
    }
};

class Child : public Parent {
public:
    void display() override {
        cout << "Display function of Child class" << endl;
    }
};

int main() {
    Parent* ptr;
    Child obj;
    ptr = &obj;

    ptr->display();  // Calls Child's display() method due to virtual function

    return 0;
}
```

**Explanation**:

- In this example, `Parent` class's `display()` method is declared as `virtual`.
- When `ptr->display()` is called in `main()`, even though `ptr` is of type `Parent*`, it points to an object of type `Child`.
- Due to dynamic dispatch (enabled by the `virtual` keyword), the call to `display()` is resolved at runtime, and `Child` class's `display()` method is executed.

**Output**:

```
Display function of Child class
```

### Key Differences:

- **Compile-time Method Overriding**: The method to be called is determined by the type of the pointer or reference at compile time. It does not depend on the actual object type but on the type of the variable used to access the object.
- **Runtime Polymorphism**: The method to be called is determined by the type of the object pointed to or referenced at runtime. This allows for more flexible and dynamic behavior based on the actual object's type.

In summary, while both compile-time method overriding and runtime polymorphism (using virtual functions) involve inheritance and method overriding, they differ in when and how the decision of which method to call is made: statically at compile time versus dynamically at runtime.
