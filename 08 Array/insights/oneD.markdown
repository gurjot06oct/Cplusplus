### Pointer vs Array in 1D Array

In a 1D array, pointers and arrays behave similarly because they both reference memory locations within the same frame of reference.

#### Example:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;

// ptr vs arr
std::cout << "Memory addresses after incrementing by 1:" << std::endl;
std::cout << ptr + 1 << std::endl;
std::cout << arr + 1 << std::endl;
std::cout << std::endl;
```

#### Difference

When it comes to pointer and array themselves, there's a difference.

#### Example:

```cpp
std::cout << "Memory addresses of pointers and arrays:" << std::endl;
std::cout << "Address of ptr: " << (unsigned long)&ptr << std::endl;
std::cout << "Address of ptr + 1: " << (unsigned long)(&ptr + 1) << std::endl;
std::cout << "Address of arr: " << (unsigned long)&arr << std::endl;
std::cout << "Address of arr + 1: " << (unsigned long)(&arr + 1) << std::endl;
std::cout << std::endl;
```

#### Explanation

- The `&` operator gives the memory address of a variable.
- When applied to a pointer like `&ptr`, it gives the address of the pointer itself.
- When applied to an array like `&arr`, it gives the address of the entire array.
- Incrementing the pointer (`ptr + 1`) increases its address by the size of the data type it points to.
- Incrementing the array (`arr + 1`) increases its address by the size of the entire array.

The difference arises because the pointer's address is incremented by the size of its type, while the array's address is incremented by the size of the entire array.

For a more detailed explanation, see the Box Demonstration.
