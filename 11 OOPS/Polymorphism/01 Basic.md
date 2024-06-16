Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common superclass. It enables flexibility and extensibility in code by allowing methods to behave differently based on the object that invokes them. This concept greatly enhances code reusability and modularity.

## Types of Polymorphism:

### Compile-time Polymorphism (Static Binding or Early Binding):

#### 1. Method Overloading:

Method overloading allows multiple functions with the same name but different parameter lists to be defined within the same scope. The compiler determines which function to call based on the number, types, and order of arguments passed to the function at compile-time.

Example:

```cpp
#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    int sum1 = calc.add(5, 10);        // Calls int add(int a, int b)
    double sum2 = calc.add(3.5, 2.5); // Calls double add(double a, double b)

    std::cout << "Sum1: " << sum1 << std::endl;
    std::cout << "Sum2: " << sum2 << std::endl;

    return 0;
}
```

#### 2. Operator Overloading:

In C++, operators like `+`, `-`, `*`, etc., can be overloaded to work with user-defined types (objects). This allows the operators to behave differently based on the operand types.

Example:

```cpp
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Overloading + operator to add two Complex objects
    Complex operator+(const Complex& c) {
        Complex temp(0, 0);
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        std::cout << "Real: " << real << ", Imaginary: " << imag << std::endl;
    }
};

int main() {
    Complex c1(3.0, 2.0);
    Complex c2(4.0, 1.0);
    Complex c3 = c1 + c2; // Calls operator+(const Complex&)

    c3.display();

    return 0;
}
```

### Runtime Polymorphism (Dynamic Binding or Late Binding):

#### 1. Method Overriding:

Method overriding occurs when a subclass provides a specific implementation of a method that is already defined in its superclass. The decision on which method to invoke is made at runtime based on the object type.

Example:

```cpp
#include <iostream>

// Base class
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Some sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Animal();
    Animal* animal2 = new Dog();

    animal1->makeSound(); // Outputs: Some sound
    animal2->makeSound(); // Outputs: Bark

    delete animal1;
    delete animal2;

    return 0;
}
```

#### 2. Virtual Functions:

Virtual functions are functions in a base class that are overridden in derived classes. They allow the correct function to be called for an object, regardless of the expression used to make the function call. This is achieved through dynamic dispatch, where the function call is resolved at runtime based on the actual object type.

Example:

```cpp
#include <iostream>

// Base class
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Some sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Bark" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Animal();
    Animal* animal2 = new Dog();

    animal1->makeSound(); // Outputs: Some sound
    animal2->makeSound(); // Outputs: Bark

    delete animal1;
    delete animal2;

    return 0;
}
```
