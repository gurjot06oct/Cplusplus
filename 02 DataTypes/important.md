| Data Type             | Size (bytes)  | Range                                                                 | Format Specifier |
| --------------------- | ------------- | --------------------------------------------------------------------- | ---------------- |
| `char`                | 1             | `-128` to `127`                                                       | `%c`             |
| `signed char`         | 1             | `-128` to `127`                                                       | `%hhd`           |
| `unsigned char`       | 1             | `0` to `255`                                                          | `%hhu`           |
| `short`               | 2             | `-32,768` to `32,767`                                                 | `%hd`            |
| `unsigned short`      | 2             | `0` to `65,535`                                                       | `%hu`            |
| `int`                 | 4             | `-2,147,483,648` to `2,147,483,647`                                   | `%d` or `%i`     |
| `unsigned int`        | 4             | `0` to `4,294,967,295`                                                | `%u`             |
| `long`                | 4 or 8        | `-2,147,483,648` to `2,147,483,647` (4 bytes)                         | `%ld`            |
|                       |               | `-9,223,372,036,854,775,808` to `9,223,372,036,854,775,807` (8 bytes) | `%ld`            |
| `unsigned long`       | 4 or 8        | `0` to `4,294,967,295` (4 bytes)                                      | `%lu`            |
|                       |               | `0` to `18,446,744,073,709,551,615` (8 bytes)                         | `%lu`            |
| `long long`           | 8             | `-9,223,372,036,854,775,808` to `9,223,372,036,854,775,807`           | `%lld`           |
| `unsigned long long`  | 8             | `0` to `18,446,744,073,709,551,615`                                   | `%llu`           |
| `float`               | 4             | `~1.2E-38` to `~3.4E+38`                                              | `%f`             |
| `double`              | 8             | `~2.2E-308` to `~1.8E+308`                                            | `%lf`            |
| `long double`         | 10, 12, or 16 | `~3.4E-4932` to `~1.1E+4932`                                          | `%Lf`            |
| `string (char array)` | N/A           | N/A                                                                   | `%s`             |
| `pointer`             | 4 or 8        | N/A                                                                   | `%p`             |

### Notes:

- The size of `long` and `unsigned long` can vary between 4 and 8 bytes depending on the platform (32-bit or 64-bit).
- The range of `float`, `double`, and `long double` is approximate and depends on the implementation.
- The size of `long double` can be 10, 12, or 16 bytes depending on the compiler and platform.
