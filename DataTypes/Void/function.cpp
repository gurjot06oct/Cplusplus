#include <iostream>

// Void Functions
// When a function does not return any value, its return type is specified as `void`. This is useful for functions that perform operations but do not need to communicate results back to the caller.

void printMessage()
{
    std::cout << "Hello, World!" << std::endl;
}
int main()
{
    printMessage();
    return 0;
}