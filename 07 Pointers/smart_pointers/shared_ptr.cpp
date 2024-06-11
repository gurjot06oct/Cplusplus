// ### `std::shared_ptr`:
// `std::shared_ptr` is a reference-counted smart pointer used when there is a need to assign one raw pointer to multiple owners. It allows shared ownership of the underlying pointer, ensuring that the raw pointer is not deleted until all `std::shared_ptr` owners have gone out of scope or have otherwise relinquished ownership. The size of `std::shared_ptr` is two pointers: one for the object and one for the shared control block containing the reference count. It is declared in the `<memory>` header file.

#include <memory>
#include <iostream>

int main()
{
    // Creating a std::shared_ptr to manage a dynamically allocated integer
    std::shared_ptr<int> ptr(new int(42));

    // Creating another std::shared_ptr that shares ownership of the same dynamically allocated integer
    std::shared_ptr<int> ptr2 = ptr;

    // Accessing the value through the std::shared_ptr
    std::cout << "Value through ptr: " << *ptr << std::endl;
    std::cout << "Value through ptr2: " << *ptr2 << std::endl;

    // Resetting one of the shared pointers (releasing ownership of the dynamically allocated object)
    ptr.reset();

    // Accessing the value through the remaining shared pointer
    std::cout << "Value through ptr2 after reset: " << *ptr2 << std::endl;

    // No need to manually delete the dynamically allocated object
    // When ptr2 goes out of scope, the memory will be automatically deallocated

    return 0;
}

// In this example:
// - We create a `std::shared_ptr` named `ptr` to manage a dynamically allocated integer with the value `42`.
// - We create another `std::shared_ptr` named `ptr2` that shares ownership of the same dynamically allocated integer as `ptr`.
// - We access the value through both `ptr` and `ptr2`.
// - We reset `ptr`, releasing ownership of the dynamically allocated object.
// - We access the value through `ptr2`.
// - When `ptr2` goes out of scope, the memory allocated for the integer is automatically deallocated.
