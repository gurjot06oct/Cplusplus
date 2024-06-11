#include <iostream>

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    // ptr vs arr
    // In a 1D array, both ptr and arr are similar because both are in same frame of reference
    std::cout << "Memory addresses after incrementing by 1:" << std::endl;
    std::cout << ptr + 1 << std::endl;
    std::cout << arr + 1 << std::endl;
    std::cout << std::endl;

    // &ptr vs &arr
    // Here's an explanation of why they are different
    std::cout << "Memory addresses of pointers and arrays:" << std::endl;
    std::cout << "Address of ptr: " << (unsigned long)&ptr << std::endl;
    std::cout << "Address of ptr + 1: " << (unsigned long)(&ptr + 1) << std::endl;
    std::cout << "Address of arr: " << (unsigned long)&arr << std::endl;
    std::cout << "Address of arr + 1: " << (unsigned long)(&arr + 1) << std::endl;
    std::cout << std::endl;

    // Explanation of the difference in memory addresses
    // The '&' operator shifts the frame of reference of ptr to a pointer,
    // so when incremented by 1, it changes by 8 bytes.
    // The '&' operator shifts the frame of reference of arr to the size of the array, which is 5 integers in this case.
    // So when incremented by 1, it changes by 20 bytes.

    // For more Detailed Explanation, see Box Demonstration
    return 0;
}
