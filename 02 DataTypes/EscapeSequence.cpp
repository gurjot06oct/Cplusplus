#include <iostream>

int main()
{
    // Demonstrating escape sequences
    std::cout << "Generating a bell sound: \a" << std::endl;
    std::cout << "Moving the cursor one place backward\b." << std::endl;
    std::cout << "Moving the cursor to the start of the next logical page\f." << std::endl;
    std::cout << "Moving the cursor to the start of the next line.\n";
    std::cout << "Moving the cursor to the start of the current line.\r";
    std::cout << "Inserting some whitespace to the left of the cursor and moving the cursor accordingly.\tTab." << std::endl;
    std::cout << "Inserting a vertical tab.\vNext like should be like this." << std::endl;
    std::cout << "Inserting a backslash character: \\" << std::endl;
    std::cout << "Displaying a single quotation mark: \'" << std::endl;
    std::cout << "Displaying double quotation marks: \"" << std::endl;
    std::cout << "Displaying a question mark: \?" << std::endl;
    std::cout << "Representing an octal number: \077" << std::endl;
    std::cout << "Representing a hexadecimal number: \x41" << std::endl;
    std::cout << "Representing the NULL character: \0" << std::endl;
    std::cout << "Representing the ASCII escape character: \e" << std::endl;

    return 0;
}
