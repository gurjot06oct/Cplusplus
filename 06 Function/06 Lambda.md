## Lambda Function

In C++, a lambda function is an anonymous function that you can define on the spot, without providing a separate name. Lambda functions are particularly useful in situations where you need a simple function for a short period, such as passing it to an algorithm or as a callback function.

### Syntax:

```cpp
[capture clause](parameters) -> return_type {
// body of the lambda function
}
```

### Capture Clauses:

Lambda functions can capture variables from the surrounding scope by value or by reference.

- **By Value**: `[=]` captures all variables from the enclosing scope by value. `[a, b]` captures 'a' and 'b' by value specifically.

- **By Reference**: `[&]` captures all variables from the enclosing scope by reference. `[&a, &b]` captures 'a' and 'b' by reference specifically.

### Parameters:

Lambda functions can take parameters just like regular functions.

### Return Type:

The return type of the lambda function can be specified using the trailing return type syntax (`-> return_type`), or it can be deduced by the compiler.

```cpp
#include <iostream>

int main()
{
    int a = 5;
    int b = 10;

    // Lambda function that captures 'a' and 'b' by value
    auto sum = [a, b]()
    {
        return a + b;
    };

    std::cout << "Sum: " << sum() << std::endl;

    return 0;
}
```

### Use Cases:

- **STL Algorithms**: Lambda functions are commonly used with algorithms like `std::transform`, `std::sort`, etc.
- **Callback Functions**: When working with libraries or APIs that expect function pointers or callable objects.

### Advantages:

- **Concise Code**: Lambda functions allow you to write short, inline functions, reducing the need for named functions.
- **Capture Semantics**: With capture clauses, you can control how variables are captured from the surrounding scope.

### Limitations:

- **Readability**: Overuse of complex lambdas can reduce code readability.
- **Performance**: While modern compilers optimize lambda functions well, misuse can lead to performance issues.

#### Capture List in Lambda Expressions

A capture list specifies which variables from the enclosing scope are accessible inside the lambda expression and how they are accessed (by value or by reference).

### Explicit Capture by Value and Reference

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Lambda with explicit capture: 'x' by value and 'y' by reference
    auto lambda_explicit = [x, &y]() {
        std::cout << "Captured x: " << x << std::endl;
        std::cout << "Captured y by reference: " << y << std::endl;
        // x++; // Error: Cannot modify 'x' captured by value
        y++; // Modifying 'y' captured by reference
    };

    lambda_explicit();                                      // Output: Captured x: 10, Captured y by reference: 20
    std::cout << "Modified value of y: " << y << std::endl; // Output: Modified value of y: 21

    return 0;
}
```

- In this example, `[x, &y]` captures `x` by value and `y` by reference.
- Changes to `x` inside the lambda are not allowed (`x++` would cause an error), but modifications to `y` affect the original variable outside the lambda.

### Implicit Capture by Reference

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Lambda with implicit capture: Capture all variables by reference
    auto lambda_implicit = [&]() {
        std::cout << "Captured x by reference: " << x << std::endl;
        std::cout << "Captured y by reference: " << y << std::endl;
        x++; // Modifying 'x' captured by reference
        y++; // Modifying 'y' captured by reference
    };

    lambda_implicit();                                                   // Output: Captured x by reference: 10, Captured y by reference: 20
    std::cout << "Modified values: x=" << x << ", y=" << y << std::endl; // Output: Modified values: x=11, y=21

    return 0;
}
```

- Here, `[&]` captures all variables (`x` and `y`) by reference, allowing modifications to affect the original variables directly.

### Capture All Variables by Value

```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Lambda with capture all variables by value
    auto lambda_all = [=]() {
        std::cout << "Captured x: " << x << std::endl;
        std::cout << "Captured y: " << y << std::endl;
        // x++; // Error: Cannot modify 'x' captured by value
        // y++; // Error: Cannot modify 'y' captured by value
    };

    lambda_all(); // Output: Captured x: 10, Captured y: 20

    return 0;
}
```

- In `[=]`, all variables (`x` and `y`) are captured by value. Modifications to `x` or `y` inside the lambda would result in compilation errors since they are captured as constants.


### Use of `mutable` with Lambda Functions

In C++, lambda functions can capture variables from their surrounding scope in two ways: by value or by reference. By default, variables captured by value are immutable within the lambda. However, if you need to modify a captured variable, you can use the `mutable` keyword.

When a lambda function captures variables by value, the `mutable` keyword allows you to modify the captured variables inside the lambda. Without `mutable`, any attempt to modify the captured variable would result in a compilation error because the captured variable is treated as `const` by default.

### Example
```cpp
#include <iostream>

int main() {
    int x = 10;

    // Lambda capturing x by value (immutable by default)
    auto lambda1 = [x]() {
        // x++; // This would cause a compilation error
        std::cout << "x (inside lambda1): " << x << std::endl;
    };

    lambda1(); // Outputs: x (inside lambda1): 10

    // Lambda capturing x by value but with mutable
    auto lambda2 = [x]() mutable {
        x++; // Allowed because of mutable
        std::cout << "x (inside lambda2): " << x << std::endl;
    };

    lambda2(); // Outputs: x (inside lambda2): 11

    // Outside the lambda, x remains unchanged
    std::cout << "x (outside lambda): " << x << std::endl; // Outputs: x (outside lambda): 10

    return 0;
}
```

### Explanation
- **`lambda1`:** Captures `x` by value. The variable `x` inside the lambda is immutable, so trying to modify it (e.g., `x++`) would result in a compilation error.
  
- **`lambda2`:** Captures `x` by value but uses the `mutable` keyword. This allows the lambda to modify the captured value. However, these modifications are local to the lambda and do not affect the original variable `x` outside the lambda.

### Key Points
- **Mutable lambdas** are useful when you need to modify captured values within the lambda function.
- The changes made to the captured variables inside a mutable lambda do not affect the original variables outside the lambda.

Would you like further clarification or more examples on this topic?