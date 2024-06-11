// In C++, converting pointers to arrays (e.g., `int (*)[]` and `int (*)[][]`) to `int *` can be achieved through typecasting. Here's how you can do it:

#include <iostream>

int main()
{

    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // ### 1. Converting `int (*)[]` to `int *`
    // An `int (*)[]` is a pointer to an array of `int`.
    int(*ptrTo1DArray)[4] = arr;

    // Convert int (*)[] to int *
    int *ptrToInt = reinterpret_cast<int *>(ptrTo1DArray);

    // ### 2. Converting `int (*)[][]` to `int *`
    // An `int (*)[][]` is a pointer to a 2D array of `int`.
    int(*ptrTo2DArray)[3][4] = &arr;

    // Convert int (*)[][] to int *
    ptrToInt = reinterpret_cast<int *>(ptrTo2DArray);

    // Alternatively, you can use a C-style cast for both 1D & 2D
    // int *ptrToInt = (int *) p;

    return 0;
}

// ### Explanation
// - `reinterpret_cast<int *>(p)` is used to cast the pointer `p` of type `int (*)[]` or `int (*)[][]` to `int *`.
// - Alternatively, you can use C-style casts like `(int *) p` which achieves the same result.
// - The dereferenced pointer allows you to access the array elements using `int *`.