// #### 2. `cout.write()`

// Writes a block of characters to the standard output.

// **Usage:**
// cout.write(const char* s, streamsize n);

// **Parameters:**
// - `s`: Pointer to the character array to write.
// - `n`: Number of characters to write.

#include <iostream>
using namespace std;

int main()
{
    const char *str = "Hello, World!";
    cout.write(str, 5); // Outputs "Hello"
    cout << endl;
    return 0;
}