## Structure Conversion Arithmetic

### 1D to 2D Array Conversion

#### 1D Array:

- Dimension: `[m]`
- Index variable: \( i \)

#### 2D Array:

- Dimension: `[p][q]`
- Index variables: \( x \) (row index), \( y \) (column index)

**Conversion Formulas:**

- Suppose you have a 1D array `arr1D` of size `m`.
- You want to reinterpret this as a 2D array `arr2D` of size `[p][q]`.

1. **Calculate `x` and `y` from `i`:**
   - Flatten the 2D indices into a 1D index: \( \text{flat_index} = x \times q + y \).
   - Invert the 1D index into 2D coordinates: \( x = \text{flat_index} / q \).
   - Get remainder of 1D index as the y coordinate: \( y = \text{flat_index} \% q \).

### Example in C++

```cpp
#include <iostream>

int main() {
    const int m = 20; // Size of 1D array
    int *arr1D = new int[m]; // Allocate memory for 1D array

    // Fill 1D array with some data
    for (int i = 0; i < m; ++i) {
        arr1D[i] = i + 1;
    }

    // Convert to 2D array of size [4][5]
    const int p = 4, q = 5; // Dimensions of new 2D array
    int (*arr2D)[q] = reinterpret_cast<int(*)[q]>(arr1D);

    // Access and print the new 2D array
    for (int x = 0; x < p; ++x) {
        for (int y = 0; y < q; ++y) {
            std::cout << arr2D[x][y] << " ";
        }
        std::cout << std::endl;
    }

    delete[] arr1D; // Clean up memory

    return 0;
}
```

### 1D to 3D Array Conversion

#### 1D Array:

- Dimension: `[m]`
- Index variable: \( i \)

#### 3D Array:

- Dimension: `[p][q][r]`
- Index variables: \( x \) (layer index), \( y \) (row index), \( z \) (column index)

**Conversion Formulas:**

- Suppose you have a 1D array `arr1D` of size `m`.
- You want to reinterpret this as a 3D array `arr3D` of size `[p][q][r]`.

1. **Calculate `x`, `y`, and `z` from `i`:**
   - Flatten the 3D indices into a 1D index: \( \text{flat_index} = x \times q \times r + y \times r + z \).
   - Invert the 1D index into 3D coordinates:
     - \( x = \text{flat_index} / (q \times r) \)
     - \( y = (\text{flat_index} / r) \% q \)
     - \( z = \text{flat_index} \% r \)

### Example in C++

```cpp
#include <iostream>

int main() {
    const int m = 60; // Size of 1D array
    int *arr1D = new int[m]; // Allocate memory for 1D array

    // Fill 1D array with some data
    for (int i = 0; i < m; ++i) {
        arr1D[i] = i + 1;
    }

    // Convert to 3D array of size [3][4][5]
    const int p = 3, q = 4, r = 5; // Dimensions of new 3D array
    int (*arr3D)[q][r] = reinterpret_cast<int(*)[q][r]>(arr1D);

    // Access and print the new 3D array
    for (int x = 0; x < p; ++x) {
        for (int y = 0; y < q; ++y) {
            for (int z = 0; z < r; ++z) {
                std::cout << arr3D[x][y][z] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    delete[] arr1D; // Clean up memory

    return 0;
}
```

### 2D to 1D Array Conversion

#### 2D Array:

- Dimension: `[p][q]`
- Index variables: \( x \) (row index), \( y \) (column index)

#### 1D Array:

- Dimension: `[m]`
- Index variable: \( i \)

**Conversion Formulas:**

- Suppose you have a 2D array `arr2D` of size `[p][q]`.
- You want to reinterpret this as a 1D array `arr1D` of size `m`.

1. **Calculate `i` from `x` and `y`:**
   - Flatten the 2D indices into a 1D index: \( \text{flat_index} = x \times q + y \).
   - Invert the 2D index into 1D coordinate: \( i = \text{flat_index} \).

### 2D to 3D Array Conversion

#### 2D Array:

- Dimension: `[p][q]`
- Index variables: \( x \) (row index), \( y \) (column index)

#### 3D Array:

- Dimension: `[r][s][t]`
- Index variables: \( l \) (layer index), \( u \) (row index), \( v \) (column index)

**Conversion Formulas:**

- Suppose you have a 2D array `arr2D` of size `[p][q]`.
- You want to reinterpret this as a 3D array `arr3D` of size `[r][s][t]`.

1. **Calculate `l`, `u`, and `v` from `x` and `y`:**
   - Flatten the 3D indices into a 2D index: \( \text{flat_index} = l \times s \times t + u \times t + v \).
   - Invert the 2D index into 3D coordinates:
     - \( l = \text{flat_index} / (s \times t) \)
     - \( u = (\text{flat_index} / t) \% s \)
     - \( v = \text{flat_index} \% t \)

### 3D to 1D Array Conversion

#### 3D Array:

- Dimension: `[p][q][r]`
- Index variables: \( x \) (layer index), \( y \) (row index), \( z \) (column index)

#### 1D Array:

- Dimension: `[m]`
- Index variable: \( i \)

**Conversion Formulas:**

- Suppose you have a 3D array `arr3D` of size `[p][q][r]`.
- You want to reinterpret this as a 1D array `arr1D` of size `m`.

1. **Calculate `i` from `x`, `y`, and `z`:**
   - Flatten the 3D indices into a 1D index: \( \text{flat_index} = x \times q \times r + y \times r + z \).
   - Invert the 3D index into 1D coordinate: \( i = \text{flat_index} \).
