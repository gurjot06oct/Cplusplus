## `while` and `do-while` Loops in C++

In C++, `while` and `do-while` loops are fundamental control flow structures that allow code to be executed repeatedly based on a condition.

### Basic `while` Loop

The `while` loop executes a block of code repeatedly as long as a specified condition is true. The loop checks the condition before entering each iteration.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Basic `while` loop example
    int i = 0; // Initialization
    while (i < 5) { // Condition
        cout << "i = " << i << endl; // Loop body
        ++i; // Increment
    }

    return 0;
}
```

**Explanation**:

- **Initialization (`int i = 0;`)**: Starts the loop with `i` initialized to 0.
- **Condition (`i < 5`)**: Specifies when to continue looping. The loop runs as long as `i` is less than 5.
- **Increment (`++i`)**: Increases `i` by 1 after each iteration.

### Breaking `while` Loop

You can terminate a `while` loop prematurely using the `break` statement based on a certain condition.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Breaking `while` loop example
    int i = 0;
    while (i < 10) {
        if (i == 5) {
            break; // Exit loop when i is 5
        }
        if (i % 2 == 0) {
            ++i;
            continue; // Skip even numbers
        }
        cout << "i = " << i << endl;
        ++i;
    }

    return 0;
}
```

**Explanation**:

- The loop runs from `i = 0` to `i = 9`.
- **`break` statement**: Terminates the loop immediately when `i` becomes 5.
- **`continue` statement**: Skips even numbers (`i % 2 == 0`) without executing further loop body statements.

### `do-while` Loop

The `do-while` loop is similar to the `while` loop, but it checks the condition after executing the loop body. This guarantees that the loop body is executed at least once.

```cpp
#include <iostream>
using namespace std;

int main() {
    // `do-while` loop example
    cout << "\n`do-while` loop:" << endl;
    int i = 0; // Initialization
    do {
        cout << "i = " << i << endl; // Loop body
        ++i; // Increment
    } while (i < 5); // Condition

    return 0;
}
```

**Explanation**:

- The loop executes the loop body once before checking the condition.
- It continues looping as long as `i` is less than 5.

### Infinite `while` Loop

An infinite `while` loop continues indefinitely unless explicitly terminated within the loop body.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Infinite `while` loop example
    cout << "\nInfinite `while` loop:" << endl;
    while (true) { // Infinite loop
        cout << "This will print forever!" << endl;
        break; // Breaking immediately to avoid infinite execution
    }

    return 0;
}
```

**Explanation**:

- **`while (true)`**: Initiates an infinite loop.
- The loop body executes indefinitely until the `break` statement is encountered.

Understanding `while` and `do-while` loops in C++ provides powerful tools for repetitive execution based on conditions. By mastering these loop structures, you gain essential skills for implementing iterative algorithms and handling various control flow scenarios in your programs.
