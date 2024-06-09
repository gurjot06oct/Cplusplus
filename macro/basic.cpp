// Macros in C++ are a powerful feature that allows for textual substitution, enabling code reuse, and can even contribute to metaprogramming. Here’s a comprehensive guide from basic to advanced usage of macros in C++:

// Simple macros are used for constant definitions. This can make your code more readable and easier to maintain.
#define PI 3.14159
#define MAX_BUFFER_SIZE 1024
// These macros can take arguments and perform simple operations.
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main()
{
    double radius = 5.0;
    double area = PI * radius * radius;
    char buffer[MAX_BUFFER_SIZE];
    int value = 5;
    int result = SQUARE(value); // result is 25
    int maxValue = MAX(10, 20); // maxValue is 20
    return 0;
}