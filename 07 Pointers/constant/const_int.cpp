#include <iostream>
using namespace std;

int main()
{
    // Define constant integer variables
    const int const_int = 20, const_int_l = 30;

    // Declare a pointer to a constant integer pointing to a constant value
    const int *const_ptr = &const_int;
    // (*const_ptr)++; // Error: Cannot modify a constant value
    // The pointer itself can be reassigned
    const_ptr = &const_int_l;
    cout << "Value accessed via const_ptr (const_int): " << *const_ptr << endl;

    // Declare a constant pointer to an integer pointing to a constant value
    // Note: This declaration is invalid because `const int` works with `const int *` only
    // int * const const_ptr = &const_int;

    // Declare a constant pointer to a constant integer pointing to a constant value
    const int *const_ptr3 = &const_int;
    // ptr_const_ptr = &const_int_l; // Error: Cannot modify a constant pointer
    // (*ptr_const_ptr)++; // Error: Cannot modify a constant value
    cout << "Value accessed via const_ptr3 (const_int): " << *const_ptr3 << endl;

    return 0;
}
