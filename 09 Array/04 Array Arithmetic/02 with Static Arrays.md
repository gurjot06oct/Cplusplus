### Visualizing Multidimensional Arrays as Nested Frames

#### **0D Array (Scalar)**

A scalar is a single value represented as a frame:

```
+--+
| 1|
+--+
```

#### **1D Array**

A one-dimensional array is a single frame containing multiple scalar values:

```cpp
int arr[] = {1, 2, 3, 4, 5};
```

```
+----------------------------+
|  +--+ +--+ +--+ +--+ +--+  |
|  | 1| | 2| | 3| | 4| | 5|  |
|  +--+ +--+ +--+ +--+ +--+  |
+----------------------------+
```

- **Base Frame (`arr`)**: Represents the entire 1D array.
- **Element Frame (`*arr`)**: Accesses individual elements within the base frame.

#### **2D Array**

A two-dimensional array is a frame containing multiple 1D arrays:

```cpp
int arr2D[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
```

```
+----------------------------+
|  +----------------------+  |
|  |  +--+ +--+ +--+ +--+ |  |
|  |  | 1| | 2| | 3| | 4| |  |
|  |  +--+ +--+ +--+ +--+ |  |
|  +----------------------+  |
|                            |
|  +----------------------+  |
|  |  +--+ +--+ +--+ +--+ |  |
|  |  | 5| | 6| | 7| | 8| |  |
|  |  +--+ +--+ +--+ +--+ |  |
|  +----------------------+  |
|                            |
|  +----------------------+  |
|  |  +--+ +--+ +--+ +--+ |  |
|  |  | 9| |10| |11| |12| |  |
|  |  +--+ +--+ +--+ +--+ |  |
|  +----------------------+  |
+----------------------------+
```

- **Base Frame (`arr2D`)**: Represents the entire 2D array.
- **Row Frame (`*arr2D`)**: Accesses individual 1D arrays within the base frame.
- **Element Frame (`**arr2D`)\*\*: Accesses individual elements within each 1D array.

#### **3D Array**

A three-dimensional array is a frame containing multiple 2D arrays:

```cpp
int arr3D[2][2][5] = {
    {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10}
    },
    {
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    }
};
```

```
+------------------------------------------------------------------------+
|                                                                        |
|  +------------------------------------------------------------------+  |
|  |  +----------------------------+  +----------------------------+  |  |
|  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
|  |  |  | 1| | 2| | 3| | 4| | 5|  |  |  | 6| | 7| | 8| | 9| |10|  |  |  |
|  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
|  |  +----------------------------+  +----------------------------+  |  |
|  +------------------------------------------------------------------+  |
|                                                                        |
|  +------------------------------------------------------------------+  |
|  |  +----------------------------+  +----------------------------+  |  |
|  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
|  |  |  |11| |12| |13| |14| |15|  |  |  |16| |17| |18| |19| |20|  |  |  |
|  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
|  |  +----------------------------+  +----------------------------+  |  |
|  +------------------------------------------------------------------+  |
+------------------------------------------------------------------------+
```

- **Base Frame (`arr3D`)**: Represents the entire 3D array.
- **2D Frame (`*arr3D`)**: Accesses individual 2D arrays within the base frame.
- **Row Frame (`**arr3D`)\*\*: Accesses individual 1D arrays within each 2D array.
- **Element Frame (`\***arr3D`)\*\*: Accesses individual elements within each 1D array.

### Navigating Through Frames

#### **Single Offset (`arr + i`)**

- **1D Array**: Moves the pointer to the `i`-th element in the array.
  - `arr + 2` points to `arr[2]`, which is `3`.
- **2D Array**: Moves the pointer to the `i`-th row in the 2D array.
  - `arr2D + 1` points to `arr2D[1]`, which is `{5, 6, 7, 8}`.
- **3D Array**: Moves the pointer to the `i`-th 2D array in the 3D array.
  - `arr3D + 1` points to `arr3D[1]`, which is `{{11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}}`.

#### **Double Offset (`*(arr + i) + j`)**

- **2D Array**: Moves the pointer to the `j`-th element in the `i`-th row.
  - `*(arr2D + 1) + 2` points to `arr2D[1][2]`, which is `7`.
- **3D Array**: Moves the pointer to the `j`-th row in the `i`-th 2D array.
  - `*(arr3D + 1) + 1` points to `arr3D[1][1]`, which is `{16, 17, 18, 19, 20}`.

#### **Triple Offset (`*(*(arr + i) + j) + k`)**

- **3D Array**: Moves the pointer to the `k`-th element in the `j`-th row of the `i`-th 2D array.
  - `*(*(arr3D + 1) + 1) + 3` points to `arr3D[1][1][3]`, which is `19`.

### Dereferencing and Accessing Values

- **Single Dereference (`*`)**: Accesses the value at the current pointer level.

  - **1D Array**: `*arr` accesses the first element, `1`.
  - **2D Array**: `*arr2D` accesses the first row, `{1, 2, 3, 4}`.
  - **3D Array**: `*arr3D` accesses the first 2D array, `{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}`.

- **Double Dereference (`**`)\*\*: Accesses the value one level deeper.
  - **2D Array**: `

\*\*arr2D`accesses the first element of the first row,`1`.

- **3D Array**: `**arr3D` accesses the first row of the first 2D array, `{1, 2, 3, 4, 5}`.

- **Triple Dereference (`\***`)\*\*: Accesses the value two levels deeper.
  - **3D Array**: `***arr3D` accesses the first element of the first row of the first 2D array, `1`.

### Conclusion

The Nested Frame Model Representation provides a structured way to visualize and understand the behavior of multidimensional arrays. By treating each dimension as a nested frame, it becomes easier to comprehend how pointers, offsets, and dereferencing operations interact to access elements within complex data structures. This theory can be extended to higher-dimensional arrays by adding additional layers of frames and dereferencing levels, maintaining the same principles outlined above.
