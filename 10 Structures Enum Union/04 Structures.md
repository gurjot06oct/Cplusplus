### Structures in C++:

In C++, structures are user-defined data types that allow you to group together variables of different data types under a single name. This grouping makes it easier to organize and manipulate related data. Unlike classes, structures default to public access, meaning their members are accessible from outside the structure without explicit access specifiers.

```cpp
struct Person
{
    char name[50];
    int age;
    float salary;
};
```

### Self-Referential Structures in C++:

Self-referential structures, also known as linked structures, are structures that contain a pointer to another instance of the same structure type. This concept is commonly used in data structures like linked lists, trees, and graphs.

```cpp
struct Node
{
    int data;
    Node *next;
};
```

### Pointer to Structure in C++:

Pointers to structures in C++ allow you to manipulate structures dynamically and efficiently. You can allocate memory for a structure dynamically using `new` and access its members using the arrow operator `->`.

```cpp
Person *ptrPerson = new Person;
ptrPerson->age = 25;
```

## Advanced Structures 
In C++, when you have a structure containing an array and you want to copy it to another variable of the same structure type, you can do so directly by using the assignment operator. The C++ compiler automatically provides a default copy constructor and assignment operator for such structures, which perform a shallow copy of the entire structure, including the array.

### Example
```cpp
#include <iostream>
#include <cstring> // For std::strcpy and std::strlen

struct MyStruct {
    int arr[5];
    int otherData;
    char* name; // Pointer to dynamically allocated memory (string)
};

int main() {
    // Initialize a structure with an array and a dynamically allocated string
    MyStruct struct1 = {{1, 2, 3, 4, 5}, 10, nullptr};

    // Allocate memory for the name and copy a string into it
    struct1.name = new char[20];
    std::strcpy(struct1.name, "Original Name");

    // Copy struct1 to struct2 (shallow copy)
    MyStruct struct2 = struct1;

    // Modify struct2 to demonstrate shallow copy behavior
    struct2.arr[0] = 100;
    struct2.otherData = 20;
    std::strcpy(struct2.name, "Modified Name");

    // Display contents of struct1 and struct2
    std::cout << "struct1.arr: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << struct1.arr[i] << " ";
    }
    std::cout << "\nstruct1.otherData: " << struct1.otherData << std::endl;
    std::cout << "struct1.name: " << struct1.name << std::endl;

    std::cout << "struct2.arr: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << struct2.arr[i] << " ";
    }
    std::cout << "\nstruct2.otherData: " << struct2.otherData << std::endl;
    std::cout << "struct2.name: " << struct2.name << std::endl;

    // Clean up dynamically allocated memory
    delete[] struct1.name;
    // Since struct2.name points to the same memory, avoid double delete
    struct2.name = nullptr; // Prevent struct2 from deleting the same memory

    return 0;
}
```

### Explanation

1. **Structure Definition**:
   - `MyStruct` now contains an array `arr` of 5 integers, an integer `otherData`, and a pointer `name` to a dynamically allocated C-style string.

2. **Initialization**:
   - `struct1` is initialized with an array `{1, 2, 3, 4, 5}`, `otherData` with the value `10`, and `name` is initially set to `nullptr`.
   - Memory is then allocated for `name`, and the string `"Original Name"` is copied into this memory.

3. **Shallow Copy**:
   - `struct2` is created as a copy of `struct1`. The default shallow copy behavior copies the array and the value of `otherData`, but it also copies the pointer `name` as is. Therefore, both `struct1.name` and `struct2.name` now point to the same memory location.

4. **Modification**:
   - Modifications to `struct2`'s array and `otherData` are independent of `struct1`.
   - However, modifying the string pointed to by `struct2.name` also affects `struct1.name` because they both point to the same memory.

5. **Output**:
   - The output shows that while the arrays and `otherData` are independent, the `name` field is shared between the two structures, demonstrating the shallow copy effect.

6. **Memory Management**:
   - After usage, the dynamically allocated memory is freed using `delete[]`. Since both `struct1.name` and `struct2.name` point to the same memory, deleting it through one pointer and setting the other to `nullptr` prevents double deletion.

### Output
```
struct1.arr: 1 2 3 4 5 
struct1.otherData: 10
struct1.name: Modified Name

struct2.arr: 100 2 3 4 5 
struct2.otherData: 20
struct2.name: Modified Name
```

### Key Points

- **Shallow Copy**: The default copy constructor and assignment operator provided by the compiler perform a shallow copy. This means that each element of the array is copied individually, but if the structure contained pointers or dynamic memory, a shallow copy would only copy the pointers, not the data they point to. Both `struct1.name` and `struct2.name` point to the same memory location. Modifications through one structure affect the other
- **Deep Copy**: If the structure contained dynamically allocated memory, you would need to implement a deep copy constructor to properly copy the data. To avoid this problem, you would need to implement a deep copy, where the `name` pointer is duplicated for each structure, so each structure manages its own memory.