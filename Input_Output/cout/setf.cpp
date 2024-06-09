// #### 7. `cout.setf()`

// Sets the format flags for the output stream.

// **Usage:**
// cout.setf(ios::fmtflags flags);
// cout.setf(ios::fmtflags flags, ios::fmtflags mask);

// **Parameters:**
// - `flags`: Format flags to set.
// - `mask`: Mask to specify which flags to set.

#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::showpos); // Show positive sign
    cout << 42 << endl;      // Outputs "+42"
    cout.unsetf(ios::showpos);
    return 0;
}
