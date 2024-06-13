## Using `decltype` in C++

This example demonstrates how to use the `decltype` keyword in C++ to declare new variables with the same type as existing variables.

### Initial Variable Declarations

```cpp
int x = 42;
double y = 3.14;
char c = 'A';
```

Here, we initialize three variables of different types: `x` (int), `y` (double), and `c` (char).

### Using `decltype` to Declare New Variables

```cpp
// Using decltype to declare new variables with the same type as existing variables
decltype(x) a;     // 'a' has the same type as 'x', which is int
decltype(y) b = y; // 'b' has the same type as 'y', which is double
decltype(c) d;     // 'd' has the same type as 'c', which is char
```

The `decltype` keyword is used to declare new variables (`a`, `b`, and `d`) with the same type as existing variables (`x`, `y`, and `c`).

### Initializing New Variables

```cpp
// Initialize 'a' and 'd'
a = x * 2; // a = 42 * 2 = 84
d = 'B';   // d is assigned the character 'B'
```

Variables `a` and `d` are initialized with values based on calculations and assignments. `a` is assigned twice the value of `x`, and `d` is assigned the character 'B'.
