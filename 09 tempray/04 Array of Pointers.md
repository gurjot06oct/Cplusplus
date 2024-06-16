## Arrays of Pointers in C++

### Method 1: Declare an Array of Integer Pointers

```cpp
const int SIZE = 5;

int *arr[SIZE];
```

Here, `int *arr[SIZE];` declares an array `arr` of size `SIZE`, where each element `arr[i]` is a pointer to an integer (`int*`).

### Method 2: Dynamically Allocate an Array of Pointers

```cpp
int** arr = new int*[SIZE];
```

Alternatively, `int** arr = new int*[SIZE];` dynamically allocates an array `arr` of `SIZE` elements, where each element is a pointer to an integer.

### Memory Allocation and Assign Values

```cpp
for (int i = 0; i < SIZE; ++i) {
    arr[i] = new int;
    *arr[i] = i * 10;
}
```

Here, each pointer is then initialized with dynamically allocated memory to store an integer, and a value (multiplied by 10) is assigned to each allocated memory location.

### Displaying Values

```cpp
for (int i = 0; i < SIZE; ++i) {
    std::cout << "Value at arr[" << i << "] = " << *arr[i] << std::endl;
}
```

This loop iterates through each element of `arr`, printing the value stored at each pointer in the array `arr`.

### Deallocating Memory for Each Integer

```cpp
for (int i = 0; i < SIZE; ++i)
    delete arr[i];
```

In this loop, `delete arr[i];` is used to free the dynamically allocated memory for each integer that `arr[i]` points to.For each iteration:

- `arr[i]` accesses the pointer to an integer at index `i` in the array `arr`.
- `delete arr[i];` frees the memory allocated for the integer pointed to by `arr[i]`.

### Freeing the Memory Allocated for the Array of Pointers

```cpp
delete[] arr;
```

After deallocating memory for each individual integer, `delete[] arr;` is used to free the memory allocated for the array `arr` itself. Here’s the breakdown:

1. **`delete[]` Operator**: When `arr` is dynamically allocated as an array of pointers using `new int*[SIZE];`, `delete[] arr;` is used to free this memory.

2. **Array Deletion**: `delete[] arr;` ensures that the entire array `arr`, including all its elements (which are pointers to integers), is deallocated.
