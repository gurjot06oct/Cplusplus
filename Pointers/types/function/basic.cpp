#include <iostream>

// **Syntax:**
// return_type (*pointer_name)(parameter_types);

// Function declaration
void myFunction(int a, int b)
{
    std::cout << "Value: " << (a + b) << std::endl;
}

int main()
{
    // Declare a function pointer that matches the signature of myFunction
    void (*funcPtr)(int, int);

    // Assign myFunction to the function pointer
    funcPtr = myFunction; // same as &myFunction because a function's name returns its address

    // Call the function through the function pointer
    funcPtr(10, 20); // Output: Value: 30

    // Another way to call the function through the pointer
    (*funcPtr)(10, 20); // Output: Value: 30

    return 0;
}
