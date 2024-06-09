// Basic `for` Loop

// A `for` loop is a control flow statement that allows code to be executed repeatedly based on a condition. It is composed of three parts:

// 1. **Initialization**: This step is executed once before the loop starts. It is typically used to initialize a loop counter.
// 2. **Condition**: Before each iteration, this condition is evaluated. If the condition is true, the loop body is executed. If the condition is false, the loop terminates.
// 3. **Increment**: This step is executed after each iteration of the loop body. It is typically used to update the loop counter.

#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; ++i)
    {                                // Initialization: int i = 0; Condition: i < 5; Increment: ++i
        cout << "i = " << i << endl; // Loop body
    }

    // Nested loop
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << "i = " << i << ", j = " << j << endl;
        }
    }
    return 0;
}