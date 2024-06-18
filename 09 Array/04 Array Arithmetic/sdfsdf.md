### Theory and Explanation of Axioms for N-Dimensional Arrays

This theory provides a structured understanding of N-dimensional arrays using a nested box concept, supported by a set of base axioms. It explores how elements, sub-arrays, and higher-dimensional arrays relate to one another using dereferencing (`*`) and referencing (`&`).

#### Axioms for 1D Arrays

1. **Array Initialization**:

   ```c
   int arr[n] = {...}
   ```

   This defines a 1D array `arr` with `n` elements.

2. **Dereferencing the First Element**:

   ```c
   *arr == arr[0]  // Returns the value of the first element
   ```

   - `*arr` accesses the value of the first element.
   - `arr[0]` is the first element in the array.
   - These are equivalent because `arr` points to the first element, so dereferencing `arr` gives `arr[0]`.

3. **Referencing the First Element**:

   ```c
   arr == &arr[0]  // Points to the first element
   ```

   - `arr` is the address of the first element.
   - `&arr[0]` explicitly takes the address of the first element.
   - These are equivalent since the array name `arr` acts as a pointer to the first element.

4. **Referencing the Whole Array**:
   ```c
   &arr == &&arr[0]  // Points to the whole array
   ```
   - `&arr` is the address of the array itself.
   - `&&arr[0]` takes the address of the address of the first element, effectively pointing to the array.

#### Axioms for 2D Arrays

1. **Array Initialization**:

   ```c
   int arr[m][n] = {...}
   ```

   This defines a 2D array `arr` with `m` rows and `n` columns.

2. **Dereferencing the First Element**:

   ```c
   **arr == arr[0][0]  // Returns the value of the first element
   ```

   - `**arr` accesses the value at the first element.
   - `arr[0][0]` is the value at the first row and first column.
   - These are equivalent because `arr` is a pointer to the first row, and `*arr` points to the first column, making `**arr` the first element.

3. **Dereferencing the First Row**:

   ```c
   *arr == arr[0] == &arr[0][0]  // Points to the first element of the first 1D array within the 2D array
   ```

   - `*arr` points to the first row.
   - `arr[0]` is the first row itself.
   - `&arr[0][0]` is the address of the first element in the first row.
   - These are equivalent because `*arr` and `arr[0]` are the same as the first row, and `&arr[0][0]` is the address of the first element in the first row.

4. **Referencing the First Row**:

   ```c
   arr == &arr[0]  // Points to the first 1D array within the 2D array
   ```

   - `arr` is the address of the first row.
   - `&arr[0]` explicitly takes the address of the first row.
   - These are equivalent since `arr` as a pointer to the array points to the first row.

5. **Referencing the Whole Array**:
   ```c
   &arr == &&arr[0][0]  // Points to the whole 2D array
   ```
   - `&arr` is the address of the entire 2D array.
   - `&&arr[0][0]` takes the address of the address of the first element, effectively pointing to the array.

#### Axioms for 3D Arrays

1. **Array Initialization**:

   ```c
   int arr[l][m][n] = {...}
   ```

   This defines a 3D array `arr` with `l` layers, `m` rows, and `n` columns.

2. **Dereferencing the First Element**:

   ```c
   ***arr == arr[0][0][0]  // Returns the value of the first element
   ```

   - `***arr` accesses the value at the first element.
   - `arr[0][0][0]` is the value at the first layer, first row, and first column.
   - These are equivalent because `arr` points to the first layer, `*arr` points to the first row, and `**arr` points to the first column, making `***arr` the first element.

3. **Dereferencing the First Row of the First Grid**:

   ```c
   **arr == arr[0][0] == &arr[0][0][0]  // Points to the first element of the first 1D array within the first 2D array
   ```

   - `**arr` points to the first row of the first grid.
   - `arr[0][0]` is the first row of the first grid.
   - `&arr[0][0][0]` is the address of the first element in the first row of the first grid.
   - These are equivalent because `**arr` and `arr[0][0]` are the same as the first row of the first grid, and `&arr[0][0][0]` is the address of the first element in that row.

4. **Dereferencing the First Grid**:

   ```c
   *arr == arr[0] == &arr[0][0] == &&arr[0][0][0]  // Points to the first 2D array within the 3D array
   ```

   - `*arr` points to the first grid.
   - `arr[0]` is the first grid itself.
   - `&arr[0][0]` is the address of the first row in the first grid.
   - `&&arr[0][0][0]` is the address of the address of the first element in the first row of the first grid.
   - These are equivalent because `*arr`, `arr[0]`, and `&arr[0][0]` all point to the first grid.

5. **Referencing the Whole Array**:
   ```c
   &arr == &&arr[0] == &&&arr[0][0][0]  // Points to the whole 3D array
   ```
   - `&arr` is the address of the entire 3D array.
   - `&&arr[0]` is the address of the address of the first grid.
   - `&&&arr[0][0][0]` is the address of the address of the address of the first element in the first row of the first grid.
   - These are equivalent since they all ultimately refer to the entire 3D array.
