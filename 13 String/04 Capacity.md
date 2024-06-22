## Capacity Functions in `std::string`

The `std::string` class in C++ provides several member functions to manage the capacity and size of the string. These functions allow you to get the current size, resize the string, check the maximum possible size, and manage the allocated storage efficiently. Below is a detailed explanation of each capacity-related function.

### 1. `size` / `length`

- **Purpose**: Returns the length of the string, i.e., the number of characters.
- **Syntax**:
  ```cpp
  size_t size() const noexcept;
  size_t length() const noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t len = str.size(); // or str.length()
  ```

### 2. `max_size`

- **Purpose**: Returns the maximum number of characters that the string can hold.
- **Syntax**:
  ```cpp
  size_t max_size() const noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t max_len = str.max_size();
  ```

### 3. `resize`

- **Purpose**: Resizes the string to contain the specified number of characters.
- **Syntax**:
  ```cpp
  void resize(size_t n);
  void resize(size_t n, char c);
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  str.resize(5); // str becomes "Geeks"
  str.resize(10, 'x'); // str becomes "Geeksxxxxx"
  ```

### 4. `capacity`

- **Purpose**: Returns the size of the storage space currently allocated for the string, expressed in terms of characters.
- **Syntax**:
  ```cpp
  size_t capacity() const noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t cap = str.capacity();
  ```

### 5. `reserve`

- **Purpose**: Requests that the string capacity be at least enough to contain `n` characters.
- **Syntax**:
  ```cpp
  void reserve(size_t n = 0);
  ```
- **Usage**:
  ```cpp
  std::string str;
  str.reserve(100); // Reserves space for at least 100 characters
  ```

### 6. `clear`

- **Purpose**: Clears the contents of the string, making it an empty string.
- **Syntax**:
  ```cpp
  void clear() noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  str.clear(); // str becomes ""
  ```

### 7. `empty`

- **Purpose**: Checks if the string is empty.
- **Syntax**:
  ```cpp
  bool empty() const noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str;
  bool is_empty = str.empty(); // true
  ```

### 8. `shrink_to_fit`

- **Purpose**: Requests the string to reduce its capacity to fit its size.
- **Syntax**:
  ```cpp
  void shrink_to_fit();
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  str.resize(5); // str becomes "Geeks"
  str.shrink_to_fit(); // Reduces capacity to fit the new size
  ```

### Example Usage of Capacity Functions

Here is an example demonstrating the use of various capacity functions in `std::string`:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "GeeksforGeeks";

    // size / length
    std::cout << "Size: " << str.size() << std::endl; // 13
    std::cout << "Length: " << str.length() << std::endl; // 13

    // max_size
    std::cout << "Max Size: " << str.max_size() << std::endl;

    // resize
    str.resize(5);
    std::cout << "After resize: " << str << std::endl; // Geeks

    // capacity
    std::cout << "Capacity: " << str.capacity() << std::endl;

    // reserve
    str.reserve(100);
    std::cout << "Capacity after reserve: " << str.capacity() << std::endl;

    // clear
    str.clear();
    std::cout << "After clear: " << str << std::endl; // (empty string)

    // empty
    std::cout << "Is empty: " << std::boolalpha << str.empty() << std::endl; // true

    // shrink_to_fit
    str = "GeeksforGeeks";
    str.resize(5);
    str.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit: " << str.capacity() << std::endl;

    return 0;
}
```

**Output:**

```
Size: 13
Length: 13
Max Size: 9223372036854775807
After resize: Geeks
Capacity: 13
Capacity after reserve: 100
After clear:
Is empty: true
Capacity after shrink_to_fit: 5
```

### Explanation

- **Size / Length**: Returns the number of characters in the string.
- **Max Size**: Shows the theoretical limit for the number of characters a string can hold.
- **Resize**: Changes the size of the string, possibly adding characters or truncating the string.
- **Capacity**: Indicates the amount of storage currently allocated to the string.
- **Reserve**: Allocates memory for at least the specified number of characters.
- **Clear**: Empties the string.
- **Empty**: Checks if the string is currently empty.
- **Shrink to Fit**: Adjusts the capacity to match the current size, potentially freeing unused memory.

These capacity functions provide fine-grained control over memory management and size adjustments of `std::string` objects in C++.
