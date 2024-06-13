## Smart Pointers in C++

Smart pointers in C++ provide automatic and safe memory management. They manage the lifetime of dynamically allocated objects by ensuring proper destruction and deallocation when the smart pointer goes out of scope. The commonly used smart pointers are `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`, defined in the `<memory>` header.

### Using `std::unique_ptr`

```cpp
#include <iostream>
#include <memory>

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
    // Unique Pointer for a Single Object
    {
        std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>();
        uniquePtr->display();
    } // uniquePtr goes out of scope and MyClass object is destroyed

    // Unique Pointer for an Array of Objects
    {
        std::unique_ptr<MyClass[]> uniqueArrayPtr = std::make_unique<MyClass[]>(3);
        for (int i = 0; i < 3; ++i)
        {
            uniqueArrayPtr[i].display();
        }
    } // uniqueArrayPtr goes out of scope and MyClass objects are destroyed

    return 0;
}
```

### Using `std::shared_ptr`

```cpp
#include <iostream>
#include <memory>

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
    // Shared Pointer for a Single Object
    {
        std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();
        {
            std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
            sharedPtr2->display();
        }
        sharedPtr1->display();
    } // sharedPtr1 goes out of scope and MyClass object is destroyed

    // Shared Pointer for an Array of Objects
    {
        std::shared_ptr<MyClass> sharedArrayPtr(new MyClass[3], std::default_delete<MyClass[]>());
        for (int i = 0; i < 3; ++i)
        {
            sharedArrayPtr.get()[i].display();
        }
    } // sharedArrayPtr goes out of scope and MyClass objects are destroyed

    return 0;
}
```
