#include <iostream>
using namespace std;

// ### Truth Table for Logical AND (`&&`):

// | Expression 1 | Expression 2  | Result  |
// |--------------|---------------|---------|
// | true         | true          | true    |
// | true         | false         | false   |
// | false        | true          | false   |
// | false        | false         | false   |

int main()
{
    bool Tru = true;
    bool Fal = false;

    // Logical AND (&&): Returns true if both operands are true
    cout << "True && False = " << (Tru && Fal) << endl; // 0 (false)

    int a = 0;
    int b = 5;

    // Logical AND (&&): Returns true if both operands are true
    // In this expression: a && b++
    // - a is 0 (false)
    // - b is 5 (true)
    // Since a is false (0), the logical AND operation short-circuits
    // This means b++ is not evaluated because the result is already determined to be false
    cout << "a && b = " << (a && b++) << endl; // Output: 0 (false)

    // Let's check the values of a and b after the operation
    cout << "a = " << a << endl; // Output: 0 (unchanged)
    cout << "b = " << b << endl; // Output: 5 (unchanged because b++ was not evaluated)

    return 0;
}
