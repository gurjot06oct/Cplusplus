### Address Calculation with Array Initialization

#### 1D Array Initialization

```cpp
int arr[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
```

1. `arr[5]`
2. `&arr + 1`
3. `*(arr + 3)`
4. `arr + 4`
5. `&arr[10]`
6. `arr + 5`
7. `*(arr + 7)`
8. `&arr + 2`
9. `arr + 3`
10. `*(arr + 6)`
11. `&arr[4]`
12. `arr + 8`
13. `*(arr + 9)`
14. `arr[2]`
15. `&arr[6]`
16. `*(arr + 5)`
17. `&arr + 3`
18. `arr + 1`
19. `*(arr + 4)`
20. `&arr[7]`

#### 2D Array Initialization

```cpp
int arr[3][5] = {
    {0, 1, 2, 3, 4},
    {5, 6, 7, 8, 9},
    {10, 11, 12, 13, 14}
};
```

1. `arr[1][2]`
2. `&arr + 1`
3. `*(arr + 1) + 2`
4. `arr + 2`
5. `&arr[1][3]`
6. `*(arr + 1) + 1`
7. `arr[2] + 3`
8. `&arr + 3`
9. `*(arr + 2)`
10. `arr[0][1]`
11. `**(arr + 1)`
12. `arr[1] + 2`
13. `&arr[2][2]`
14. `*(*(arr + 2) + 1)`
15. `arr + 3`
16. `&arr[2][1]`
17. `**(arr + 3)`
18. `*(arr[2] + 1)`
19. `&arr + 2`
20. `*(*(arr + 1) + 3)`

#### 3D Array Initialization

```cpp
int arr[2][3][4] = {
    {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    },
    {
        {12, 13, 14, 15},
        {16, 17, 18, 19},
        {20, 21, 22, 23}
    }
};
```

1. `arr[1][1][2]`
2. `&arr + 1`
3. `*(arr + 1) + 1`
4. `arr + 2`
5. `&arr[1][2][1]`
6. `*(arr + 1) + 2`
7. `arr[1][2] + 3`
8. `&arr + 3`
9. `*(*(arr + 2))`
10. `arr[0][1][1]`
11. `***(&arr + 1)`
12. `arr[1] + 2`
13. `&arr[2][1][1]`
14. `*(*(*(arr + 2) + 1))`
15. `arr + 3`
16. `&arr[2][0][2]`
17. `***(&arr + 3)`
18. `arr[2] + 1`
19. `&arr + 2`
20. `*(*(*(arr + 1) + 3))`

### Answers

#### 1D Arrays

1. `arr[5]`: `Base Address + 5 * sizeof(int)`

   - Result: `arr + 20`

2. `&arr + 1`: `Base Address + 15 * sizeof(int)`

   - Result: `arr + 60`

3. `*(arr + 3)`: `Value at (Base Address + 3 * sizeof(int))`

   - Result: `3`

4. `arr + 4`: `Base Address + 4 * sizeof(int)`

   - Result: `arr + 16`

5. `&arr[10]`: `Base Address + 10 * sizeof(int)`

   - Result: `arr + 40`

6. `arr + 5`: `Base Address + 5 * sizeof(int)`

   - Result: `arr + 20`

7. `*(arr + 7)`: `Value at (Base Address + 7 * sizeof(int))`

   - Result: `7`

8. `&arr + 2`: `Base Address + 15 * sizeof(int)`

   - Result: `arr + 60`

9. `arr + 3`: `Base Address + 3 * sizeof(int)`

   - Result: `arr + 12`

10. `*(arr + 6)`: `Value at (Base Address + 6 * sizeof(int))`

    - Result: `6`

11. `&arr[4]`: `Base Address + 4 * sizeof(int)`

    - Result: `arr + 16`

12. `arr + 8`: `Base Address + 8 * sizeof(int)`

    - Result: `arr + 32`

13. `*(arr + 9)`: `Value at (Base Address + 9 * sizeof(int))`

    - Result: `9`

14. `arr[2]`: `Base Address + 2 * sizeof(int)`

    - Result: `arr + 8`

