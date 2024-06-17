## Passing Arrays as Function Parameters Using Pointers

### Function Prototypes:

#### `void Passsing0d(int *ptr_to_single_int)`

- This function prototype accepts a pointer to a single integer (0D pointer).
- It iterates over the elements of the array, printing them sequentially.
- The parameter `ptr_to_single_int` allows accessing the array elements as if they were a continuous sequence of integers.

#### `void Passsing1d(int (*ptr_to_array)[3])`

- This function prototype takes a pointer to an array of integers (1D pointer).
- It treats `ptr_to_array` as a pointer to an array and prints each element using array notation.
- The size of the array (3 in this case) is implied by the context and known to the function.
- Elements are accessed using single dereferencing because `ptr_to_array` points directly to the array.

#### `void Passsing2d(int (*ptr_to_2d_array)[3][3])`

- This function prototype receives a pointer to a 2D array of integers with 3 columns (2D pointer).
- It iterates over the rows and columns of the array, printing each element.
- The row size (3) must be specified in the function parameter because `ptr_to_2d_array` points to a 2D array where the row size is fixed but the column size can vary.
- Elements are accessed using double dereferencing because `ptr_to_2d_array` is a pointer to a 2D array.

### Example Usage:

#### Define a 2D array of integers

```cpp
int arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

#### Passing `arr` as a 0D Pointer:

```cpp
Passsing0d(*arr);
```

#### Passing `arr` as a 1D Pointer:

```cpp
Passsing1d(arr);
```

#### Passing `arr` as a 2D Pointer:

```cpp
Passsing2d(&arr);
```
