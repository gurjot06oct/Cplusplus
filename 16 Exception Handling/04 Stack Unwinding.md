# Stack Unwinding in C++

Stack unwinding is the process of removing function entries from the function call stack at runtime. The local objects are destroyed in the reverse order in which they were constructed. This process is closely related to exception handling in C++.

## What is Stack Unwinding?

When an exception occurs in C++, the function call stack is searched linearly for an exception handler. All entries before the function with the exception handler are removed from the call stack. Exception handling involves stack unwinding if the exception is not handled in the same function where it was thrown. Stack unwinding is essentially the process of calling destructors for all automatic objects constructed at runtime whenever an exception is thrown.

## Example

Consider the following program demonstrating stack unwinding:

```cpp
#include <iostream>
using namespace std;

// Function f1() that throws an int exception
void f1() throw(int) {
    cout << "\n f1() Start ";
    throw 100;
    cout << "\n f1() End ";
}

// Function f2() that calls f1()
void f2() throw(int) {
    cout << "\n f2() Start ";
    f1();
    cout << "\n f2() End ";
}

// Function f3() that calls f2() and handles the exception thrown by f1()
void f3() {
    cout << "\n f3() Start ";
    try {
        f2();
    } catch (int i) {
        cout << "\n Caught Exception: " << i;
    }
    cout << "\n f3() End";
}

// Driver code
int main() {
    f3();
    return 0;
}
```

**Output:**

```
 f3() Start
 f2() Start
 f1() Start
 Caught Exception: 100
 f3() End
```

## Explanation

1. **Function Call Flow**:

   - `f3()` starts and calls `f2()`.
   - `f2()` starts and calls `f1()`.
   - `f1()` starts and throws an exception of type `int` with the value `100`.

2. **Stack Unwinding**:

   - When `f1()` throws the exception, its entry is removed from the function call stack because it does not contain an exception handler.
   - The next entry, `f2()`, also does not have an exception handler, so its entry is removed from the stack.
   - Finally, the entry for `f3()` is found, which contains a catch block for the exception. The catch block is executed, and then the remaining code in `f3()` runs.

3. **Skipped Lines**:

   - The lines `cout << "\n f1() End ";` and `cout << "\n f2() End ";` are not executed because of the exception and subsequent stack unwinding.

4. **Local Objects**:
   - If there were local class objects inside `f1()` and `f2()`, their destructors would be called during the stack unwinding process.

## Note

Stack unwinding also occurs in other programming languages, such as Java, when an exception is not handled in the same function where it is thrown.

## Conclusion

Stack unwinding is a crucial concept in exception handling, ensuring that resources are properly released and destructors are called for automatic objects. This helps maintain program stability and resource management even when exceptions occur.
