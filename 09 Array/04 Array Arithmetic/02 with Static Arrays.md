## Static Array as Nested Boxes

Imagine a multidimensional array as a stack of nested boxes, where each box represents a dimension in the array. The concept of nested dereferencing (`*`) and adding offsets (`m`, `n`, etc.) can be visualized as follows:

**Note**: As we know, the array `arr` will pointer to its base element (first element). This means pointing `arr` is equivalent pointing to `&arr[0]`.

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

   - `arr` represents a closed box containing elements (`1`, `2`, `3`, `4`, `5`), each element being a scalar value.
   - `arr` points to the base address of the entire 1D array (`&arr[0]`), which is the starting point (`1`) of the array.

2. **\*arr**:

   - `*arr` dereferences the pointer `arr`, accessing the value at the base address (`arr[0]`).
   - In the visualization, `*arr` directly accesses `1`, the first element in the array.

3. **&arr**:
   - `&arr` provides the address of the entire 1D array, encompassing all elements (`1`, `2`, `3`, `4`, `5`).
   - It points to the starting address of the array (`&arr[0]`), treating the entire array as a single entity.

### Offset Movement:

- **Using Offset (`arr + i`)**:
  - Adding an offset `i` to `arr` moves the pointer to the `i`-th index element in the array.
  - For instance, `arr + 2` points to `arr[2]`, which is `3` in the array `{1, 2, 3, 4, 5}`.

#### Visualizing Offset Movement:

- When we add an offset `i` to `arr`, we're metaphorically shifting our focus on the elements of array:
  - `arr` points to `arr[0]` (`1`)
  - `arr + 1` points to `arr[1]` (`2`)
  - `arr + 2` points to `arr[2]` (`3`)
  - and so on...
  - Dereferencing (`*`) them accesses the value stored at the memory address it points to, akin to opening the currently focused box and retrieving its contents.

### **2D Array**:

```cpp
int arr[3][4] = {
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

#### Key Concepts:

1. **arr**:

   - `arr` represents a collection of closed boxes containing elements (`1` to `12`), arranged in rows and columns.
   - `arr` points to the base address of the 2D array (`&arr[0]`), referring to the first row or a 1D array within the 2D structure, with its address serving as the base address of this 1D array.
   - In the visualization, `arr` does not directly point to the element `1` but rather to the first row of the array: `{1, 2, 3, 4}`, but returns the base address of this row which corresponds to the address of its base element, which is `1`.

2. **\*arr**:

   - `*arr` dereferences `arr`, pointing the base element of first row of the array (`arr[0]`), which contains the elements `{1, 2, 3, 4}`.
   - In the visualization, `*arr` directly points to the element `1` within the first row.

3. **\*\*arr**:

   - `**arr` further dereferences `*arr`, accessing the value at the base element of the first row, which is `1`.
   - In the visualization, `**arr` returns the element `1` within the first row.

4. **&arr**:
   - `&arr` provides the address of the entire 2D array, encompassing all rows and columns.
   - It points to the starting address of the array (`&arr[0][0]`), treating the entire 2D array as a single entity.

### Offset Movement:

- **Using Offset (`arr + i`)**:

  - Adding an offset `i` to `arr` moves the pointer to the `i`-th index row in the array.
  - For instance, `arr + 1` points to the second row in the array: `{5, 6, 7, 8}`.

- **Using Double Offset (`*(arr + i) + j`)**:
  - After moving to the `i`-th index row with `arr + i` and dereferencing it , adding `j` moves to the `j`-th index element in that row.
  - For example, `*(arr + 1) + 2` points to the third element in the second row, which is `7`.

#### Visualizing Offset Movement:

- When we add an offset `i` to `arr`, we shift our focus to different rows:

  - `arr + 0` points to the first row: `{1, 2, 3, 4}`
  - `arr + 1` points to the second row: `{5, 6, 7, 8}`
  - `arr + 2` points to the third row: `{9, 10, 11, 12}`

- Adding `j` after `*(arr + i)` allows navigation within each row:
  - `*(arr + 1) + 0` points to `6`
  - `*(arr + 2) + 3` points to `12`

### **3D Array**:

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
