### Address Calculation in Arrays

Understanding the memory address calculation for elements in 1D, 2D, and 3D arrays is crucial for manipulating array elements using pointers and pointer arithmetic. Here’s a detailed explanation and formula for each type of array:

---

## 1D Arrays

### Concept

A 1D array is a linear collection of elements stored in contiguous memory locations. The address of any element can be calculated using the base address of the array and the size of the elements.

### Formula

Memory Address of `arr[i]` = Base Address of `arr` + $ i \times \text{sizeof}(arrtype) $

### Example

Consider an array `int arr[5] = {1, 2, 3, 4, 5};` where each `int` occupies `4` bytes:

- **Base Address**: Let's assume the base address of `arr` is `100`.
- **Element Address Calculation**:
  - Address of `arr[0]` = `100 + 0 * 4` = `100`
  - Address of `arr[1]` = `100 + 1 * 4` = `104`
  - Address of `arr[2]` = `100 + 2 * 4` = `108`

---

## 2D Arrays

### Concept

A 2D array is a collection of rows and columns stored in contiguous memory. To access an element, we need to consider the row and column indices.

### Formula

Memory Address of `arr[i][j]` = Base Address of `arr` + $(i \times \text{numcols} + j) \times \text{sizeof}(arrtype)$

Where `numcols` is the number of columns in the 2D array.

### Example

Consider an array `int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};` where each `int` occupies `4` bytes:

- **Base Address**: Let's assume the base address of `arr` is `200`.
- **Element Address Calculation**:
  - Address of `arr[0][0]` = `200 + (0 * 4 + 0) * 4` = `200`
  - Address of `arr[1][2]` = `200 + (1 * 4 + 2) * 4` = `200 + 6 * 4` = `224`
  - Address of `arr[2][3]` = `200 + (2 * 4 + 3) * 4` = `200 + 11 * 4` = `244`

---

## 3D Arrays

### Concept

A 3D array is a collection of 2D arrays (layers), and each layer contains rows and columns. To access an element, we need to consider the layer, row, and column indices.

### Formula

Memory Address of `arr[i][j][k]` = Base Address of `arr` + $ ((i \times \text{numrows} \times \text{numcols}) + (j \times \text{numcols}) + k) \times \text{sizeof}(arrtype) $

Where `numrows` is the number of rows and `numcols` is the number of columns in each 2D array layer.

### Example

Consider an array `int arr[2][3][4]` where each `int` occupies `4` bytes:

- **Base Address**: Let's assume the base address of `arr` is `300`.
- **Element Address Calculation**:
  - Address of `arr[0][0][0]` = `300 + ((0 * 3 * 4) + (0 * 4) + 0) * 4` = `300`
  - Address of `arr[1][2][3]` = `300 + ((1 * 3 * 4) + (2 * 4) + 3) * 4` = `300 + (12 + 8 + 3) * 4` = `300 + 23 * 4` = `392`
  - Address of `arr[1][1][2]` = `300 + ((1 * 3 * 4) + (1 * 4) + 2) * 4` = `300 + (12 + 4 + 2) * 4` = `300 + 18 * 4` = `372`
