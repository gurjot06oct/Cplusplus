## Integer in C++

#### Signed Integer Types

```cpp
#include <iostream>
#include <limits>
#include <climits>

int main() {
    // Signed Integer Types
    short int si = 32767;                // 16 bits, Range: -32768 to 32767
    int i = 2147483649;                  // 32 bits, Range: -2147483648 to 2147483647
    long li = -2147483647;               // 32 bits or 64 bits, Range: -2147483648 to 2147483647 (32 bits) or wider range for 64 bits
    long long lli = 9223372036854775807; // 64 bits, Range: -9223372036854775808 to 9223372036854775807

    std::cout << "short int (32767): " << si << std::endl;
    std::cout << "int (2147483649): " << i << std::endl;
    std::cout << "long int (-2147483647): " << li << std::endl;
    std::cout << "long long int (9223372036854775807): " << lli << std::endl;

    return 0;
}
```

##### Explanation:

- **Signed Integer Types:**
  - `short int si = 32767;` initializes `si` as a 16-bit signed integer with the maximum value.
  - `int i = 2147483649;` initializes `i` as a 32-bit signed integer, which exceeds its maximum value, leading to implementation-defined behavior due to overflow.
  - `long li = -2147483647;` initializes `li` as a 32-bit or 64-bit signed integer with a negative value.
  - `long long lli = 9223372036854775807;` initializes `lli` as a 64-bit signed integer with the maximum value.

#### Unsigned Integer Types

```cpp
#include <iostream>
#include <limits>
#include <climits>

int main() {
    // Unsigned Integer Types
    unsigned short int usi = -1;      // 16 bits, Range: 0 to 65535
    unsigned int ui = -1;             // 32 bits, Range: 0 to 4294967295
    unsigned long int uli = -1;       // 32 bits or 64 bits, Range: 0 to 4294967295 (32 bits) or wider range for 64 bits
    unsigned long long int ulli = -1; // 64 bits, Range: 0 to 18446744073709551615

    std::cout << "unsigned short int (-1): " << usi << std::endl;
    std::cout << "unsigned int (-1): " << ui << std::endl;
    std::cout << "unsigned long int (-1): " << uli << std::endl;
    std::cout << "unsigned long long int (-1): " << ulli << std::endl;

    return 0;
}
```

##### Explanation:

- **Unsigned Integer Types:**
  - `unsigned short int usi = -1;` initializes `usi` as a 16-bit unsigned integer with the maximum value.
  - `unsigned int ui = -1;` initializes `ui` as a 32-bit unsigned integer with the maximum value.
  - `unsigned long int uli = -1;` initializes `uli` as a 32-bit or 64-bit unsigned integer with the maximum value.
  - `unsigned long long int ulli = -1;` initializes `ulli` as a 64-bit unsigned integer with the maximum value.

#### Macros and Limits

```cpp
#include <iostream>
#include <limits>
#include <climits>

int main() {
    // Macros and Limits for Signed Types
    std::cout << "Minimum value of signed short: " << std::numeric_limits<short>::min() << std::endl;
    std::cout << "Maximum value of signed short: " << std::numeric_limits<short>::max() << std::endl;

    std::cout << "Minimum value of signed int: " << INT_MIN << std::endl;
    std::cout << "Maximum value of signed int: " << INT_MAX << std::endl;

    std::cout << "Minimum value of signed long: " << LONG_MIN << std::endl;
    std::cout << "Maximum value of signed long: " << LONG_MAX << std::endl;

    std::cout << "Minimum value of signed long long: " << LLONG_MIN << std::endl;
    std::cout << "Maximum value of signed long long: " << LLONG_MAX << std::endl;

    // Macros for Unsigned Types
    std::cout << "Maximum value of unsigned short: " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "Maximum value of unsigned int: " << UINT_MAX << std::endl;
    std::cout << "Maximum value of unsigned long: " << ULONG_MAX << std::endl;
    std::cout << "Maximum value of unsigned long long: " << ULLONG_MAX << std::endl;

    return 0;
}
```

##### Explanation:

- **Macros and Limits:**
  - Demonstrates the usage of macros (`INT_MIN`, `INT_MAX`, etc.) and `std::numeric_limits` to retrieve the minimum and maximum values for various signed and unsigned integer types.
  - Provides insights into the specific ranges supported by each integer type in C++.

