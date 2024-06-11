// `cin.get()`

// Reads a single character, including whitespace.

// **Usage:**
// ```cpp
// char c;
// cin.get(c);

#include <iostream>
using namespace std;

int main()
{
    char c;
    cout << "Enter a character: ";
    cin.get(c);
    cout << "You entered: " << c << endl;
    return 0;
}