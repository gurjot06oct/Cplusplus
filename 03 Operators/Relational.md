### Relational Operators in C++

Relational operators are essential tools in C++ programming, allowing comparisons between variables. These operators test relationships between values and return a boolean result (`true` or `false`). Let's dive into the use of each relational operator with a practical example.

#### Example Program

```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 20;

    if (x == y)
        cout << "x is equal to y" << endl;
    else
        cout << "x is not equal to y" << endl;

    if (x != y)
        cout << "x is not equal to y" << endl;
    else
        cout << "x is equal to y" << endl;

    if (x > y)
        cout << "x is greater than y" << endl;
    else
        cout << "x is not greater than y" << endl;

    if (x < y)
        cout << "x is less than y" << endl;
    else
        cout << "x is not less than y" << endl;

    if (x >= y)
        cout << "x is greater than or equal to y" << endl;
    else
        cout << "x is not greater than or equal to y" << endl;

    if (x <= y)
        cout << "x is less than or equal to y" << endl;
    else
        cout << "x is not less than or equal to y" << endl;

    return 0;
}

```

#### Explanation

1. **Equal to (`==`)**:

   - Compares two values to check if they are equal.
   - `if (x == y)` evaluates to `false` because `10` is not equal to `20`.
   - Output: `x is not equal to y`.

2. **Not equal to (`!=`)**:

   - Compares two values to check if they are not equal.
   - `if (x != y)` evaluates to `true` because `10` is not equal to `20`.
   - Output: `x is not equal to y`.

3. **Greater than (`>`)**:

   - Checks if the value on the left is greater than the value on the right.
   - `if (x > y)` evaluates to `false` because `10` is not greater than `20`.
   - Output: `x is not greater than y`.

4. **Less than (`<`)**:

   - Checks if the value on the left is less than the value on the right.
   - `if (x < y)` evaluates to `true` because `10` is less than `20`.
   - Output: `x is less than y`.

5. **Greater than or equal to (`>=`)**:

   - Checks if the value on the left is greater than or equal to the value on the right.
   - `if (x >= y)` evaluates to `false` because `10` is not greater than or equal to `20`.
   - Output: `x is not greater than or equal to y`.

6. **Less than or equal to (`<=`)**:
   - Checks if the value on the left is less than or equal to the value on the right.
   - `if (x <= y)` evaluates to `true` because `10` is less than or equal to `20`.
   - Output: `x is less than or equal to y`.

These relational operators form the backbone of decision-making in C++ programming. By comparing variables, they guide the program flow based on conditions, making them indispensable in writing logical and functional code.
