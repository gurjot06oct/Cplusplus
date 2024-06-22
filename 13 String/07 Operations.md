## String Operations in `std::string`

The `std::string` class in C++ provides a variety of member functions for performing operations on strings. These functions allow you to manipulate, access, search, compare, and extract substrings from strings. Below is an explanation of each string operation function available in `std::string`.

### 1. `c_str`

- **Purpose**: Returns a pointer to a null-terminated character array (`C-string`) representing the contents of the string.
- **Syntax**:
  ```cpp
  const char* c_str() const noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  const char* cstr = str.c_str(); // cstr points to "GeeksforGeeks\0"
  ```

### 2. `data`

- **Purpose**: Returns a pointer to the beginning of the character string used internally by the `std::string` to store its own data.
- **Syntax**:
  ```cpp
  const char* data() const noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  const char* data = str.data(); // data points to "GeeksforGeeks"
  ```

### 3. `get_allocator`

- **Purpose**: Returns the allocator object used by the `std::string` to allocate storage.
- **Syntax**:
  ```cpp
  allocator_type get_allocator() const noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  auto alloc = str.get_allocator(); // allocates storage for the string
  ```

### 4. `copy`

- **Purpose**: Copies a substring of the string into a character array.
- **Syntax**:
  ```cpp
  size_t copy(char* dest, size_t count, size_t pos = 0) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  char buffer[20];
  size_t len = str.copy(buffer, 5); // Copies first 5 characters
  buffer[len] = '\0'; // Null-terminate the copied string
  ```

### 5. `find`

- **Purpose**: Finds the first occurrence of a substring within the string.
- **Syntax**:
  ```cpp
  size_t find(const std::string& str, size_t pos = 0) const noexcept;
  size_t find(const char* s, size_t pos = 0) const;
  size_t find(const char* s, size_t pos, size_t n) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t found = str.find("for"); // found is 5
  ```

### 6. `rfind`

- **Purpose**: Finds the last occurrence of a substring within the string.
- **Syntax**:
  ```cpp
  size_t rfind(const std::string& str, size_t pos = npos) const noexcept;
  size_t rfind(const char* s, size_t pos = npos) const;
  size_t rfind(const char* s, size_t pos, size_t n) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t found = str.rfind("Geeks"); // found is 0
  ```

### 7. `find_first_of`

- **Purpose**: Finds the first occurrence of any character in the given set within the string.
- **Syntax**:
  ```cpp
  size_t find_first_of(const std::string& str, size_t pos = 0) const noexcept;
  size_t find_first_of(const char* s, size_t pos = 0) const;
  size_t find_first_of(const char* s, size_t pos, size_t n) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t found = str.find_first_of("kG"); // found is 1 (first occurrence of 'k' or 'G')
  ```

### 8. `find_last_of`

- **Purpose**: Finds the last occurrence of any character in the given set within the string, starting from the end.
- **Syntax**:
  ```cpp
  size_t find_last_of(const std::string& str, size_t pos = npos) const noexcept;
  size_t find_last_of(const char* s, size_t pos = npos) const;
  size_t find_last_of(const char* s, size_t pos, size_t n) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t found = str.find_last_of("kG"); // found is 10 (last occurrence of 'k' or 'G')
  ```

### 9. `find_first_not_of`

- **Purpose**: Finds the first character in the string that is not in the given set.
- **Syntax**:
  ```cpp
  size_t find_first_not_of(const std::string& str, size_t pos = 0) const noexcept;
  size_t find_first_not_of(const char* s, size_t pos = 0) const;
  size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t found = str.find_first_not_of("Gekosr"); // found is 7 (first character not 'G', 'e', 'k', 'o', 's', or 'r')
  ```

### 10. `find_last_not_of`

- **Purpose**: Finds the last character in the string that is not in the given set, starting from the end.
- **Syntax**:
  ```cpp
  size_t find_last_not_of(const std::string& str, size_t pos = npos) const noexcept;
  size_t find_last_not_of(const char* s, size_t pos = npos) const;
  size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  size_t found = str.find_last_not_of("Gekosr"); // found is 9 (last character not 'G', 'e', 'k', 'o', 's', or 'r')
  ```

### 11. `substr`

- **Purpose**: Returns a substring of the current string.
- **Syntax**:
  ```cpp
  std::string substr(size_t pos = 0, size_t len = npos) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  std::string substr = str.substr(5, 3); // substr is "for"
  ```

### 12. `compare`

- **Purpose**: Compares two strings lexicographically.
- **Syntax**:
  ```cpp
  int compare(const std::string& str) const noexcept;
  int compare(size_t pos, size_t len, const std::string& str) const;
  int compare(size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen) const;
  int compare(const char* s) const;
  int compare(size_t pos, size_t len, const char* s) const;
  int compare(size_t pos, size_t len, const char* s, size_t n) const;
  ```
- **Usage**:
  ```cpp
  std::string str = "Geeks";
  int result = str.compare("GeeksforGeeks"); // result is negative
  ```

### Example Usage of String Operations

Here is an example demonstrating the use of various string operation functions in `std::string`:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "GeeksforGeeks";

    // c_str
    const char* cstr = str.c_str();
    std::cout << "C-string equivalent: " << cstr << std::endl;

    // data
    const char* data = str.data();
    std::cout << "String data: " << data << std::endl;

    // copy
    char buffer[20];
    size_t len = str.copy(buffer, 5);
    buffer[len] = '\0';
    std::cout << "Copied string: " << buffer << std::endl;

    // find
    size_t found = str.find("for");
    std::cout << "Substring found at index: " << found << std::endl;

    // rfind
    size_t rfound = str.rfind("Geeks");
    std::cout << "Last substring found at index: " << rfound << std::endl;

    // find_first_of
    size_t found_first_of = str.find_first_of("kG");
    std::cout << "First of 'k' or 'G' found at index: " << found_first_of << std::endl;

    // find_last_of
    size_t found_last_of = str.find_last_of("kG");
    std::cout << "Last of 'k' or 'G' found at index: " << found_last_of << std::endl;

    //

 find_first_not_of
    size_t found_first_not_of = str.find_first_not_of("Gekosr");
    std::cout << "First character not in 'Gekosr' found at index: " << found_first_not_of << std::endl;

    // find_last_not_of
    size_t found_last_not_of = str.find_last_not_of("Gekosr");
    std::cout << "Last character not in 'Gekosr' found at index: " << found_last_not_of << std::endl;

    // substr
    std::string substr = str.substr(5, 3);
    std::cout << "Substring: " << substr << std::endl;

    // compare
    int result = str.compare("GeeksforGeeks");
    std::cout << "Comparison result: " << result << std::endl;

    return 0;
}
```

This example demonstrates various operations such as finding substrings, comparing strings, accessing substrings, and converting to C-string equivalents using `std::string` member functions.
