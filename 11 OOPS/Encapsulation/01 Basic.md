### Encapsulation in C++

Encapsulation in C++ is the concept of bundling data and methods that operate on that data within a single unit, typically a class. This principle is a cornerstone of Object-Oriented Programming (OOP), aiming to protect data and hide implementation details.

#### Real-Life Example of Encapsulation

Imagine a company with various departments like accounts, finance, and sales. Each department has specific roles:

- The finance department manages all financial transactions and records.
- The sales department handles all sales-related activities and keeps track of sales data.

If a finance officer needs sales data for a particular month, they cannot directly access the sales records. Instead, they must request this information from the sales department. This scenario mirrors encapsulation, where each department encapsulates its data and functions, making direct access restricted.

#### Key Properties of Encapsulation

1. **Data Protection**: Encapsulation safeguards the internal state of an object by keeping its data members private. Access and modification are done through public methods, ensuring controlled and secure data handling.
2. **Information Hiding**: Encapsulation hides a class’s internal implementation from external code. Only the public interface is accessible, providing abstraction and allowing internal changes without affecting external code.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Temp {
    int a;
    int b;
public:
    int solve(int input) {
        a = input;
        b = a / 2;
        return b;
    }
};

int main() {
    int n;
    cin >> n;
    Temp half;
    int ans = half.solve(n);
    cout << ans << endl;
    return 0;
}
```

### Features of Encapsulation

- Functions within a class must use member variables to be considered encapsulated.
- Encapsulation enhances readability, maintainability, and security by grouping data and methods.
- It helps control data member modification.
- Encapsulation also supports data abstraction by hiding data from other sections, as seen in the department example.

### Simple Example of Encapsulation in C++

```cpp
#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void setAge(int age) {
        this->age = age;
    }
    int getAge() {
        return age;
    }
};

int main() {
    Person person("John Doe", 30);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    person.setName("Jane Doe");
    person.setAge(32);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;

    return 0;
}
```

**Output:**

```
Name: John Doe
Age: 30
Name: Jane Doe
Age: 32
```

In C++, encapsulation is implemented using classes and access specifiers.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Encapsulation {
private:
    int x;
public:
    void set(int a) { x = a; }
    int get() { return x; }
};

int main() {
    Encapsulation obj;
    obj.set(5);
    cout << obj.get();
    return 0;
}
```

**Output:**

```
5
```

**Explanation**: The variable `x` is private and can only be accessed or modified through the public methods `set()` and `get()`.

### Example with Circle Class

```cpp
#include <iostream>
using namespace std;

class Circle {
private:
    float area;
    float radius;
public:
    void getRadius() {
        cout << "Enter radius\n";
        cin >> radius;
    }
    void findArea() {
        area = 3.14 * radius * radius;
        cout << "Area of circle=" << area;
    }
};

int main() {
    Circle cir;
    cir.getRadius();
    cir.findArea();
    return 0;
}
```

**Output:**

```
Enter radius
Area of circle=0
```

### Role of Access Specifiers in Encapsulation

Access specifiers like private, protected, and public control access to class members and methods, facilitating data hiding:

- **Private**: Members are accessible only within the class.
- **Protected**: Members are accessible within the class and derived classes.
- **Public**: Members are accessible from any code.

### Points to Consider

- Encapsulation involves creating a class to bundle data and methods.
- Use access specifiers to hide data and control access.

By following these principles, encapsulation ensures data integrity and security, enabling more robust and maintainable code.
