## Element Access Functions in `std::string`

The `std::string` class in C++ provides several member functions to access individual characters within a string. These functions allow you to retrieve characters at specific positions, as well as directly access the first and last characters. Here is an overview of each element access function.

### 1. `operator[]`

- **Purpose**: Provides access to the character at a specified position in the string. This operator does not perform bounds checking.
- **Syntax**:
  ```cpp
  char& operator[](size_t pos);
  const char& operator[](size_t pos) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  char c = str[0]; // c is 'G'
  str[0] = 'g'; // str becomes "geeksforGeeks"
  ```

### 2. `at`

- **Purpose**: Returns a reference to the character at the specified position in the string. This function performs bounds checking and throws an `out_of_range` exception if the position is invalid.
- **Syntax**:
  ```cpp
  char& at(size_t pos);
  const char& at(size_t pos) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  try {
      char c = str.at(0); // c is 'G'
      str.at(0) = 'g'; // str becomes "geeksforGeeks"
  } catch (const std::out_of_range& e) {
      std::cout << "Index out of range" << std::endl;
  }
  ```

### 3. `back`

- **Purpose**: Returns a reference to the last character in the string.
- **Syntax**:
  ```cpp
  char& back();
  const char& back() const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  char c = str.back(); // c is 's'
  str.back() = 'S'; // str becomes "GeeksforGeekS"
  ```

### 4. `front`

- **Purpose**: Returns a reference to the first character in the string.
- **Syntax**:
  ```cpp
  char& front();
  const char& front() const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  char c = str.front(); // c is 'G'
  str.front() = 'g'; // str becomes "geeksforGeeks"
  ```

### Example Usage of Element Access Functions

Here is an example demonstrating the use of various element access functions in `std::string`:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "GeeksforGeeks";

    // operator[]
    std::cout << "First character using operator[]: " << str[0] << std::endl;
    str[0] = 'g';
    std::cout << "After modification using operator[]: " << str << std::endl;

    // at
    try {
        std::cout << "First character using at: " << str.at(0) << std::endl;
        str.at(0) = 'G';
        std::cout << "After modification using at: " << str << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Index out of range" << std::endl;
    }

    // back
    std::cout << "Last character using back: " << str.back() << std::endl;
    str.back() = 'S';
    std::cout << "After modification using back: " << str << std::endl;

    // front
    std::cout << "First character using front: " << str.front() << std::endl;
    str.front() = 'g';
    std::cout << "After modification using front: " << str << std::endl;

    return 0;
}
```

**Output:**

```
First character using operator[]: G
After modification using operator[]: geeksforGeeks
First character using at: g
After modification using at: GeeksforGeeks
Last character using back: s
After modification using back: GeeksforGeekS
First character using front: G
After modification using front: geeksforGeekS
```

### Explanation

- **`operator[]`**: Directly accesses characters without bounds checking. Modifications are straightforward but unsafe if the index is out of range.
- **`at`**: Accesses characters with bounds checking, making it safer to use for invalid indices, but it can throw exceptions.
- **`back`**: Provides direct access to the last character of the string, useful for operations on the string's end.
- **`front`**: Provides direct access to the first character of the string, useful for operations on the string's beginning.

These element access functions allow for flexible and efficient manipulation of individual characters within a `std::string` in C++.
