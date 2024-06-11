// Replacing Default Parameters with Function Overloading:
// You can replace default parameters with function overloading to provide multiple versions of a function with different numbers of parameters.

#include <iostream>
void printMessage()
{
    std::cout << "Hello, World!" << std::endl;
}

void printMessage(std::string message)
{
    std::cout << message << std::endl;
}

int main()
{
    printMessage();           // Outputs: Hello, World!
    printMessage("Goodbye!"); // Outputs: Goodbye!
    return 0;
}