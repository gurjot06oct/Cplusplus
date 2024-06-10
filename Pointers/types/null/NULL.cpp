// ### Using `NULL` Macro
// In traditional C programming, the `NULL` macro is used to represent a null pointer. It is defined in the `<cstddef>` header file (or `<stddef.h>` in C). In C++, you can include `<cstddef>` or `<iostream>` to access the `NULL` macro.

#include <iostream>

int main()
{
    int *ptr = NULL;                                   // Initializing pointer with NULL using the NULL macro
    std::cout << "Value of ptr: " << ptr << std::endl; // Output: 0 (null pointer address)

    return 0;
}