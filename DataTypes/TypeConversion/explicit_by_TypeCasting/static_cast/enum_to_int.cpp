#include <iostream>
using namespace std;

enum class Color
{
    RED,
    GREEN,
    BLUE
};

int main()
{
    Color c = Color::GREEN;
    int value = static_cast<int>(c);            // Convert enum to int
    cout << "Integer value: " << value << endl; // Output: 1
    return 0;
}
// - Here, we have an enumeration `Color` with values `RED`, `GREEN`, and `BLUE`.
// - We initialize a variable `c` with the value `GREEN`.
// - Using `static_cast<int>(c)`, we convert `c` to an `int`. Enum classes in C++ are strongly-typed, but `static_cast` allows for converting them to integer types.
// - The converted value `1` is printed out.