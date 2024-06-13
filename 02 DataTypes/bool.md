## Boolean Variables

Boolean variables in C++ (`bool`) are used to represent logical values `true` and `false`. They are fundamental for expressing conditions and control flow in programs, especially when combined with logical operators (`!`, `&&`, `||`) to perform complex logical evaluations. Understanding these operations is crucial for writing clear and efficient code in C++.

#### Declaration and Initialization

```cpp
#include <iostream>

int main() {
    // Declaration and initialization of bool variables
    bool isTrue = true;
    bool isFalse = false;

    // Outputting bool variables
    std::cout << "isTrue: " << isTrue << std::endl;   // Output: 1 (true)
    std::cout << "isFalse: " << isFalse << std::endl; // Output: 0 (false)

    return 0;
}
```

##### Explanation:

- **Boolean Variables:**
  - `bool isTrue = true;` declares a boolean variable `isTrue` initialized to `true`.
  - `bool isFalse = false;` declares a boolean variable `isFalse` initialized to `false`.
- **Outputting Boolean Variables:**
  - `std::cout` statements print the boolean variables.
  - `isTrue` prints as `1` (true) because in C++, `true` is represented numerically as `1`.
  - `isFalse` prints as `0` (false) because `false` is represented numerically as `0`.

#### Logical Operations

```cpp
#include <iostream>

int main() {
    bool isTrue = true;
    bool isFalse = false;

    // Logical NOT operator (!)
    bool notResult = !isTrue;
    std::cout << "Logical NOT of isTrue: " << notResult << std::endl; // Output: 0 (false)

    // Logical AND operator (&&)
    bool andResult = isTrue && isFalse;
    std::cout << "Logical AND of isTrue and isFalse: " << andResult << std::endl; // Output: 0 (false)

    // Logical OR operator (||)
    bool orResult = isTrue || isFalse;
    std::cout << "Logical OR of isTrue and isFalse: " << orResult << std::endl; // Output: 1 (true)

    return 0;
}
```

##### Explanation:

- **Logical NOT Operator (`!`):**
  - `bool notResult = !isTrue;`
  - The `!` operator negates the value of `isTrue`. Since `isTrue` is `true`, `!isTrue` evaluates to `false`, which is represented as `0`. Thus, `notResult` is `0`.
- **Logical AND Operator (`&&`):**
  - `bool andResult = isTrue && isFalse;`
  - The `&&` operator performs a logical AND operation between `isTrue` and `isFalse`. In this case, since `isFalse` is `false`, the result of `isTrue && isFalse` is `false`. Thus, `andResult` is `0`.
- **Logical OR Operator (`||`):**
  - `bool orResult = isTrue || isFalse;`
  - The `||` operator performs a logical OR operation between `isTrue` and `isFalse`. Since `isTrue` is `true`, at least one operand is `true`, so the result is `true`, represented as `1`. Thus, `orResult` is `1`.

### Boolean Comparisons

```cpp
#include <iostream>

int main() {
    // Example 1: Comparison with integer
    bool result1 = 5 == isTrue;
    std::cout << "5 == isTrue is " << result1 << std::endl; // Output: 0 (false)

    // Example 2: Comparison with another bool variable
    bool result2 = 5 == isFalse;
    std::cout << "5 == isFalse is " << result2 << std::endl; // Output: 0 (false)

    return 0;
}
```

#### Explanation: Comparison Operations with `bool` Variables

##### Comparison with `bool` Variables:

1. **Example 1: `5 == isTrue`**

   - `bool result1 = 5 == isTrue;`
   - Here, `5` is compared with `isTrue`. Since `isTrue` is `true` (`1`), the comparison `5 == 1` evaluates to `false` (`0`).

2. **Example 2: `5 == isFalse`**
   - `bool result2 = 5 == isFalse;`
   - Similarly, `5` is compared with `isFalse`. Since `isFalse` is `false` (`0`), the comparison `5 == 0` also evaluates to `false` (`0`).
