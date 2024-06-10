// **Void Pointer**:
// - A void pointer (`void*`) is a special type of pointer in C++ that points to a memory location without specifying the type of data it points to.
// - It is used when you have a pointer that can point to an object of any data type.

// **Characteristics**:
// - **No Dereferencing**: Void pointers cannot be directly dereferenced because the compiler doesn't know the size or type of the data being pointed to.
// - **Typecasting Required**: To access the data pointed by a void pointer, you must typecast it to the appropriate pointer type.
// - **No Pointer Arithmetic**: Since the size of the data pointed by a void pointer is unknown, pointer arithmetic (incrementing or decrementing) is not allowed.

// **Usage**:
// - Commonly used in functions that deal with memory allocation (`malloc`, `realloc`, `free` in C, `new`, `delete` in C++), where the type of data is not known at compile time.

#include <iostream>

int main()
{
    int intValue = 10;
    double doubleValue = 3.14;
    char charValue = 'A';

    // Declare void pointers
    void *voidPtr1;
    void *voidPtr2;

    // Assign addresses of different data types to void pointers
    voidPtr1 = &intValue;
    voidPtr2 = &doubleValue;

    // Typecast void pointers to access their data
    int *intPtr = static_cast<int *>(voidPtr1);
    double *doublePtr = static_cast<double *>(voidPtr2);

    // Print values using typecasted pointers
    std::cout << "Integer value: " << *intPtr << std::endl;   // Output: Integer value: 10
    std::cout << "Double value: " << *doublePtr << std::endl; // Output: Double value: 3.14

    // Assign address of a char variable to a void pointer
    voidPtr1 = &charValue;

    // Typecast void pointer to access its data
    char *charPtr = static_cast<char *>(voidPtr1);

    // Print value using typecasted pointer
    std::cout << "Character value: " << *charPtr << std::endl; // Output: Character value: A

    return 0;
}

// ### Explanation

// 1. Three variables of different data types (`int`, `double`, `char`) are declared and initialized.
// 2. Two void pointers (`voidPtr1`, `voidPtr2`) are declared.
// 3. Addresses of `intValue` and `doubleValue` are assigned to `voidPtr1` and `voidPtr2` respectively.
// 4. The void pointers are then typecasted to appropriate pointer types (`int*`, `double*`) to access their data.
// 5. The data pointed by the typecasted pointers is printed.
// 6. Later, the address of `charValue` is assigned to `voidPtr1` and then typecasted to a `char*` pointer to access its data.