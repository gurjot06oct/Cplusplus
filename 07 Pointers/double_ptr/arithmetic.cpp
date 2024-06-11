#include <iostream>

int main()
{
    int value1 = 5;
    int *ptr1 = &value1;     // Pointer to value1
    int **doublePtr = &ptr1; // Double pointer to ptr1

    std::cout << "Address of ptr1: " << (unsigned long)doublePtr << std::endl;
    // Pointer arithmetic: Adding 1 to the double pointer adds 8 bytes to address as sizeof(pointer) = ( 8 bytes (64 bit systems)/ 4 bytes (32 bit systems) )
    doublePtr++;

    // Printing the addresses after pointer arithmetic
    std::cout << "Address of ptr1 after arithmetic: " << (unsigned long)doublePtr << std::endl;

    return 0;
}
