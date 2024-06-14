#include <memory>
#include <iostream>

int main()
{
    // Creating a std::shared_ptr to manage a dynamically allocated integer
    std::shared_ptr<int> ptr1(new int(42));

    // Moving ownership from ptr1 to ptr2
    std::shared_ptr<int> ptr2 = std::move(ptr1);

    // Both ptr1 and ptr2 share ownership of the dynamically allocated integer
    std::cout << "*ptr2: " << *ptr2 << std::endl;                // Output: *ptr2: 42
    std::cout << "Use count: " << ptr2.use_count() << std::endl; // Output: Use count: 1

    // Use count remains the same after move
    std::cout << "Use count: " << ptr1.use_count() << std::endl; // Output: Use count: 1

    return 0;
}
