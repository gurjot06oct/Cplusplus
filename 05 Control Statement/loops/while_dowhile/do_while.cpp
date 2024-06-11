#include <iostream>
using namespace std;

// ### `do-while` Loop
// A `do-while` loop is similar to a `while` loop, but the condition is evaluated after the loop body. This means the loop body will execute at least once.

int main()
{
    int i = 0; // Initialization
    do
    {
        cout << "i = " << i << endl; // Loop body
        ++i;                         // Increment
    } while (i < 5); // Condition
    return 0;
}