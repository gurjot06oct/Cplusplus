"The `static` storage class is utilized to declare static variables, commonly employed in C++ programs. Static variables retain their value even after they go out of scope, thus preserving the value of their last use within their scope. Essentially, they are initialized only once and persist until the program's termination. Consequently, no new memory allocation occurs because they are not re-declared. Global static variables can be accessed from any part of the program.

Properties of `static` Storage Class:

- **Scope:** Local
- **Default Value:** Zero
- **Memory Location:** RAM
- **Lifetime:** Until the end of the program"

```cpp
#include <iostream>
using namespace std;

// Function containing static variables
int staticFunction()
{
    cout << "Static variables: ";
    static int count = 0;
    count++;
    return count;
}

// Function containing non-static variables
int nonStaticFunction()
{
    cout << "Non-Static variables: ";
    int count = 0;
    count++;
    return count;
}

int main()
{
    // Calling the static function
    cout << staticFunction() << "\n";
    cout << staticFunction() << "\n";

    // Calling the non-static function
    cout << nonStaticFunction() << "\n";
    cout << nonStaticFunction() << "\n";

    return 0;
}
```
