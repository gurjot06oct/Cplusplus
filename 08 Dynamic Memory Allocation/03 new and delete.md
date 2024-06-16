## Dynamic Memory Allocation in C++ Using `new` and `delete`

In C++, the `new` and `delete` operators are fundamental for dynamic memory allocation and deallocation. They offer a more flexible and type-safe approach compared to traditional C-style functions. This demonstration will explore their usage, covering allocation and deallocation for both single objects and arrays of objects.

### Single Object Allocation and Deallocation

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

int main()
{
    // Dynamically allocate memory for a single object
    MyClass *ptr = new MyClass;

    // Deallocate memory
    delete ptr;

    return 0;
}
```

When dynamically allocating memory for a single object using `new`, the constructor of the class is called to initialize the object. Similarly, when deallocating memory using `delete`, the destructor is invoked to perform any necessary cleanup.
