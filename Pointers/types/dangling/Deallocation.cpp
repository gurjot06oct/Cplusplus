// In this example, a pointer becomes a dangling pointer after the memory it points to is deallocated.

#include <iostream>

int main()
{
    int *ptr = new int(10); // Dynamically allocate memory
    std::cout << "Value before delete: " << *ptr << std::endl;

    delete ptr; // Deallocate memory
    // ptr is now a dangling pointer

    // Accessing the dangling pointer can cause undefined behavior
    // std::cout << "Value after delete: " << *ptr << std::endl; // Uncommenting this line may cause a crash

    ptr = nullptr; // Best practice to avoid dangling pointers

    return 0;
}

// #### Explanation
// - `new int(10)` allocates memory and initializes it to 10.
// - `delete ptr` deallocates the memory.
// - `ptr` now points to a memory location that has been freed, making it a dangling pointer.
// - Accessing `*ptr` after `delete` leads to undefined behavior.
// - Setting `ptr` to `nullptr` is a good practice to prevent accidental access.