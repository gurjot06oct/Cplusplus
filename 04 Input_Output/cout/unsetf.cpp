// #### 8. `cout.unsetf()`

// Unsets the format flags specified by the mask.

// **Usage:**
// cout.unsetf(ios::fmtflags mask);

// **Parameters:**
// - `mask`: Format flags to unset.

#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::showpos);
    cout << 42 << endl; // Outputs "+42"
    cout.unsetf(ios::showpos);
    cout << 42 << endl; // Outputs "42"
    return 0;
}