// #### 3. `cout.flush()`

// Flushes the output buffer, ensuring all output is written to the console immediately.

// **Usage:**
// cout.flush();

#include <iostream>
using namespace std;

int main()
{
    cout << "This will be immediately displayed." << flush;
    return 0;
}