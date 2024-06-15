## Pointer vs Array

### In 1D Array

In a 1D array, pointers and arrays behave similarly because they both reference memory locations within the same frame of reference.

#### Example:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;

std::cout << "Memory addresses after incrementing by 1:" << std::endl;
std::cout << ptr + 1 << std::endl; // Points to the memory location of the second element in the array.
std::cout << arr + 1 << std::endl; // Points to the memory location of the second element in the array.
std::cout << std::endl;
```

#### Difference

When it comes to pointer and array themselves, there's a difference.

#### Example:

```cpp
std::cout << "Memory addresses of pointers and arrays:" << std::endl;
std::cout << "Address of &ptr: " << (unsigned long)&ptr << std::endl;
std::cout << "Address of &ptr + 1: " << (unsigned long)(&ptr + 1) << std::endl;
std::cout << "Address of &arr: " << (unsigned long)&arr << std::endl;
std::cout << "Address of &arr + 1: " << (unsigned long)(&arr + 1) << std::endl;
std::cout << std::endl;
```

#### Explanation

- The `&` operator gives the memory address of a variable.
- When applied to a pointer like `&ptr`, it gives the address of the pointer itself.
- When applied to an array like `&arr`, it gives the address of the entire array.
- Incrementing the pointer (`&ptr + 1`) increases its address by the size of the pointer itself.
- Incrementing the array (`&arr + 1`) increases its address by the size of the entire array.

### In 2D Array

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
