// #### 4. `cout.precision()`

// Sets the decimal precision for floating-point output.

// **Usage:**
// cout.precision(int p);

// **Parameters:**
// - `p`: Number of significant digits.

#include <iostream>
using namespace std;

int main()
{
    double pi = 3.141592653589793;
    cout.precision(5);
    cout << "Pi to 5 significant digits: " << pi << endl;
    return 0;
}