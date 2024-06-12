// ### Array of Pointers to Integers

#include <iostream>

int main()
{
    const int SIZE = 5;

    // Declare an array of integer pointers
    int *arr[SIZE];
    // or
    // Dynamically allocate an array of integer pointers
    // int** arr = new int*[SIZE];

    // Allocate memory and assign values
    for (int i = 0; i < SIZE; ++i)
    {
        arr[i] = new int; // Allocate memory for each integer
        *arr[i] = i * 10; // Assign a value to the allocated memory
    }

    // Display the values
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << "Value at arr[" << i << "] = " << *arr[i] << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < SIZE; ++i)
    {
        delete arr[i]; // Free the memory allocated
    }

    // Free the memory allocated for the array of pointers if dynamically allocated
    // delete[] arr;
    return 0;
}

// ### Explanation

// 1. **Declaration**: `int* arr[SIZE];` declares an array named `arr` of `SIZE` elements where each element is a pointer to an integer.
// 2. **Memory Allocation**: Using a loop, `new int` is called to allocate memory for each element in the array. `*arr[i] = i * 10;` assigns values to the allocated memory.
// 3. **Display Values**: Another loop is used to display the values stored at each pointer in the array.
// 4. **Memory Deallocation**: It's crucial to free the allocated memory using `delete` to prevent memory leaks.