// #### 4. `cin.ignore()`

// Ignores characters in the input buffer.

// **Usage:**
// cin.ignore(streamsize n = 1, int delim = EOF);

// **Parameters:**
// - `n`: Maximum number of characters to ignore (default is 1).
// - `delim`: Character to stop ignoring at (default is EOF).

#include <iostream>
using namespace std;

int main()
{
    int a;
    char b;
    cin >> a;
    cin.ignore(10, '\n'); // Ignores up to 10 characters or until newline
    cin.get(b);
    cout << "You entered: " << a << " and " << b << endl;
    return 0;
}
