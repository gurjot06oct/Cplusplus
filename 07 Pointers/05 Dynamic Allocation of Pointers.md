# Dynamic Allocation of Pointers

## Types for Dynamic Allocation

### On the Basis of Number:

1. **Single Allocation**: Allocate memory for the `type T`.
2. **Multi Allocation**: Allocate memory for an array of `type T`.

### On the Basis of Level:

1. **Single Pointer Allocation**: Allocate memory for the `type T`.
2. **Double Pointer Allocation**: Allocate memory for a pointer to `type T`.
3. **Triple Pointer Allocation**: Allocate memory for a pointer to a pointer to `type T`.

## Single Allocation

### **Single Pointer**:

#### **Declaration then Initialization**:

```cpp
T* ptr = new T;
*T = value;
```

- Allocates memory for a pointer to a `type T`.
- Sets the value of the pointer to `value`.

#### **Declaration with Initialization**:

```cpp
T* ptr = new T(value);
```

- Allocates memory for a single `type T` and initializes it to `value`.

#### **Returns**: A pointer (`T*`) to the allocated memory of type `T`.

### **Double Pointer**:

#### **Declaration then Initialization**:

```cpp
T** ptr2ptr = new T*;
*ptr2ptr = ptr;
```

- Allocates memory for a pointer to a `type T`.
- Sets the value of the pointer to point to `ptr`.

#### **Declaration with Initialization**:

```cpp
T** ptr2ptr = new T*(ptr);
```

- Allocates memory for a pointer to a `type T` and initializes it to point to `ptr`.

#### **Returns**: A pointer (`T**`) to the allocated memory of type `T*`.

### **Triple Pointer**:

#### **Declaration then Initialization**:

```cpp
T*** ptr2ptr2ptr = new T**;
*ptr2ptr2ptr = ptr2ptr;
```

- Allocates memory for a pointer to a pointer to a `type T`.
- Sets the value of the pointer to point to `ptr2ptr`.

#### **Declaration with Initialization**:

```cpp
T*** ptr2ptr2ptr = new T**(ptr2ptr);
```

- Allocates memory for a pointer to a pointer to a `type T` and initializes it to point to `ptr2ptr`.

#### **Returns**: A pointer (`T***`) to the allocated memory of type `T**`.

### **Memory Deallocation**:

```cpp
delete ptr;
delete ptr2ptr;
delete ptr2ptr2ptr;
```

- Each dynamically allocated memory block is freed in the reverse order of allocation to avoid memory leaks.

## Multi Allocation

### Multi Allocation with Continuous Memory

When we allocate memory for an array, we create a contiguous block of memory large enough to hold the specified number of elements. This block can be accessed using pointers and manipulated efficiently.

**Note** - Before delving into multiple allocations with pointers, it's crucial to first grasp pointer arithmetic.

### **Single Pointer Allocation**:

Allocate memory for an array of type `T`.

#### **Declaration then Initialization**:

```cpp
T* ptrArray = new T[size];
for (int i = 0; i < size; ++i) {
    *(ptrArray + i) = value*i;
}
```

- Allocates memory for an array of `size` elements of type `T`
- Sets the value of each element.

#### **Declaration with Initialization**:

```cpp
T* ptrArray = new T[size]{value1, value2, value3, ...};
```

- Allocates memory for an array of `size` elements of type `T` and initializes each element using the initializer list.

#### **Returns**: A pointer (`T*`) to the first element of the allocated memory of type `T`.

### **Double Pointer Allocation**:

Allocate memory for an array of pointers to type `T`.

#### **Declaration then Initialization**:

```cpp
T** ptr2ptrArray = new T*[size];
for (int i = 0; i < size; ++i) {
    ptr2ptrArray[i] = new T;
}
```

- Allocates memory for an array of `size` pointers to type `T`.
- Allocates memory for each element in the array.

#### **Declaration with Initialization**:

```cpp
T** ptr2ptrArray = new T*[size]{new T(value1), new T(value2), new T(value3), ...};
```

- Allocates memory for an array of `size` pointers to type `T` and initializes each element using the initializer list.

#### **Returns**: A pointer (`T**`) to the first element of the allocated memory of type `T*`.

### **Triple Pointer Allocation**:

Allocate memory for an array of pointers to pointers to type `T`.

#### **Declaration then Initialization**:

```cpp
T*** ptr2ptr2ptrArray = new T**[size];
for (int i = 0; i < size; ++i) {
    ptr2ptr2ptrArray[i] = new T*;
    *ptr2ptr2ptrArray[i] = new T;
}
```

- Allocates memory for an array of `size` pointers to pointers to type `T`.
- Allocates memory for each pointer to type `T` in the array.
- Allocates memory for each `T` that each pointer points to.

#### **Declaration with Initialization**:

```cpp
T*** ptr2ptr2ptrArray = new T**[size]{new T*(new T(value1)), new T*(new T(value2)), new T*(new T(value3)), ...};
```

- Allocates memory for an array of `size` pointers to pointers to type `T`.
- Initializes each pointer to point to a new `T` using the initializer list.

#### **Returns**: A pointer (`T***`) to the first element of the allocated memory of type `T**`.

### **Memory Deallocation**:

**Single Pointer Allocation**:

```cpp
delete[] ptrArray;
```

- Deallocates memory for an array of type `T`.

**Double Pointer Allocation**:

```cpp
for (int i = 0; i < size; ++i) {
    delete ptr2ptrArray[i];
}
delete[] ptr2ptrArray;
```

- Deallocates memory for each element in the array of pointers to type `T`.
- Deallocates memory for the array of pointers.

**Triple Pointer Allocation**:

```cpp
for (int i = 0; i < size; ++i) {
    delete *ptr2ptr2ptrArray[i];
    delete ptr2ptr2ptrArray[i];
}
delete[] ptr2ptr2ptrArray;
```

- Deallocates memory for each `T` that each pointer points to.
- Deallocates memory for each pointer to type `T`.
- Deallocates memory for the array of pointers to pointers to type `T`.

This structure ensures proper memory management and avoids memory leaks by freeing memory in the reverse order of allocation.
