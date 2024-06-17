### NULL Pointers in C++

In C++, NULL pointers are used to represent pointers that do not point to any memory location. There are two primary methods to initialize a NULL pointer: using the `NULL` macro and the `nullptr` keyword. Let's delve into both methods and explore their differences and best practices.

### 1. Using `NULL` Macro

In traditional C programming, the `NULL` macro is commonly used to denote a null pointer. It is typically defined as `0` or `(void*)0`, indicating that the pointer does not point to any valid memory address.

#### Key Points:

- **Type Safety**: `NULL` is a macro that expands to a numeric value, which can lead to ambiguity, especially in overloaded functions or templates.
- **Compile-time Detection**: Errors such as assigning pointers to non-pointer types may not be caught at compile time when using `NULL`.
- **Standardization**: `NULL` has been a part of C and C++ for a long time, ensuring compatibility with older codebases.
- **Example**:

  ```cpp
  #include <iostream>
  #include <cstddef> // for NULL definition

  int *ptr = NULL; // Initializing pointer with NULL using the NULL macro
  std::cout << "Value of ptr: " << ptr << std::endl; // Output: 0 (null pointer address)
  ```

### 2. Using `nullptr` Keyword

Introduced in C++11, `nullptr` is a keyword specifically designed to represent a null pointer. Unlike `NULL`, which is a macro, `nullptr` is of type `nullptr_t`, providing better type safety and avoiding potential ambiguities in code.

#### Key Points:

- **Type Safety**: `nullptr` is a keyword of type `nullptr_t`, ensuring that it can be used in overloaded functions without ambiguity.
- **Compile-time Error Detection**: Using `nullptr` helps detect errors like assigning pointers to non-pointer types at compile time, enhancing code reliability.
- **Readability**: `nullptr` explicitly indicates a null pointer, making the code more readable and understandable.
- **Example**:

  ```cpp
  #include <iostream>

  int *ptr = nullptr; // Initializing pointer with nullptr
  std::cout << "Value of ptr: " << ptr << std::endl; // Output: 0 (null pointer address)
  ```

### Key Differences:

- **Type Safety**: `nullptr` offers stronger type safety compared to `NULL`, which is expanded to a numeric value.
- **Compile-time Detection**: `nullptr` helps catch errors early during compilation, which `NULL` may not.
- **Standardization**: `nullptr` is part of modern C++ standards (C++11 and later), whereas `NULL` remains for compatibility with older code.
