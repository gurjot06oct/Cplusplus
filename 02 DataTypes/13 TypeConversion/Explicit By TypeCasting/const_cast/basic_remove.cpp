#include <iostream>
using namespace std;

// Removing `const` Qualifier (unsafe)

void modifyValue(int &ref)
{
    ref = 20; // Modify the value
}

int main()
{
    const int number = 5;
    const int *ptr = &number;

    // int* nonConstPtr = ptr; if we use this
    // instead of without using const_cast
    // we will get error of invalid conversion

    // Removing constness using const_cast
    int *nonConstPtr = const_cast<int *>(ptr);
    *nonConstPtr = 10; // Modifying const value (undefined behavior)

    cout << "number: " << number << endl;                         // Output: number: 5
    cout << "Modified number (unsafe): " << *nonConstPtr << endl; // Output: Modified number: 10

    return 0;
}
