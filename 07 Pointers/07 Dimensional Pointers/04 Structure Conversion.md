## Structure Conversion

In C++, converting between different dimensional structures, involves careful memory management and reinterpretation of pointers. Here, we'll explore how to convert arrays between 1D, 2D, and 3D structures step by step.

### 1D to 2D Conversion

#### Step-by-Step Explanation

1. **Declaration and Allocation**:

   - Declare a 1D array and allocate memory for it.

   ```cpp
   const int size = 12; // Size of 1D array
   int* array1D = new int[size];
   ```

2. **Initialization**:

   - Fill the 1D array with data.

   ```cpp
   for (int i = 0; i < size; ++i) {
       array1D[i] = i + 1;
   }
   ```

3. **Reinterpretation**:

   - Reinterpret the 1D array as a 2D array.

   ```cpp
   const int rows = 3, cols = 4; // Dimensions of 2D array
   int (*array2D)[cols] = reinterpret_cast<int(*)[cols]>(array1D);
   ```

4. **Printing the Reinterpreted Array**:
   - Access and print the elements of the 2D array.
   ```cpp
   for (int i = 0; i < rows; ++i) {
       for (int j = 0; j < cols; ++j) {
           std::cout << array2D[i][j] << " ";
       }
       std::cout << std::endl;
   }
   ```

#### Output Explanation

- **Initialization**: The 1D array is filled with values `1` to `12`.
- **Reinterpretation**: The 1D array `array1D` is reinterpreted as a 2D array `array2D` with dimensions `[3][4]`.
- **Printing**: The reinterpreted 2D array is printed row by row.

### 1D to 3D Conversion

#### Step-by-Step Explanation

1. **Declaration and Allocation**:

   - Declare a 1D array and allocate memory for it.

   ```cpp
   const int size = 24; // Size of 1D array
   int* array1D = new int[size];
   ```

2. **Initialization**:

   - Fill the 1D array with data.

   ```cpp
   for (int i = 0; i < size; ++i) {
       array1D[i] = i + 1;
   }
   ```

3. **Reinterpretation**:

   - Reinterpret the 1D array as a 3D array.

   ```cpp
   const int depth = 2, rows = 3, cols = 4; // Dimensions of 3D array
   int (*array3D)[rows][cols] = reinterpret_cast<int(*)[rows][cols]>(array1D);
   ```

4. **Printing the Reinterpreted Array**:
   - Access and print the elements of the 3D array.
   ```cpp
   for (int k = 0; k < depth; ++k) {
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               std::cout << array3D[k][i][j] << " ";
           }
           std::cout << std::endl;
       }
       std::cout << std::endl;
   }
   ```

#### Output Explanation

- **Initialization**: The 1D array is filled with values `1` to `24`.
- **Reinterpretation**: The 1D array `array1D` is reinterpreted as a 3D array `array3D` with dimensions `[2][3][4]`.
- **Printing**: The reinterpreted 3D array is printed layer by layer, each layer is printed row by row.

### 2D to 1D Conversion

#### Step-by-Step Explanation

1. **Declaration and Allocation**:

   - Declare a 2D array and allocate memory for it.

   ```cpp
   const int rows = 3, cols = 4; // Dimensions of 2D array
   int (*array2D)[cols] = new int[rows][cols];
   ```

2. **Initialization**:

   - Fill the 2D array with data.

   ```cpp
   for (int i = 0; i < rows; ++i) {
       for (int j = 0; j < cols; ++j) {
           array2D[i][j] = i * cols + j + 1;
       }
   }
   ```

3. **Reinterpretation**:

   - Reinterpret the 2D array as a 1D array.

   ```cpp
   const int size = rows * cols; // Size of 1D array
   int* array1D = reinterpret_cast<int*>(array2D);
   ```

4. **Printing the Reinterpreted Array**:
   - Access and print the elements of the 1D array.
   ```cpp
   for (int i = 0; i < size; ++i) {
       std::cout << array1D[i] << " ";
   }
   std::cout << std::endl;
   ```

#### Output Explanation

- **Initialization**: The 2D array `[3][4]` is filled with values `1` to `12`.
- **Reinterpretation**: The 2D array `array2D` is reinterpreted as a 1D array `array1D`.
- **Printing**: The reinterpreted 1D array is printed in a single line.

### 2D to 3D Conversion

#### Step-by-Step Explanation

