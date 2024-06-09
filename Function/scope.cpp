#include <iostream>

// Global scope
int globalVar = 1;

namespace MyNamespace
{
    // Namespace scope
    int namespaceVar = 2;

    void namespaceFunction()
    {
        // Local scope within namespace function
        int localVar = 3;
        std::cout << "Local variable inside namespaceFunction: " << localVar << std::endl;
        std::cout << "Namespace variable inside namespaceFunction: " << namespaceVar << std::endl;
        std::cout << "Global variable inside namespaceFunction: " << globalVar << std::endl;
    }
}

void functionScopeExample()
{
    // Function scope
    int functionVar = 4;

    // Block scope within a function
    if (true)
    {
        int blockVar = 5;
        std::cout << "Block variable inside if block: " << blockVar << std::endl;
        std::cout << "Function variable inside if block: " << functionVar << std::endl;
        std::cout << "Global variable inside if block: " << globalVar << std::endl;
    }
    // blockVar is not accessible here
    std::cout << "Function variable after if block: " << functionVar << std::endl;
}

int main()
{
    std::cout << "Global variable in main: " << globalVar << std::endl;
    std::cout << "Namespace variable in main: " << MyNamespace::namespaceVar << std::endl;

    MyNamespace::namespaceFunction();
    functionScopeExample();

    return 0;
}
