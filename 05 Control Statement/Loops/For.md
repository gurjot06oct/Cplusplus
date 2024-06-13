## `for` Loops in C++

In C++, the `for` loop is a fundamental control flow statement that allows repetitive execution of a block of code based on specified conditions.

### Basic `for` Loop

The basic `for` loop structure consists of three parts: initialization, condition, and increment/decrement.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Basic `for` Loop
    cout << "Basic for loop:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "i = " << i << endl; // Loop body
    }

    return 0;
}
```

In this example:

- **Initialization (`int i = 0;`)**: Initializes the loop variable `i` to 0 before the loop starts.
- **Condition (`i < 5;`)**: Specifies the condition for executing the loop. The loop continues as long as `i` is less than 5.
- **Increment (`++i`)**: Increases `i` by 1 after each iteration of the loop.

### Nested `for` Loop

Nested `for` loops are used when one loop is placed inside another loop.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Nested `for` Loop
    cout << "\nNested for loop:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "i = " << i << ", j = " << j << endl;
        }
    }

    return 0;
}
```

In this example:

- The outer loop runs 3 times (`i = 0` to `i = 2`).
- For each iteration of the outer loop, the inner loop runs 2 times (`j = 0` to `j = 1`).

### Breaking and Continuing

The `break` and `continue` statements are used to control the flow within a `for` loop.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Breaking and Continuing
    cout << "\nBreaking and Continuing:" << endl;
    for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            break; // Exit loop when i is 5
        }
        if (i % 2 == 0) {
            continue; // Skip even numbers
        }
        cout << "i = " << i << endl;
    }

    return 0;
}
```

In this example:

- The loop runs from `i = 0` to `i = 9`.
- `break` statement exits the loop immediately when `i` becomes 5.
- `continue` statement skips printing even numbers (`i % 2 == 0`).

### Infinite Loop

An infinite loop runs indefinitely unless terminated explicitly.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Infinite Loop
    cout << "\nInfinite Loop:" << endl;
    for (;;) {
        cout << "This will print forever!" << endl;
        break; // Breaking immediately to avoid infinite execution
    }

    return 0;
}
```

In this example:

- The loop `for (;;) { ... }` is an infinite loop.
- The `break` statement is used to terminate the loop after printing once.

### Range-Based `for` Loop (C++11 and later)

C++11 introduced the range-based `for` loop for iterating over elements of a container or a range.

```cpp
#include <iostream>
using namespace std;

int main() {
    // Range-Based `for` Loop (C++11 and later)
    cout << "\nRange-Based for loop:" << endl;
    int arr[]{1, 2, 3, 4, 5};
    for (int value : arr) {
        cout << value << endl;
    }

    return 0;
}
```

In this example:

- `int arr[]{1, 2, 3, 4, 5};` initializes an array `arr` with values.
- The range-based `for` loop iterates over each element (`value`) in the array `arr`.

Understanding the versatility of `for` loops is crucial for efficient programming in C++. By mastering these variations and understanding their applications, programmers can write concise and effective code to handle repetitive tasks and iterate over data structures.
