// ### What is a Pointer?
// A pointer is a variable that stores the memory address of another variable. Pointers are used for various purposes, such as dynamic memory allocation, array handling, and referencing functions.

// ### Address-of Operator (`&`), also used for reference
// The address-of operator (`&`) is used to get the memory address of a variable.
// `&var` gives the address of the variable `var`, and this address is assigned to the pointer.

// ### Declaring Pointers
// To declare a pointer, you specify the type of data it will point to, followed by an asterisk (`*`), and then the pointer's name.
// int* ptr; // Declares a pointer to an integer
// char* charPtr; // Declares a pointer to a char
// double* doublePtr; // Declares a pointer to a double

// ### Initializing Pointers
// Pointers can be initialized when they are declared, usually by assigning them the address of an existing variable.
// int var = 20;
// int* ptr = &var; // ptr is now pointing to the address of var

// ### Dereferencing Pointers
// Dereferencing a pointer means accessing the value stored at the memory address the pointer holds. This is done using the dereference operator (`*`).
// int var = 20;
// int* ptr = &var;
// int value = *ptr; // value now holds 20, which is the value at the address stored in ptr

#include <iostream>
using namespace std;

int main()
{
    int var = 10;    // Declare an integer variable
    int *ptr = &var; // Declare a pointer to an integer and initialize it with the address of var

    cout << "Value of var: " << var << endl;                        // Output the value of var
    cout << "Address of var: " << &var << endl;                     // Output the address of var
    cout << "Pointer ptr points to: " << ptr << endl;               // Output the address stored in ptr
    cout << "Value at the address ptr points to: " << *ptr << endl; // Output the value at the address ptr points to

    *ptr = 20;                                   // Change the value of var using the pointer
    cout << "New value of var: " << var << endl; // Output the new value of var

    // Size of Pointer ( 8 bytes )
    cout << "Size of ptr: " << sizeof(ptr) << endl; // Output : 8
    return 0;
}
