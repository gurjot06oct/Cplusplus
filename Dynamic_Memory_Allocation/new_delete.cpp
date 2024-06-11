// In C++, `new` and `delete` operators are used for dynamic memory allocation and deallocation. They provide a more flexible and type-safe way to manage memory compared to the C-style functions (`malloc`, `realloc`, `free`, `calloc`). Below is an advanced explanation and examples demonstrating how to use `new` and `delete` to allocate and deallocate memory for single objects and arrays of objects.

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
    // Dynamically allocate memory for single Types
    // Constructor called!
    MyClass *ptr = new MyClass;

    // Deallocate memory
    // Destructor called!
    delete ptr;

    // Dynamically allocate memory for an array of 5 Types
    // Constructor called!
    MyClass *arr = new MyClass[5];

    // Deallocate memory
    // Destructor called!
    delete[] arr;

    // When using `new` and `new[]` for objects, their constructors are called. Similarly, `delete` and `delete[]` call the destructors for objects before deallocating the memory.
    return 0;
}

// ### Important Points to Remember
// 1. **Single Object vs. Array Allocation**:
//    - Use `delete` for memory allocated with `new`.
//    - Use `delete[]` for memory allocated with `new[]`.
// 2. `new` and `delete`: Does not require explicit type casting.