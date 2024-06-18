## Dimensional Pointers in C++

In C++, dimensional pointers refer to pointers that point to arrays of different dimensions. This concept is often used when dealing with arrays, matrices, and multi-dimensional data structures. Let's delve into each type of dimensional pointer and how they are utilized, particularly focusing on dynamic allocation of memory.

### Types:

- **0D Pointer (`T*`)**:
  - Points to individual elements or single elements within 1D arrays (`int[]`).
- **1D Pointer (`T (*)[]`)**:
  - Points to entire 1D array within 2D arrays (`int[][]`).
- **2D Pointer (`T (*)[][]`)**:
  - Points to entire 2D array within 3D arrays (`int[][][]`).
- **ND Pointer (`T (*)[][][]...[]`)**:
  - Points to entire ND array within (N+1)D arrays (`int[][][]....[]`).

### Dimensional Pointers Types

#### 1. 0D Pointer (`T*`) to 1D Dynamic Array (`int[]`)

- A 0D pointer (`T*`) dynamically allocates memory for a single element of type `T` (`int` in this case).
- Memory for `int[]` is allocated in a contiguous block, ensuring that all elements (`int`) are stored sequentially in memory.
- Example:
  ```cpp
  int* ptr = new int; // new int[1]
  ```
  This allocates memory for a single `int` element, ensuring it is stored contiguously.

#### 2. 1D Pointer (`T (*)[]`) to 2D Dynamic Array (`int[][]`)

- A 1D pointer (`T (*)[]`) points to rows or single arrays within a dynamically allocated 2D array (`int[][]`).
- Memory for `int[][]` is allocated such that each row (`int[]`) is allocated independently but the array of pointers (`T (*)[]`) to these rows is stored contiguously.
- Example:
  ```cpp
  int (*ptr)[cols] = new int[rows][cols];
  ```
  Here, `ptr` is a pointer to an array of `cols` integers within an array of `rows` such arrays, ensuring each row is contiguous in memory.

#### 3. 2D Pointer (`T (*)[][]`) to 3D Dynamic Array (`int[][][]`)

- A 2D pointer (`T (*)[][]`) points to entire 2D arrays (`int[][]`) within a dynamically allocated 3D array (`int[][][]`).
- Memory for `int[][][]` is allocated in a way that each 2D slice (`int[][]`) maintains its own contiguous memory layout, and the array of pointers (`T (*)[][]`) to these 2D slices is stored contiguously.
- Example:
  ```cpp
  int (*ptr)[rows][cols] = new int[layers][rows][cols];
  ```
  In this case, `ptr` is a pointer to a 2D array (`rows` rows and `cols` columns) within an array of `layers` such 2D arrays, ensuring each 2D slice is contiguous.

### Pointer Decay and Dimensionality

### Static Array of `n` Dimensions (`arr[][]...[]`):

1. **Definition**:

   - A static array in C or C++ is declared with a fixed size known at compile-time.
   - An `n`-dimensional static array is defined as `arr[d1][d2]...[dn]`, where `d1`, `d2`, ..., `dn` are the dimensions of the array.

2. **Memory Layout**:

   - Memory for a static array of `n` dimensions is contiguous, meaning all elements are stored adjacently in memory.
   - Access to elements is direct and computed using pointer arithmetic based on the array indices.

3. **Pointer Type Returned**:
   - When you pass a static `n`-dimensional array to a function or assign it to a pointer, it decays to a pointer to its first element (of type `T*`, where `T` is the type of elements in the array).
   - For an `n`-dimensional array (`arr[][]...[]`), passing it or assigning it typically results in an `(n-1)`-dimensional pointer.

### Dynamic Array of `n` Dimensions (`new int[][]...[]`):

1. **Definition**:

   - A dynamic array in C++ is allocated using `new` and can have its size determined at runtime.
   - An `n`-dimensional dynamic array is allocated as `new int[d1][d2]...[dn]`.

2. **Memory Layout**:

   - Each dimension of a dynamic array is a pointer to an array of the next dimension.
   - For instance, `new int[d1]` returns a pointer to an array of `d1` integers, and so on for subsequent dimensions.

3. **Pointer Type Returned**:
   - Similar to static arrays, dynamic `n`-dimensional arrays decay to pointers when passed to functions or assigned to pointers.
   - However, the pointer type returned when you pass a dynamic `n`-dimensional array to a function is a `(n-1)`-dimensional pointer.

### Pointer to `(n-1)`-Dimensional Pointer (`int (*)[]...[]`):

1. **Explanation**:

   - This notation `(int (*)[]...[])` represents a pointer to an `(n-1)`-dimensional pointer.
   - In C or C++, arrays decay to pointers to their first elements, and multidimensional arrays decay similarly to pointers to their first rows or planes, depending on the number of dimensions.

2. **Usage**:
   - When dealing with arrays of arrays (`int[][]...[]`), you often work with pointers to arrays, especially when passing arrays to functions or managing them dynamically.
