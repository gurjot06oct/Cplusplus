### Constructors in Multiple Inheritance

In C++, when dealing with multiple inheritance, the constructors of the base classes and the derived class are called in a specific sequence to ensure proper initialization of all inherited components. Let's break down the concept of constructors in multiple inheritance with clearer naming and examples:

#### Concept

**Constructor:** A constructor is a special member function of a class that is automatically invoked when an object of that class is created. It initializes the object's state and allocates memory as needed.

**Multiple Inheritance:** This feature of C++ allows a class to inherit from multiple base classes. When a derived class inherits from multiple base classes, the constructors of each base class and the derived class itself are called in a specific order during object creation.

#### Example Explained

Consider the following example where we have two base classes (`A1` and `A2`) and a derived class `S` that inherits from both `A1` and `A2` using virtual inheritance.

```cpp
#include <iostream>
using namespace std;

class A1 {
public:
    A1() {
        cout << "Constructor of base class A1" << endl;
    }
};

class A2 {
public:
    A2() {
        cout << "Constructor of base class A2" << endl;
    }
};

class S : public A1, virtual public A2 {
public:
    S() : A1(), A2() {
        cout << "Constructor of derived class S" << endl;
    }
};

int main() {
    S obj;
    return 0;
}
```

#### Output Explanation

When you run the above program, the output will be:

```
Constructor of base class A2
Constructor of base class A1
Constructor of derived class S
```

#### Sequence of Constructor Calls

1. **Base Class `A2` Constructor:** Since `A2` is virtually inherited, its constructor is called first. Virtual base class constructors are always called before non-virtual base class constructors.
2. **Base Class `A1` Constructor:** Next, the constructor of `A1` is called.
3. **Derived Class `S` Constructor:** Finally, the constructor of the derived class `S` is executed.
