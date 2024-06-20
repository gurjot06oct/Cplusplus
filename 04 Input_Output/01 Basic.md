## Standard I/O with `cin` and `cout`

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;         // Input two integers
    cout << a + b << endl; // Output their sum
    return 0;
}
```

**Advantages:**

- Easy to use.
- Well-integrated with C++ standard libraries.

**Disadvantages:**

- Slower compared to other methods, especially with large input/output.

## Advanced I/O

### Using Fast I/O with `getchar_unlocked` and `putchar_unlocked`

These are non-standard functions that provide extremely fast I/O operations but are specific to some compilers like GCC.

```cpp
#include <cstdio>
#include <cctype>
inline void fastInput(int &x)
{
    x = 0;
    int c = getchar_unlocked();
    while (!isdigit(c))
        c = getchar_unlocked();
    for (; isdigit(c); c = getchar_unlocked())
        x = x * 10 + c - '0';
}

inline void fastOutput(int x)
{
    char buf[11];
    int i = 10;
    buf[10] = '\n';
    do
    {
        buf[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    do
    {
        putchar_unlocked(buf[i]);
    } while (buf[i++] != '\n');
}

int main()
{
    int a, b;
    fastInput(a);
    fastInput(b);
    fastOutput(a + b);
    return 0;
}
```

**Advantages:**

- Very fast for large inputs and outputs.

**Disadvantages:**

- Less portable (non-standard).
- More complex and harder to debug.

### Faster I/O

```cpp
#include <cstdio>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b); // Input two integers
    printf("%d\n", a + b);  // Output their sum
    return 0;
}
```

**Advantages:**

- Faster than `cin` and `cout`.
- More control over formatting.

**Disadvantages:**

- More error-prone (e.g., format specifiers must match the variable types).

## Reading and Writing with `ifstream` and `ofstream`

```cpp
#include <fstream>
using namespace std;
```

When dealing with file input and output, use these standard C++ classes.

```cpp
int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int a, b;
    infile >> a >> b;
    outfile << a + b << endl;

    infile.close();
    outfile.close();

    return 0;
}
```

**Advantages:**

- Standard and portable.
- Suitable for file operations.

**Disadvantages:**

- Not the fastest method for competitive programming.
