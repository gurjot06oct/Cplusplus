// In modern C++, the best practice for typecasting a `void` pointer obtained from memory allocation functions (`malloc`, `realloc`, `calloc`) is to use `static_cast` or `reinterpret_cast` based on the situation.
#include <iostream>
#include <cstdlib>

int main()
{

    // 1. **`static_cast`**: Use this when you're converting between types in a way that is well-defined and safe. This is typically used for casting between related types, such as pointer-to-pointer conversions.

    void *ptr = malloc(sizeof(int));
    int *intPtr_static = static_cast<int *>(ptr);

    // 2. **`reinterpret_cast`**: Use this when you need to cast between unrelated types or when you want to perform low-level casts that may not be safe. This should be used with caution as it bypasses type checking.
    // Remember, while `reinterpret_cast` can be powerful, it's also potentially dangerous because it allows you to cast pointers from one type to another without any checks. So, it's essential to ensure that your usage is correct and safe.

    int *intPtr_reinterpret = reinterpret_cast<int *>(ptr);
    return 0;
}
// Additionally, in modern C++, you should prefer using smart pointers (`std::unique_ptr` and `std::shared_ptr`) and containers (`std::vector`, `std::array`, `std::string`) over raw pointers and manual memory management whenever possible. These smart pointers automatically handle memory allocation and deallocation for you, reducing the risk of memory leaks and dangling pointers.