#include <iostream>

int main()
{
    // Define a 2D array of integers
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // 0D Pointer (ptr):
    // - Refers to a single integer's memory address within the 2D array.
    // - Converted from a 2D pointer using typecasting.
    int *ptr = reinterpret_cast<int *>(&arr);

    // 1D Pointer (ptr1D):
    // - Points to the first row (1D array) within the 2D array.
    // - `arr` and `ptr1D` share the same memory address and frame of reference.
    // int(*ptr1D)[3] = arr;

    // 2D Pointer (ptr2D):
    // - Represents a pointer to the entire 2D array.
    // - `&arr` and `ptr2D` both have the same memory address and frame of reference.
    // int(*ptr2D)[3][3] = &arr;

    // `arr` is a 2D array, representing the base address of the entire array.
    // Each element is accessed based on this base address.

    // `ptr` is a 0D pointer, simply pointing to a memory address without a referential frame.
    // It does not represent the entire array like `arr`.

    // Demonstrate the Difference in Addressing:

    // Accessing the value at ptr + 1 points to the second element of the first row.
    // Incrementing a 0D pointer moves to the next consecutive memory address.
    std::cout << "\nValue at ptr + 1: " << *(ptr + 1) << std::endl; // Outputs: 2

    // However, &arr + 1 returns the same address as &arr[2][2] + 1,
    // which means it points to the memory address right after the last element of the last row.
    // This is outside the array's defined range and may result in garbage values.
    std::cout << "\nValue at &arr + 1: " << *(&arr + 1) << std::endl; // Outputs: Garbage value

    return 0;
}
