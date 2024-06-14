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
