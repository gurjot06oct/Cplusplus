// #### 1. `cout.put()`

// Writes a single character to the standard output.

// **Usage:**
// cout.put(char c);

#include <iostream>
using namespace std;

int main()
{
    char c = 'A';
    cout.put(c);
    cout.put('\n'); // Equivalent to cout << '\n'
    return 0;
}