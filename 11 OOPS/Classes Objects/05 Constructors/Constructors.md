## Constructors

A constructor in C++ is a special method automatically invoked during object creation. Its primary purpose is to initialize the data members of newly created objects. Typically, a constructor shares the same name as the class or structure and provides essential data, hence its name "constructor."

### Key Points:

- Constructors are member functions of a class with the same name as the class itself.
- They automatically initialize data members for objects of the class upon creation.
- Constructors do not return values; thus, they lack a return type.
- Invocation occurs automatically during object creation.
- Constructors can be overloaded.
- They cannot be declared virtual.
- Syntax:

```cpp
<class-name>(list-of-parameters);
```

### Constructors can be defined within or outside the class declaration:

#### 1. Defining constructor within the class:

```cpp
#include <iostream>
using namespace std;

class Student {
    int rollNumber;
    char studentName[50];
    double tuitionFee;

public:
    // Constructor
    Student() {
        cout << "Enter the Roll Number: ";
        cin >> rollNumber;
        cout << "Enter the Name: ";
        cin >> studentName;
        cout << "Enter the Tuition Fee: ";
        cin >> tuitionFee;
    }

    void display() {
        cout << endl << "Roll Number: " << rollNumber << "\nName: " << studentName << "\nTuition Fee: " << tuitionFee;
    }
};

int main() {
    Student s; // Constructor called automatically
    s.display();
    return 0;
}

```

**Output:**

```
Enter the Roll Number: 101
Enter the Name: John
Enter the Tuition Fee: 1500

Roll Number: 101
Name: John
Tuition Fee: 1500
```

#### 2. Defining constructor outside the class:

```cpp
#include <iostream>
using namespace std;

class Student {
    int rollNumber;
    char studentName[50];
    double tuitionFee;

public:
    // Constructor declaration
    Student();
    void display();
};

// Constructor definition outside the class
Student::Student() {
    cout << "Enter the Roll Number: ";
    cin >> rollNumber;
    cout << "Enter the Name: ";
    cin >> studentName;
    cout << "Enter the Tuition Fee: ";
    cin >> tuitionFee;
}

void Student::display() {
    cout << endl << "Roll Number: " << rollNumber << "\nName: " << studentName << "\nTuition Fee: " << tuitionFee;
}

int main() {
    Student s;
    s.display();
    return 0;
}
```

**Output:**

```
Enter the Roll Number: 101
Enter the Name: John
Enter the Tuition Fee: 1500

Roll Number: 101
Name: John
Tuition Fee: 1500
```

### Characteristics:

- Constructor name matches the class name.
- Typically declared in the public section of a class.
- No return type as they don't return values.
- Automatic invocation during object creation.
- Can be overloaded but not declared virtual.
- Cannot be inherited.
- Their addresses cannot be referred to.
- Implicitly calls new and delete operators during memory allocation.

### Constructor Types

Constructors in C++ can be categorized according to the scenarios in which they are employed. There exist four primary types of constructors:

### 1. **Default Constructor**
   - **Definition**: A constructor that takes no arguments or has default values for all its parameters.
   - **Purpose**: It initializes objects with default values.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass() {
             // Default constructor
         }
     };
     ```

### 2. **Parameterized Constructor**
   - **Definition**: A constructor that takes one or more arguments.
   - **Purpose**: It allows the object to be initialized with specific values at the time of creation.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass(int x, int y) {
             // Parameterized constructor
         }
     };
     ```

### 3. **Copy Constructor**
   - **Definition**: A constructor that initializes an object using another object of the same class.
   - **Purpose**: It creates a new object as a copy of an existing object.
   - **Syntax**: The copy constructor takes a reference to an object of the same class as its parameter.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass(const MyClass &obj) {
             // Copy constructor
         }
     };
     ```

### 4. **Move Constructor (C++11 and later)**
   - **Definition**: A constructor that transfers resources from a temporary (rvalue) object to a new object.
   - **Purpose**: It is used to avoid unnecessary deep copying, especially when dealing with large objects or resources like dynamic memory or file handles.
   - **Syntax**: The move constructor takes an rvalue reference (e.g., `ClassName&&`) as its parameter.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass(MyClass&& obj) noexcept {
             // Move constructor
         }
     };
     ```

### 5. **Defaulted Constructor (C++11 and later)**
   - **Definition**: A constructor that is explicitly specified to use the compiler-generated default behavior.
   - **Purpose**: It is used when you want to explicitly define that a class should have a default constructor, even if other constructors exist.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass() = default; // Defaulted constructor
     };
     ```

### 6. **Deleted Constructor (C++11 and later)**
   - **Definition**: A constructor that is explicitly marked as deleted to prevent its use.
   - **Purpose**: It is used to disable certain types of object construction, such as preventing copying or moving.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass() = delete; // Deleted constructor
     };
     ```

### 7. **Explicit Constructor**
   - **Definition**: A constructor that is marked with the `explicit` keyword to prevent implicit conversions or copy-initialization.
   - **Purpose**: It prevents the compiler from using the constructor for implicit conversions.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         explicit MyClass(int x) {
             // Explicit constructor
         }
     };
     ```

### 8. **Delegating Constructor (C++11 and later)**
   - **Definition**: A constructor that delegates all or part of its work to another constructor in the same class.
   - **Purpose**: It allows code reuse within different constructors of the same class.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass() : MyClass(0) {
             // Delegating to another constructor
         }

         MyClass(int x) {
             // Actual initialization code
         }
     };
     ```

### 9. **Conversion Constructor**
   - **Definition**: A constructor that can be used for type conversion, usually from a single argument.
   - **Purpose**: It allows implicit or explicit conversion from a certain type to the class type.
   - **Example**:
     ```cpp
     class MyClass {
     public:
         MyClass(int x) {
             // Conversion constructor
         }
     };

     MyClass obj = 10; // Implicit conversion from int to MyClass
     ```

### 10. **Constructor Initialization Lists**
   - **Purpose**: To initialize member variables directly rather than assigning values to them inside the constructor body.
   - **Advantages**: 
     - **Efficiency**: Direct initialization avoids an extra default construction followed by assignment.
     - **Const and Reference Members**: These must be initialized in the initialization list since they cannot be assigned after the object is constructed.
   - **Example**:
     ```cpp
     class MyClass {
     private:
         const int a;
         int& b;
     public:
         MyClass(int x, int& y) : a(x), b(y) {
             // a and b are directly initialized
         }
     };
     ```