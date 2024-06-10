#include <iostream>

int main()
{
    int value = 5;
    int *ptr1 = &value; // Pointer to an integer
    int **ptr2 = &ptr1; // Double pointer to an integer pointer

    // Printing values
    std::cout << "Value: " << value << std::endl;
    std::cout << "Value through ptr1: " << *ptr1 << std::endl;
    std::cout << "Value through ptr2: " << **ptr2 << std::endl;

    return 0;
}

// - We have an integer variable `value` with a value of `5`.
// - `ptr1` is a pointer to an integer that holds the address of `value`.
// - `ptr2` is a double pointer to an integer pointer that holds the address of `ptr1`.
// - We print the value of `value`, the value pointed to by `ptr1` (dereferencing once), and the value pointed to by `ptr2` (dereferencing twice).