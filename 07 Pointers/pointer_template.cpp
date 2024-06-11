#include <iostream>

// Template alias to create pointers of any type
template <typename T>
using ptr = T *;

int main()
{
    // Create pointers of different types using the template alias
    ptr<int> ptr_int;
    ptr<double> ptr_double;
    ptr<char> ptr_char;

    // Assign values to the pointers
    *ptr_int = 10;
    *ptr_double = 3.14;
    *ptr_char = 'A';

    // Print the values through the pointers
    std::cout << "Value of ptr_int: " << *ptr_int << std::endl;       // Output: 10
    std::cout << "Value of ptr_double: " << *ptr_double << std::endl; // Output: 3.14
    std::cout << "Value of ptr_char: " << *ptr_char << std::endl;     // Output: A

    return 0;
}