### Variable Declarations with Modifiers

In C++, when declaring variables, you can use modifiers like `short`, `long`, or `long long` to specify the size and range of integers without explicitly stating the base type (`int`). Here's how each declaration works:

1. **Short Modifiers:**

   ```cpp
   short var_Short;
   unsigned short var_UnsignedShort;
   ```

   - `short var_Short;`: Declares a variable `var_Short` of type `short int`. The `short` keyword indicates that `var_Short` will be a signed integer with a smaller range and size compared to `int`.
   - `unsigned short var_UnsignedShort;`: Declares a variable `var_UnsignedShort` of type `unsigned short int`. The `unsigned short` modifier indicates that `var_UnsignedShort` will be an unsigned integer, meaning it can only store non-negative values but has a larger positive range compared to `short`.

2. **Long Modifiers:**

   ```cpp
   long var_Long;
   unsigned long var_UnsignedLong;
   ```

   - `long var_Long;`: Declares a variable `var_Long` of type `long int`. The `long` modifier indicates that `var_Long` will be a signed integer with a larger range and size compared to `int`. On most modern systems, `long` is typically 32 bits, but it can also be 64 bits depending on the platform.
   - `unsigned long var_UnsignedLong;`: Declares a variable `var_UnsignedLong` of type `unsigned long int`. The `unsigned long` modifier indicates that `var_UnsignedLong` will be an unsigned integer, allowing it to store non-negative values over a larger positive range compared to `long`.

3. **Long Long Modifiers:**
   ```cpp
   long long var_LongLong;
   unsigned long long var_UnsignedLongLong;
   ```
   - `long long var_LongLong;`: Declares a variable `var_LongLong` of type `long long int`. The `long long` modifier indicates that `var_LongLong` will be a signed integer with an even larger range and size compared to `long`. It is specifically designed to handle very large integer values.
   - `unsigned long long var_UnsignedLongLong;`: Declares a variable `var_UnsignedLongLong` of type `unsigned long long int`. The `unsigned long long` modifier indicates that `var_UnsignedLongLong` will be an unsigned integer, offering the largest positive range among all integer types in C++.

### Key Points:

- **Type Modifiers**: Using `short`, `long`, or `long long` modifies the base integer type (`int`) to specify different sizes and ranges.
- **Signed vs. Unsigned**: Adding `unsigned` before the type modifier changes the variable to an unsigned integer, which cannot store negative values but extends the positive range.
- **Platform Dependency**: The exact size and range of `long` and `long long` types may vary depending on the compiler and platform, but they provide flexibility in handling integer values of varying magnitudes.

### Wrap-around Behavior in Signed Data Types

In C++, signed integer data types exhibit a wrap-around or circular behavior when their values exceed their defined range. This behavior stems from the two's complement representation used in most modern computer systems, where values are represented in binary form.

#### How Wrap-around Works

Signed integers, such as `int`, have a fixed range defined by their number of bits. For a 32-bit `int`, the range is typically from `-2147483648` to `2147483647`.

```cpp
int maxValue = 2147483647;  // Maximum value of int
int minValue = -2147483648; // Minimum value of int

// Incrementing maxValue by 1
maxValue++;
std::cout << "After incrementing maxValue: " << maxValue << std::endl;

// Decrementing minValue by 1
minValue--;
std::cout << "After decrementing minValue: " << minValue << std::endl;
```

1. **Incrementing `maxValue`**:

   - `maxValue` starts with `2147483647`, the maximum value representable by a 32-bit signed integer (`int`).
   - When `maxValue` is incremented by 1 (`maxValue++`), it exceeds the maximum value (`2147483647`). According to wrap-around behavior, the value wraps around to `-2147483648`, which is the minimum value representable by a 32-bit signed integer.

2. **Decrementing `minValue`**:
   - `minValue` starts with `-2147483648`, the minimum value representable by a 32-bit signed integer (`int`).
   - When `minValue` is decremented by 1 (`minValue--`), it goes below the minimum value (`-2147483648`). Following wrap-around rules, the value wraps around to `2147483647`, which is the maximum value representable by a 32-bit signed integer.

This wrap-around behavior is essential to understand when working with signed integers in C++, as it affects arithmetic operations and overflow conditions, especially in scenarios involving cyclic data structures or numerical simulations where values may oscillate within defined bounds.
