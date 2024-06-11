#include <iostream>

int main()
{
    // String literals
    const char *greeting = "Hello, world!";           // C-style string literal
    const char myName[] = {'J', 'o', 'h', 'n', '\0'}; // Character array initialized with string literal

    // Outputting string literals
    std::cout << "Greeting: " << greeting << std::endl;
    std::cout << "My name: " << myName << std::endl;

    // String literals can be concatenated simply by placing them next to each other without any operator in between. This is a feature of the C and C++ languages known as string literal concatenation.
    const char *fullName = "John"
                           " "
                           "Doe"; // Concatenated string literals

    std::cout << "My name: " << fullName << std::endl;
    return 0;
}

// - `"Hello, world!"` is a string literal representing the greeting message.
// - `greeting` is a pointer to the first character of the string literal.
// - `{'J', 'o', 'h', 'n', '\0'}` is a character array initialized with the characters of the string literal "John" followed by the null terminator `'\0'`.
// - `myName` is an array of characters initialized with the characters of the string literal.
