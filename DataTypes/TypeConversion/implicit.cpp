#include <iostream>
using namespace std;

// Implicit type conversion, also known as automatic type conversion or type coercion, happens when the compiler automatically converts one data type to another without requiring any explicit instructions from the programmer. This typically occurs when:

// - The data type of an operand in an expression is different from the data type expected by the operator.
// - When passing arguments to functions that accept different data types.

int main()
{
    int num1 = 10;
    double num2 = 5.5;

    double result = num1 + num2; // Implicit conversion of int to double
    cout << "Result: " << result << endl;

    return 0;
}

// - `num1` is an integer, and `num2` is a double.
// - When `num1` is added to `num2`, the compiler automatically promotes `num1` to a double before performing the addition.
// - The result of the addition is stored in a double variable `result`.