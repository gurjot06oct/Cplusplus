#include <iostream>

int main()
{
    // The variable arr is a 2D array, and it uses a referential frame.
    // This means that arr represents the base address of the entire array
    // and its elements are accessed based on this base address.

    // On the other hand, the pointer ptr is a normal pointer, and it doesn't
    // have the concept of referential frame. It simply points to a memory address.

    // When we use &arr, it gives the address of the entire array (referential frame).
    // Adding 1 to this address would move to the next memory block after the array.

    // On the other hand, ptr + 1 moves ptr to the next consecutive memory address,
    // which is the address of the next integer element, because ptr is just a pointer.

    // int(*ptr)[3][3] = &arr + 1;
    // Therefore, *(&arr + 1) and *(ptr + 1) both give the same memory address,
    // but they interpret it differently:
    // *(&arr + 1) considers the referential frame and gives the value at that address
    // *(ptr + 1) simply goes to the next integer value in memory.

    // Define a 2D array of integers
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};

    // Define a pointer to an integer
    int *ptr = (int *)(&arr + 1);

    // Display the elements of the array using the pointer
    std::cout << "Using Pointer:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << *(ptr + i * 3 + j) << " ";
        }
        std::cout << std::endl;
    }

    // Display the elements of the array using the array notation
    std::cout << "\nUsing Array Notation:" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Demonstrate the difference in addressing

    // Pointer arithmetic: ptr + 1 moves to the previous consecutive integer value
    // Here, it's the value '9' in the array
    std::cout << "\nValue at ptr + 1: " << *(ptr - 1) << std::endl;

    return 0;
}
