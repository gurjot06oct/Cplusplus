NULL pointers are used to represent pointers that do not point to any memory location. There are two commonly used methods to initialize a NULL pointer: using `NULL` macro and using `nullptr` keyword. Let's explore both methods in detail:

### 1. Using `NULL` Macro

### 2. Using `nullptr` Keyword

### Key Differences:

1. **Type Safety**:

   - `NULL` is a macro defined as `0` or `(void*)0`, which can lead to ambiguity in overloaded functions or templates.
   - `nullptr` is a keyword of type `nullptr_t`, which provides stronger type safety and can be used in overloaded functions without ambiguity.

2. **Compile-time Error Detection**:

   - Using `nullptr` helps in detecting potential errors at compile time, such as assigning pointers to integer types, which may go unnoticed when using `NULL`.

3. **Standardization**:

   - `nullptr` is part of the C++11 standard and is recommended for modern C++ programming.
   - `NULL` is still available for compatibility with existing codebases but is generally discouraged in favor of `nullptr`.

4. **Readability**:
   - `nullptr` explicitly indicates a null pointer, making the code more readable and self-explanatory compared to `NULL`, which may not convey the same meaning to all developers.
