A union in C++ is a user-defined data type that allows you to store different data types in the same memory location. Unlike structures, where each member has its own memory space, all members of a union share the same memory space. This means that modifying one member of the union can affect the values of other members.

### Syntax:

union UnionName {
member1_type member1_name;
member2_type member2_name;
// more members...
};

### Key Points:

1. **Memory Sharing**: All members of a union share the same memory location, so modifying one member can affect the values of other members.
2. **Size**: The size of a union is determined by the largest member it contains.
3. **Use Cases**:
   - **Memory Efficiency**: Unions are useful when you need to store different types of data in a memory-efficient way.
   - **Type Puning**: Unions are often used for type punning, where you interpret the same chunk of memory as different types.

```cpp
#include <iostream>
using namespace std;

union MyUnion
{
    int i;
    float f;
    char c;
};
int main()
{

    // **Type Puning**
    // Accessing the same memory as a other type

    MyUnion u;
    u.i = 10;
    cout << "Integer: " << u.i << endl;

    u.f = 1.23f;
    cout << "Float: " << u.f << endl; // Reading as float

    u.c = 'A';
    cout << "Char: " << u.c << endl; // Reading as char
    return 0;
}
```
