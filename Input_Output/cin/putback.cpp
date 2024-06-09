// #### 6. `cin.putback()`

// Puts a character back into the input buffer.

// **Usage:**
// cin.putback(char c);

#include <iostream>
using namespace std;

int main()
{
    char c;
    cout << "Enter a character: ";
    cin.get(c);
    cout << "You entered: " << c << endl;
    cin.putback(c);
    char d;
    cin.get(d);
    cout << "Character after putback: " << d << endl;
    return 0;
}