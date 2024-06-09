// In C++, the `mutable` storage class specifier is used primarily in the context of member variables within classes. It serves to modify the behavior of member variables, particularly in relation to const member functions.

// - **Scope:** Limited to class member functions.
// - **Default Value:** Depends on initialization or constructor.
// - **Memory Location:** Determined by storage duration rules.
// - **Lifetime:** Tied to the lifespan of the object.
// - **Usage:** Overrides constness in const member functions.

#include <iostream>
using std::cout;

class Test
{
public:
    int x;
    mutable int y; // Mutable member variable

    Test()
    {
        x = 4;
        y = 10;
    }
};

int main()
{
    const Test t1; // t1 is constant

    // Since y is mutable, it can be modified
    t1.y = 20;
    cout << t1.y; // Output will be 20

    // Uncommenting the below lines will result in a compilation error
    // t1.x = 8; // Error: Cannot modify x because t1 is const
    // cout << t1.x;

    return 0;
}
