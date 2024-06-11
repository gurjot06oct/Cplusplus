// In C++, a lambda function is an anonymous function that you can define on the spot, without providing a separate name. Lambda functions are particularly useful in situations where you need a simple function for a short period, such as passing it to an algorithm or as a callback function.

// Syntax:
// [capture clause](parameters) -> return_type {
//     // body of the lambda function
// }

// ### Capture Clauses:
// Lambda functions can capture variables from the surrounding scope by value or by reference.

// - **By Value**: `[=]` captures all variables from the enclosing scope by value. `[a, b]` captures 'a' and 'b' by value specifically.
// - **By Reference**: `[&]` captures all variables from the enclosing scope by reference. `[&a, &b]` captures 'a' and 'b' by reference specifically.

// ### Parameters:
// Lambda functions can take parameters just like regular functions.

// ### Return Type:
// The return type of the lambda function can be specified using the trailing return type syntax (`-> return_type`), or it can be deduced by the compiler.

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

// ### Use Cases:
// - **STL Algorithms**: Lambda functions are commonly used with algorithms like `std::transform`, `std::sort`, etc.
// - **Callback Functions**: When working with libraries or APIs that expect function pointers or callable objects.

// ### Advantages:
// - **Concise Code**: Lambda functions allow you to write short, inline functions, reducing the need for named functions.
// - **Capture Semantics**: With capture clauses, you can control how variables are captured from the surrounding scope.

// ### Limitations:
// - **Readability**: Overuse of complex lambdas can reduce code readability.
// - **Performance**: While modern compilers optimize lambda functions well, misuse can lead to performance issues.
