// #### 5. `cin.peek()`

// Returns the next character in the input buffer without extracting it.

// **Usage:**
// int c = cin.peek();

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a character: ";
    char c = cin.peek();
    cout << "Next character in buffer: " << c << endl;
    return 0;
}
