// #### 5. `cout.width()`

// Sets the minimum field width for the next output operation.

// **Usage:**
// cout.width(int w);

// **Parameters:**
// - `w`: Minimum number of characters for the next output.

#include <iostream>
using namespace std;

int main()
{
    cout.width(10);
    cout << 42 << endl; // Outputs "        42" (with leading spaces)
    return 0;
}