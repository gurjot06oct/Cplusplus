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

void display(Base &baseRef)
{
    try
    {
        Derived &derivedRef = dynamic_cast<Derived &>(baseRef); // Safe downcasting using dynamic_cast
        derivedRef.show();                                      // Output: Derived class
    }
    catch (const bad_cast &e)
    {
        cout << "Bad cast: " << e.what() << endl;
    }
}

int main()
{
    Derived derivedObj;
    Base &baseRef = derivedObj; // Base reference referring to a Derived object

    display(baseRef);

    return 0;
}
// - A `Base` class reference (`baseRef`) refers to an object of type `Derived`.
// - Inside the `display` function, we attempt to downcast `baseRef` to a `Derived` class reference (`derivedRef`) using `dynamic_cast`.
// - If the cast is valid, the `show()` method of `Derived` is called. If the cast fails, a `std::bad_cast` exception is caught and handled.