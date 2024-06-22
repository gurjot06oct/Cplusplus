## Array of Strings in C++ – 5 Different Ways to Create

In C++, a string is typically represented as an array of characters that terminates with the NULL character '\0'. An array of strings, therefore, is a 2-dimensional array where each row contains a string.

### 1. Using Pointers

Pointers in C++ store the address of variables. An array of string literals can be created using an array of pointers, where each pointer points to a specific string.

**Example:**

```cpp
// C++ program demonstrating array of strings using pointers
#include <iostream>

int main() {
    const char* colour[] = { "Blue", "Red", "Orange", "Yellow" };

    // Printing strings stored in the array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    return 0;
}
```

### 2. Using a 2-D Array

A 2-dimensional array stores data in a tabular form. This method allocates memory in a single block and is useful when the length of all strings is known.

**Example:**

```cpp
// C++ program demonstrating array of strings using a 2D character array
#include <iostream>

int main() {
    char colour[4][10] = { "Blue", "Red", "Orange", "Yellow" };

    // Printing strings stored in the array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    return 0;
}
```

### 3. Using the String Class

The `std::string` class in C++ provides a dynamic and mutable array of strings. It allows strings to be changed in size and content.

**Example:**

```cpp
// C++ program demonstrating array of strings using std::string
#include <iostream>
#include <string>

int main() {
    std::string colour[] = { "Blue", "Red", "Orange", "Yellow" };

    // Printing strings stored in the array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    return 0;
}
```

### 4. Using the Vector Class

The `std::vector` class provides a dynamic array that can grow or shrink in size. It is part of the C++ Standard Library (STL) and allows flexibility in managing arrays of strings.

**Example:**

```cpp
// C++ program demonstrating array of strings using std::vector
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> colour = { "Blue", "Red", "Orange" };

    // Adding another string to the vector
    colour.push_back("Yellow");

    // Printing strings stored in the vector
    for (int i = 0; i < colour.size(); i++)
        std::cout << colour[i] << "\n";

    return 0;
}
```

### 5. Using the Array Class

The `std::array` class provides a fixed-size array that is part of the STL. It offers similar functionality to a C-style array but with additional benefits of the STL, such as iterators and size management.

**Example:**

```cpp
// C++ program demonstrating array of strings using std::array
#include <iostream>
#include <array>
#include <string>

int main() {
    std::array<std::string, 4> colour = { "Blue", "Red", "Orange", "Yellow" };

    // Printing strings stored in the array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    return 0;
}
```
