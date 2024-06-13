### Explicit Type Conversion by Assignment in C++

```cpp
#include <iostream>
using namespace std;

int main()
{
    double x = 1.2;

    // Explicit conversion from double to int
    int sum = (int)x + 1;

    cout << "Sum = " << sum;

    return 0;
}
```

#### Explanation

- **Explicit Conversion:** `(int)x` converts the `double` variable `x` to an `int`. This truncates the fractional part of `x`, resulting in `1`.
- **Addition:** `1` is added to the converted integer value `(int)x`, resulting in `2`.
- **Output:** The sum `2` is printed as `"Sum = 2"` using `cout`.

#### Purpose

This code snippet demonstrates how to explicitly convert a `double` to an `int` using type casting `(int)x`. Explicit conversions are useful for ensuring data type compatibility and controlling how values are interpreted and used in expressions.
