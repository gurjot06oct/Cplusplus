#include <iostream>
#define SWAP(a, b) (a ^= b, b ^= a, a ^= b)
using namespace std;

// Function definitions
void bar()
{
    cout << "bar() called" << endl;
}

void baz()
{
    cout << "baz() called" << endl;
}

int qux()
{
    cout << "qux() called" << endl;
    return 42;
}

int main()
{
    // Example 1: Basic Usage
    int a = 1, b = 2;
    int x = (a = 3, b = 4, a + b);
    cout << "Example 1 - Basic Usage: x = " << x << endl; // Output: 7

    // Example 2: For Loop Control
    cout << "Example 2 - For Loop Control:" << endl;
    for (int i = 0, j = 10; i < j; i++, j--)
    {
        cout << "i = " << i << ", j = " << j << endl;
    }

    // Example 3: Combining Expressions
    cout << "Example 3 - Combining Expressions: " << endl;
    int y = (a = 5, b = 10, a * b);
    cout << "y = " << y << endl; // Output: 50

    // Example 4: Side Effects in Macros
    int p = 1, q = 2;
    SWAP(p, q);
    cout << "Example 4 - Side Effects in Macros: p = " << p << ", q = " << q << endl; // Output: p = 2, q = 1

    // Example 5: Sequence Points and Side Effects
    int c = 1, d = 2;
    int result = (c += 5, d *= 3);
    cout << "Example 5 - Sequence Points and Side Effects: result = " << result << endl; // Output: 6

    // Example 6: Function Calling
    cout << "Example 6 - Function Calling: " << endl;
    int finalResult = (bar(), baz(), qux());
    cout << "finalResult = " << finalResult << endl;
    // Output:
    // bar() called
    // baz() called
    // qux() called
    // finalResult = 42

    return 0;
}
