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

1. Default Constructor
2. Parameterized Constructor
3. Copy Constructor
4. Move Constructor
