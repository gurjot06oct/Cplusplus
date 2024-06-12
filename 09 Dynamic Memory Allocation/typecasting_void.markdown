## Typecasting `void` Pointers in Modern C++

In modern C++, typecasting `void` pointers obtained from memory allocation functions (`malloc`, `realloc`, `calloc`) is best done using `static_cast` or `reinterpret_cast`, depending on the situation. This article discusses the usage of each cast and emphasizes modern C++ practices regarding memory management.

### Using `static_cast`

```cpp
#include <iostream>
#include <cstdlib>

int main()
{
    // Use static_cast for well-defined and safe type conversions, especially between related types.
    void *ptr = malloc(sizeof(int));
    int *intPtr_static = static_cast<int *>(ptr);

    return 0;
}
```

The `static_cast` is preferred for type conversions that are well-defined and safe, particularly between related types like pointer-to-pointer conversions.

### Using `reinterpret_cast`

```cpp
#include <iostream>
#include <cstdlib>

int main()
{
    // Use reinterpret_cast for casting between unrelated types or for low-level casts. Exercise caution as it bypasses type checking.
    void *ptr = malloc(sizeof(int));
    int *intPtr_reinterpret = reinterpret_cast<int *>(ptr);

    return 0;
}
```

The `reinterpret_cast` is suitable for casting between unrelated types or for low-level casts. However, it should be used with caution due to its potential for unsafe behavior.

### Modern C++ Practices

```cpp
#include <iostream>
#include <memory>

int main()
{
    // Modern C++ encourages the use of smart pointers (std::unique_ptr and std::shared_ptr) and containers (std::vector, std::array, std::string) over raw pointers and manual memory management whenever possible.
    std::unique_ptr<int> ptr_unique(new int);
    std::shared_ptr<int> ptr_shared = std::make_shared<int>();

    return 0;
}
```

Modern C++ promotes the use of smart pointers (`std::unique_ptr` and `std::shared_ptr`) and containers (`std::vector`, `std::array`, `std::string`) over raw pointers and manual memory management. These smart pointers automatically handle memory allocation and deallocation, reducing the risk of memory leaks and dangling pointers.
