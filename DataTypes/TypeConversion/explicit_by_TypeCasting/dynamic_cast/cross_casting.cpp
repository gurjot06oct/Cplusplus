#include <iostream>
#include <typeinfo>
using namespace std;

// Cross-casting refers to casting between sibling classes in the same hierarchy. It can be achieved using `dynamic_cast` when you have a common base class.

class Base
{
public:
    virtual ~Base() {} // Ensure Base has at least one virtual function
};

class Derived1 : public Base
{
public:
    void show1()
    {
        cout << "Derived1 class" << endl;
    }
};

class Derived2 : public Base
{
public:
    void show2()
    {
        cout << "Derived2 class" << endl;
    }
};

int main()
{
    Derived1 derived1Obj;
    Base *basePtr = &derived1Obj; // Base pointer pointing to a Derived1 object

    // Attempt to cross-cast from Derived1 to Derived2
    Derived2 *derived2Ptr = dynamic_cast<Derived2 *>(basePtr);

    if (derived2Ptr)
    {
        derived2Ptr->show2();
    }
    else
    {
        cout << "Cross-cast failed" << endl; // Output: Cross-cast failed
    }

    return 0;
}
// - We have two classes `Derived1` and `Derived2` both inheriting from `Base`.
// - A `Base` class pointer (`basePtr`) points to an object of type `Derived1`.
// - We attempt to cross-cast `basePtr` to a `Derived2` class pointer (`derived2Ptr`) using `dynamic_cast`.
// - The cast fails because `basePtr` actually points to a `Derived1` object, not a `Derived2` object. Therefore, `derived2Ptr` is `nullptr`.