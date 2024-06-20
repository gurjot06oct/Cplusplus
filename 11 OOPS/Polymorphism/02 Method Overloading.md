## Method Overloading in Object-Oriented Programming

Method overloading in object-oriented programming (OOP) is analogous to function overloading in traditional procedural programming languages. The key difference lies in how it relates to classes and objects.

### Similarity to Function Overloading

Just like function overloading in non-OOP languages:

- **Multiple Definitions**: Method overloading allows a class to have multiple methods with the same name but different parameter lists.
- **Same Name**: Methods in a class can share the same name, but each method must have a unique parameter list (number, type, or order of parameters).
- **Compile-Time Resolution**: The compiler determines which method to call based on the number and types of arguments provided during the function call.

In C++, you can overload functions based on whether the parameter is a constant or not. This feature allows you to provide different implementations depending on whether the input argument should be modifiable or not. Here’s how you can use const and non-const parameters for overloading:

### Overloading Based on Const Methods

In C++, member functions can be overloaded based on the const-qualification of the `this` pointer. This means you can have different implementations depending on whether the member function is called on a const or non-const object.

```cpp
class Example {
public:
    void show() {
        cout << "Non-const show function called" << endl;
    }
    void show() const {
        cout << "Const show function called" << endl;
    }
};
```

### Explanation

- **Non-const member function**: `void show()`
  - This function can be called on non-const objects and can modify the object.
- **Const member function**: `void show() const`
  - This function can be called on const objects and cannot modify the object.

### `mutable` Keyword

The `mutable` keyword in C++ is used to modify a member of a `const` class object. By marking a data member as `mutable`, you're essentially telling the compiler that this particular member can be modified even if the object itself is `const`.

### Use Cases for `mutable` in `const` Class Objects

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    mutable int count; // Mutable member variable

public:
    Counter(int initialCount) : count(initialCount) {}

    // Method to increment count
    void increment() const {
        count++; // Allowed because 'count' is mutable
    }

    // Method to get current count
    int getCount() const {
        return count;
    }
};

int main() {
    const Counter c(5); // Declare a const Counter object

    cout << "Initial Count: " << c.getCount() << endl; // Output: Initial Count: 5
    // We can still modify 'count' inside 'c' using the mutable keyword
    c.increment();

    cout << "Count after increment: " << c.getCount() << endl; // Output: Count after increment: 6

    return 0;
}
```

### Explanation:

- **Class `Counter`**: Represents a simple counter with a `count` member variable.
- **`mutable int count;`**: This member variable is marked as `mutable`, which means it can be modified even within `const` member functions.
- **Method `increment()`**: Increments the `count` variable. Despite being called within a `const` member function (`increment()`), it can modify `count` because `count` is `mutable`.
- **Usage in `main()`**:
  - We create a `const Counter` object `c` with an initial count of 5.
  - `count` is `mutable` , allowing us to call `increment()` directly.
  - After incrementing, we retrieve and print the updated count using `c.getCount()`.

### Purpose and Uses

- **Purpose of `mutable`**: Allows modifying specific member variables of a `const` object without violating the `const` correctness principle.
- **Use Case**: Useful for maintaining internal state or caching within `const` objects without exposing this behavior externally.
