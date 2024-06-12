## **Copy Constructors**

In the realm of C++ programming, understanding copy constructors is essential for ensuring efficient object initialization and manipulation. A copy constructor, a member function within a class, facilitates the creation of an object by replicating the attributes of another object from the same class. Let's delve into the syntax, examples, and applications of copy constructors to grasp their significance in C++.

### **Syntax of Copy Constructor**

The syntax for a copy constructor involves taking a reference to an object of the same class as an argument. It typically appears as follows:

```cpp
ClassName(ClassName &obj)
{
    // body_containing_logic
}
```

In this syntax, `ClassName` denotes the name of the class, and `obj` represents the object being copied.

**Implicit Copy Constructor**

Similar to the default constructor, if an explicit copy constructor is not defined within a class, the C++ compiler automatically generates an implicit copy constructor. Unlike the default constructor, the presence of any explicit constructor, including a copy constructor or a move constructor, does not nullify the implicit copy constructor. It is always created by the compiler when an explicit copy constructor is absent.

**Implicit Copy Constructor**

```cpp
#include <iostream>
using namespace std;

class Sample {
    int id;

public:
    // Constructor
    Sample(int x) {
        id = x;
    }

    // Display function
    void display() {
        cout << "ID=" << id;
    }
};

int main() {
    // Creating first object
    Sample firstObj(10);
    cout << "First Object: ";
    firstObj.display();
    cout << endl;

    // Creating second object by copy constructor
    Sample secondObj(firstObj);
    cout << "Second Object: ";
    secondObj.display();

    return 0;
}

```

**Defining an Explicit Copy Constructor**

```cpp
#include <iostream>
using namespace std;

class Sample {
    int id;

public:
    // Default constructor
    Sample() {}

    // Parameterized constructor
    Sample(int x) { id = x; }

    // Copy constructor
    Sample(const Sample& t) { id = t.id; }

    // Display function
    void display() { cout << "ID=" << id; }
};

int main() {
    // Creating first object with parameterized constructor
    Sample firstObj(10);
    cout << "First Object: ";
    firstObj.display();
    cout << endl;

    // Creating second object using copy constructor
    Sample secondObj(firstObj);
    cout << "Second Object: ";
    secondObj.display();

    return 0;
}
```

**Copy Constructor with Parameterized Constructor**

```cpp
#include <iostream>
#include <string> // For std::string

class Student
{
    int rollNumber;
    std::string studentName; // Using std::string instead of char array
    double tuitionFee;

public:
    // Parameterized constructor
    Student(int, const std::string &, double);

    // Copy constructor
    Student(const Student &);

    // Display function
    void display();
};

// Parameterized constructor definition
Student::Student(int no, const std::string &n, double f)
{
    rollNumber = no;
    studentName = n;
    tuitionFee = f;
}

// Copy constructor definition
Student::Student(const Student &t)
{
    rollNumber = t.rollNumber;
    studentName = t.studentName;
    tuitionFee = t.tuitionFee;
}

// Display function definition
void Student::display()
{
    std::cout << std::endl
              << "Roll Number: " << rollNumber << "\nName: " << studentName << "\nFee: " << tuitionFee;
}

int main()
{
    // Creating first object using parameterized constructor
    Student firstStudent(1001, "Manjeet", 10000);
    std::cout << "First Student:";
    firstStudent.display();

    // Creating second object using copy constructor
    Student secondStudent(firstStudent);
    std::cout << "\n\nSecond Student:";
    secondStudent.display();

    return 0;
}
```

**Uses of Copy Constructors**

1. **Object Initialization**: Copy constructors facilitate the creation of new objects by copying values from existing objects of the same class.
2. **Deep Copy**: They enable deep copying, ensuring that all attributes, including dynamically allocated memory, are correctly duplicated.
3. **Customized Initialization**: Copy constructors can be tailored to modify specific attributes during the copying process, allowing for customized object initialization.

## **Understanding When Copy Constructors are Called**

In C++, a copy constructor plays a crucial role in initializing an object using another object of the same class. It is invoked primarily when a new object is created as a copy of an existing object. Let's delve into the scenarios where a copy constructor is called in C++ and explore examples illustrating these cases.

**1. Object Returned by Value:**
When an object of a class is returned by value from a function, the copy constructor is invoked to create a copy of the returned object.

**2. Object Passed by Value:**
When an object of a class is passed by value as an argument to a function, the copy constructor is called to initialize the parameter object with the argument object's values.

**3. Object Initialization:**
Direct initialization of an object with another object of the same type invokes the copy constructor.

**4. Initialization Lists with Braces:**
When objects are constructed using initialization lists with braces, the copy constructor may be called.

