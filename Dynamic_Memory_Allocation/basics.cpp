// Dynamic memory allocation in C++ allows you to allocate memory at runtime, which means you can create data structures whose size is determined during program execution. This is useful when you don't know the size of the data in advance or when the size may change during the execution of the program.

// let's talk about the old C-style memory allocation functions: `malloc`, `realloc`, `free`, and `calloc`.

#include <iostream>
#include <cstdlib> // for malloc, realloc, free, and calloc

int main()
{
    // 1. `malloc`: It stands for "memory allocation". It is used to allocate a block of memory of a specified size. It returns a void pointer (void*) to the beginning of the block of memory, initialized to 0.
    int *ptr_malloc = (int *)malloc(sizeof(int));
    if (ptr_malloc == nullptr)
    {
        std::cerr << "Memory allocation failed!" << std::endl;
        return 1;
    }
    *ptr_malloc = 10; // Store value 10 in the allocated memory

    // 2. `realloc`: It is used to resize a previously allocated block of memory. It takes two arguments: a pointer to the previously allocated memory block and the new size. If the new size is larger, it may move the existing data to a new location. If the new size is smaller, it may truncate the existing data.
    int *ptr_realloc = (int *)realloc(ptr_malloc, 2 * sizeof(int));
    if (ptr_realloc == nullptr)
    {
        std::cerr << "Memory reallocation failed!" << std::endl;
        free(ptr_malloc); // Free the previously allocated memory
        return 1;
    }
    // Note: ptr_malloc may no longer be valid after realloc

    ptr_realloc[1] = 20; // Store value 20 in the newly allocated memory

    // 3. `free`: It is used to deallocate memory previously allocated by `malloc`, `calloc`, or `realloc`.
    free(ptr_realloc);

    // 4. calloc: Allocate memory for an array of integers and initialize it to zero
    int *ptr_calloc = (int *)calloc(5, sizeof(int));
    if (ptr_calloc == nullptr)
    {
        std::cerr << "Memory allocation (calloc) failed!" << std::endl;
        return 1;
    }
    // ptr_calloc points to an array of 5 integers, all initialized to 0

    // 4. `calloc`: It is used to allocate a block of memory for an array of elements, each of which has the same size. It initializes the allocated memory to zero.
    std::cout << "Values stored in the array allocated by calloc:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << ptr_calloc[i] << " ";
    }
    std::cout << std::endl;

    // Deallocate the memory allocated by calloc
    free(ptr_calloc);

    return 0;
}
