## Dynamic Allocation of Arrays using Pointer-to-Array (Dimensional Pointer)

### 1. 1D Array using `T*`

- **Dynamic Allocation**:

  ```cpp
  int size = 5;
  T* arr = new T[size];  // Allocate memory for 5 elements of type T
  ```

- **Initialization**:
  ```cpp
  for (int i = 0; i < size; ++i) {
      arr[i] = initialValue;  // Initialize elements as needed
  }
  ```
- **Full Initialization**: Allocate and initialize.

  ```cpp
  T *arr1D = new T[size] {1, 2, 3, 4, 5};
  ```

  - **Explanation**:
    - `arr1D` is a dynamically allocated 1D array of `type T` with size `5` (`T (*arr1D)`).
    - Memory is allocated using `new T[size]`.
    - The array is initialized with the values `{val1, val2, val3, val4, val5}`.

### 2D Array using `T (*arr)[m]`

- **Dynamic Allocation**: Allocate memory for a 2D array with 'n' rows and 'm' columns

  ```cpp
  int n = 3, n = 4;
  T (*arr)[m] = new T[n][m];
  ```

- **Initialization**:
  ```cpp
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
          arr[i][j] = initialValue;  // Initialize elements as needed
      }
  }
  ```
- **Full Initialization**: Allocate and initialize a 2D array dynamically.

  ```cpp
  int rows = 3, cols = 4;

  // Allocate memory for the array of rows
  int (*arr2D)[cols] = new int[rows][cols] {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
  };
  ```

  - **Explanation**:
    - `arr2D` is a dynamically allocated 2D array of integers with `3` rows and `4` columns (`int (*arr2D)[cols]`).
    - Memory is allocated using `new int[rows][cols]`.
    - Each row is initialized explicitly within the initializer list `{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} }`.

### 3. 3D Array using `T (*arr)[m][l]`

- **Dynamic Allocation**:

  ```cpp
  int depth = 2, rows = 3, cols = 4;
  T (*arr)[3][4] = new T[depth][m][l];  // Allocate memory for a 3D array with 2 layers, each with 'm' rows and 'l' columns
  ```

- **Initialization**:
  ```cpp
  for (int i = 0; i < depth; ++i) {
      for (int j = 0; j < m; ++j) {
          for (int k = 0; k < l; ++k) {
              arr[i][j][k] = initialValue;  // Initialize elements as needed
          }
      }
  }
  ```
- **Full Initialization**: Allocate and initialize a 3D array dynamically.

  ```cpp
  int l = 3, m = 3, n = 3;
  array3d = new int[l][m][n] {
    { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} },
    { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} },
    { {19, 20, 21}, {22, 23, 24}, {25, 26, 27} }
  };
  ```

### Partial Initialization (Flattened Initializer List)

**Partial initialization** involves initializing an array by providing a single-dimensional initializer list, which is flattened to fill the array elements in a systematic order.

#### 1. Partial Initialization for 1D Array

Example:

```cpp
int * arr1D = new int[4]{1, 2, 3, 4};
```

- **Explanation**:
  - `arr1D` point to the first element of a 1D array of integers with 4 elements (`int arr1D[4]`).
  - The initializer list `{1, 2, 3, 4}` initializes each element of the array explicitly.

#### 2. Partial Initialization for 2D Array

Example:

```cpp
int (*arr2D)[3] = new int[2][3]{1, 2, 3, 4, 5, 6};
```

- **Explanation**:
  - `arr2D` point to the first row of a 2D array of integers with 2 rows and 3 columns (`int arr2D[2][3]`).
  - The initializer list `{1, 2, 3, 4, 5, 6}` initializes the array in row-major order.
  - This initializes `arr2D[0][0] = 1`, `arr2D[0][1] = 2`, `arr2D[0][2] = 3`, `arr2D[1][0] = 4`, `arr2D[1][1] = 5`, and `arr2D[1][2] = 6`.

#### 3. Partial Initialization for 3D Array

Example:

```cpp
int (*arr3D)[2][2] = new int[2][2][2]{1, 2, 3, 4, 5, 6, 7, 8};
```

- **Explanation**:
  - `arr3D` point to the first 2D Array of a 3D array of integers with 2 layers, each containing 2 rows and 2 columns (`int arr3D[2][2][2]`).
  - The initializer list `{1, 2, 3, 4, 5, 6, 7, 8}` initializes the entire 3D array in layer-row-column order.
  - This initializes `arr3D[0][0][0] = 1`, `arr3D[0][0][1] = 2`, `arr3D[0][1][0] = 3`, `arr3D[0][1][1] = 4`, `arr3D[1][0][0] = 5`, `arr3D[1][0][1] = 6`, `arr3D[1][1][0] = 7`, and `arr3D[1][1][1] = 8`.

### Summary

- **Full Initialization**: Specifies each element or sub-array explicitly within nested initializer lists.
- **Partial Initialization (Flattened Initializer List)**: Initializes the array by providing a single-dimensional initializer list, which is used to populate the array elements sequentially based on the array's structure.

### Structural Differences Between Dynamic and Static Arrays

#### Static Arrays

- **1D Static Array**:

  ```cpp
  T arr[5];  // Allocated on the stack, fixed size
  ```

- **2D Static Array**:

  ```cpp
  T arr[3][4];  // Allocated on the stack, fixed size
  ```

- **3D Static Array**:
  ```cpp
  T arr[2][3][4];  // Allocated on the stack, fixed size
  ```

#### Dynamic Arrays

- **1D Dynamic Array (`T*`)**:

  - Memory allocated on the heap, size can be determined at runtime.

- **2D Dynamic Array (`T (*arr)[m]`)**:

  - Memory for entire array allocated as a single block, internally contiguous.

- **3D Dynamic Array (`T (*arr)[m][l]`)**:

  - Memory for entire array allocated as a single block, internally contiguous.
