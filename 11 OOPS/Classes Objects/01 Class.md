### Classes in C++

A class in C++ is a blueprint for creating objects that defines the structure and behavior of those objects. It serves as a template or a prototype, encapsulating data members (variables) and member functions (methods) that operate on that data. Classes provide a way to organize and manage related data and functionality, promoting code reusability, modularity, and abstraction.

#### How to Create a Class

In C++, a class is created using the `class` keyword followed by the class name and a pair of curly braces `{}`. Inside the curly braces, you define the components of the class.

#### Components of a Class

A class in C++ consists of two main components:

1. **Data Members**: These are variables declared within the class. They represent the properties or attributes of objects created from the class.

2. **Member Functions (Methods)**: These are functions declared within the class. They define the behavior or actions that objects of the class can perform.

#### Example

```cpp
#include <iostream>
#include <string>

// Define the Car class
class Car {
    // Data Members
    std::string make;
    std::string model;
    int year;

public:
    // Member Functions
    void setMake(std::string carMake) {
        make = carMake;
    }

    void setModel(std::string carModel) {
        model = carModel;
    }

    void setYear(int carYear) {
        year = carYear;
    }
} obj1, obj2; // Objects can also be created like this

int main() {
    // Create an object of the Car class
    Car myCar;

    // Access and modify object data members
    myCar.setMake("Toyota");
    myCar.setModel("Corolla");
    myCar.setYear(2020);

    return 0;
}
```

In this example, `Car` is a class with data members `make`, `model`, and `year`. It also has member functions `setMake()`, `setModel()`, and `setYear()` to set the values of these data members. In the `main()` function, an object of the `Car` class is created, and its member functions are called to set the values of its data members.

Defining data members (variables) and member functions outside the class involves using the scope resolution operator `::` to link the member with the class. Here's how you can do it:

```cpp
#include <iostream>
#include <string>

class MyClass {
public:
    // Declaration of member functions
    void setData(int value);
    int getData();

private:
    // Declaration of data members
    int dataMember;
};

// Definition of member functions outside the class
void MyClass::setData(int value) {
    dataMember = value;
}

int MyClass::getData() {
    return dataMember;
}

// Definition of data member outside the class is allowed only if it is static
// int MyClass::dataMember = 0;

int main() {
    MyClass obj;
    obj.setData(42);
    std::cout << "Data member value: " << obj.getData() << std::endl;
    return 0;
}
```

In this example:

- The `dataMember` is declared inside the `MyClass` class as a private member.
- It's defined outside the class using the scope resolution operator `::`. You also need to specify the data type.
- Remember that data member can only be initialized outside the class definition if it is static.

This separation allows you to keep the class declaration clean while defining member functions and data members separately.
