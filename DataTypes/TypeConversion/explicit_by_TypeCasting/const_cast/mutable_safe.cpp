// Correct Usage with Mutable State
// A safer and more practical use case for `const_cast` is when a `const` method needs to modify a member variable that is logically mutable (e.g., a cached value).
#include <iostream>
using namespace std;

class MyClass
{
public:
    MyClass() : value(0), cache(-1) {}

    int getValue() const
    {
        if (cache == -1)
        {
            // Updating cache using const_cast
            const_cast<MyClass *>(this)->cache = calculateValue();
        }
        return cache;
    }

private:
    int value;
    mutable int cache;

    int calculateValue() const
    {
        return value + 10; // Some complex calculation
    }
};

int main()
{
    MyClass obj;
    cout << "Cached value: " << obj.getValue() << endl; // Output: Cached value: 10

    return 0;
}

// - The class `MyClass` has a `mutable` member variable `cache`, which is used to store a computed value.
// - The `getValue` method is `const` but needs to update the `cache` member.
// - `const_cast` is used to cast away the `const`ness of `this` pointer, allowing `cache` to be modified within a `const` method.
// - This usage is safe because `cache` is `mutable` and logically intended to be modified even within `const` methods.