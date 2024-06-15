// ### `std::unique_ptr`:
// `std::unique_ptr` allows exactly one owner of the underlying pointer. It is used as the default choice for plain-old C++ objects (POCO) unless shared ownership is explicitly required. Unlike `std::shared_ptr`, `std::unique_ptr` cannot be shared or copied; it can only be moved to a new owner. `std::unique_ptr` is small and efficient, with a size of one pointer, and it supports rvalue references for fast insertion and retrieval from C++ Standard Library collections. It is declared in the `<memory>` header file.

#include <memory>
#include <iostream>

int main()
{
    // Creating a std::unique_ptr to manage a dynamically allocated integer
    std::unique_ptr<int> ptr(new int(42));

    // Accessing the value through the std::unique_ptr
    std::cout << "Value: " << *ptr << std::endl;

    // Resetting the std::unique_ptr (releasing ownership of the dynamically allocated object)
    ptr.reset();

    // Creating a std::unique_ptr using std::make_unique (C++14 and later)
    auto ptr2 = std::make_unique<int>(100);

    // Accessing the value through the std::unique_ptr
    std::cout << "Value: " << *ptr2 << std::endl;

    // No need to manually delete the dynamically allocated object
    // When ptr2 goes out of scope, the memory will be automatically deallocated

    return 0;
}

// In this example:
// - We create a `std::unique_ptr` named `ptr` to manage a dynamically allocated integer with the value `42`.
// - We access the value through `ptr`.
// - We reset `ptr`, releasing ownership of the dynamically allocated object.
// - We create another `std::unique_ptr` named `ptr2` using `std::make_unique` to manage another dynamically allocated integer with the value `100`.
// - We access the value through `ptr2`.
// - When `ptr2` goes out of scope, the memory allocated for the integer is automatically deallocated.