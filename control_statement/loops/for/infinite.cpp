#include <iostream>
using namespace std;

// Infinite Loops
// A `for` loop can be used to create an infinite loop by omitting the condition.

int main()
{
    for (;;)
    { // Infinite loop
        cout << "This will print forever!" << endl;
        break; // But we break immediately here. Remove it to make it go on forever.
    }
    return 0;
}