Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common superclass. It enables flexibility and extensibility in code by allowing methods to behave differently based on the object that invokes them. This concept greatly enhances code reusability and modularity.

## Types of Polymorphism:

### Compile-time Polymorphism (Static Binding or Early Binding):

#### 1. Method Overloading:

Method overloading allows multiple functions with the same name but different parameter lists to be defined within the same scope. The compiler determines which function to call based on the number, types, and order of arguments passed to the function at compile-time.

#### 2. Operator Overloading:

In C++, operators like `+`, `-`, `*`, etc., can be overloaded to work with user-defined types (objects). This allows the operators to behave differently based on the operand types.

### Runtime Polymorphism (Dynamic Binding or Late Binding):

#### Method Overriding:

Method overriding occurs when a subclass provides a specific implementation of a method that is already defined in its superclass. The decision on which method to invoke can be made at runtime based on the object type. Virtual functions are functions in a base class that are overridden in derived classes. They allow the correct function to be called for an object, regardless of the expression used to make the function call. This is achieved through dynamic dispatch, where the function call is resolved at runtime based on the actual object type.

### Method Overriding vs Method Overloading

Method overriding and method overloading are two fundamental concepts in object-oriented programming, and they serve different purposes and follow different rules. Here's a detailed comparison between the two:

### Method Overriding

1. **Definition**: Method overriding allows a subclass to provide a specific implementation of a method that is already defined in its superclass.
2. **Signature**: The overridden method must have the same name, return type, and parameters as the method in the superclass.
3. **Inheritance**: It occurs between superclass and subclass, involving inheritance.
4. **Virtual Functions**: In languages like C++, the method in the superclass must be declared as `virtual` to allow overriding.
5. **Purpose**: It allows a subclass to provide a specific implementation of a method that is already defined in its superclass.
6. **Binding**: It uses dynamic binding (runtime) to determine the method to be called based on the object type.

#### Example of Overriding (C++)

```cpp
#include <iostream>

class Base {
public:
    virtual void show() { // Virtual function
        std::cout << "Base show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Override base class method
        std::cout << "Derived show" << std::endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    basePtr->show(); // Calls Derived's show() due to dynamic binding

    return 0;
}
```

### Method Overloading

1. **Definition**: Method overloading allows multiple methods in the same scope to have the same name but different parameters (different type, number, or both).
2. **Signature**: Overloaded methods must have the same name but different parameter lists.
3. **Inheritance**: It can occur within a single class or across different classes in the same inheritance hierarchy.
4. **Virtual Functions**: It does not require the use of virtual functions.
5. **Purpose**: It allows methods to perform similar but slightly different tasks, depending on the input parameters.
6. **Binding**: It uses static binding (compile-time) to determine which method to call based on the method signature.

#### Example of Overloading (C++)

```cpp
#include <iostream>

class Print {
public:
    void show(int i) {
        std::cout << "Integer: " << i << std::endl;
    }
    void show(double d) {
        std::cout << "Double: " << d << std::endl;
    }
    void show(std::string s) {
        std::cout << "String: " << s << std::endl;
    }
};

int main() {
    Print p;

    p.show(5);          // Calls show(int)
    p.show(3.14);       // Calls show(double)
    p.show("Hello");    // Calls show(string)

    return 0;
}
```

### Summary of Differences

| Feature            | Overriding                                       | Overloading                                                          |
| ------------------ | ------------------------------------------------ | -------------------------------------------------------------------- |
| **Definition**     | Redefines a superclass method in a subclass      | Defines multiple methods with the same name but different parameters |
| **Method Name**    | Same as the superclass method                    | Same name, different parameter lists                                 |
| **Parameter List** | Must be exactly the same                         | Must be different (type, number, or both)                            |
| **Return Type**    | Must be the same or covariant return type        | Can be different                                                     |
| **Inheritance**    | Requires inheritance                             | Can be within the same class or inheritance hierarchy                |
| **Binding**        | Dynamic binding (runtime)                        | Static binding (compile-time)                                        |
| **Use of Virtual** | Requires `virtual` keyword in superclass (C++)   | No `virtual` keyword required                                        |
| **Purpose**        | To provide specific implementation in a subclass | To provide multiple versions of a method                             |
