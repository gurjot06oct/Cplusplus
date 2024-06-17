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
