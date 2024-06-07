#include <iostream>
using namespace std;

int main()
{
    // Example: Casting pointers to unrelated types
    int intValue = 65;
    // Pointer to the integer
    int *intPointer = &intValue;

    // Cast int pointer to char pointer using reinterpret_cast
    char *charPointer = reinterpret_cast<char *>(intPointer);

    // Output the integer value
    cout << "Integer value: " << *intPointer << endl; // Output: 65

    // Output the character value (interpreted as a char)
    cout << "Character value: " << *charPointer << endl; // Output: 'A' (ASCII 65)

    return 0;
}
