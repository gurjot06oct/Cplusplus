// #### 6. `cout.fill()`

// Sets the character to be used to fill the width when the output is shorter than the specified width.

// **Usage:**
// cout.fill(char c);

// **Parameters:**
// - `c`: Character to use for filling.

#include <iostream>
using namespace std;

int main()
{
    cout.fill('*');
    cout.width(10);
    cout << 42 << endl; // Outputs "********42"
    return 0;
}
