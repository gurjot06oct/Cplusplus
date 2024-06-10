#include <iostream>

// In C++, an array is a collection of elements of the same data type stored in contiguous memory locations. Arrays provide a way to store multiple values of the same type under a single identifier.

int main()
{
    // Syntax
    // type arrayName[arraySize];

    // Declaration of an integer array with 5 elements
    int numbers[5];

    // Declaration and Initialization of an array
    // The size can be omitted if you use an initializer list
    int initializedNumbers[] = {1, 2, 3, 4, 5};

    // Accessing Elements
    int firstElement = initializedNumbers[0]; // Accessing the first element (index 0)
    int thirdElement = initializedNumbers[2]; // Accessing the third element (index 2)

    // Calculate the size of the array
    // sizeof(initializedNumbers) gives the total size in bytes
    // sizeof(initializedNumbers[0]) gives the size of one element in bytes
    int arraySize = sizeof(initializedNumbers) / sizeof(initializedNumbers[0]);

    // Output the results
    std::cout << "First element: " << firstElement << std::endl;
    std::cout << "Third element: " << thirdElement << std::endl;
    std::cout << "Size of the array: " << arraySize << std::endl;

    return 0;
}
