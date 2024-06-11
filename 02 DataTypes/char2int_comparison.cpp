#include <iostream>

int main()
{
    char a = 0xfb;
    unsigned char b = 0xfb;

    std::cout << "a = " << a;
    std::cout << "\nb = " << b;

    if (a == b)
        std::cout << "\nSame";
    else
        std::cout << "\nNot Same";

    // Output: Not Same
    // int(a) = -5, int(b) = 251

    return 0;
}
