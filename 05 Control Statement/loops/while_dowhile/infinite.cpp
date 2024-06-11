// Infinite `while` Loop
// A `while` loop can be used to create an infinite loop by using a condition that always evaluates to true.

#include <iostream>
using namespace std;

int main()
{
    while (true)
    { // Infinite loop
        cout << "This will print forever!" << endl;
        break; // But we break immediately here. Remove it to make it go on forever.
    }
    return 0;
}