## Conditional Statements in C++

Conditional statements in C++ allow programmers to control the flow of execution based on conditions evaluated at runtime.

### Basic `if` Statement

The `if` statement is used to execute a block of code if a specified condition is true.

```cpp
#include <iostream>

int main() {
    int number = 15;

    // Basic if statement
    if (number > 10)
        std::cout << "Number is greater than 10 (if statement)" << std::endl;

    return 0;
}
```

In this example:

- The condition `number > 10` is evaluated.
- If true, the message "Number is greater than 10 (if statement)" is displayed.

### `if-else` Statement

The `if-else` statement executes one block of code if the condition is true and another block if the condition is false.

```cpp
#include <iostream>

int main() {
    int number = 15;

    // if-else statement
    if (number > 20)
        std::cout << "Number is greater than 20 (if-else statement)" << std::endl;
    else
        std::cout << "Number is not greater than 20 (if-else statement)" << std::endl;

    return 0;
}
```

In this example:

- If `number` is greater than 20, it prints "Number is greater than 20 (if-else statement)".
- Otherwise, it prints "Number is not greater than 20 (if-else statement)".

### `if-else if-else` Statement

The `if-else if-else` statement allows checking multiple conditions sequentially.

```cpp
#include <iostream>

int main() {
    int number = 15;

    // if-else if-else statement
    if (number > 30)
        std::cout << "Number is greater than 30 (if-else if-else statement)" << std::endl;
    else if (number > 20)
        std::cout << "Number is greater than 20 but less than or equal to 30 (if-else if-else statement)" << std::endl;
    else if (number > 10)
        std::cout << "Number is greater than 10 but less than or equal to 20 (if-else if-else statement)" << std::endl;
    else
        std::cout << "Number is 10 or less (if-else if-else statement)" << std::endl;

    return 0;
}
```

In this example:

- It checks multiple conditions (`number > 30`, `number > 20`, `number > 10`) sequentially.
- It prints the message corresponding to the first true condition found.

### Nested `if-else` Statement

Nested `if-else` statements are `if-else` statements inside another `if` or `else` block.

```cpp
#include <iostream>

int main() {
    int number = 15;

    // Nested if-else statement
    if (number > 10) {
        std::cout << "Number is greater than 10 (nested if-else statement)" << std::endl;
        if (number > 20)
            std::cout << "Number is also greater than 20 (nested if-else statement)" << std::endl;
        else
            std::cout << "Number is not greater than 20 (nested if-else statement)" << std::endl;
    } else {
        std::cout << "Number is 10 or less (nested if-else statement)" << std::endl;
        if (number < 5)
            std::cout << "Number is also less than 5 (nested if-else statement)" << std::endl;
        else
            std::cout << "Number is between 5 and 10 (nested if-else statement)" << std::endl;
    }

    return 0;
}
```

In this example:

- Depending on whether `number` is greater than 10 or not, different blocks of code are executed.
- Each block may contain another `if-else` statement for further condition checking.

Understanding and mastering conditional statements in C++ is fundamental for writing effective and structured code. They provide the flexibility to execute specific blocks of code based on varying conditions evaluated during program execution. By leveraging `if`, `if-else`, `if-else if-else`, and nested `if-else` statements, programmers can create logic that responds dynamically to different scenarios encountered in their programs.
