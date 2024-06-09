#include <iostream>
using namespace std;

int main()
{
    bool condition = true;

    // Example 1: Basic use of logical NOT
    cout << "Initial condition: " << condition << endl;  // Output: 1 (true)
    cout << "Negated condition: " << !condition << endl; // Output: 0 (false)

    // Example 2: Using logical NOT in an if statement
    int a = 5, b = 10;

    if (!(a > b))
    {
        cout << "a is not greater than b" << endl; // This will be printed because a is not greater than b
    }
    else
    {
        cout << "a is greater than b" << endl;
    }

    // Example 3: Logical NOT with complex expressions
    bool isSunny = true;
    bool isWarm = false;

    if (!isSunny || isWarm)
    {
        cout << "It is either not sunny or it is warm" << endl;
    }
    else
    {
        cout << "It is sunny and not warm" << endl;
    }

    // Example 4: Logical NOT with variables
    bool isValid = false;
    cout << "Is the input valid? " << (isValid ? "Yes" : "No") << endl;
    cout << "Is the input not valid? " << (!isValid ? "Yes" : "No") << endl;

    return 0;
}
