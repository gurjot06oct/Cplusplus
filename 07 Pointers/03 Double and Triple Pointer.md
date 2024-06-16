### Double and Triple Pointers in C++

A double pointer in C++ refers to a pointer that points to another pointer. It is used to store the address of another pointer, enabling indirect access to variables or memory locations. Double pointers are essential for tasks involving dynamic memory allocation and manipulation of arrays of pointers.

#### Declaration Syntax

The syntax for declaring a double pointer involves specifying two levels of indirection:

```cpp
type** doublePtr;
```

- Here, `doublePtr` is a double pointer that can hold the address of another pointer (`type*`).

#### Common Use Cases

1. **Dynamic Memory Allocation**: Managing memory dynamically by allocating and deallocating memory blocks.
2. **Function Arguments**: Modifying pointer values within functions to manipulate data indirectly or to return multiple values.
3. **Arrays of Pointers**: Dynamically creating and managing arrays of pointers to handle complex data structures.
4. **Linked Lists**: Implementing linked lists where each node contains a pointer to the next node.

#### Pointer to Pointer to Pointer (Triple Pointer)

In more complex scenarios, it's possible to use a triple pointer, which points to a pointer to a pointer:

```cpp
type*** triplePtr;
```

- This concept extends to Multidimensional Array.

### Pointer Basics

#### Single Pointer

A single pointer (`ptr1`) is defined to point to an integer:

```cpp
int value = 5;
int *ptr1 = &value;
```

Here, `ptr1` holds the memory address of `value`, allowing indirect access to its contents.

#### Double Pointer

A double pointer (`ptr2`) is then defined to point to the single pointer `ptr1`:

```cpp
int **ptr2 = &ptr1;
```

`ptr2` now holds the address of `ptr1`, effectively creating an additional layer of indirection.

### Dereferencing Pointers

Dereferencing pointers allows us to access the value stored at the memory address they point to.

#### Dereferencing `ptr1`

```cpp
int dereferenced_value = *ptr1;
```

This statement retrieves the value stored at `value` through `ptr1`.

#### Dereferencing `ptr2`

```cpp
int double_dereferenced_value = **ptr2;
```

Here, `**ptr2` first retrieves `ptr1` using `ptr2`, and then accesses the value stored at `value` through `ptr1`.

### Pointer to a Pointer Arithmetic

In C++, pointer arithmetic allows us to manipulate pointers by adding or subtracting integers to/from them. This operation is influenced by the size of the data type the pointer points to (`sizeof(pointer)` bytes).

```cpp
int value1 = 5;
int *ptr1 = &value1;        // Pointer to value1
int **doublePtr = &ptr1;    // Double pointer to ptr1
```

#### Initial Address

```cpp
std::cout << "Address of ptr1: " << reinterpret_cast<unsigned long>(doublePtr) << std::endl;
```

Here, `doublePtr` stores the address of `ptr1`, which in turn stores the address of `value1`.

#### Incrementing Pointer to a Pointer Pointer

```cpp
doublePtr++;
```

In pointer arithmetic, adding 1 to `doublePtr` increments the address it holds by `sizeof(pointer)` bytes cause it points a pointer. On 64-bit systems, where a pointer typically occupies 8 bytes, `doublePtr++` would advance by 8 bytes. On 32-bit systems, where a pointer is usually 4 bytes, the increment would be by 4 bytes.

#### Printing After Arithmetic

```cpp
std::cout << "Address of ptr1 after arithmetic: " << reinterpret_cast<unsigned long>(doublePtr) << std::endl;
```

After the arithmetic operation (`doublePtr++`), we print the updated address stored in `doublePtr`.

### **Note**:

`triplePtr` will have a similar effect because it also points to a pointer.
