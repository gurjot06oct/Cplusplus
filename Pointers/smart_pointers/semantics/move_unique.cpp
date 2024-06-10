#include <memory>
#include <iostream>

int main()
{
    // Creating a std::unique_ptr to manage a dynamically allocated integer
    std::unique_ptr<int> ptr1(new int(42));

    // Moving ownership from ptr1 to ptr2
    std::unique_ptr<int> ptr2 = std::move(ptr1);

    // ptr1 is now null, and ptr2 owns the dynamically allocated integer
    std::cout << "*ptr2: " << *ptr2 << std::endl; // Output: *ptr2: 42

    // Accessing ptr1 after move results in an error (null pointer)
    // std::cout << "*ptr1: " << *ptr1 << std::endl; // Error: Accessing null pointer

    return 0;
}
