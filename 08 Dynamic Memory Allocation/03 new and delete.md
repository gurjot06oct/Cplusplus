## Dynamic Memory Allocation in C++ Using `new` and `delete`

In C++, the `new` and `delete` operators are essential for dynamic memory management, providing a type-safe and flexible alternative to traditional C-style functions like `malloc` and `free`. This guide demonstrates their usage, including allocation and deallocation of both single objects and arrays of objects.

### Single Object Allocation and Deallocation

To illustrate single object allocation and deallocation, consider the following class:

```cpp
#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "Constructor called!" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "Destructor called!" << std::endl;
    }
    void display() const
    {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};
```

You can allocate and deallocate memory for a single instance of `MyClass` using `new` and `delete`:

```cpp
MyClass *ptr = new MyClass; // Constructor called

ptr->display(); // Output: Hello from MyClass!

delete ptr; // Destructor called
```

When dynamically allocating memory with `new`, the constructor of the class is invoked to initialize the object. Similarly, when deallocating memory with `delete`, the destructor is called to perform any necessary cleanup.

### Single Object Allocation with Initialization

You can also allocate memory for a built-in data type and initialize it simultaneously:

```cpp
int *intPtr = new int(10);
std::cout << *intPtr << std::endl; // Output: 10

delete intPtr;
```
