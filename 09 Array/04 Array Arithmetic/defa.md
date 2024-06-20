## Static Array as Nested Frames

Imagine a multidimensional array as a stack of nested frames, where each frame represents a dimension in the array. The concept of nested dereferencing (`*`) and adding offsets (`m`, `n`, etc.) can be visualized as follows:

**Note**: As we know, the array `arr` will pointer to its base element (first element). This means address of `arr` is equivalent address of `&arr[0]`.

### **0D Array**:

```
+--+
| 1|
+--+
```

- A zero-dimensional array, or scalar, directly returns its contained value.

### **1D Array**:

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

#### Key Concepts:

1. **arr**:

   - `arr` points to the base address of the entire 1D array (`&arr[0]`)(address of `1`).
   - Visually, `arr` represents the frame enclosing the base element in the array (`1`).

2. **\*arr**:

   - `*arr` dereferences the `arr`, meaning going in the frame, accessing the value at the base address (`arr[0]`).
   - Visually, `*arr` directly represents `1`, which is the base element in the array.

3. **&arr**:

   - `&arr` points to the address of the entire 1D array, encompassing all elements (`1`, `2`, `3`, `4`, `5`).
   - Visually, `&arr` represents the outermost frame of the 1D array structure, containing all its elements (`1` to `5`).

### Visualizing Movement:

- **Using Offset (`arr + i`)**:
  - Adding an offset `i` to `arr` moves the pointer to the `i`-th index element in the array.
  - For instance, `arr + 2` points to `arr[2]`, which is `3` in the array `{1, 2, 3, 4, 5}`.
  - When we add an offset `i` to `arr`, we're metaphorically moving from one frame to another:
    - `arr` represents frame of `arr[0]` (`1`)
    - `arr + 1` represents frame of `arr[1]` (`2`)
    - `arr + 2` represents frame of `arr[2]` (`3`)
    - and so on...
    - Dereferencing (`*`) them accesses the value stored at the memory address it points to, akin to opening the box and retrieving its contents.

### **2D Array**:

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

### Key Concepts:

1. **arr2D**:

   - `arr2D` points to the base address of the entire 2D array. Technically, it returns the address of the first element (`1`) in the 2D array, but it points to the base 1D array (`{1, 2, 3, 4}`).
   - Visually, `arr2D` represents the frame of the first row of the 2D array: `{1, 2, 3, 4}`.

2. **\*arr2D**:

   - `*arr2D` dereferences the `arr2D`, allowing access to the elements of the entire 1D array (`{1, 2, 3, 4}`). This means it goes into the frame represented by the first row of the 2D array, and pointing the first element of the row.
   - `*arr2D` points to the base address of the first row of 2D array.
   - Technically, `*arr2D` points to the address of the first element (`1`) in the 1D array (first row of the 2D array).
   - Visually, `*arr2D` represents the frame of the first element (`1`) in the first row (`{1, 2, 3, 4}`) of the 2D array.

3. **\*\*arr2D**:

   - `**arr2D` double dereferences the `arr2D`, which metaphorically means going two layers deep into the frames, and accesses the value at the base address of the first element (`arr[0][0]`), which is `1`.
   - Technically and Visually, `**arr` directly represents `1`, the first element in the 2D array.

4. **&arr**:

   - `&arr` points to the address of the entire 2D array, encompassing all elements (`1` to `12`). It represents the outermost frame of the 2D array structure, containing all its elements.
   - Technically, `*arr2D` points to the address of the first element (`1`) in the first row of the 2D array.
   - Visually, `&arr` represents the outermost frame enclosing the entire 2D array structure (`1` to `12`).

### Visualizing Movement

- **Using Single Offset (`arr + i`)**:

  - Adding an offset `i` to `arr` moves the pointer to the `i`-th index row of the 2D array (`arr[i]`).
  - When using a single offset, we can move through rows of the 2D array:

    - `arr + 0` represents frame of the first row (`{1, 2, 3, 4}`)
    - `arr + 1` represents frame of the second row (`{5, 6, 7, 8}`)
    - `arr + 2` represents frame of the third row (`{9, 10, 11, 12}`)

- **Using Double Offset (`*(arr + i) + j`)**:
  - Adding an offset `j` to `*(arr + i)` accesses the `j`-th index element in the `i`-th index row of the 2D array (`arr[i][j]`).
  - When using double offset, we can access any element in the 2D array:
    - `*(arr + 0) + 0` represents the frame of `arr[0][0]` which is akin to pointing to `1` directly.
    - `*(arr + 0) + 1` represents the frame of `arr[0][1]` which is akin to pointing to `2` directly.
    - `*(arr + 1) + 0` represents the frame of `arr[1][0]` which is akin to pointing to `5` directly.
    - `*(arr + 2) + 3` represents the frame of `arr[2][3]` which is akin to pointing to `12` directly.
  - Dereferencing (`*`) them accesses the value stored at the memory address it points to, akin to opening the box and retrieving its contents.

