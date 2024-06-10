// Incorrect Initialization
#include <iostream>

int main()
{
    int *ptr = (int *)0x12345678; // Incorrectly initialized to an arbitrary memory address

    // Dereferencing an incorrectly initialized pointer can cause undefined behavior
    // std::cout << *ptr << std::endl; // Uncommenting this line may cause a crash
    return 0;
}

// #### Explanation
// - `int* ptr = (int*)0x12345678;` initializes the pointer to an arbitrary memory address.
// - The address `0x12345678` is not necessarily a valid memory location.
// - Dereferencing `*ptr` can lead to undefined behavior, as it tries to access an invalid memory address.