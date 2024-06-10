### Difference Between C Structures and C++ Structures:

1. **Access Specifiers**: In C, all members of a structure are public by default, while in C++, members are private by default.
2. **Functions Inside Structures**: C++ allows functions to be defined inside structures (known as methods or member functions), whereas C does not.
3. **Constructors and Destructors**: C++ structures can have constructors and destructors, which C structures cannot.
4. **Inheritance and Polymorphism**: C++ structures can participate in inheritance hierarchies and support polymorphism, which is not possible in C.
5. **Encapsulation**: C++ structures support encapsulation through access specifiers like private, protected, and public, allowing better control over data access and manipulation.

**Example (C++ Structure with Constructor):**

```cpp
struct Rectangle {
    int width, height;
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() { return width * height; }
};
```

**Example (C Structure):**

```c
struct Rectangle {
    int width, height;
};
```
