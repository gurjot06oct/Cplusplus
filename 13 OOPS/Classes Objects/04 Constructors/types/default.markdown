## **Default Constructor**

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

```cpp
#include <iostream>
using namespace std;

class Construct {
public:
    int valueA, valueB;

    // Default Constructor
    Construct() {
        valueA = 10;
        valueB = 20;
    }
};

int main() {
    // Default constructor called automatically
    // when the object is created
    Construct c;
    cout << "Value of a: " << c.valueA << endl << "Value of b: " << c.valueB;
    return 0;
}
```

**Output:**

```
Value of a: 10
Value of b: 20
```

**Note:** Even without explicitly defining any constructor, the compiler automatically provides a default constructor.
