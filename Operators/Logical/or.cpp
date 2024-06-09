#include <iostream>
using namespace std;

// ### Truth Table for Logical OR (`||`):

// | Expression 1 | Expression 2  | Result  |
// |--------------|---------------|---------|
// | true         | true          | true    |
// | true         | false         | true    |
// | false        | true          | true    |
// | false        | false         | false   |

int main()
{

    bool Tru = true;
    bool Fal = false;

    // Logical OR (||): Returns true if at least one operand is true
    cout << "True || False = " << (Tru || Fal) << endl; // 1 (true)

    int a = 1;
    int b = 5;

    // Logical OR (||): Returns true if either operand is true
    // In this expression: a || b++
    // - a is 1 (true)
    // - b is 5 (true)
    // Since a is true (1), the logical OR operation short-circuits
    // This means b++ is not evaluated because the result is already determined to be true
    cout << "a || b = " << (a || b++) << endl; // Output: 1 (true)

    // Let's check the values of a and b after the operation
    cout << "a = " << a << endl; // Output: 1 (unchanged)
    cout << "b = " << b << endl; // Output: 5 (unchanged because b++ was not evaluated)

    return 0;
}
