## Arithmetic Operators

Arithmetic operators in C++ perform mathematical operations on operands.

### Unary Operators: Unary Plus (`+`) and Unary Minus (`-`)

```cpp
#include <iostream>

int main()
{
    // Unary Operators: Unary Plus (+) and Unary Minus (-)
    int positiveValue = 5;
    int negativeValue = -positiveValue;

    std::cout << "Value after unary plus: " << positiveValue << std::endl;
    std::cout << "Value after unary minus: " << negativeValue << std::endl;

    return 0;
}
```

- `positiveValue` is assigned `5`.
- `negativeValue` is assigned `-positiveValue`, resulting in `-5`.
- Outputs the effects of unary operators on these values.

### Binary Arithmetic Operators: Addition, Subtraction, Multiplication

```cpp
#include <iostream>

int main()
{
    int operand1 = 3, operand2 = 6, result = 0;

    // Addition
    result = operand1 + operand2;
    std::cout << "Addition result: " << result << std::endl;

    // Subtraction
    result = operand1 - operand2;
    std::cout << "Subtraction result: " << result << std::endl;

    // Multiplication
    result = operand1 * operand2;
    std::cout << "Multiplication result: " << result << std::endl;

    return 0;
}
```

- Demonstrates basic binary arithmetic operations (`+`, `-`, `*`).
- Outputs results of addition, subtraction, and multiplication operations.

### Binary Arithmetic Operators: Division, Modulo

```cpp
#include <iostream>

int main()
{
    int operand1 = 10, operand2 = 3, result = 0;

    // Division
    result = operand1 / operand2;
    std::cout << "Division result: " << result << std::endl;

    // Modulo
    result = operand1 % operand2;
    std::cout << "Modulo result: " << result << std::endl;

    return 0;
}
```

- Shows division (`/`) of `operand1` by `operand2`.
- Outputs the integer division result.
- Shows modulo (`%`) operation, which gives the remainder of `operand1` divided by `operand2`.
- Outputs the remainder.

### Increment and Decrement Operators: Prefix and Postfix

```cpp
#include <iostream>

int main()
{
    int number = 5;

    // Postfix Increment
    int postIncResult = number++;
    std::cout << "Value after postfix increment: " << number << std::endl;
    std::cout << "Postfix increment result: " << postIncResult << std::endl;

    // Prefix Increment
    int preIncResult = ++number;
    std::cout << "Value after prefix increment: " << number << std::endl;
    std::cout << "Prefix increment result: " << preIncResult << std::endl;

    // Postfix Decrement
    int postDecResult = number--;
    std::cout << "Value after postfix decrement: " << number << std::endl;
    std::cout << "Postfix decrement result: " << postDecResult << std::endl;

    // Prefix Decrement
    int preDecResult = --number;
    std::cout << "Value after prefix decrement: " << number << std::endl;
    std::cout << "Prefix decrement result: " << preDecResult << std::endl;

    return 0;
}
```

- Demonstrates prefix and postfix increment (`++`), decrement (`--`) operators.
- Shows the difference between postfix (changes value after using) and prefix (changes value before using) forms.
- Outputs results for each increment and decrement operation.

### Increment and Decrement with Comma Operators

```cpp
#include <iostream>

int main()
{
    int varA = 5, varB = 6, varC = 3;
    std::cout << "\nInitial values: varA=" << varA << ", varB=" << varB << ", varC=" << varC << std::endl;

    // Comma Operator
    int resultFromComma = (varA++, varB--, varC++);
    std::cout << "Values after comma expression: varA=" << varA << ", varB=" << varB << ", varC=" << varC << std::endl;
    std::cout << "Result of comma expression: " << resultFromComma << std::endl;

    return 0;
}
```

- Initializes variables `varA`, `varB`, and `varC`.
- Uses the comma operator to sequentially execute expressions (`varA++`, `varB--`, `varC++`).
- Outputs updated values of `varA`, `varB`, `varC` after the comma expression and the result of the comma expression itself.