1. **Declaration and Allocation**:

   - Declare a 2D array and allocate memory for it.

   ```cpp
   const int rows = 3, cols = 4; // Dimensions of 2D array
   int (*array2D)[cols] = new int[rows][cols];
   ```

2. **Initialization**:

   - Fill the 2D array with data.

   ```cpp
   for (int i = 0; i < rows; ++i) {
       for (int j = 0; j < cols; ++j) {
           array2D[i][j] = i * cols + j + 1;
       }
   }
   ```

3. **Reinterpretation**:

   - Allocate memory for a 3D array and copy data from 2D to 3D.

   ```cpp
   const int depth = 2, newrows = 2, newcols = 3;
    int (*array3D)[newrows][newcols] = reinterpret_cast<int(*)[newrows][newcols]>(array2D);
   ```

4. **Printing the Reinterpreted Array**:
   - Access and print the elements of the 3D array.
   ```cpp
   for (int k = 0; k < depth; ++k) {
       for (int i = 0; i < newrows; ++i) {
           for (int j = 0; j < newcols; ++j) {
               std::cout << array3D[k][i][j] << " ";
           }
           std::cout << std::endl;
       }
       std::cout << std::endl;
   }
   ```

#### Output Explanation

- **Initialization**: The 2D array `[3][4]` is filled with values `1` to `12`.
- **Reinterpretation**: The 2D array `array2D` is converted to a 3D array `array3D` with dimensions `[2][2][3]`.
- **Printing**: The reinterpreted 3D array is printed layer by layer, each layer is printed row by row.

### 3D to 1D Conversion

#### Step-by-Step Explanation

1. **Declaration and Allocation**:

   - Declare a 3D array and allocate memory for it.

   ```cpp
   const int depth = 2, rows = 3, cols = 4; // Dimensions of 3D array
   int (*array3D)[rows][cols] = new int[depth][rows][cols];
   ```

2. **Initialization**:

   - Fill the 3D array with data.

   ```cpp
   for (int k = 0; k < depth; ++k) {
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               array3D[k][i][j] = k * rows * cols + i * cols + j + 1;
           }
       }
   }
   ```

3. **Reinterpretation**:

   - Reinterpret the 3D array as a 1D array.

   ```cpp
   const int size = depth * rows * cols; // Size of 1D array
   int* array1D = reinterpret_cast<int*>(array3D);
   ```

4. **Printing the Reinterpreted Array**:

   - Access and print the elements of the 1D array.

   ```cpp


   for (int i = 0; i < size; ++i) {
       std::cout << array1D[i] << " ";
   }
   std::cout << std::endl;
   ```

#### Output Explanation

- **Initialization**: The 3D array `[2][3][4]` is filled with values `1` to `24`.
- **Reinterpretation**: The 3D array `array3D` is reinterpreted as a 1D array `array1D`.
- **Printing**: The reinterpreted 1D array is printed in a single line.

### 3D to 2D Conversion

#### Step-by-Step Explanation

1. **Declaration and Allocation**:

   - Declare a 3D array and allocate memory for it.

   ```cpp
   const int depth = 2, rows = 3, cols = 4; // Dimensions of 3D array
   int (*array3D)[rows][cols] = new int[depth][rows][cols];
   ```

2. **Initialization**:

   - Fill the 3D array with data.

   ```cpp
   for (int k = 0; k < depth; ++k) {
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               array3D[k][i][j] = k * rows * cols + i * cols + j + 1;
           }
       }
   }
   ```

3. **Reinterpretation**:

   - Reinterpret the 3D array as a 2D array.

   ```cpp
   const int rows2D = depth * rows, cols2D = cols; // Dimensions of 2D array
   int (*array2D)[cols2D] = reinterpret_cast<int(*)[cols2D]>(array3D);
   ```

4. **Printing the Reinterpreted Array**:
   - Access and print the elements of the 2D array.
   ```cpp
   for (int i = 0; i < rows2D; ++i) {
       for (int j = 0; j < cols2D; ++j) {
           std::cout << array2D[i][j] << " ";
       }
       std::cout << std::endl;
   }
   ```

#### Output Explanation

- **Initialization**: The 3D array `[2][3][4]` is filled with values `1` to `24`.
- **Reinterpretation**: The 3D array `array3D` is reinterpreted as a 2D array `array2D` with dimensions `[6][4]`.
- **Printing**: The reinterpreted 2D array is printed row by row.
