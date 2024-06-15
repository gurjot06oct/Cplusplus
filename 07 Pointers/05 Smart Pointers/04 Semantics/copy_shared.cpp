#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> ptr1(new int(42));
    std::shared_ptr<int> ptr2 = ptr1; // Shared ownership, ptr1 and ptr2 both point to the same object

    std::cout << "*ptr1: " << *ptr1 << std::endl; // Output: *ptr1: 42
    std::cout << "*ptr2: " << *ptr2 << std::endl; // Output: *ptr2: 42

    return 0;
}
