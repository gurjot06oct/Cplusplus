### Pointer Indexing

In C and C++, when `ptr` is of type `T*`, the expressions `*(ptr + i)` and `ptr[i]` are used interchangeably to access elements in arrays or memory blocks pointed to by `ptr`.

#### \*(ptr + i) and ptr[i]

1. **(ptr + i)**

   - This syntax dereferences the pointer `ptr` offset by `i` positions.
   - It accesses the value stored at the memory location calculated by adding `i` times the size of `T` (`sizeof(T)`) to the base address `ptr`.
   - Example:

     ```cpp
     T arr[] = {value1, value2, value3};
     T* ptr = &arr[0];

     // Using *(ptr + i)
     T element1 = *(ptr + 1); // Accesses the second element
     ```

2. **ptr[i]**

   - This syntax is shorthand for `*(ptr + i)`.
   - It accesses the value at the `i`-th index from the base address `ptr`.
   - Example:

     ```cpp
     // Using ptr[i]
     T element2 = ptr[1]; // Accesses the second element
     ```

### Key Points

- When `ptr` is of type `T*`, both `*(ptr + i)` and `ptr[i]` access the `i`-th element from the base address `ptr`.
- Pointer arithmetic (`*(ptr + i)` or `ptr + i`) automatically scales by the size of `T` (`sizeof(T)`), facilitating easy traversal and manipulation of arrays or dynamically allocated memory blocks.
- Understanding and using pointer indexing with `T*` is fundamental for efficient data access and manipulation in C and C++.