**5. Compiler-Generated Temporary Objects:**
Temporary objects generated by the compiler may also trigger the invocation of the copy constructor.

Let's explore an example to understand these scenarios:

```cpp
#include <iostream>
using namespace std;

class Storage {
public:
    // Constructor
    Storage() {}
    // Copy Constructor
    Storage(const Storage& original) {
        cout << "Copy constructor has been called " << endl;
    }
};

// Function returning an object by value
Storage returnObject() {
    Storage obj;
    return obj;
}

// Function taking an object as an argument by value
void functionWithArgument(Storage& obj) {
    return;
}

// Driver code
int main() {
    Storage object1;

    cout << "Case 1: ";
    returnObject();
    cout << endl;

    cout << "Case 2: ";
    functionWithArgument(object1);
    cout << endl;

    cout << "Case 3: ";
    Storage object2 = object1;

    return 0;
}
```

**Output:**

```
Case 1:
Case 2:
Case 3: Copy constructor has been called
```

It's important to note that the invocation of the copy constructor is not guaranteed in all scenarios due to compiler optimizations, such as Return Value Optimization (RVO). However, the C++ compiler implicitly provides a copy constructor if none is explicitly defined within the class.

Understanding when copy constructors are called in C++ is fundamental for efficient object initialization and manipulation, ensuring the proper handling of object copies throughout the program execution.

## **When Should We Write Our Own Copy Constructor?**

A copy constructor in C++ initializes an object using another object of the same class. While the C++ compiler provides a default copy constructor (and assignment operator) for classes, there are scenarios where writing our own copy constructor becomes essential.

**1. Dynamic Memory Allocation:**
If a class contains members that are dynamically allocated at runtime, using pointers for example, the default copy constructor performs a shallow copy. This means it copies the address of the dynamically allocated memory instead of creating a new copy. Consequently, both objects end up pointing to the same memory location, leading to issues like unintended modifications, dangling pointers, and memory leaks. In such cases, writing a custom copy constructor allows for deep copying, ensuring that each object has its own separate copy of dynamically allocated memory.

**2. Specific Data Member Handling:**
Sometimes, we may want to copy only specific data members of a class while keeping others unchanged. By defining our own copy constructor, we can control which data members are copied and how they are copied, providing flexibility in managing object initialization.

**3. Deep Copy Requirements:**
Deep copying, where pointers (or references) of copied objects point to new memory locations, is only achievable with a user-defined copy constructor. If deep copying is necessary for a class due to its design requirements, then writing a custom copy constructor becomes imperative.

In summary, we should write our own copy constructor in C++ under the following circumstances:

- The class contains dynamically allocated memory or pointers.
- Specific handling of data members is required during copying.
- Deep copying is necessary for proper object initialization and management.

By implementing a custom copy constructor, we ensure proper handling of object copying, prevent issues related to shallow copying, and maintain the integrity of our class design.

## **Understanding Shallow Copy and Deep Copy**

When it comes to creating a copy of an object in C++, it's essential to understand the concepts of shallow copy and deep copy, particularly concerning dynamically allocated resources. Let's explore these concepts and how they relate to object copying in C++.

**1. Shallow Copy:**
Shallow copying creates a new object that is an exact replica of the original object. However, it does not replicate the dynamically allocated resources held by the original object. Instead, it copies the memory addresses of these resources. Consequently, both the original object and the copied object end up sharing the same dynamically allocated memory. Shallow copying is typically performed using the default copy constructor or the default assignment operator.

```cpp
// Shallow Copy using default copy constructor or assignment operator
Geeks Obj1(Obj); // Copy Constructor
// or
Geeks Obj1 = Obj; // Default assignment operator
```

**2. Deep Copy:**
Deep copying, on the other hand, involves creating a new object with its own separate copies of dynamically allocated resources. This ensures that changes made to one object do not affect the other, providing independence between the original and copied objects. Deep copying is necessary when the object's variables include dynamically allocated memory. It requires a custom copy constructor or assignment operator to ensure that each object has its own distinct resources.

```cpp
// Deep Copy using custom copy constructor or assignment operator
Geeks Obj2;
Obj2 = Obj1; // Default assignment operator
```

In summary, whether to perform shallow copy or deep copy depends on the nature of the resources held by the object:

- **Shallow Copy**: Used when the object's variables do not involve dynamically allocated memory. The default copy constructor or assignment operator can be utilized.
- **Deep Copy**: Necessary when the object's variables include dynamically allocated memory. A custom copy constructor or assignment operator must be implemented to ensure independent copies of resources for each object.

By understanding and appropriately implementing shallow copy and deep copy mechanisms, C++ programmers can ensure proper object copying while managing dynamically allocated resources effectively.
