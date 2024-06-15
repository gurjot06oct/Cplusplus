## Dimensional Pointers (Pointer to an Array) in C++

Understanding dimensional pointers in C++ involves grasping pointers that reference arrays of different dimensions. Let's explore the types of dimensional pointers and how they are utilized in practice:

### 0D Pointer (int\*)

A 0D pointer is a pointer to a single integer within an array.

```cpp
int *ptrToInt = *arr2d; // or int *ptrToInt = arr2d[0];
```

- **Explanation**: `ptrToInt` points to the first element of the 2D array `arr2d`. It provides access to individual integers within the array.

### 1D Pointer (int (\*)[n])

A 1D pointer is a pointer to an array of n integers.

```cpp
int (*ptrTo1DArray)[10] = arr2d;
```

- **Explanation**: `ptrTo1DArray` points to the first 1D array (which contains 10 integers) within the 2D array `arr2d`. It allows traversal through rows of the 2D array.

### 2D Pointer (int (\*)[n][m])

A 2D pointer is a pointer to a 2D array of n arrays, each containing m integers.

```cpp
int (*ptrTo2DArray)[5][10] = &arr2d;
```

- **Explanation**: `ptrTo2DArray` points to the entire 2D array `arr2d` of size 5x10 integers. It serves as a pointer to the whole matrix.

### Conversion and Typecasting

To convert pointers to arrays (e.g., `int (*)[]` and `int (*)[][]`) to `int*`, typecasting is used:

- `reinterpret_cast<int *>(p)` or `(int *) p` can be used to cast pointers `p` of type `int (*)[]` or `int (*)[][]` to `int *`.

#### Example Usage

```cpp
#include <iostream>

int main()
{
    int arr2d[5][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}};

    int *ptrToInt = *arr2d; // 0D pointer to the first element
    int (*ptrTo1DArray)[10] = arr2d; // 1D pointer to the first row
    int (*ptrTo2DArray)[5][10] = &arr2d; // 2D pointer to the entire array

    // Accessing elements using the 0D pointer
    for (int i = 0; i < 50; ++i)
    {
        std::cout << ptrToInt[i] << " ";
    }

    return 0;
}
```

- **0D Pointer**: Points to individual elements.
- **1D Pointer**: Points to rows or single arrays.
- **2D Pointer**: Points to the entire 2D array.

Understanding these distinctions helps in effectively manipulating multi-dimensional arrays using pointers in C++. Each type of dimensional pointer provides a unique perspective on array traversal and memory access patterns, contributing to versatile programming techniques in C++.

### Passing Arrays as Function Parameters Using Pointers

#### Function Prototypes:

##### `void Passsing0d(int *ptr_to_single_int)`

- This function prototype accepts a pointer to a single integer (0D pointer).
- It iterates over the elements of the array, printing them sequentially.
- The parameter `ptr_to_single_int` allows accessing the array elements as if they were a continuous sequence of integers.

##### `void Passsing1d(int (*ptr_to_array)[3])`

- This function prototype takes a pointer to an array of integers (1D pointer).
- It treats `ptr_to_array` as a pointer to an array and prints each element using array notation.
- The size of the array (3 in this case) is implied by the context and known to the function.
- Elements are accessed using single dereferencing because `ptr_to_array` points directly to the array.

#### `void Passsing2d(int (*ptr_to_2d_array)[3][3])`

- This function prototype receives a pointer to a 2D array of integers with 3 columns (2D pointer).
- It iterates over the rows and columns of the array, printing each element.
- The row size (3) must be specified in the function parameter because `ptr_to_2d_array` points to a 2D array where the row size is fixed but the column size can vary.
- Elements are accessed using double dereferencing because `ptr_to_2d_array` is a pointer to a 2D array.

#### Example Usage:

##### Define a 2D array of integers

```cpp
int arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

##### Passing `arr` as a 0D Pointer:

```cpp
Passsing0d(*arr);
```

##### Passing `arr` as a 1D Pointer:

```cpp
Passsing1d(arr);
```

##### Passing `arr` as a 2D Pointer:

```cpp
Passsing2d(&arr);
```
