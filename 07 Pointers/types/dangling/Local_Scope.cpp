// In this example, a pointer points to a local variable that goes out of scope, causing the pointer to become a dangling pointer.
#include <iostream>

int *getPointer()
{
    int localVar = 10; // local variable
    return &localVar;  // return address of local variable
}

int main()
{
    int *ptr = getPointer(); // ptr now points to localVar, which is out of scope after getPointer() returns
    // ptr is now a dangling pointer

    // Accessing the dangling pointer can cause undefined behavior
    // std::cout << "Value of dangling pointer: " << *ptr << std::endl; // Uncommenting this line may cause a crash

    return 0;
}

// #### Explanation
// - `localVar` is a local variable within the function `getPointer`.
// - Returning the address of `localVar` causes `ptr` to point to a memory location that becomes invalid once the function returns.
// - Accessing `*ptr` leads to undefined behavior because `localVar` is out of scope.