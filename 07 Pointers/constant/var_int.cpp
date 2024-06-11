#include <iostream>
using namespace std;

int main()
{
    // Non-constant integer variables
    int var_int = 20, var_int_l = 30;

    // Pointer to a constant integer pointing to var value
    const int *const_ptr = &var_int;
    // (*const_ptr)++; // Error: Cannot modify a constant value
    // The pointer itself can be changed
    const_ptr = &var_int_l;
    cout << "Value through const_ptr: " << *const_ptr << endl;

    // Constant pointer to an integer pointing to var value
    int *const ptr_const = &var_int;
    // ptr_const = &var_int_l; // Error: Cannot change a constant pointer
    // The value pointed to can be changed
    (*ptr_const)++;
    cout << "Value through ptr_const: " << *ptr_const << endl;

    // Constant pointer to a constant integer pointing to var value
    const int *const ptr_const_ptr = &var_int;
    // ptr_const_ptr = &var_int_l; // Error: Cannot change a constant pointer
    // (*ptr_const_ptr)++; // Error: Cannot modify a constant value
    cout << "Value through ptr_const_ptr: " << *ptr_const_ptr << endl;

    return 0;
}
