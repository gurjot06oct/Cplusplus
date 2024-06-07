#include <iostream>
#include <cstdint> // Required for uintptr_t
using namespace std;

int main()
{
    // Example: Casting pointers to and from integer types
    int number = 42;
    // Pointer to the integer
    int *intPtr = &number;

    // Cast int pointer to uintptr_t using reinterpret_cast
    uintptr_t intAddress = reinterpret_cast<uintptr_t>(intPtr);

    // Cast uintptr_t back to int pointer using reinterpret_cast
    int *intPtrAgain = reinterpret_cast<int *>(intAddress);

    // Output the original pointer
    cout << "Original pointer: " << intPtr << endl;

    // Output the integer address
    cout << "Integer address: " << intAddress << endl;

    // Output the reinterpreted pointer
    cout << "Reinterpreted pointer: " << intPtrAgain << endl;

    // Output the value from the reinterpreted pointer
    cout << "Value from reinterpreted pointer: " << *intPtrAgain << endl;

    return 0;
}