15. `&arr[6]`: `Base Address + 6 * sizeof(int)`

    - Result: `arr + 24`

16. `*(arr + 5)`: `Value at (Base Address + 5 * sizeof(int))`

    - Result: `5`

17. `&arr + 3`: `Base Address + 15 * sizeof(int)`

    - Result: `arr + 60`

18. `arr + 1`: `Base Address + 1 * sizeof(int)`

    - Result: `arr + 4`

19. `*(arr + 4)`: `Value at (Base Address + 4 * sizeof(int))`

    - Result: `4`

20. `&arr[7]`: `Base Address + 7 * sizeof(int)`
    - Result: `arr + 28`

#### 2D Arrays

1. `arr[1][2]`: `Base Address + ((1 * num_cols + 2) * sizeof(int))`

   - Given `num_cols = 5`
   - Result: `arr + 12`

2. `&arr + 1`: `Base Address + (total_elements * sizeof(int))`

   - Given `total_elements = 15`
   - Result: `arr + 60`

3. `*(arr + 1) + 2`: `Value at (Base Address + (1 * num_cols + 2) * sizeof(int))`

   - Given `num_cols = 5`
   - Result: `7`

4. `arr + 2`: `Base Address + (2 * num_cols * sizeof(int))`

   - Given `num_cols = 5`
   - Result: `arr + 20`

5. `&arr[1][3]`: `Base Address + ((1 * num_cols + 3) * sizeof(int))`

   - Given `num_cols = 5`
   - Result: `arr + 16`

6. `*(arr + 1) + 1`: `Value at (Base Address + (1 * num_cols + 1) * sizeof(int))`

   - Given `num_cols = 5`
   - Result: `6`

7. `arr[2] + 3`: `Base Address + ((2 * num_cols + 3) * sizeof(int))`

   - Given `num_cols = 5`
   - Result: `arr + 23`

8. `&arr + 3`: `Base Address + (total_elements * sizeof(int))`

   - Given `total_elements = 15`
   - Result: `arr + 60`

9. `*(arr + 2)`: `Value at (Base Address + (2 * num_cols + 0) * sizeof(int))`

   - Given `num_cols = 5`
   - Result: `10`

10. `arr[0][1]`: `Base Address + (1 * num_cols + 1) * sizeof(int)`

    - Given `num_cols = 5`
    - Result: `arr + 5`

11. `**(arr + 1)`: `Value at (Base Address + (1 * num_cols + 0) * sizeof(int))`

    - Given `num_cols = 5`
    - Result: `5`

12. `arr[1] + 2`: `Base Address + (1 * num_cols + 2) * sizeof(int)`

    - Given `num_cols = 5`
    - Result: `arr + 12`

13. `&arr[2][2]`: `Base Address + ((2 * num_cols + 2) * sizeof(int))`

    - Given `num_cols = 5`
    - Result: `arr + 22`

14. `*(*(arr + 2) + 1)`: `Value at (Base Address + (2 * num_cols + 1) * sizeof(int))`

    - Given `num_cols = 5`
    - Result: `21`

15. `arr + 3`: `Base Address + (3 * num_cols * sizeof(int))`

    - Given `num_cols = 5`
    - Result: `arr + 30`

16. `&arr[2][1]`: `Base Address + ((2 * num_cols + 1) * sizeof(int))`

    - Given `num_cols = 5`
    - Result: `arr + 21`

17. `**(arr + 3)`: `Value at (Base Address + (3 * num_cols + 0) * sizeof(int))`

    - Given `num_cols = 5`
    - Result: `15`

18. `*(arr[2] + 1)`: `Value at (Base Address + (2 * num_cols + 1) * sizeof(int))`

    - Given `num_cols = 5`
    - Result: `21`

19. `&arr + 2`: `Base Address + (total_elements * sizeof(int))`

    - Given `total_elements = 15`
    - Result: `arr + 60`

20. `*(*(arr + 1) + 3)`: `Value at (Base Address + (1 * num_cols + 3) * sizeof(int))`
    - Given `num_cols = 5`
    - Result: `9`

