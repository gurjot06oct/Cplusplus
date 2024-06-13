#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
    virtual ~Base() {} // Ensure Base has at least one virtual function
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived class" << endl;
    }
};

int main()
{
    Base *basePtr = new Derived(); // Base pointer pointing to a Derived object

    // Safe downcasting using dynamic_cast
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);

    if (derivedPtr)
    {
        derivedPtr->show(); // Output: Derived class
    }
    else
    {
        cout << "Cast failed" << endl;
    }

    delete basePtr;
    return 0;
}

// - A `Base` class pointer (`basePtr`) points to an object of type `Derived`.
// - We attempt to downcast `basePtr` to a `Derived` class pointer (`derivedPtr`) using `dynamic_cast`.
// - If the cast is valid, `derivedPtr` is not `nullptr` and we call the `show()` method. If the cast fails, `derivedPtr` is `nullptr`.