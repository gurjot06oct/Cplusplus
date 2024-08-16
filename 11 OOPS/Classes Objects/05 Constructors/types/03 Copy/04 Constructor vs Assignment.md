## Copy Constructor vs Copy Assignment
The copy constructor and copy assignment operator are related but serve different purposes in C++. Understanding how they work and interact is crucial for managing object copying and resource management.

### Copy Constructor

**Purpose**: The copy constructor is used to create a new object as a copy of an existing object. It initializes the new object using the values from the original object.

**Syntax**:
```cpp
ClassName(const ClassName& other);
```

**Example**:
```cpp
class MyClass {
public:
    MyClass(const MyClass& other) {
        // Copy constructor implementation
    }
};
```

**Usage**:
```cpp
MyClass obj1;
MyClass obj2 = obj1; // Calls the copy constructor
```

### Copy Assignment Operator

**Purpose**: The copy assignment operator is used to copy the values from one existing object to another existing object. It assigns the values of the source object to the target object.

**Syntax**:
```cpp
ClassName& operator=(const ClassName& other);
```

**Example**:
```cpp
class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        // Copy assignment implementation
        return *this;
    }
};
```

**Usage**:
```cpp
MyClass obj1;
MyClass obj2;
obj2 = obj1; // Calls the copy assignment operator
```

### Key Differences

1. **Initialization vs. Assignment**:
   - **Copy Constructor**: Used for initializing a new object.
   - **Copy Assignment Operator**: Used for assigning values to an already initialized object.

2. **Object Lifecycle**:
   - **Copy Constructor**: Creates a new object and initializes it with the values of an existing object.
   - **Copy Assignment Operator**: Assigns the values of an existing object to another already existing object.

### Example Combining Both

Here’s a more detailed example illustrating both the copy constructor and copy assignment operator:

```cpp
#include <iostream>

class MyClass {
private:
    int* data;
public:
    // Constructor
    MyClass(int value) : data(new int(value)) {
        std::cout << "Constructor called" << std::endl;
    }

    // Copy Constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {
        std::cout << "Copy Constructor called" << std::endl;
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        delete data; // Clean up existing resource
        data = new int(*other.data); // Copy the resource
        std::cout << "Copy Assignment Operator called" << std::endl;
        return *this;
    }

    // Destructor
    ~MyClass() {
        delete data;
        std::cout << "Destructor called" << std::endl;
    }

    // For demonstration
    void show() const {
        std::cout << "Value: " << *data << std::endl;
    }
};

int main() {
    MyClass obj1(10); // Constructor called
    MyClass obj2 = obj1; // Copy Constructor called
    obj2.show(); // Value: 10

    MyClass obj3(20); // Constructor called
    obj3 = obj1; // Copy Assignment Operator called
    obj3.show(); // Value: 10

    return 0;
}
```