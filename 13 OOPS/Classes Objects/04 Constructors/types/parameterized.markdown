## **Parameterized Constructor**

A parameterized constructor in C++ enables the passing of arguments to constructors. These arguments are typically used to initialize an object during its creation. To define a parameterized constructor, simply include parameters in the constructor's declaration and use them to initialize the object within the constructor's body.

**Syntax of Parameterized Constructor**

```cpp
className (parameters...) {
    // constructor body
}
```

### **Examples of Parameterized Constructor**

**Note:**: When defining a parameterized constructor and no default constructor is explicitly defined, creating an object without passing any arguments will result in an error.

**Error Caused by Not Defining an Explicit Default Constructor**

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
    int rno;
    string name;
    double fee;

public:
    Student(int no, const string& n, double f) : rno(no), name(n), fee(f) {}
};

int main()
{
    Student s; // This will cause an error
    return 0;
}
```

**Note:** Whenever we define one or more non-default constructors (with parameters) for a class, a default constructor (without parameters) should also be explicitly defined, as the compiler will not provide a default constructor implicitly. However, it's not necessary, but it's considered best practice to always define a default constructor.

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
    Example(int initialValue = 0) { initialData = initialValue; }

    int getData() { return initialData; }
};

int main()
{

    Example firstInstance; // will not throw error

    Example secondInstance(25);

    cout << "First Object Data: " << firstInstance.getData() << endl;
    cout << "Second Object Data: " << secondInstance.getData()
         << endl;

    return 0;
}
```

In this example, default values assigned to every argument of the parameterized constructor allow creating the object without passing any parameters, similar to default constructors. Thus, this type of constructor functions as both a default and parameterized constructor.

**Default Constructor in C++**

A default constructor in C++ is a constructor that doesn't require any arguments. It's essentially a constructor without parameters, often referred to as a zero-argument constructor.

**Syntax:**

```
className() {
    // constructor body
}
```

**Explanation:**
A default constructor is used to initialize the object's data members when no values are provided explicitly during object creation. It's automatically invoked upon object instantiation if no other constructor is explicitly called.

**Examples:**

**Example 1:**

```
// C++ program to illustrate the concept of default constructors
#include <iostream>
using namespace std;

class Construct {
public:
    int a, b;

    // Default Constructor
    Construct() {
        a = 10;
        b = 20;
    }
};

int main() {
    // Default constructor called automatically
    // when the object is created
    Construct c;
    cout << "a: " << c.a << endl << "b: " << c.b;
    return 1;
}
```

**Output:**

```
a: 10
b: 20
```

**Note:** Even without explicitly defining any constructor, the compiler automatically provides a default constructor.
