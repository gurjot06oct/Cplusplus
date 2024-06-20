## Dynamic Arrays:

Dynamic arrays, unlike static arrays, allow for size adjustments during runtime. However, their underlying conceptual representation in memory and access patterns through pointers remain analogous to static arrays. However, there are some difference which will be disscusessed.

### **1D Dynamic Array**:

    ```cpp
    int *arr = new int[5]{1, 2, 3, 4, 5};
    ```

    ```
    +--+ +--+ +--+ +--+ +--+
    | 1| | 2| | 3| | 4| | 5|
    +--+ +--+ +--+ +--+ +--+
    ```

### **2D Dynamic Array**:

    ```cpp
    int (*arr2D)[5] = new int[2][5]{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
    };
    ```

    ```
    +----------------------------+  +----------------------------+
    |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |
    |  | 1| | 2| | 3| | 4| | 5|  |  |  | 6| | 7| | 8| | 9| |10|  |
    |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |
    +----------------------------+  +----------------------------+
    ```

### **3D Dynamic Array**:

    ```cpp
    int (*arr3D)[2][5] = new int[2][5]{
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
    +------------------------------------------------------------------+
    |  +----------------------------+  +----------------------------+  |
    |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |
    |  |  | 1| | 2| | 3| | 4| | 5|  |  |  | 6| | 7| | 8| | 9| |10|  |  |
    |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |
    |  +----------------------------+  +----------------------------+  |
    +------------------------------------------------------------------+

    +------------------------------------------------------------------+
    |  +----------------------------+  +----------------------------+  |
    |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |
    |  |  |11| |12| |13| |14| |15|  |  |  |16| |17| |18| |19| |20|  |  |
    |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |
    |  +----------------------------+  +----------------------------+  |
    +------------------------------------------------------------------+
    ```

**Important**:

- `arr`, `arr2D`, and `arr3D` are similar to static arrays, but the difference lies in how they are referenced.
- When an array is created dynamically, it decays into a pointer to its first element and loses its enclosing frame structure, unlike a static array which retains its enclosing frame structure.
- This means, `&arr`, `&arr2D`, and `&arr3D` point to the memory location where the array pointer is stored, not the entire array itself.
