### Classes in C++

A class in C++ is a blueprint for creating objects that defines the structure and behavior of those objects. It serves as a template or a prototype, encapsulating data members (variables) and member functions (methods) that operate on that data. Classes provide a way to organize and manage related data and functionality, promoting code reusability, modularity, and abstraction.

#### How to Create a Class

In C++, a class is created using the `class` keyword followed by the class name and a pair of curly braces `{}`. Inside the curly braces, you define the components of the class.

#### Components of a Class

A class in C++ consists of two main components:

1. **Data Members**: These are variables declared within the class. They represent the properties or attributes of objects created from the class.

2. **Member Functions (Methods)**: These are functions declared within the class. They define the behavior or actions that objects of the class can perform.

### Understanding the Class

#### 1. Define the `Car` class

```cpp
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
```

#### Class Structure and Data Members

The `Car` class encapsulates three private data members:

- `make` (type `std::string`): Represents the make of the car.
- `model` (type `std::string`): Represents the model of the car.
- `year` (type `int`): Represents the manufacturing year of the car.

#### Public Member Functions

The class provides three public member functions (`setMake`, `setModel`, and `setYear`) to modify the private data members:

- `setMake`: Assigns a value to the `make` member variable.
- `setModel`: Assigns a value to the `model` member variable.
- `setYear`: Assigns a value to the `year` member variable.

These functions enable the user to set or update the details of a car object after its instantiation.

#### Object Instantiation and Usage

```cpp
// Create an object of the Car class
Car myCar;

// Access and modify object data members
myCar.setMake("Toyota");
myCar.setModel("Corolla");
myCar.setYear(2020);
```

Here:

- An object `myCar` of the `Car` class is instantiated.
- Using the `setMake`, `setModel`, and `setYear` functions, the attributes of `myCar` are set to "Toyota" (make), "Corolla" (model), and 2020 (year), respectively.

#### 2. Define the `MyClass` class

```cpp
class MyClass {
public:
    // Declaration of member functions
    void setData(int value);
    int getData();

private:
    // Declaration of data members
    int dataMember;
};
```

- **Class `MyClass`**: This defines a class named `MyClass` which encapsulates functionality related to manipulating an integer data member.
- **Public Member Functions**:
  - `setData`: This function takes an integer parameter `value` and sets the private member `dataMember` to this value.
  - `getData`: This function returns the current value of the private member `dataMember`.
- **Private Data Member**:
  - `dataMember`: An integer variable that holds the data within an instance of `MyClass`. It is private, meaning it can only be accessed or modified through the public member functions of the class.

#### Definition of Member Functions Outside the Class

```cpp
void MyClass::setData(int value) {
    dataMember = value;
}

int MyClass::getData() {
    return dataMember;
}
```

- These lines define the implementation of the member functions `setData` and `getData` outside the class definition. They provide the functionality previously declared in the class.

#### Error in the Code

```cpp
int MyClass::dataMember = 0; // Error! Definitions of data members outside the class are allowed only if they are static.
```

- This line attempts to initialize `dataMember` outside of the class, which is incorrect because `dataMember` is not declared as a static member. Non-static data members must be initialized inside a constructor or through member functions, not directly outside the class.

#### Object Instantiation and Usage

```cpp
MyClass obj;
obj.setData(42);
std::cout << "Data member value: " << obj.getData() << std::endl;
return 0;
```

- An object `obj` of type `MyClass` is created.
- The `setData` function is used to set the value of `dataMember` to 42.
- The `getData` function retrieves the current value of `dataMember`, which is then printed out.
