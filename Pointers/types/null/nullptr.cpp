// ###  Using `nullptr` Keyword
// In modern C++ (C++11 and later), the `nullptr` keyword is introduced to represent a null pointer. It provides better type safety and avoids ambiguities associated with using `NULL` macro.

#include <iostream>

int main()
{
   int *ptr = nullptr;                                // Initializing pointer with nullptr
   std::cout << "Value of ptr: " << ptr << std::endl; // Output: 0 (null pointer address)

   return 0;
}