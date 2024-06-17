### Void Pointers in Dynamic Memory Allocation

Void pointers (`void*`) in C++ play a crucial role in managing memory dynamically, especially in scenarios where the exact data type is not known upfront or varies during program execution. This demonstration explores how void pointers are used in conjunction with dynamic memory allocation functions (`malloc`, `realloc`, `free` in C, and `new`, `delete` in C++) to handle memory effectively.

#### Dynamic Memory Allocation

Dynamic memory allocation allows programs to request memory from the operating system at runtime, rather than statically allocating memory at compile time. This flexibility is essential for applications where the memory requirements may vary or aren't known in advance.

#### Using Void Pointers in `malloc` and `free`

Void pointers serve as a generic pointer type that can hold the address of any data type. They are particularly useful when dealing with memory allocated dynamically, where the type of data is determined at runtime.

Let's illustrate how void pointers can be employed with `malloc` and `free` to allocate and deallocate memory dynamically:

```cpp
#include <iostream>
#include <cstdlib> // For malloc and free

int main() {
    void *voidPtr;
    voidPtr = malloc(5 * sizeof(int));

    if (voidPtr == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }
    int *intPtr = static_cast<int *>(voidPtr);

    for (int i = 0; i < 5; ++i) {
        intPtr[i] = i + 1;
    }

    std::cout << "Values in dynamically allocated array:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << intPtr[i] << " ";
    }
    std::cout << std::endl;

    free(voidPtr);

    return 0;
}
```

1. **Memory Allocation**:

   - `voidPtr` is declared as a void pointer.
   - `malloc(5 * sizeof(int))` allocates memory for an array of 5 integers. The size of memory allocated is calculated as `5 * sizeof(int)` bytes.
   - Error handling checks if memory allocation was successful.

2. **Typecasting and Initialization**:

   - `voidPtr` is typecasted to `int*` (`intPtr`) to access and manipulate the allocated memory as an array of integers.
   - Values are initialized in the dynamically allocated integer array using `intPtr`.

3. **Accessing and Printing Values**:

   - Values stored in the dynamically allocated array are accessed and printed using `intPtr`.

4. **Memory Deallocation**:
   - `free(voidPtr)` deallocates the dynamically allocated memory once it is no longer needed.
