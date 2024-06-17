### Pointer Arithmetic with Different Levels of Pointers in C++

Pointer arithmetic changes the addresses stored in pointers. For `T*`, `T**`, and `T***`, the principles remain the same, but the context changes based on the level of indirection.

#### Basic Concepts

1. **T\* (Pointer to type T):**

   - Points to a `type T`.
   - Incrementing (`ptr++`) moves to the next `type T` in memory.
   - Decrementing (`ptr--`) moves to the previous `type T` in memory.
   - The address changes by `sizeof(type T)` bytes.

2. **T\*\* (Pointer to a pointer to type T):**

   - Points to a `type T*`.
   - Incrementing (`ptr++`) moves to the next `type T*` in memory.
   - Decrementing (`ptr--`) moves to the previous `type T*` in memory.
   - The address changes by `sizeof(type T*)` bytes.

3. **T\*\*\* (Pointer to a pointer to a pointer to type T):**

   - Points to a `type T**`.
   - Incrementing (`ptr++`) moves to the next `type T**` in memory.
   - Decrementing (`ptr--`) moves to the previous `type T**` in memory.
   - The address changes by `sizeof(type T**)` bytes.

   - Adding an integer (`ptr + n`) moves the pointer forward by `n * sizeof(type T)` bytes.
   - Subtracting an integer (`ptr - n`) moves the pointer backward by `n * sizeof(type T)` bytes.

4. **Pointer Addition and Subtraction:**
   - Adding an integer to a pointer (`ptr + n`) moves it forward by `n` times the size of type it points to.
   - Subtracting an integer from a pointer (`ptr - n`) moves it backward by `n` times the size of type it points to.
   - The result of subtraction (`ptr2 - ptr1`) return the number of elements (or pointers) between `ptr1` and `ptr2`.

#### Formula

This formula calculates the number of `T` elements between `ptr1` and `ptr2` by dividing the difference in their addresses (`ptr2 - ptr1`) by the size of `T` (`sizeof(T)`).
For pointers `ptr1` and `ptr2` of type `T*`:

\[ \text{Number of } T \text{ elements} = \frac{{\text{ptr2} - \text{ptr1}}}{{\text{sizeof}(T)}} \]
