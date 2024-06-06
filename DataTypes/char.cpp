#include <iostream>
int main()
{
    // char: Range: -128 to 127 (8 bits)
    // Negative values don't have a character to represent
    char myChar = -134; // Assigning character 'z'
    std::cout << "char: " << myChar << std::endl;

    // unsigned char: Range: 0 to 255 (8 bits)
    unsigned char myUnsignedChar = 255; // Assigning character 'A'
    std::cout << "unsigned char: " << myUnsignedChar << std::endl;

    // char16_t: Range: 0 to 65,535 (16 bits)
    char16_t myChar16 = u'\u03A3'; // Assigning a Unicode character (Greek Sigma)
    std::cout << "char16_t: " << myChar16 << std::endl;

    // char32_t: Range: 0 to 4,294,967,295 (32 bits)
    char32_t myChar32 = U'\U0001F600'; // Assigning a Unicode character (Smiling Face)
    std::cout << "char32_t: " << myChar32 << std::endl;

    // wchar_t: Platform dependent and grabs the maximum size possible, typically 16 or 32 bits
    wchar_t myWideChar = L'猫'; // Assigning a wide character (Chinese for "cat")
    std::wcout << "wchar_t: " << myWideChar << std::endl;

    return 0;
}
