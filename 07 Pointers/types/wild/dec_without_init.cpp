// Declaration without Initialization

#include <iostream>

int main()
{
    int *ptr; // Declared but not initialized
    // ptr contains a garbage value

    // Dereferencing a wild pointer can cause undefined behavior
    // std::cout << *ptr << std::endl; // Uncommenting this line may cause a crash

    // DO THIS INSTEAD for Declaration but not initialization
    int *ptr_ = new int; // Best practice, Dynamically allocate memory
    return 0;
}

// #### Explanation

// - `int* ptr;` declares a pointer but does not initialize it.
// - `ptr` contains a garbage value, which points to an unknown memory location.
// - Dereferencing `*ptr` can lead to undefined behavior, as it tries to access a random memory address.