### **3D Array**:

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

#### Key Concepts:

1. **arr3D**:

   - `arr3D` points to the base address of the entire 3D array. Technically, it returns the address of the first element (`1`) in the 3D array, but it points to the base 2D array (`{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}`).
   - Visually, `arr3D` represents the frame of the first 2D array (`{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}`) in the 3D array.

2. **\*arr3D**:

   - `*arr3D` dereferences `arr3D`, allowing access to the elements of the entire first 2D array (`{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}`). This means it points to the base address of the first 2D array.
   - Technically, `*arr3D` points to the address of the first 1D array (`{1, 2, 3, 4, 5}`) in the first 2D array.
   - Visually, `*arr3D` represents the frame of the first 1D array (`{1, 2, 3, 4, 5}`) of the first 2D array (`{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}`).

3. **\*\*arr3D**:

   - `**arr3D` double dereferences `arr3D`, which metaphorically means going two layers deep into the frames, and pointing the first element (`arr3D[0][0][0]`), which is `1`.
   - Technically, `**arr3D` points to the address of the first element (`1`) of 1D array (`{1, 2, 3, 4, 5}`) in the first 2D array.
   - Visually, `**arr3D` represents the frame of the first element (`1`) of first 1D array (`{1, 2, 3, 4, 5}`) of the first 2D array (`{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}`).

4. **\*\*\*arr3D**:

   - `***arr3D` triple dereferences `arr3D`, meaning it goes three layers deep into the frames, and accesses the value at the base address of the first element (`arr3D[0][0][0]`), which is `1`.
   - Technically and visually, `***arr3D` directly represents `1`, emphasizing that it accesses the innermost element in the 3D array structure.

5. **&arr3D**:

   - `&arr3D` points to the address of the entire 3D array, encompassing all elements (`1` to `20`). It represents the outermost frame of the 3D array structure, containing all its elements.
   - Technically, `&arr3D` points to the address of the first element (`1`) in the 3D array.
   - Visually, `&arr3D` represents the outermost frame enclosing the entire 3D array structure (`1` to `20`).

#### Visualizing Movement

- **Using Single Offset (`arr3D + i`)**:

  - Adding an offset `i` to `arr3D` moves the pointer to the `i`-th index 2D array (`arr3D[i]`).
  - When using a single offset, we can move through the 2D arrays in the 3D array:

    - `arr3D + 0` represents the frame of the first 2D array (`{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}`)
    - `arr3D + 1` represents the frame of the second 2D array (`{{11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}}`)

- **Using Double Offset (`*(arr3D + i) + j`)**:

  - Adding an offset `j` to `*(arr3D + i)` accesses the `j`-th index 1D array in the `i`-th index 2D array (`arr3D[i][j]`).
  - When using double offset, we can access any element in the 3D array:

    - `*(arr3D + 0) + 0` represents the frame of the first 1D array of first 2D array `arr3D[0][0]` (`{1, 2, 3, 4, 5}`).
    - `*(arr3D + 0) + 1` represents the frame of the first 1D array of second 2D array `arr3D[0][1]` (`{6, 7, 8, 9, 10}`).
    - `*(arr3D + 1) + 0` represents the frame of the second 1D array of first 2D array `arr3D[1][0]` (`{11, 12, 13, 14, 15}`).
    - `*(arr3D + 1) + 1` represents the frame of the second 1D array of second 2D array `arr3D[1][4]` (`{16, 17, 18, 19, 20}`).

- **Using Triple Offset (`*(arr3D + i) + j + k`)**:

  - Adding an offset `k` to `*(arr3D + i) + j` accesses the `k`-th index element in the `j`-th index 1D array of the `i`-th index 2D array (`arr3D[i][j][k]`).
  - When using triple offset, we can access any element in the 3D array:

    - `*(arr3D + 0) + 0 + 0` represents the frame of `arr3D[0][0][0]` which is akin to pointing to `1` directly.
    - `*(arr3D + 0) + 1 + 2` represents the frame of `arr3D[0][1][2]` which is akin to pointing to `8` directly.
    - `*(arr3D + 1) + 1 + 3` represents the frame of `arr3D[1][1][3]` which is akin to pointing to `19` directly.

  - Each offset (`i`, `j`, `k`) moves through the corresponding dimensions of the 3D array, akin to navigating through nested frames, and dereferencing (`*`) them accesses the value stored at the memory address it points to, akin to opening the box and retrieving its contents.
