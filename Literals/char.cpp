#include <iostream>

int main()
{
    // Character literal representing the character 'A'
    char ch1 = 'A';
    std::cout << "Character 1: " << ch1 << std::endl;

    // Character literal representing the newline character '\n'
    char ch2 = '\n';
    std::cout << "Character 2: " << ch2 << std::endl;

    // Character literal representing the escape sequence '\t' (tab)
    char ch3 = '\t';
    std::cout << "Character 3: " << ch3 << "Hello" << std::endl;

    // Character literal representing the Unicode character '\u03B1' (Greek letter alpha)
    char ch4 = '\u03B1';
    std::cout << "Character 4: " << ch4 << std::endl;

    return 0;
}
