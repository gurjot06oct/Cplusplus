#include <iostream>

// Void Pointers
// A `void*` (void pointer) is a special type of pointer that can hold the address of any data type. However, since it does not have a type, you cannot directly dereference it without casting it to another pointer type.

int main()
{
    void *ptr;
    int x = 10;
    ptr = &x; // ptr now holds the address of x

    int *intPtr = static_cast<int *>(ptr); // cast void pointer back to int pointer
    std::cout << *intPtr << std::endl;     // Output: 10
    return 0;
}