## Operator overloading

Operator overloading in C++ allows you to define the behavior of operators (like `+`, `-`, `*`, `/`, `==`, `!=`, etc.) for user-defined types (classes or structs). However, there are some constraints and limitations to consider when overloading operators. Here's a complete list of various ways to overload operators and situations where operator overloading cannot be performed:

### Operators that Can be Overloaded

1. **Unary Operators**:

   - `+` (unary plus)
   - `-` (unary minus)
   - `++` (prefix and postfix increment)
   - `--` (prefix and postfix decrement)
   - `*` (dereference)
   - `&` (address of)
   - `!` (logical NOT)
   - `~` (bitwise NOT)

2. **Binary Arithmetic Operators**:

   - `+` (addition)
   - `-` (subtraction)
   - `*` (multiplication)
   - `/` (division)
   - `%` (modulus)

3. **Compound Assignment Operators**:

   - `+=`, `-=`, `*=`, `/=`, `%=`
   - `&=`, `|=`, `^=`
   - `<<=`, `>>=`

4. **Comparison Operators**:

   - `==` (equality)
   - `!=` (inequality)
   - `<` (less than)
   - `<=` (less than or equal to)
   - `>` (greater than)
   - `>=` (greater than or equal to)

5. **Logical Operators**:

   - `&&` (logical AND)
   - `||` (logical OR)

6. **Bitwise Operators**:

   - `&` (bitwise AND)
   - `|` (bitwise OR)
   - `^` (bitwise XOR)
   - `<<` (left shift)
   - `>>` (right shift)

7. **Function Call Operator** (`()`):

   - `operator()`

8. **Subscript Operator** (`[]`):

   - `operator[]`

9. **Pointer-to-member Operators**:
   - `->*` (pointer-to-member dereference)
   - `.*` (pointer-to-member selection)

### Constraints and Limitations

1. **New Operators**: You cannot define new operators or change the precedence and associativity of operators.

2. **Operators with Built-in Types**: Operators that involve at least one operand of a built-in type (like `int`, `double`, etc.) cannot be overloaded for built-in types themselves.

3. **Short-circuit Operators (`&&` and `||`)**: Overloading these operators does not guarantee short-circuit behavior because it is a language-defined behavior for built-in types.

4. **Conditional Operator (`?:`)**: This operator cannot be overloaded.

5. **Comma Operator (`operator,`)**: It cannot be overloaded.

6. **sizeof Operator (`sizeof`)**: It cannot be overloaded because it is evaluated at compile-time.

7. **Scope Resolution Operator (`::`)**: It cannot be overloaded.
