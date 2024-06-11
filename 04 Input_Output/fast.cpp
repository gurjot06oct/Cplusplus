#include <cstdio>

// Faster I/O
int main()
{
    int a, b;
    scanf("%d %d", &a, &b); // Input two integers
    printf("%d\n", a + b);  // Output their sum
    return 0;
}
// **Advantages:**
// - Faster than `cin` and `cout`.
// - More control over formatting.

// **Disadvantages:**
// - More error-prone (e.g., format specifiers must match the variable types).