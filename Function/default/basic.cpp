#include <iostream>
void printMessage(std::string message = "Hello, World!")
{
    std::cout << message << std::endl;
}

int main()
{
    printMessage();           // Outputs: Hello, World!
    printMessage("Goodbye!"); // Outputs: Goodbye!
    return 0;
}