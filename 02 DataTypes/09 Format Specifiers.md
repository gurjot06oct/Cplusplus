## Format Specifiers for `printf` (Output)

| Format Specifier | Description                                                                                |
| ---------------- | ------------------------------------------------------------------------------------------ |
| `%d` or `%i`     | Signed decimal integer                                                                     |
| `%u`             | Unsigned decimal integer                                                                   |
| `%f`             | Decimal floating point                                                                     |
| `%lf`            | Double floating point                                                                      |
| `%e` or `%E`     | Scientific notation (mantissa/exponent) using 'e' or 'E'                                   |
| `%g` or `%G`     | Shortest representation: `%e` or `%f`                                                      |
| `%x` or `%X`     | Unsigned hexadecimal integer                                                               |
| `%o`             | Unsigned octal integer                                                                     |
| `%c`             | Single character                                                                           |
| `%s`             | String of characters                                                                       |
| `%p`             | Pointer address                                                                            |
| `%n`             | Number of characters printed so far (stores in an integer variable passed to the function) |
| `%a` or `%A`     | Hexadecimal floating point                                                                 |

## Format Specifiers for `scanf` (Input)

| Format Specifier | Description                                         |
| ---------------- | --------------------------------------------------- |
| `%d`             | Reads a signed decimal integer                      |
| `%i`             | Reads an integer (auto-detects the base)            |
| `%u`             | Reads an unsigned decimal integer                   |
| `%f`             | Reads a floating point value                        |
| `%lf`            | Reads a double floating point value                 |
| `%e`, `%E`       | Reads a floating point value in scientific notation |
| `%g`, `%G`       | Reads a floating point value using `%e` or `%f`     |
| `%x`             | Reads an unsigned hexadecimal integer               |
| `%o`             | Reads an unsigned octal integer                     |
| `%c`             | Reads a single character                            |
| `%s`             | Reads a string of characters (stops at whitespace)  |
| `%p`             | Reads a pointer address                             |

## Size Modifiers

### Integer Size Modifiers

| Size Modifier | Description            |
| ------------- | ---------------------- |
| `%hhd`        | Signed char            |
| `%hhu`        | Unsigned char          |
| `%hd`         | Short int              |
| `%hu`         | Unsigned short int     |
| `%ld`         | Long int               |
| `%lu`         | Unsigned long int      |
| `%lld`        | Long long int          |
| `%llu`        | Unsigned long long int |

### Floating Point Size Modifiers

| Size Modifier | Description |
| ------------- | ----------- |
| `%f`          | Float       |
| `%lf`         | Double      |
| `%Lf`         | Long double |
