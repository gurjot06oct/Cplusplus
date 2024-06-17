## Level Pointers (int\*, int**, int\***)

### Single Pointer (`int*`)

A single pointer is a variable that stores the memory address of another variable.

#### Declaration and Initialization

```cpp
int value = 5;
int *ptr1 = &value;
```

- `ptr1` holds the memory address of `value`.

#### Usage

Single pointers are used for:

1. **Dynamic Memory Allocation**: Allocating memory for single variables or arrays.
2. **Function Arguments**: Passing large structures or arrays by reference.
3. **Simple Data Structures**: Managing data structures like linked lists.

### Double Pointer (`int**`)

A double pointer is a pointer that points to another pointer, effectively allowing for an extra level of indirection.

#### Declaration and Initialization

```cpp
int *ptr1 = new int(5);
int **ptr2 = &ptr1;
```

- `ptr2` holds the address of `ptr1`.

#### Usage

Double pointers are used for:

1. **Dynamic Memory Allocation**: Managing arrays of pointers.
2. **Function Arguments**: Functions can modify the pointer itself.
3. **Complex Data Structures**: Managing data structures like 2D arrays, trees, and graphs.

### Triple Pointer (`int***`)

A triple pointer is a pointer that points to a double pointer, adding yet another level of indirection.

#### Declaration and Initialization

```cpp
int **ptr2 = new int*[5];
for (int i = 0; i < 5; ++i) {
    ptr2[i] = new int(i);
}
int ***ptr3 = &ptr2;
```

- `ptr3` holds the address of `ptr2`.

#### Usage

Triple pointers are used for:

1. **Dynamic Memory Allocation**: Managing arrays of double pointers, which can be used for 3D arrays.
2. **Function Arguments**: Passing complex data structures to functions.
3. **Very Complex Data Structures**: Managing structures like 3D arrays or advanced data structures.
