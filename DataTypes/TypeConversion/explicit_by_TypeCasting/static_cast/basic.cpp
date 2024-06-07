#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    double y = 4.5;

    int result = static_cast<int>(x + y); // Convert double to int
    cout << "Result: " << result << endl; // Output: 14

    return 0;
}

// - In this example, we have an integer `x` and a double `y`.
// - We perform an arithmetic operation `x + y`, where `y` is implicitly converted to an integer due to the presence of `x`.
// - Using `static_cast<int>`, we explicitly convert the result to an `int`, which truncates the fractional part.
// - The result `14` is printed out.