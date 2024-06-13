### Ternary Operators in C++

Ternary operators in C++ provide a concise way to make decisions based on conditions. They are powerful tools for enhancing code readability and efficiency. Let's explore each usage of ternary operators in detail with practical examples.

#### 1. Basic Ternary Operator

```cpp
#include <iostream>

int main()
{
    int a = 10;
    int b = 20;

    // Basic ternary operator
    int maxBasic = (a > b) ? a : b;
    std::cout << "Basic Ternary: The maximum value is " << maxBasic << std::endl;

    return 0;
}
```

**Explanation:**

- **Basic Ternary Operator**:
  - Syntax: `(condition) ? true_expression : false_expression`.
  - Example: `(a > b) ? a : b;`
  - If `a > b` is true, `maxBasic` gets the value of `a`; otherwise, it gets the value of `b`.
  - Output: Prints the maximum value between `a` and `b`.

---

#### 2. Nested Ternary Operator

```cpp
#include <iostream>

int main()
{
    int a = 10;
    int b = 20;
    int c = 15;

    // Nested ternary operator
    int maxNested = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    std::cout << "Nested Ternary: The maximum value is " << maxNested << std::endl;

    return 0;
}
```

**Explanation:**

- **Nested Ternary Operator**:
  - Allows nesting of ternary operators to handle multiple conditions.
  - Example: `(a > b) ? (a > c ? a : c) : (b > c ? b : c);`
  - If `a > b` is true, it evaluates `(a > c ? a : c)` to find the maximum between `a` and `c`.
  - If `a > b` is false, it evaluates `(b > c ? b : c)` to find the maximum between `b` and `c`.
  - Output: Prints the maximum value among `a`, `b`, and `c` using nested ternary operators.

---

#### 3. Ternary Operator with Function Calls

```cpp
#include <iostream>

// Function definitions
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main()
{
    int x = 5;
    int y = 10;
    bool shouldAdd = true;

    // Ternary operator with function calls
    int resultFunc = shouldAdd ? add(x, y) : subtract(x, y);
    std::cout << "Ternary with Functions: The result is " << resultFunc << std::endl;

    return 0;
}
```

**Explanation:**

- **Ternary Operator with Function Calls**:
  - Uses ternary operator to choose between function calls based on a condition.
  - Example: `shouldAdd ? add(x, y) : subtract(x, y);`
  - If `shouldAdd` is true, calls `add(x, y)` and assigns the result to `resultFunc`.
  - If `shouldAdd` is false, calls `subtract(x, y)` and assigns the result.
  - Output: Prints the result of either addition or subtraction based on the value of `shouldAdd`.

---

#### 4. Combining Ternary with Loops

```cpp
#include <iostream>

int main()
{
    // Combining ternary with other control structures
    std::cout << "Combining with Loops:" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << " is " << (i % 2 == 0 ? "even" : "odd") << std::endl;
    }

    return 0;
}
```

**Explanation:**

- **Combining Ternary with Loops**:
  - Integrates ternary operator within a loop for conditional output.
  - Example: `(i % 2 == 0 ? "even" : "odd")`
  - Checks if `i` is even (`i % 2 == 0`). If true, prints `"even"`, otherwise prints `"odd"`.
  - Output: Prints whether each `i` in the loop is even or odd using a ternary operator inside the loop.

---

Ternary operators are versatile and effective in scenarios where concise conditional decisions are required, enhancing both code clarity and efficiency in C++ programming.
