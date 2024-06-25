The `register` storage class in C and C++ is used to hint to the compiler that a variable would be better off stored in a CPU register for faster access. However, it's important to note that the use of `register` is more of a suggestion to the compiler rather than a strict directive. Modern compilers are generally smart enough to optimize variable storage and access automatically, often making the use of `register` unnecessary.

- **Scope:** Same as automatic variables; limited to the block or function where they are declared.
- **Default Value:** Garbage Value.
- **Memory Location:** Stored in CPU registers for faster access (compiler-dependent).
- **Lifetime:** Limited to the block or function where they are declared, like automatic variables.

```cpp
#include <iostream>
using namespace std;

void myFunction()
{
    cout << "Examining register storage\n";

    // Declaring a variable with register storage
    register char x = 'X';

    // Printing the register variable
    cout << "Value of 'x' declared as register: " << x;
}

int main()
{
    // To demonstrate register storage class
    myFunction();
    return 0;
}
```
