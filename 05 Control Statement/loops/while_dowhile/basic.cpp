#include <iostream>
using namespace std;

// A `while` loop is a control flow statement that allows code to be executed repeatedly based on a condition. The loop checks the condition before executing the loop body.
int main()
{
    int i = 0; // Initialization
    while (i < 5)
    {                                // Condition
        cout << "i = " << i << endl; // Loop body
        ++i;                         // Increment
    }
    return 0;
}