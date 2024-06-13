#include <iostream>
using namespace std;

// Adding `const` Qualifier (unsafe)

void printValue(const int &ref)
{
    cout << "Value: " << ref << endl;
}

int main()
{
    int x = 15;

    // Adding constness using const_cast
    printValue(const_cast<const int &>(x)); // Adding constness

    return 0;
}

// - A non-const integer `x` is declared and initialized to `10`.
// - The function `printValue` takes a `const` reference to an integer.
// - `const_cast<const int&>(x)` is used to add the `const` qualifier to `x` before passing it to `printValue`.
