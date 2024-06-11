// Array pointers in C++ can be a bit tricky due to the syntax and the different ways pointers can be used.
// Let's break down the types of array pointers:

// 0D Pointer (int*):
// - A pointer to a single integer.
// - Frame of reference: a single integer (int).

// 1D Pointer (int (*)[n]):
// - A pointer to an array of n integers.
// - Frame of reference: a 1D array of n integers (int[n]).

// 2D Pointer (int (*)[n][m]):
// - A pointer to a 2D array of n arrays, each containing m integers.
// - Frame of reference: a 2D array of nxm integers (int[n][m]).

#include <iostream>

int main()
{
    int arr2d[5][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}};

    // A 0D pointer is a pointer to a single integer
    int *ptrToInt = *arr2d; // or int *ptrToInt = arr2d[0];
    // Here, `ptrToInt` points to the first element of the 2D array `arr2d`. It is a 0D pointer.

    // A 1D pointer is a pointer to an array of integers
    int(*ptrTo1DArray)[10] = arr2d;
    // Here, `ptrTo1DArray` points to the first 1D array (which has 10 integers) within the 2D array `arr2d`. It is a 1D pointer.

    // A 2D pointer is a pointer to an array of arrays
    int(*ptrTo2DArray)[5][10] = &arr2d;
    // Here, `ptrTo2DArray` points to the entire 2D array of 5x10 integers. It is a 2D pointer.

    // - `int*`: A pointer to an integer.
    // - `int (*)[]`: A pointer to an array of integers.
    // - `int (*)[][]`: A pointer to a 2D array or array of arrays.

    // Converting pointers to arrays (e.g., int (*)[] and int (*)[][]) to int * can be achieved through typecasting.
    // - `reinterpret_cast<int *>(p)` is used to cast the pointer `p` of type `int (*)[]` or `int (*)[][]` to `int *`.
    // - Alternatively, you can use C-style casts like `(int *) p` which achieves the same result.

    // Accessing elements using the 0D pointer using array indexing method
    for (int i = 0; i < 50; ++i)
    {
        std::cout << ptrToInt[i] << " ";
    }

    return 0;
}
