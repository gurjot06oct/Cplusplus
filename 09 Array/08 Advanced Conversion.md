## Conversions between `T(*)[]`, `T(*)[][]` and `T*`

### Description:

In C++, pointers and arrays can be used interchangeably in many contexts, but sometimes, we need to convert between different types of pointers to work with multi-dimensional arrays. Here is how to convert between zero-dimensional, one-dimensional, and two-dimensional pointers using `reinterpret_cast`.

### Conversion Theory:

In C++, pointers can be cast to different pointer types to reinterpret the memory they point to. This is particularly useful when dealing with arrays of different dimensions. The process involves the following:

1. **Pointer Types:**

   - **0D Pointer**: Points to individual elements.
   - **1D Pointer**: Points to rows or single arrays.
   - **2D Pointer**: Points to the entire 2D array.

2. **Memory Layout:**

   - **1D Array**: A contiguous block of memory. They return a zero-dimensional pointer.
   - **2D Array**: Interpreted as an array of arrays. They return a one-dimensional pointer.
   - **3D Array**: Interpreted as an array of arrays of arrays. They return a two-dimensional pointer.

3. **Pointer Casting:**

   - **`reinterpret_cast<type>`**: Changes the type of the pointer without modifying the actual data in memory.
   - Allows for reinterpretation of the memory layout, treating a block of memory as a different type or structure.

4. **Index Calculation:**
   - Accessing elements in multi-dimensional arrays involves calculating the offset from the base pointer.
   - **1D Array**: `int0DPtr[i]` accesses the `i`th element.
   - **2D Array**: `int1DPtr[i][j]` accesses the `i`th row and `j`th column.
   - **3D Array**: `int2DPtr[i][j][k]` accesses the `i`th "2D slice", `j`th row, and `k`th column.

#### Conversions:

1. **From 0D to 1D and 2D:**

   ```cpp
   std::cout << *int_0d_to_1d[1] << std::endl;  // 50
   std::cout << **int_0d_to_2d[1] << std::endl; // 0
   ```

   - **`*int_0d_to_1d[1]`**:
     - The original pointer `int0DPtr` points to the first element a one-dimensional array of integers: `[0, 10, 20, 30, 40, 50, 60, 70, 80, 90]`.
     - When cast to `int (*int_0d_to_1d)[5]`, it treats the same memory as a 2D array with rows of 5 elements each.
     - So, `int_0d_to_1d[1]` points to the first element of the second row: `[50, 60, 70, 80, 90]`.
     - Dereferencing `*int_0d_to_1d[1]` gives the first element of the second row: `50`.
   - **`**int_0d_to_2d[1]`\*\*:
     - The same memory is interpreted as a 3D array with dimensions `[10][5]`.
     - `int_0d_to_2d[1]` points to the second "2D slice", which starts at `int0DPtr + 50` (since each 2D slice would logically occupy `50` elements in this context).
     - `*int_0d_to_2d[1]` points to the first element of this "2D slice", which is `0` (corresponding to `int0DPtr[50]`).

2. **From 1D to 0D and 2D:**

   ```cpp
   std::cout << int_1d_to_0d[10] << std::endl; // 10
   std::cout << *int_1d_to_2d[1] << std::endl; // 10
   ```

   - **`int_1d_to_0d[10]`**:
     - The `int1DPtr` points to a 2D array: `[ [0, 10, 20, 30, 40, 50, 60, 70, 80, 90], ... ]`.
     - Casting to `int *int_1d_to_0d` flattens this 2D array into a 1D array.
     - Accessing the element at index `10` in this flattened array gives the first element of the second row: `10`.
   - **`*int_1d_to_2d[1]`**:
     - `int1DPtr` interpreted as `int (*int_1d_to_2d)[10]` is essentially the same 2D array.
     - `int_1d_to_2d[1]` points to the second row, and dereferencing gives the first element of the second row: `10`.

3. **From 2D to 0D and 1D:**
   ```cpp
   std::cout << int_2d_to_0d[110] << std::endl; // 20
   std::cout << *int_2d_to_1d[1] << std::endl;  // 10
   ```
   - **`int_2d_to_0d[110]`**:
     - The `int2DPtr` points to a 3D array: `[[[0, 10, 20, ..., 90], [10, 20, 30, ..., 100], ... ], ...]`.
     - Casting to `int *int_2d_to_0d` flattens this 3D array into a 1D array.
     - Accessing the element at index `110` gives the value `20` (calculated as part of initialization).
   - **`*int_2d_to_1d[1]`**:
     - `int2DPtr` interpreted as `int (*int_2d_to_1d)[10]` sees each "2D slice" as a row.
     - `int_2d_to_1d[1]` points to the first row of the second "2D slice".
     - Dereferencing gives the first element of this row: `10`.

### Usage:

- **When manipulating memory blocks that are logically structured as arrays:** This technique is useful when working with large blocks of memory where the logical structure needs to be changed dynamically.
- **Optimizations or memory management scenarios:** It can be particularly useful in performance-critical applications where arrays are accessed frequently and the memory layout needs to be optimized for cache usage or other hardware considerations.
