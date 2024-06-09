// `cin.unget()`

// Puts the last character extracted back into the input buffer.

// **Usage:**
// cin.unget();

// #include <iostream>
// using namespace std;

int main()
{
    char c;
    cout << "Enter a character: ";
    cin.get(c);
    cout << "You entered: " << c << endl;
    cin.unget();
    char d;
    cin.get(d);
    cout << "Character after unget: " << d << endl;
    return 0;
}
