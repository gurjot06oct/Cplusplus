#include <iostream>

// ### `Passsing0d(int *_0d)`

// - This function receives a pointer to a single integer (0D pointer).
// - It iterates over the elements of the array, printing them.
// - However, since it expects a pointer to a single integer, it prints the values as if they were a contiguous sequence of integers.

void Passsing0d(int *_0d)
{
    for (int i = 0; i < 9; ++i)
    {
        std::cout << _0d[i] << " ";
    }
    std::cout << std::endl;
}

// ### `Passsing1d(int (*_1d)[])`

// - This function receives a pointer to an array of integers (1D pointer).
// - It treats the pointer as a pointer to an array of integers and prints each element using array notation.
// - Note that the size of the array doesn't need to be specified in the parameter, but the size is must be known for the context.
// - Inside the function, the elements can accessed using single dereferencing also because `_1d` is a pointer to a 1D array.

void Passsing1d(int (*_1d)[])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            std::cout << (*_1d)[i * 3 + j] << " "; // *(*_1d + i * 3 + j)
        std::cout << std::endl;
    }
}

// ### `Passsing2d(int (*_2d)[][3])`

// - This function receives a pointer to a 2D array of integers with 3 columns (2D pointer).
// - It iterates over the rows and columns of the array, printing each element.
// - The row size needs to be specified in the function parameter because the function expects a pointer to a 2D array where the row size is fixed but the column size can vary.
// - Inside the function, the elements can accessed using double dereferencing also because `_2d` is a pointer to a 2D array.

void Passsing2d(int (*_2d)[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
            std::cout << (*_2d)[i][j] << " "; // *(*(*_2d + i ) + j)
        std::cout << std::endl;
    }
}

int main()
{
    // Define a 2D array of integers
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Passing arr as a 0D Pointer:
    Passsing0d(*arr);

    // Passing arr as a 1D Pointer:
    Passsing1d(arr);

    // Passing arr as a 2D Pointer:
    Passsing2d(&arr);

    return 0;
}
