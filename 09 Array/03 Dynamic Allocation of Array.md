### Dynamic Allocation of Array

#### Without Initialization

If you want to allocate an array without initializing its elements explicitly, you can still use `new`:

```cpp
// Example: Dynamically allocate an array of integers without initialization
int size = 5;
int* arr = new int[size];

// Access elements of the array
for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";  // Note: elements are uninitialized
}

// Don't forget to free memory after use
delete[] arr;
```

- `new int[size]` allocates an array of `size` integers without initializing them.
- The values in `arr` are not initialized, so accessing them without initialization leads to undefined behavior unless each element is explicitly initialized later.

### With Initialization

When you want to dynamically allocate an array and initialize its elements, you can use uniform initialization along with `new`. Here’s how you do it:

```cpp
// Example: Dynamically allocate an array of integers with initialization
int size = 5;
int* arr = new int[size] {1, 2, 3, 4, 5};

// Access elements of the array
for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
}

// Don't forget to free memory after use
delete[] arr;
```

In this example:

- `new int[size]` dynamically allocates an array of `size` integers.
- `{1, 2, 3, 4, 5}` initializes the elements of the array with the specified values.
- `delete[] arr` frees the memory allocated for the array.

### Array Allocation and Deallocation

```cpp
// Dynamically allocate memory for an array of objects
MyClass *arr = new MyClass[5];

// Deallocate memory
delete[] arr;
```

Similarly, when dynamically allocating memory for an array of objects using `new[]`, the constructors of the individual objects are called. Upon deallocation using `delete[]`, the destructors are invoked for each object in the array.

### Memory Management Best Practices

1. **Single Object vs. Array Allocation**:

   - Use `delete` for single objects allocated with `new`.
   - Use `delete[]` for arrays of objects allocated with `new[]`.

2. **Type Safety**:
   - Unlike C-style functions, `new` and `delete` operators do not require explicit type casting.

Understanding and mastering these concepts ensures efficient memory management in C++ programs, contributing to their flexibility and reliability.

## Dynamic Memory Allocation for a 2D Array

### User Input for Dimensions

```cpp
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
```

### Memory Allocation and Initialization

```cpp
    int **array = new int *[rows];
    for (int i = 0; i < rows; ++i)
        array[i] = new int[cols];

    // Set values to i * j
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            array[i][j] = i * j;
```

### Printing the Array

```cpp
    std::cout << "The 2D array is:" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            std::cout << array[i][j] << " ";
        std::cout << std::endl;
    }
```

### Memory Deallocation

```cpp
    // Deallocate memory
    for (int i = 0; i < rows; ++i)
        delete[] array[i];
    delete[] array;
```
