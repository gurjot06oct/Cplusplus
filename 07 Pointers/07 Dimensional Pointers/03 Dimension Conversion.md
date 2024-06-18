## Dimension Conversion

Dimension conversion in arrays involves reinterpretation of array pointers to change the way elements are accessed, effectively altering the apparent dimensions of the array while preserving its underlying structure. This process is particularly useful when adapting array data for different computational requirements or when interfacing with libraries that expect specific data shapes.

### 2D Dimension Conversion

1. **Declaration and Allocation**:

   ```cpp
   const unsigned rows = 4, columns = 5;
   int(*array2D)[columns] = new int[rows][columns];
   ```

2. **Initialization**:

   ```cpp
   for (int i = 0; i < rows; i++)
   {
       for (int j = 0; j < columns; j++)
       {
           array2D[i][j] = i * columns + j + 1;
           std::cout << array2D[i][j] << " ";
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
   for (int i = 0; i < newrows; i++)
   {
       for (int j = 0; j < newcolumns; j++)
       {
           std::cout << reinterpretedArray2D[i][j] << " ";
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

### 3D Dimension Conversion

1. **Declaration and Allocation**:

   ```cpp
   const unsigned depth = 4, rows = 4, columns = 4;
   int(*array3D)[rows][columns] = new int[depth][rows][columns];
   ```

2. **Initialization**:

   ```cpp
   for (int i = 0; i < depth; i++)
   {
       for (int j = 0; j < rows; j++)
       {
           for (int k = 0; k < columns; k++)
           {
               array3D[i][j][k] = i * rows * columns + j * columns + 1 + k;
               std::cout << array3D[i][j][k] << " ";
           }
           std::cout << std::endl;
       }
       std::cout << std::endl;
   }
   ```

3. **Reinterpretation**:

   ```cpp
   const unsigned newdepth=2, newrows = 8, newcolumns = 4;
   int(*reinterpretedArray3D)[newrows][newcolumns] = reinterpret_cast<int(*)[newrows][newcolumns]>(array3D);
   ```

4. **Printing the Reinterpreted Array**:
   ```cpp
   for (int i = 0; i < newdepth; i++)
   {
       for (int j = 0; j < newrows; j++)
       {
           for (int k = 0; k < newcolumns; k++)
           {
               std::cout << reinterpretedArray3D[i][j][k] << " ";
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
