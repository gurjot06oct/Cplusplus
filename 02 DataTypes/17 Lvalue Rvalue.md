In C++, **lvalues** and **rvalues** are fundamental concepts related to expressions and variables.

### lvalue (Left Value)

- An **lvalue** (locator value) represents an object that occupies some identifiable location in memory (i.e., it has an address).
- It refers to a value that can appear on the left-hand side or the right-hand side of an assignment.
- lvalues can be modified unless they are `const`.

Examples of lvalues:

```cpp
int x = 5;    // 'x' is an lvalue
x = 10;       // 'x' can be on the left side of the assignment
int* p = &x;  // 'x' has an address, so we can take its address using '&'
```

### rvalue (Right Value)

- An **rvalue** (read value) represents a temporary object or a value that does not have a persistent memory address.
- It refers to values that can appear on the right-hand side of an assignment but not on the left-hand side.
- rvalues are typically temporary and cannot be assigned to, except by moving.

Examples of rvalues:

```cpp
int y = 5 + 3;  // '5 + 3' is an rvalue (temporary result)
int z = x + y;  // 'x + y' is an rvalue
int* p = &(x + y);  // Error: rvalue does not have an address
```

### rvalue References (C++11 and later)

- With C++11, a new type of reference was introduced: **rvalue references**, denoted by `T&&`.
- rvalue references allow you to bind to temporary objects (rvalues) and modify them. This is particularly useful in move semantics and perfect forwarding.

Example of rvalue reference:

```cpp
int&& rref = 10;  // '10' is an rvalue, and 'rref' is an rvalue reference
rref = 20;        // Valid, we can modify the temporary object
```

### Summary

- **lvalue**: Refers to an object that has a name and persists beyond a single expression. It has an identifiable location in memory.
- **rvalue**: Refers to a temporary object or value that does not have a persistent location in memory. It usually exists only during the expression in which it is used.
