#include <iostream>
#include <memory> // For std::unique_ptr and std::shared_ptr

// Smart pointers in C++ provide automatic and safe memory management. They manage the lifetime of dynamically allocated objects by ensuring that objects are properly destroyed and memory is deallocated when the smart pointer goes out of scope. The most commonly used smart pointers in C++ are `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`, all of which are defined in the `<memory>` header.

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
        // Create a unique_ptr for a single MyClass object
        std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>();
        uniquePtr->display();
        // No need to explicitly delete, unique_ptr will handle it
    } // uniquePtr goes out of scope and MyClass object is destroyed

    // Unique Pointer for an Array of Objects
    {
        // Create a unique_ptr for an array of MyClass objects
        std::unique_ptr<MyClass[]> uniqueArrayPtr = std::make_unique<MyClass[]>(3);
        for (int i = 0; i < 3; ++i)
        {
            uniqueArrayPtr[i].display();
        }
        // No need to explicitly delete, unique_ptr will handle it
    } // uniqueArrayPtr goes out of scope and MyClass objects are destroyed

    // Shared Pointer for a Single Object
    {
        // Create a shared_ptr for a single MyClass object
        std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();
        {
            // sharedPtr2 shares ownership with sharedPtr1
            std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
            sharedPtr2->display();
            // sharedPtr2 goes out of scope, but MyClass object is not destroyed because sharedPtr1 still exists
        }
        sharedPtr1->display();
        // No need to explicitly delete, sharedPtr will handle it when the last owner goes out of scope
    } // sharedPtr1 goes out of scope and MyClass object is destroyed

    // Shared Pointer for an Array of Objects
    {
        // Create a shared_ptr for an array of MyClass objects
        // Note: std::make_shared does not support arrays, so we use new and a custom deleter
        std::shared_ptr<MyClass> sharedArrayPtr(new MyClass[3], std::default_delete<MyClass[]>());
        for (int i = 0; i < 3; ++i)
        {
            sharedArrayPtr.get()[i].display();
        }
        // No need to explicitly delete, sharedPtr will handle it
    } // sharedArrayPtr goes out of scope and MyClass objects are destroyed

    return 0;
}
