# Exception Handling in C++

In C++, exceptions are runtime anomalies or abnormal conditions that a program encounters during its execution. Exception handling is the process of managing these exceptions, allowing control to transfer from the point where the exception occurred to another part of the code.

Using exception handling in C++, we can ensure that our program continues running despite encountering errors.

## What is a C++ Exception?

An exception is an unexpected problem that arises during the execution of a program, causing it to terminate abruptly. Exceptions occur at runtime.

### Types of C++ Exceptions

There are two types of exceptions in C++:

1. **Synchronous**: These occur due to errors in the input data or the program's inability to handle the current data type, such as division by zero.
2. **Asynchronous**: These are beyond the program’s control, such as hardware failures or keyboard interrupts.

## C++ try, catch, and throw

C++ provides built-in features for exception handling using the keywords `try`, `catch`, and `throw`, each serving a distinct purpose.

### Syntax of try-catch in C++

```cpp
try {
    // Code that might throw an exception
    throw SomeExceptionType("Error message");
}
catch (ExceptionName e1) {
    // Catch block to handle the exception
}
```

### Explanation

1. **try**: The `try` keyword represents a block of code that may throw an exception. It’s followed by one or more `catch` blocks. If an exception occurs, the `try` block throws that exception.
2. **catch**: The `catch` statement represents a block of code that is executed when a particular exception is thrown from the `try` block. The code to handle the exception is written inside the `catch` block.
3. **throw**: An exception in C++ can be thrown using the `throw` keyword. When a program encounters a `throw` statement, it immediately terminates the current function and starts looking for a matching `catch` block.

**Note**: Multiple `catch` statements can be used to handle different types of exceptions thrown by the `try` block.

## Advantages of Exception Handling in C++

1. **Separation of Error Handling Code from Normal Code**: Traditional error handling using if-else conditions mixes error-handling code with normal code, making it less readable and maintainable. With try/catch blocks, error-handling code is separated from normal code.
2. **Functions/Methods Handle Only Selected Exceptions**: A function can throw many exceptions but choose to handle only some of them. Unhandled exceptions are passed to the caller.
3. **Grouping of Error Types**: Both basic types and objects can be thrown as exceptions in C++. We can create a hierarchy of exception objects, group exceptions in namespaces or classes, and categorize them according to their types.

## Examples of Exception Handling in C++

### Example 1

This example demonstrates the use of `try`, `catch`, and `throw` in exception handling.

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int numerator = 10;
        int denominator = 0;
        int res;

        if (denominator == 0) {
            throw runtime_error("Division by zero not allowed!");
        }

        res = numerator / denominator;
        cout << "Result after division: " << res << endl;
    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
```

**Output:**

```
Exception: Division by zero not allowed!
```

### Example 2

This example shows a simple flow of `try`/`catch` blocks.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = -1;

    cout << "Before try \n";

    try {
        cout << "Inside try \n";
        if (x < 0) {
            throw x;
            cout << "After throw (Never executed) \n";
        }
    } catch (int x) {
        cout << "Exception Caught \n";
    }

    cout << "After catch (Will be executed) \n";
    return 0;
}
```

**Output:**

```
Before try
Inside try
Exception Caught
After catch (Will be executed)
```

## Properties of Exception Handling in C++

### Property 1: Catch-All Block

The `catch(...)` block can catch all types of exceptions.

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        throw 10;
    } catch (char* excp) {
        cout << "Caught " << excp;
    } catch (...) {
        cout << "Default Exception\n";
    }
    return 0;
}
```

**Output:**

```
Default Exception
```

### Property 2: No Implicit Type Conversion for Primitive Types

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        throw 'a';
    } catch (int x) {
        cout << "Caught " << x;
    } catch (...) {
        cout << "Default Exception\n";
    }
    return 0;
}
```

**Output:**

```
Default Exception
```

### Property 3: Uncaught Exceptions Terminate Program

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        throw 'a';
    } catch (int x) {
        cout << "Caught ";
    }
    return 0;
}
```

**Output:**

```
terminate called after throwing an instance of 'char'
```

### Property 4: Dynamic Exception Specification

Dynamic exception specifications are deprecated since C++11, but here is an example for educational purposes.

```cpp
#include <iostream>
using namespace std;

void fun(int* ptr, int x) throw(int*, int) {
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
}

int main() {
    try {
        fun(NULL, 0);
    } catch (...) {
        cout << "Caught exception from fun()";
    }
    return 0;
}
```

**Output:**

```
Caught exception from fun()
```

### Property 5: Nested try/catch Blocks and Re-throwing Exceptions

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        try {
            throw 20;
        } catch (int n) {
            cout << "Handle Partially ";
            throw;
        }
    } catch (int n) {
        cout << "Handle remaining ";
    }
    return 0;
}
```

**Output:**

```
Handle Partially Handle remaining
```

### Property 6: Objects Destruction Before Control Transfer

```cpp
#include <iostream>
using namespace std;

class Test {
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};

int main() {
    try {
        Test t1;
        throw 10;
    } catch (int i) {
        cout << "Caught " << i << endl;
    }
    return 0;
}
```

**Output:**

```
Constructor of Test
Destructor of Test
Caught 10
```

## Limitations of Exception Handling in C++

1. **Code Structure and Flow**: Exceptions can create multiple invisible exit points in the code, making it hard to read and debug.
2. **Resource Leaks**: Improper handling of exceptions can lead to resource leaks.
3. **Learning Curve**: Writing exception-safe code can be challenging.
4. **Lack of Standard Practices**: There is no standard in C++ for exception handling practices, leading to variations.

By understanding and utilizing these concepts and examples, you can effectively manage exceptions in C++, ensuring robust and maintainable code.
