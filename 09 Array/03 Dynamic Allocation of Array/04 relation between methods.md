### Relationship Between Dimensional Pointers (pointer-to-arrays) and Level Pointers ( pointer-to-pointers )

#### 1. `T*` Pointer and `int*` Array

- **`T*` Pointer**:

  - Points to a single element of type `T`.
  - Example:
    ```cpp
    int* ptr = new int;
    ```
    Dynamically allocates memory for a single `int` and `ptr` points to that location.

- **`int*` Array**:

  - Represents a dynamically allocated 1-dimensional array of integers.
  - Example:
    ```cpp
    int* arr = new int[size];
    ```
    Allocates memory for `size` integers, stored contiguously.

- **Relationship**:
  - A `T*` pointer (`int*`) can point to the first element of an `int*` array.
  - The pointer (`ptr`) and the array (`arr`) are used interchangeably for accessing elements.
  - Accessing elements:
    - Using pointer arithmetic: `*(ptr + i)` or `*(arr + i)`
    - Using array subscript: `ptr[i]` or `arr[i]`

#### 2. `T (*)[]` Pointer and `int**` Array

- **`T (*)[]` Pointer**:

  - Points to an array of `T` elements. This is commonly used to point to rows in a 2D array.
  - Example:
    ```cpp
    int (*ptr)[cols] = new int[rows][cols];
    ```
    Dynamically allocates memory for a 2-dimensional array (`rows` rows and `cols` columns).

- **`int**` Array\*\*:

  - Represents a dynamically allocated 2-dimensional array of integers.
  - Example:
    ```cpp
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    ```
    Allocates memory for `rows` rows of `cols` integers each, with each row allocated separately.

- **Relationship**:
  - A `T (*)[]` pointer can point to the entire row in a 2-dimensional `int**` array.
  - The pointer (`ptr`) and the array (`arr`) are used interchangeably for accessing elements.
  - Accessing elements:
    - Using double indexing: `ptr[i][j]` or `arr[i][j]`
    - Using array subscript: `arr[i][j]` or `ptr[i][j]`

#### 3. `T (*)[][]` Pointer and `int***` Array

- **`T (*)[][]` Pointer**:

  - Points to an array of 2-dimensional arrays (`T[][]`). This is used to point to 3D arrays.
  - Example:
    ```cpp
    int (*ptr)[rows][cols] = new int[depth][rows][cols];
    ```
    Dynamically allocates memory for a 3-dimensional array (`depth` layers, each with `rows` rows and `cols` columns).

- **`int\***` Array\*\*:

  - Represents a dynamically allocated 3-dimensional array of integers.
  - Example:
    ```cpp
    int*** arr = new int**[depth];
    for (int i = 0; i < depth; ++i) {
        arr[i] = new int*[rows];
        for (int j = 0; j < rows; ++j) {
            arr[i][j] = new int[cols];
        }
    }
    ```
    Allocates memory for `depth` layers of `rows` rows of `cols` integers each, with each layer and row allocated separately.

- **Relationship**:
  - A `T (*)[][]` pointer can point to the entire 2-dimensional array within a 3-dimensional `int***` array.
  - The pointer (`ptr`) and the array (`arr`) are used interchangeably for accessing elements.
  - Accessing elements:
    - Using triple indexing: `ptr[i][j][k]` or `arr[i][j][k]`
    - Using array subscript: `arr[i][j][k]` or `ptr[i][j][k]`
