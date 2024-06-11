#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "Base class" << endl;
    }
};

class Derived : public Base
{
public:
    void show() override
    {
        cout << "Derived class" << endl;
    }
};

int main()
{
    Derived derivedObj;
    Base *basePtr = &derivedObj;

    Derived *derivedPtr = static_cast<Derived *>(basePtr); // Upcasting
    derivedPtr->show();                                    // Output: Derived class

    return 0;
}

// - Here, we have a base class `Base` and a derived class `Derived`.
// - We create an object of the `Derived` class and obtain its address.
// - We then have a pointer `basePtr` of type `Base*` pointing to this object.
// - Using `static_cast<Derived*>(basePtr)`, we explicitly cast `basePtr` to `Derived*`. This is upcasting since `basePtr` points to a derived class object.
// - The cast is valid because we know at compile-time that `basePtr` points to an object of type `Derived` (due to how it was assigned), so the conversion is safe.
// - Finally, we call the `show()` function using `derivedPtr`, which prints "Derived class".