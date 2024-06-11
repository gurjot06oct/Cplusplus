#include <iostream>
#include <cstdint> // std::uintptr_t
using namespace std;

int main()
{
    int intArray[5] = {10, 20, 30, 40, 50};        // Array of integers
    char charArray[5] = {'a', 'b', 'c', 'd', 'e'}; // Array of characters

    int *intPtr = intArray;    // Pointer to the first element of intArray
    char *charPtr = charArray; // Pointer to the first element of charArray
    cout << "Initial address of intPtr: " << (uintptr_t)intPtr << endl;
    cout << "Initial address of charPtr: " << (uintptr_t)charPtr << endl;

    // Pointer arithmetic
    intPtr++;  // Move to the next int (4 bytes ahead)(size of int)
    charPtr++; // Move to the next char (1 byte ahead)(size of char)
    cout << "Address of intPtr after increment: " << (uintptr_t)intPtr << endl;
    cout << "Address of charPtr after increment: " << (uintptr_t)charPtr << endl;

    // Advanced arithmetic
    intPtr += 2;  // Move two more ints (8 bytes ahead)
    charPtr += 2; // Move two more chars (2 bytes ahead)
    cout << "Address of intPtr after adding 2: " << (uintptr_t)intPtr << endl;
    cout << "Address of charPtr after adding 2: " << (uintptr_t)charPtr << endl;

    intPtr -= 2;  // Move two ints back (8 bytes ahead)
    charPtr -= 2; // Move two chars back (2 bytes ahead)
    cout << "Address of intPtr after subtracting 2: " << (uintptr_t)intPtr << endl;
    cout << "Address of charPtr after subtracting 2: " << (uintptr_t)charPtr << endl;

    return 0;
}
