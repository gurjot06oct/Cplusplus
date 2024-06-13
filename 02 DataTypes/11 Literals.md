## Literals

```cpp
#include <iostream>

int main() {
    // Character literals
    char ch1 = 'A';             // Single character 'A'
    char ch2 = '\n';            // Newline character
    char ch3 = '\t';            // Tab character
    char ch4 = '\u03B1';        // Unicode character α

    // Float literals
    float temperature = 25.5f;  // Single-precision floating point
    float velocity = 3.0e8f;    // Scientific notation float

    // String literals
    const char *greeting = "Hello, world!";  // C-style string literal
    const char myName[] = {'J', 'o', 'h', 'n', '\0'};  // Character array literal

    // Concatenated string literals
    const char *fullName = "John" " " "Doe";

    // Decimal literals
    short decimal_short = 42;              // Signed short int
    unsigned short u_decimal_short = 42U;  // Unsigned short int
    int decimal = 42;                      // Signed int
    unsigned int u_decimal = 42u;          // Unsigned int
    long decimal_long = 42L;                // Signed long int
    unsigned long u_decimal_long = 42UL;   // Unsigned long int
    long long decimal_llong = 42LL;        // Signed long long int
    unsigned long long u_decimal_llong = 42ULL;  // Unsigned long long int

    // Octal literals
    short octal_short = 052;               // Signed octal short int
    unsigned short u_octal_short = 052u;   // Unsigned octal short int
    int octal = 052;                       // Signed octal int
    unsigned int u_octal = 052u;           // Unsigned octal int
    long octal_long = 052L;                // Signed octal long int
    unsigned long u_octal_long = 052UL;    // Unsigned octal long int
    long long octal_llong = 052LL;         // Signed octal long long int
    unsigned long long u_octal_llong = 052ULL;  // Unsigned octal long long int

    // Hexadecimal literals
    short hex_short = 0x2A;                // Signed hexadecimal short int
    unsigned short u_hex_short = 0x2Au;    // Unsigned hexadecimal short int
    int hex = 0x2A;                        // Signed hexadecimal int
    unsigned int u_hex = 0x2Au;            // Unsigned hexadecimal int
    long hex_long = 0x2AL;                 // Signed hexadecimal long int
    unsigned long u_hex_long = 0x2AUL;     // Unsigned hexadecimal long int
    long long hex_llong = 0x2ALL;          // Signed hexadecimal long long int
    unsigned long long u_hex_llong = 0x2AULL;  // Unsigned hexadecimal long long int

    // Binary literals (C++14 and later)
    short binary_short = 0b101010;             // Binary short int
    unsigned short u_binary_short = 0b101010u; // Unsigned binary short int
    int binary = 0b101010;                     // Binary int
    unsigned int u_binary = 0b101010u;         // Unsigned binary int
    long binary_long = 0b101010L;              // Binary long int
    unsigned long u_binary_long = 0b101010UL;  // Unsigned binary long int
    long long binary_llong = 0b101010LL;       // Binary long long int
    unsigned long long u_binary_llong = 0b101010ULL;  // Unsigned binary long long int

    return 0;
}
```

### Explanation:

- **Character Literals**: Represent single characters ('A'), special characters ('\n', '\t'), and Unicode characters ('\u03B1').
- **Float Literals**: Include regular floating-point numbers (25.5f) and scientific notation (3.0e8f).
- **String Literals**: Represented by `"Hello, world!"` for C-style strings and character arrays (`{'J', 'o', 'h', 'n', '\0'}`) for names.
- **Numeric Literals**: Cover decimal (`42`), octal (`052`), hexadecimal (`0x2A`), and binary (`0b101010`) forms, with signed and unsigned variants for short, int, long, and long long types.

These literals illustrate various ways to initialize and represent data in C++, each tailored to specific needs such as character handling, numerical precision, and different numeral systems.
