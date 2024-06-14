## Dynamic Memory Allocation

Dynamic memory allocation in C++ provides the flexibility to allocate memory at runtime. This feature is particularly valuable when dealing with data structures whose size is unknown beforehand or may vary during program execution. In this demonstration, we'll delve into the usage of the traditional C-style memory allocation functions: `malloc`, `realloc`, `free`, and `calloc`.

### `malloc`: Memory Allocation

The `malloc` function, short for "memory allocation," reserves a block of memory of a specified size. It returns a void pointer (`void*`) pointing to the beginning of the allocated memory block, initialized to zero if no other value is specified. Here's how it's used:

```cpp
int *ptr_malloc = (int *)malloc(sizeof(int));
if (ptr_malloc == nullptr)
{
    std::cerr << "Memory allocation failed!" << std::endl;
    return 1;
}
```

In this example, we allocate memory to hold an integer value. If `malloc` fails to allocate memory, it returns a null pointer, signaling allocation failure.

### `realloc`: Resizing Memory

The `realloc` function is used to resize a previously allocated block of memory. It takes two arguments: a pointer to the previously allocated memory block and the new size. If the new size is larger, `realloc` may move the existing data to a new location. If the new size is smaller, it may truncate the existing data. Here's an example:

```cpp
int *ptr_realloc = (int *)realloc(ptr_malloc, 2 * sizeof(int));
if (ptr_realloc == nullptr)
{
    std::cerr << "Memory reallocation failed!" << std::endl;
    free(ptr_malloc); // Free the previously allocated memory
    return 1;
}
```

### `free`: Deallocating Memory

The `free` function is used to deallocate memory previously allocated by `malloc`, `calloc`, or `realloc`. It releases the memory back to the system for reuse. Here's how it's used:

```cpp
free(ptr_realloc);
```

### `calloc`: Allocating and Initializing Memory

The `calloc` function allocates memory for an array of elements, initializing them to zero. It takes two arguments: the number of elements to allocate and the size of each element. Here's an example:

```cpp
int *ptr_calloc = (int *)calloc(5, sizeof(int));
if (ptr_calloc == nullptr)
{
    std::cerr << "Memory allocation (calloc) failed!" << std::endl;
    return 1;
}
```

In this example, `ptr_calloc` points to an array of 5 integers, all initialized to zero.
