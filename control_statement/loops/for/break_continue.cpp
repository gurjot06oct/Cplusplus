// Breaking and Continuing

// You can control the flow of the loop using `break` and `continue`.
// - `break`: Exits the loop immediately.
// - `continue`: Skips the rest of the loop body and proceeds with the next iteration.
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        if (i == 5)
        {
            break; // Exit loop when i is 5
        }
        if (i % 2 == 0)
        {
            continue; // Skip even numbers
        }
        cout << "i = " << i << endl;
    }
    return 0;
}