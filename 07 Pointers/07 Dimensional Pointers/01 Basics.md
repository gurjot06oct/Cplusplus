## Dimensional Pointers in C++

In C++, dimensional pointers refer to pointers that point to arrays of different dimensions. This concept is often used when dealing with arrays, matrices, and multi-dimensional data structures. Let's delve into each type of dimensional pointer and how they are utilized, particularly focusing on dynamic allocation of memory.

### Types:

- **0D Pointer (`T*`)**:
  - Points to individual elements or single elements within dynamically allocated arrays (`int[]`).
- **1D Pointer (`T (*)[]`)**:
  - Points to rows or single arrays within dynamically allocated 2D arrays (`int[][]`).
- **2D Pointer (`T (*)[][]`)**:
  - Points to entire 2D arrays within dynamically allocated 3D arrays (`int[][][]`).

### Dimensional Pointers Types

#### 1. 0D Pointer (`T*`)

- **1D Dynamic Array (`int[]`)**:
  - A 0D pointer (`T*`) dynamically allocates memory for a single element of type `T` (`int` in this case).
  - Memory for `int[]` is allocated in a contiguous block, ensuring that all elements (`int`) are stored sequentially in memory.
  - Example:
    ```cpp
    int* ptr = new int; // new int[1]
    ```
    This allocates memory for a single `int` element, ensuring it is stored contiguously.

#### 2. 1D Pointer (`T (*)[]`)

- **2D Dynamic Array (`int[][]`)**:
  - A 1D pointer (`T (*)[]`) points to rows or single arrays within a dynamically allocated 2D array (`int[][]`).
  - Memory for `int[][]` is allocated such that each row (`int[]`) is allocated independently but the array of pointers (`T (*)[]`) to these rows is stored contiguously.
  - Example:
    ```cpp
    int (*ptr)[cols] = new int[rows][cols];
    ```
    Here, `ptr` is a pointer to an array of `cols` integers within an array of `rows` such arrays, ensuring each row is contiguous in memory.

#### 3. 2D Pointer (`T (*)[][]`)

- **3D Dynamic Array (`int[][][]`)**:
  - A 2D pointer (`T (*)[][]`) points to entire 2D arrays (`int[][]`) within a dynamically allocated 3D array (`int[][][]`).
  - Memory for `int[][][]` is allocated in a way that each 2D slice (`int[][]`) maintains its own contiguous memory layout, and the array of pointers (`T (*)[][]`) to these 2D slices is stored contiguously.
  - Example:
    ```cpp
    int (*ptr)[rows][cols] = new int[layers][rows][cols];
    ```
    In this case, `ptr` is a pointer to a 2D array (`rows` rows and `cols` columns) within an array of `layers` such 2D arrays, ensuring each 2D slice is contiguous.
