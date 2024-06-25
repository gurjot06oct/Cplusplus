The `thread_local` storage class in C++11 allows variables to have a separate instance for each thread that uses them. Here's an explanation of the six properties of the `thread_local` storage class based on the provided information and the example code:

- **Scope**: Local to the defining block.
- **Lifetime**: Created on block entry, destroyed on exit.
- **Access**: Cannot take address directly.
- **Memory Location**: RAM.
- **Initialization**: Can be initialized during declaration.
- **Thread Safety**: Independent instance for each thread.

```cpp
#include <iostream>
#include <thread>
using namespace std;

// Define thread_local variable
thread_local int var = 10;

// Function to print thread's var value
void printVar(int increment)
{
    cout << "Thread " << this_thread::get_id() << " var Value: " << (var += increment) << '\n';
}

int main()
{
    // Thread 1
    thread th1([]()
               { printVar(18); });

    // Thread 2
    thread th2([]()
               { printVar(7); });

    // Thread 3
    thread th3([]()
               { printVar(13); });

    // Join threads
    th1.join();
    th2.join();
    th3.join();

    return 0;
}
```
