The `auto` keyword in the context of storage class specifies that the variable has automatic storage duration. By default, all local variables have this storage class if no other storage class is specified. However, in C++11 and later, `auto` is more commonly used for type inference rather than storage class specification.

- **Scope:** Local to the block in which they are defined.
- **Default Value:** Garbage Value
- **Memory Location:** RAM
- **Lifetime:** Automatically created when the block is entered and destroyed when the block is exited.
- **Default behavior:** Local variables without explicit storage class specifier.

```cpp
#include <iostream>
using namespace std;

void autoStorageClass()
{
    cout << "Demonstrating auto storage class\n";

    // Declaring auto storage class variables
    int a = 32;
    float b = 3.2f;
    char *c = "GeeksforGeeks";
    char d = 'G';

    // Printing the auto storage class variables
    cout << a << " \n";
    cout << b << " \n";
    cout << c << " \n";
    cout << d << " \n";
}

int main()
{
    // To demonstrate auto Storage Class
    autoStorageClass();

    return 0;
}
```
