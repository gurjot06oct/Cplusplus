## **Parameterized Constructor**

A parameterized constructor in C++ enables the passing of arguments to constructors. These arguments are typically used to initialize an object during its creation. To define a parameterized constructor, simply include parameters in the constructor's declaration and use them to initialize the object within the constructor's body.

**Syntax of Parameterized Constructor**

```cpp
className (parameters...) {
    // constructor body
}
```

### **Error Caused by Not Defining an Explicit Default Constructor**

When defining a parameterized constructor and no default constructor is explicitly defined, creating an object without passing any arguments will result in an error. When a class includes one or more non-default constructors (those with parameters), it's essential to explicitly define a default constructor (one without parameters). The compiler won't generate a default constructor automatically in such cases. While it's not mandatory, adhering to this practice is recommended for better code clarity and to avoid unexpected behavior.

```cpp
#include <iostream>
#include <string>
using namespace std;

class SchoolStudent {
    int rollNumber;
    string studentName;
    double tuitionFee;

public:
    SchoolStudent(int rollNo, const string& name, double fee) : rollNumber(rollNo), studentName(name), tuitionFee(fee) {}
};

int main()
{
    // Attempting to create an instance of SchoolStudent without providing necessary arguments
    // This will cause a compilation error since no default constructor is defined in SchoolStudent
    SchoolStudent s;
    return 0;
}
```

### **Uses of Parameterized Constructor**

- Used to initialize the various data elements of different objects with different values when they are created.
- Used for constructor overloading.

## **Default Arguments with C++ Parameterized Constructor**

Just like normal functions, default values can be defined for the arguments of parameterized constructors. All the rules of default arguments are applied to these parameters.

**Defining Parameterized Constructor with Default Values**

```cpp
#include <iostream>
using namespace std;

class Example {
private:
    int initialData;

public:
    // Constructor with default parameter
    Example(int initialValue = 0) {
        initialData = initialValue;
    }

    int getData() {
        return initialData;
    }
};

int main() {
    // Creating an object using the default constructor
    Example firstInstance; // This will use the default value 0 instead of throwing error
    // Creating an object with a specified initial value
    Example secondInstance(25); // This will use the value 25

    // Example secondInstance{25};  // Uses uniform initialization

    // Displaying the data of both objects
    cout << "First Object Data: " << firstInstance.getData() << endl;
    cout << "Second Object Data: " << secondInstance.getData() << endl;

    return 0;
}

```

In this example, default values assigned to every argument of the parameterized constructor allow creating the object without passing any parameters, similar to default constructors. Thus, this type of constructor functions as both a default and parameterized constructor.