#### 3D Arrays

1. `arr[1][1][2]`: `Base Address + ((1 * num_rows * num_cols + 1 * num_cols + 2) * sizeof(int))`

   - Given `num_rows = 2`, `num_cols = 3`
   - Result: `arr + 14`

2. `&arr + 1`: `Base Address + (total_elements * sizeof(int))`

   - Given `total_elements = 24`
   - Result: `arr + 96`

3. `*(arr + 1) + 1`: `Value at (Base Address + (1 * num_cols + 1) * sizeof(int))`

   - Given `num_cols = 12`
   - Result: `5`

4. `arr + 2`: `Base Address + (2 * num_rows * num_cols * sizeof(int))`

   - Given `num_rows = 2`, `num_cols = 3`
   - Result: `arr + 24`

5. `&arr[1][2][1]`: `Base Address + ((1 * num_rows * num_cols + 2 * num_cols + 1) * sizeof(int))`

   - Given `num_rows = 2`, `num_cols = 3`
   - Result: `arr + 13`

6. `*(arr + 1) + 2`: `Value at (Base Address + (1 * num_cols + 2) * sizeof(int))`

   - Given `num_cols = 3`
   - Result: `8`

7. `arr[1][2] + 3`: `Base Address + ((1 * num_rows * num_cols + 2 * num_cols + 3) * sizeof(int))`

   - Given `num_rows = 2`, `num_cols = 3`
   - Result: `arr + 17`

8. `&arr + 3`: `Base Address + (total_elements * sizeof(int))`

   - Given `total_elements = 24`
   - Result: `arr + 96`

9. `*(*(arr + 2))`: `Value at (Base Address + (0 * num_rows * num_cols + 0 * num_cols + 0) * sizeof(int))`

   - Given `num_rows = 2`, `num_cols = 3`
   - Result: `12`

10. `arr[0][1][1]`: `Base Address + ((0 * num_rows * num_cols + 1 * num_cols + 1) * sizeof(int))`

    - Given `num_rows = 2`, `num_cols = 3`
    - Result: `5`

11. `***(&arr + 1)`: `Value at (Base Address + (1 * num_cols + 0) * sizeof(int))`

    - Given `num_cols = 3`
    - Result: `0`

12. `arr[1] + 2`: `Base Address + ((1 * num_rows * num_cols + 2 * num_cols + 0) * sizeof(int))`

    - Given `num_rows = 2`, `num_cols = 3`
    - Result: `10`

13. `&arr[2][1][1]`: `Base Address + ((2 * num_rows * num_cols + 1 * num_cols + 1) * sizeof(int))`

    - Given `num_rows = 2`, `num_cols = 3`
    - Result: `arr + 16`

14. `*(*(*(arr + 2) + 1))`: `Value at (Base Address + (1 * num_cols + 1) * sizeof(int))`

    - Given `num_cols = 3`
    - Result: `17`

15. `arr + 3`: `Base Address + (3 * num_rows * num_cols * sizeof(int))`

    - Given `num_rows = 2`, `num_cols = 3`
    - Result: `arr + 36`

16. `&arr[2][0][2]`: `Base Address + ((2 * num_rows * num_cols + 0 * num_cols + 2) * sizeof(int))`

    - Given `num_rows = 2`, `num_cols = 3`
    - Result: `arr + 14`

17. `***(&arr + 3)`: `Value at (Base Address + (0 * num_rows * num_cols + 0 * num_cols + 0) * sizeof(int))`

    - Given `num_rows = 2`, `num_cols = 3`
    - Result: `12`

18. `*(arr[2] + 1)`: `Value at (Base Address + (1 * num_cols + 1) * sizeof(int))`

    - Given `num_cols = 3`
    - Result: `17`

19. `&arr + 2`: `Base Address + (total_elements * sizeof(int))`

    - Given `total_elements = 24`
    - Result: `arr + 96`

20. `*(*(*(arr + 1) + 3))`: `Value at (Base Address + (3 * num_cols + 0) * sizeof(int))`
    - Given `num_cols = 3`
    - Result: `15`
