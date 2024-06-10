#include <iostream>

int main()
{
    // A C-style string is an array of characters terminated by a special character called the null character (`'\0').
    // This null character signifies the end of the string.

    // Declaration and Initialization

    // Using string literal:
    // A sequence of characters enclosed in double quotes, automatically terminated by the null character `'\0`.
    char greeting[] = "Hello"; // Size: 6
    // "Hello" is stored as: {'H', 'e', 'l', 'l', 'o', '\0'}

    // Explicitly:
    char explicitGreeting[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    // What if '\0' is not added:
    char noNull[] = {'A', 'B', 'C', 'D'};
    std::cout << "String without null terminator: " << noNull << std::endl; // Undefined Output

    // Accessing Elements:
    std::cout << "First character: " << greeting[0] << std::endl;
    std::cout << "Third character: " << greeting[2] << std::endl;

    return 0;
}
