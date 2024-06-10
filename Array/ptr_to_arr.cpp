#include <iostream>

int main()
{
    // Declare and initialize an array of integers
    int arr[5] = {1, 2, 3, 4, 5};

    // Declare a pointer to an array of integers and assign the address of the array to it
    int(*ptr)[5] = &arr;

    // Also, Here's another method to define a pointer that directly points to the first element of the array
    int *ptr_ = arr;

    // Print the original array
    std::cout << "Original Array:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Now, let's apply pointer arithmetic to go out of range
    // Incrementing the pointer to go beyond the end of the array
    std::cout << "Elements beyond the original array:" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << *(ptr_ + i) << " "; // Dereference the pointer to access the elements
    }
    // Values out of range are garbage values.
    std::cout << std::endl;

    return 0;
}
