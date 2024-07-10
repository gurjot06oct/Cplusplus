## Dimension Conversion Arithmetic

### 2D Array Dimension Conversion

#### Original Array:

- Dimensions: `[m][n]`
- Index variables: $ i $ (row index), $ j $ (column index)
- Product of dimensions: $ m \times n $

#### Reinterpreted Array:

- Dimensions: `[p][q]`
- Index variables: $ x $ (row index), $ y $ (column index)
- Product of dimensions: $ p \times q = m \times n $

To convert coordinates $ (i, j) $ from the original array to $ (x, y) $ in the reinterpreted array:

- **Conversion Formulas:**
  - $\text{flat\_index} = i \times n + j$
  - $x = \frac{\text{flat\_index}}{q}$
  - $y = \text{flat\_index} \% q$

### Example Code:

```cpp
#include <iostream>

int main() {
    const int m = 4, n = 5; // Dimensions of original 2D array
    int (*array2D)[n] = new int[m][n];

    // Fill the 2D array with some data
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            array2D[i][j] = i * n + j + 1;
            std::cout << array2D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Convert to 2D array of size [2][10]
    const int p = 2, q = 10; // Dimensions of new 2D array
    int (*newArray2D)[q] = reinterpret_cast<int(*)[q]>(array2D);

    // Access and print the new 2D array
    for (int x = 0; x < p; ++x) {
        for (int y = 0; y < q; ++y) {
            std::cout << newArray2D[x][y] << " ";
        }
        std::cout << std::endl;
    }

    delete[] array2D; // Clean up memory

    return 0;
}
```

### 3D Array Dimension Conversion

#### Original Array:

- Dimensions: `[m][n][o]`
- Index variables: $ i $ (layer index), $ j $ (row index), $ k $ (column index)
- Product of dimensions: $ m \times n \times o $

#### Reinterpreted Array:

- Dimensions: `[p][q][r]`
- Index variables: $ x $ (layer index), $ y $ (row index), $ z $ (column index)
- Product of dimensions: $ p \times q \times r = m \times n \times o $

To convert coordinates $ (i, j ,k) $ from the original array to $ (x, y, z) $ in the reinterpreted array:

- **Conversion Formulas:**
  - $\text{flat\_index} = i \times n \times o + j \times o + k$
  - $x = \frac{\text{flat\_index}}{q \times r}$
  - $y = \frac{\left(\text{flat\_index}\% (q \times r)\right)}{r} = \left( \frac{\text{flat\_index}}{r} \right) \% q$
  - $z = \left(\text{flat\_index}\% (q \times r)\right) \% r = \text{flat\_index} \% r$

### Example Code:

```cpp
#include <iostream>

int main() {
    const int m = 4, n = 4, o = 4; // Dimensions of original 3D array
    int (*array3D)[n][o] = new int[m][n][o];

    // Fill the 3D array with some data
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < o; ++k) {
                array3D[i][j][k] = i * n * o + j * o + k + 1;
                std::cout << array3D[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Convert to 3D array of size [2][8][4]
    const int p = 2, q = 8, r = 4; // Dimensions of new 3D array
    int (*newArray3D)[q][r] = reinterpret_cast<int(*)[q][r]>(array3D);

    // Access and print the new 3D array
    for (int x = 0; x < p; ++x) {
        for (int y = 0; y < q; ++y) {
            for (int z = 0; z < r; ++z) {
                std::cout << newArray3D[x][y][z] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    delete[] array3D; // Clean up memory

    return 0;
}
```
