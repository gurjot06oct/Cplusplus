// `cin.getline()`

// Reads an entire line of text, including spaces, until a newline character is encountered.

// **Usage:**
// cin.getline(char* buffer, streamsize size);
// cin.getline(char* buffer, streamsize size, char delimiter="\n");

// **Parameters:**
// - `buffer`: Character array to store the input.
// - `size`: Maximum number of characters to read (including the null terminator).
// - `delimiter`: Character at which to stop reading (default is newline).

// **Returns:**
// Returns an entire line of text, including spaces, until a newline character is encountered
// Returns characters up to `size-1` without including null terminator

#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cout << "Enter a line of text: ";
    cin.getline(str, 5);
    cout << "You entered: " << str << endl;
    return 0;
}
