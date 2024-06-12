### Pointer vs Array in 2D Array

In a 2D array, pointers and arrays behave differently due to the multi-dimensional nature of the array.

#### Example:

```cpp
int arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};

int *ptr = reinterpret_cast<int *>(&arr);
```

### Pointer Types Explained

- **0D Pointer (`ptr`)**:
  - Refers to a single integer's memory address within the 2D array.
  - Converted from a 2D pointer using typecasting.

```cpp
int *ptr = reinterpret_cast<int *>(&arr);
```

- **1D Pointer (`ptr1D`)** (commented out):
  - Points to the first row (1D array) within the 2D array.
  - `arr` and `ptr1D` share the same memory address and frame of reference.

```cpp
int(*ptr1D)[3] = arr;
```

- **2D Pointer (`ptr2D`)** (commented out):
  - Represents a pointer to the entire 2D array.
  - `&arr` and `ptr2D` both have the same memory address and frame of reference.

```cpp
int(*ptr2D)[3][3] = &arr;
```

### Difference in Addressing

- **Accessing Values with `ptr`**:
  - `*(ptr + 1)` fetches the value at the next memory address, giving the second element of the first row (which is 2).

```cpp
std::cout << "\nValue at ptr + 1: " << *(ptr + 1) << std::endl; // Outputs: 2
```

- **Accessing Values with `ptr2D`**:
  - `*(&arr + 1)` points to a memory location beyond the array's bounds, leading to unpredictable results.

```cpp
std::cout << "\nValue at &arr + 1: " << *(&arr + 1) << std::endl; // Outputs: Garbage value
```
