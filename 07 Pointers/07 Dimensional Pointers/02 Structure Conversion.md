## Structure Conversion

Structure conversion in arrays involves reinterpretation of array pointers to change the way elements are accessed, effectively altering the apparent dimensions of the array while preserving its underlying structure. This process is particularly useful when adapting array data for different computational requirements or when interfacing with libraries that expect specific data shapes.

### 2D Structure Conversion

1. **Declaration and Allocation**:

   ```cpp
   const unsigned rows = 4, columns = 5;
   int(*array2D)[columns] = new int[rows][columns];
   ```

2. **Initialization**:

   ```cpp
   for (int row = 0; row < rows; row++)
   {
       for (int col = 0; col < columns; col++)
       {
           array2D[row][col] = row * columns + 1 + col;
           std::cout << array2D[row][col] << " ";
       }
       std::cout << std::endl;
   }
   ```

3. **Reinterpretation**:

   ```cpp
   const unsigned newrows = 2, newcolumns = 10;
   int(*reinterpretedArray2D)[newcolumns] = reinterpret_cast<int(*)[newcolumns]>(array2D);
   ```

4. **Printing the Reinterpreted Array**:
   ```cpp
   for (int row = 0; row < newrows; row++)
   {
       for (int col = 0; col < newcolumns; col++)
       {
           std::cout << reinterpretedArray2D[row][col] << " ";
       }
       std::cout << std::endl;
   }
   ```

#### Output Explanation

The original 2D array of `[4][5]`:

```
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
```

Reinterpreted as `[2][10]`:

```
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
```

### 3D Structure Conversion

#### Step-by-Step Explanation

1. **Declaration and Allocation**:

   ```cpp
   const unsigned depth = 4, rows = 4, columns = 4;
   int(*array3D)[rows][columns] = new int[depth][rows][columns];
   ```

2. **Initialization**:

   ```cpp
   for (int layer = 0; layer < depth; layer++)
   {
       for (int row = 0; row < rows; row++)
       {
           for (int col = 0; col < columns; col++)
           {
               array3D[layer][row][col] = layer * depth * columns + row * columns + 1 + col;
               std::cout << array3D[layer][row][col] << " ";
           }
           std::cout << std::endl;
       }
       std::cout << std::endl;
   }
   ```

3. **Reinterpretation**:

   ```cpp
   int(*reinterpretedArray3D)[8][4] = reinterpret_cast<int(*)[8][4]>(array3D);
   ```

4. **Printing the Reinterpreted Array**:
   ```cpp
   for (int layer = 0; layer < 2; layer++)
   {
       for (int row = 0; row < 8; row++)
       {
           for (int col = 0; col < 4; col++)
           {
               std::cout << reinterpretedArray3D[layer][row][col] << " ";
           }
           std::cout << std::endl;
       }
       std::cout << std::endl;
   }
   ```

#### Output Explanation

The original 3D array of `[4][4][4]`:

```
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

17 18 19 20
21 22 23 24
25 26 27 28
29 30 31 32

33 34 35 36
37 38 39 40
41 42 43 44
45 46 47 48

49 50 51 52
53 54 55 56
57 58 59 60
61 62 63 64
```

Reinterpreted as `[2][8][4]`:

```
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
17 18 19 20
21 22 23 24
25 26 27 28
29 30 31 32

33 34 35 36
37 38 39 40
41 42 43 44
45 46 47 48
49 50 51 52
53 54 55 56
57 58 59 60
61 62 63 64
```

### Cleanup

Remember to clean up the allocated memory:

For the 2D array:

```cpp
delete[] array2D;
```

For the 3D array:

```cpp
delete[] array3D;
```
