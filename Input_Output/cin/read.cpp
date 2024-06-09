// `cin.read()`

// Reads a specified number of characters into a buffer.

// **Usage:**
// cin.read(char* buffer, streamsize size);

#include <iostream>
using namespace std;

int main()
{
    char buffer[10];
    cout << "Enter some text: ";
    cin.read(buffer, 5);
    buffer[5] = '\0'; // Null-terminate the string
    cout << "You entered: " << buffer << endl;
    return 0;
}
