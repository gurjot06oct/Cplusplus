// In C++, `new` and `delete` are operators designed for dynamic memory management, whereas `malloc` and `free` are functions inherited from C. There are important differences between them, particularly regarding the invocation of constructors and destructors.

// ### Key Differences Between `new`, `malloc`, `delete` and `free`

// 1. **Constructor/Destructor Invocation**:
//    - `new`: Calls the constructor of the object being created.
//    - `malloc`: Allocates raw memory but does not call the constructor of the object.
//    - `delete`: Calls the destructor of the object being destroyed.
//    - `free`: Deallocates raw memory but does not call the destructor.

// 2. **Type Safety**:
//    - `new`: Does not require explicit type casting.
//    - `malloc`: Returns a `void*` pointer, requiring explicit type casting.
//    - `delete`: Does not require explicit type casting.
//    - `free`: Requires explicit type casting if used with pointers to objects.

#include <iostream>
#include <cstdlib> // For malloc and free

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
    // Using new and delete
    std::cout << "Using new and delete:" << std::endl;
    MyClass *obj1 = new MyClass(); // Constructor is called
    obj1->display();
    delete obj1; // Destructor is called

    // Using malloc and free
    std::cout << "\nUsing malloc and free:" << std::endl;
    MyClass *obj2 = (MyClass *)malloc(sizeof(MyClass)); // Constructor is NOT called
    // obj2->display(); // This would cause undefined behavior since the object is not properly constructed
    free(obj2); // Destructor is NOT called

    return 0;
}

// ### Explanation

// 1. **Using `new` and `delete`**:
//    - `new MyClass()`: Allocates memory for `MyClass` and calls the constructor.
//    - `delete obj1`: Calls the destructor and then deallocates the memory.

// 2. **Using `malloc` and `free`**:
//    - `malloc(sizeof(MyClass))`: Allocates raw memory but does not call the constructor.
//    - `free(obj2)`: Deallocates the memory but does not call the destructor.