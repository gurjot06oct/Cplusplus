### Operator Precedence and Associativity in C++

| Precedence | Operator                          | Description                                          | Associativity   |
|------------|-----------------------------------|------------------------------------------------------|-----------------|
| 1          | `::`                              | Scope resolution                                     | Left-to-right   |
| 2          | `a++`, `a--`                      | Suffix/postfix increment and decrement               |                 |
|            | `type()`, `type{}`                | Functional cast                                      |                 |
|            | `a()`                             | Function call                                        |                 |
|            | `a[]`                             | Subscript                                            |                 |
|            | `.` , `->`                        | Member access                                        |                 |
| 3          | `++a`, `--a`                      | Prefix increment and decrement                       | Right-to-left   |
|            | `+a`, `-a`                        | Unary plus and minus                                 |                 |
|            | `!`, `~`                          | Logical NOT and bitwise NOT                          |                 |
|            | `(type)`                          | C-style cast                                         |                 |
|            | `*a`, `&a`                        | Indirection and address-of                           |                 |
|            | `sizeof`                          | Size-of                                              |                 |
|            | `co_await`                        | Await-expression (C++20)                             |                 |
|            | `new`, `new[]`                    | Dynamic memory allocation                            |                 |
|            | `delete`, `delete[]`              | Dynamic memory deallocation                          |                 |
| 4          | `.*`, `->*`                       | Pointer-to-member                                    | Left-to-right   |
| 5          | `*`, `/`, `%`                     | Multiplication, division, and remainder              |                 |
| 6          | `+`, `-`                          | Addition and subtraction                             |                 |
| 7          | `<<`, `>>`                        | Bitwise left shift and right shift                   |                 |
| 8          | `<=>`                             | Three-way comparison operator (since C++20)          |                 |
| 9          | `<`, `<=`, `>`, `>=`              | Relational operators                                 |                 |
| 10         | `==`, `!=`                        | Equality operators                                   |                 |
| 11         | `&`                               | Bitwise AND                                          |                 |
| 12         | `^`                               | Bitwise XOR (exclusive or)                           |                 |
| 13         | `|`                               | Bitwise OR (inclusive or)                            |                 |
| 14         | `&&`                              | Logical AND                                          |                 |
| 15         | `||`                              | Logical OR                                           |                 |
| 16         | `a ? b : c`                       | Ternary conditional                                  | Right-to-left   |
|            | `throw`                           | Throw operator                                       |                 |
|            | `co_yield`                        | Yield-expression (C++20)                             |                 |
| 17         | `=`                               | Direct assignment                                    |                 |
|            | `+=`, `-=`, `*=`, `/=`, `%=`      | Compound assignment by sum, difference, product, quotient, remainder |                 |
|            | `<<=`, `>>=`, `&=`, `^=`    | Compound assignment by bitwise operations            |                 |
| 18         | `,`                               | Comma                                                | Left-to-right   |

### Notes:

- **Associativity**:
  - **Left-to-right**: Operators of the same precedence level are grouped from left to right.
  - **Right-to-left**: Operators of the same precedence level are grouped from right to left.

- **Special Cases**:
  - The postfix increment (`a++`) and decrement (`a--`) have higher precedence than their prefix versions (`++a`, `--a`).
  - The ternary conditional operator (`? :`) and the throw operator have right-to-left associativity, which is relatively unusual.
  - The comma operator (`,`) has the lowest precedence and groups left-to-right, allowing for sequential evaluations.