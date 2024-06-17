## Dynamic Allocation of an Array using Pointers

### 1D or Single Dimension

#### without Initialization

```cpp
int* arr = new int[size]; // Dynamic allocation of array of integers
```

**Access and print elements (uninitialized)**:

```
for (int i = 0; i < size; ++i) {
    cout << arr[i] << " "; // Output will be garbage values
}
cout << endl;

```

**Deallocate memory**:

```cpp
delete[] arr;
```

**Explanation:**

- `new int[size];` dynamically allocates an array of `size` integers on the heap.
- Elements in the array are uninitialized and will contain garbage values.
- Looping through `arr` prints these uninitialized values.

#### Initialization with Initializer List

```cpp
int* arr = new int[size]{10, 20, 30, 40, 50}; // Dynamic allocation with initializer list
```

**Access and print elements (initialized)**:

```cpp
for (int i = 0; i < size; ++i) {
    cout << arr[i] << " "; // Output will be 10 20 30 40 50
}
cout << endl;

```

**Deallocate memory**:

```cpp
delete[] arr;
```

**Explanation:**

- `new int[size]{10, 20, 30, 40, 50};` dynamically allocates an array of `size` integers on the heap and initializes it with values `{10, 20, 30, 40, 50}`.
- Looping through `arr` prints these initialized values.

### Key Points:

- **Dynamic Allocation:** `new int[size]` allocates memory on the heap for an array of `size` integers.
- **Initialization:**
  - Without initialization, the elements contain garbage values until explicitly set.
  - With initialization using `{}` or `()` syntax initializes the elements with specified values.
- **Memory Deallocation:** `delete[] arr;` deallocates the dynamically allocated memory to avoid memory leaks.

### Multi Dimension
