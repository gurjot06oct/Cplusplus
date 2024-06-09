// Advanced I/O

#include <cstdio>
#include <cctype>

// #### Using Fast I/O with `getchar_unlocked` and `putchar_unlocked`

// These are non-standard functions that provide extremely fast I/O operations but are specific to some compilers like GCC.

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

// **Advantages:**
// - Very fast for large inputs and outputs.

// **Disadvantages:**
// - Less portable (non-standard).
// - More complex and harder to debug.