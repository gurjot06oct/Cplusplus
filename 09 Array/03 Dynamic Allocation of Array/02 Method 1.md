## Allocating Arrays using pointer-to-pointer (Level Pointer)

#### 1. 1D Array using `int*`

- **Dynamic Allocation**:

  ```cpp
  int size = 5;
  int* arr = new int[size];  // Allocate memory for 5 integers
  ```

- **Initialization**:
  ```cpp
  for (int i = 0; i < size; ++i) {
      arr[i] = i + 1;  // Initialize elements
  }
  ```

#### 2. 2D Array using `int**`

- **Dynamic Allocation**:

  ```cpp
  int rows = 3, cols = 4;
  int** arr = new int*[rows];  // Allocate memory for rows pointers
  for (int i = 0; i < rows; ++i) {
      arr[i] = new int[cols];  // Allocate memory for each row
  }
  ```

- **Initialization**:
  ```cpp
  for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
          arr[i][j] = i * cols + j + 1;  // Initialize elements
      }
  }
  ```

#### 3. 3D Array using `int***`

- **Dynamic Allocation**:

  ```cpp
  int depth = 2, rows = 3, cols = 4;
  int*** arr = new int**[depth];  // Allocate memory for depth pointers
  for (int i = 0; i < depth; ++i) {
      arr[i] = new int*[rows];  // Allocate memory for rows pointers
      for (int j = 0; j < rows; ++j) {
          arr[i][j] = new int[cols];  // Allocate memory for each row
      }
  }
  ```

- **Initialization**:
  ```cpp
  for (int i = 0; i < depth; ++i) {
      for (int j = 0; j < rows; ++j) {
          for (int k = 0; k < cols; ++k) {
              arr[i][j][k] = (i * rows * cols) + (j * cols) + k + 1;  // Initialize elements
          }
      }
  }
  ```

### Structural Differences Between Dynamic (Method I) and Static Arrays

#### Static Arrays

- **1D Static Array**:

  ```cpp
  int arr[5];  // Allocate memory for 5 integers
  ```

- **2D Static Array**:

  ```cpp
  int arr[3][4];  // Allocate memory for 3 rows and 4 columns
  ```

- **3D Static Array**:
  ```cpp
  int arr[2][3][4];  // Allocate memory for 2 layers, each with 3 rows and 4 columns
  ```

#### Visualization and Continuity

- **1D Array**:

  - **Dynamic (`int*`)**:

    ```
    [1] [2] [3] [4] [5]
    ```

    - Memory is contiguous and allocated on the heap.

  - **Static**:
    ```
    [1] [2] [3] [4] [5]
    ```
    - Memory is contiguous and allocated on the stack (or static memory area).

- **2D Array**:

  - **Dynamic `(int\*\*)`**:

    ```
    Row 0: [1]  [2]  [3]  [4]
    Row 1: [5]  [6]  [7]  [8]
    Row 2: [9] [10] [11] [12]
    ```

    - In a dynamic 2D array (represented as `int**`), each row is allocated as a separate block of contiguous memory. However, these blocks are not contiguous with each other. This means that while elements within the same row (e.g., 1, 2, 3, and 4) are stored next to each other in memory, elements from different rows (e.g., 4 and 5) are not stored contiguously. This can be visualized as:

      ```
      Memory layout:
      [1, 2, 3, 4]  [5, 6, 7, 8]  [9, 10, 11, 12]
      ```

    - Here, each row (e.g., `[1, 2, 3, 4]`) is a contiguous block, but there are gaps between these blocks in memory.

  - **Static**:

    ```
    [1] [2] [3] [4]
    [5] [6] [7] [8]
    [9] [10] [11] [12]
    ```

    - Memory is contiguous across the entire 2D array.

- **3D Array**:

  - **Dynamic `(int\*\*\*)`**:

    ```
    Layer 0, Row 0: [1] [2] [3] [4]
    Layer 0, Row 1: [5] [6] [7] [8]
    Layer 0, Row 2: [9] [10] [11] [12]

    Layer 1, Row 0: [13] [14] [15] [16]
    Layer 1, Row 1: [17] [18] [19] [20]
    Layer 1, Row 2: [21] [22] [23] [24]
    ```

    - Each layer and each row within each layer are allocated separately, resulting in non-contiguous memory across layers and rows but contiguous memory within rows.

  - **Visualizing Memory Layout:**

  - In memory, the structure might look like this (hypothetically):

    ```
    Memory layout:
    Layer 0: [1, 2, 3, 4]  [5, 6, 7, 8]  [9, 10, 11, 12]
    Layer 1: [13, 14, 15, 16]  [17, 18, 19, 20]  [21, 22, 23, 24]
    ```

    - Here, each row (`[1, 2, 3, 4]`, `[5, 6, 7, 8]`, etc.) is contiguous within itself, but there are separations (`gaps`) between different rows and layers.

  - **Understanding the Memory Allocation:**

    1. **Layers Allocation :** `(int*** array)`

    - First, memory is allocated for the `int***` array, which holds pointers to the layers (`Layer 0`, `Layer 1`).

    2. **Rows Allocation :** `(int** array[layer_count])`

    - For each layer (`Layer 0`, `Layer 1`), memory is allocated for an `int**` array. Each element of this array (`array[layer]`) points to a row of integers.

    3. **Integers Allocation `(int array[layer][row][column])`:**

    - Finally, for each row in each layer, memory is allocated for an `int` array. This array stores the actual integers (`1` to `24` in this example).

  - **Contiguity**

    - **Contiguous Memory within Rows:**

      - Within each row (e.g., `Layer 0, Row 0: [1] [2] [3] [4]`), the integers `[1, 2, 3, 4]` are stored sequentially in memory. This ensures that accessing elements within the same row is efficient and direct.

    - **Non-Contiguous Memory between Rows:**

      - Between rows of the same layer (e.g., between `Layer 0, Row 0` and `Layer 0, Row 1`), the memory allocated for `[1, 2, 3, 4]` and `[5, 6, 7, 8]` are separate. They are allocated as different blocks of memory, not contiguous with each other. This means there may be gaps or other data between these rows in memory.

    - **Non-Contiguous Memory between Layers:**
      - Similarly, between layers (e.g., `Layer 0` and `Layer 1`), the memory allocated for `Layer 0` (`[1, 2, 3, 4]` to `[9, 10, 11, 12]`) and `Layer 1` (`[13, 14, 15, 16]` to `[21, 22, 23, 24]`) are separate. Each layer is allocated as an independent block of memory.

  - **Static**:

    ```
    Layer 0:
    [1] [2] [3] [4]
    [5] [6] [7] [8]
    [9] [10] [11] [12]

    Layer 1:
    [13] [14] [15] [16]
    [17] [18] [19] [20]
    [21] [22] [23] [24]
    ```

    - Memory is contiguous across the entire 3D array.

### Summary

- **Dynamic Arrays (`int*`, `int**`, `int**\*`)**:

  - Provide flexibility in size and dimensions, allocated on the heap.
  - May result in non-contiguous memory blocks for multi-dimensional arrays.
  - Initialization requires explicit memory management (allocation and deallocation).

- **Static Arrays**:
  - Fixed size and dimensions, allocated on the stack or static memory area.
  - Memory is contiguous across the entire array.
  - Initialization is simpler and managed by the compiler.

Understanding the structural differences and memory allocation patterns helps in choosing the right type of array for specific applications, ensuring efficient memory usage and access patterns in C++.
