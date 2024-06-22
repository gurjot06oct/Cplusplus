## Modifiers in `std::string`

The `std::string` class in C++ provides several member functions to modify the content of a string. These functions allow you to append, insert, erase, replace, and assign content to a string, as well as manage individual characters. Below is a detailed explanation of each modifier function.

### 1. `operator+=`

- **Purpose**: Appends a string or character to the current string.
- **Syntax**:
  ```cpp
  std::string& operator+=(const std::string& str);
  std::string& operator+=(const char* s);
  std::string& operator+=(char c);
  ```
- **Usage**:
  ```cpp
  std::string str = "Geeks";
  str += "forGeeks"; // str becomes "GeeksforGeeks"
  str += '!'; // str becomes "GeeksforGeeks!"
  ```

### 2. `append`

- **Purpose**: Appends a string or character sequence to the current string.
- **Syntax**:
  ```cpp
  std::string& append(const std::string& str);
  std::string& append(const std::string& str, size_t subpos, size_t sublen);
  std::string& append(const char* s);
  std::string& append(const char* s, size_t n);
  std::string& append(size_t n, char c);
  template <class InputIterator>
  std::string& append(InputIterator first, InputIterator last);
  ```
- **Usage**:
  ```cpp
  std::string str = "Geeks";
  str.append("forGeeks"); // str becomes "GeeksforGeeks"
  str.append(3, '!'); // str becomes "GeeksforGeeks!!!"
  ```

### 3. `push_back`

- **Purpose**: Appends a single character to the end of the string.
- **Syntax**:
  ```cpp
  void push_back(char c);
  ```
- **Usage**:
  ```cpp
  std::string str = "Geeks";
  str.push_back('!'); // str becomes "Geeks!"
  ```

### 4. `assign`

- **Purpose**: Assigns new content to the string, replacing its current contents.
- **Syntax**:
  ```cpp
  std::string& assign(const std::string& str);
  std::string& assign(const std::string& str, size_t subpos, size_t sublen);
  std::string& assign(const char* s);
  std::string& assign(const char* s, size_t n);
  std::string& assign(size_t n, char c);
  template <class InputIterator>
  std::string& assign(InputIterator first, InputIterator last);
  ```
- **Usage**:
  ```cpp
  std::string str;
  str.assign("GeeksforGeeks"); // str becomes "GeeksforGeeks"
  str.assign(5, 'x'); // str becomes "xxxxx"
  ```

### 5. `insert`

- **Purpose**: Inserts characters into the string at a specified position.
- **Syntax**:
  ```cpp
  std::string& insert(size_t pos, const std::string& str);
  std::string& insert(size_t pos, const std::string& str, size_t subpos, size_t sublen);
  std::string& insert(size_t pos, const char* s);
  std::string& insert(size_t pos, const char* s, size_t n);
  std::string& insert(size_t pos, size_t n, char c);
  iterator insert(const_iterator p, char c);
  iterator insert(const_iterator p, size_t n, char c);
  template <class InputIterator>
  iterator insert(const_iterator p, InputIterator first, InputIterator last);
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksGeeks";
  str.insert(5, "for"); // str becomes "GeeksforGeeks"
  str.insert(5, 3, '!'); // str becomes "Geeks!!!forGeeks"
  ```

### 6. `erase`

- **Purpose**: Erases characters from the string.
- **Syntax**:
  ```cpp
  std::string& erase(size_t pos = 0, size_t len = npos);
  iterator erase(const_iterator p);
  iterator erase(const_iterator first, const_iterator last);
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  str.erase(5, 3); // str becomes "GeeksGeeks"
  str.erase(str.begin() + 5); // str becomes "GeeksGeeks"
  ```

### 7. `replace`

- **Purpose**: Replaces a portion of the string with new content.
- **Syntax**:
  ```cpp
  std::string& replace(size_t pos, size_t len, const std::string& str);
  std::string& replace(size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen);
  std::string& replace(size_t pos, size_t len, const char* s);
  std::string& replace(size_t pos, size_t len, const char* s, size_t n);
  std::string& replace(size_t pos, size_t len, size_t n, char c);
  iterator replace(const_iterator i1, const_iterator i2, const std::string& str);
  template <class InputIterator>
  iterator replace(const_iterator i1, const_iterator i2, InputIterator first, InputIterator last);
  ```
- **Usage**:
  ```cpp
  std::string str = "GeeksforGeeks";
  str.replace(5, 3, "123"); // str becomes "Geeks123Geeks"
  ```

### 8. `swap`

- **Purpose**: Swaps the content of the string with another string.
- **Syntax**:
  ```cpp
  void swap(std::string& str) noexcept;
  ```
- **Usage**:
  ```cpp
  std::string str1 = "Geeks";
  std::string str2 = "forGeeks";
  str1.swap(str2); // str1 becomes "forGeeks", str2 becomes "Geeks"
  ```

### 9. `pop_back`

- **Purpose**: Deletes the last character from the string.
- **Syntax**:
  ```cpp
  void pop_back();
  ```
- **Usage**:
  ```cpp
  std::string str = "Geeks!";
  str.pop_back(); // str becomes "Geeks"
  ```

### Example Usage of Modifier Functions

Here is an example demonstrating the use of various modifier functions in `std::string`:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "Geeks";

    // operator+=
    str += "forGeeks";
    std::cout << "After += : " << str << std::endl; // GeeksforGeeks

    // append
    str.append("!!!");
    std::cout << "After append : " << str << std::endl; // GeeksforGeeks!!!

    // push_back
    str.push_back('?');
    std::cout << "After push_back : " << str << std::endl; // GeeksforGeeks!!!?

    // assign
    str.assign(5, 'x');
    std::cout << "After assign : " << str << std::endl; // xxxxx

    // insert
    str.insert(2, "YYY");
    std::cout << "After insert : " << str << std::endl; // xxYYYxxx

    // erase
    str.erase(2, 3);
    std::cout << "After erase : " << str << std::endl; // xxxxx

    // replace
    str.replace(2, 3, "ABC");
    std::cout << "After replace : " << str << std::endl; // xxABC

    // swap
    std::string str2 = "12345";
    str.swap(str2);
    std::cout << "After swap, str: " << str << ", str2: " << str2 << std::endl; // str: 12345, str2: xxABC

    // pop_back
    str.pop_back();
    std::cout << "After pop_back : " << str << std::endl; // 1234

    return 0;
}
```

**Output:**

```
After += : GeeksforGeeks
After append : GeeksforGeeks!!!
After push_back : GeeksforGeeks!!!?
After assign : xxxxx
After insert : xxYYYxxx
After erase : xxxxx
After replace : xxABC
After swap, str: 12345, str2: xxABC
After pop_back : 1234
```

### Explanation

- **`operator+=`**: Efficiently appends strings or characters.
- **`append`**: Adds a string or character sequence to the current string.
- **`push_back`**: Adds a single character to the end of the string.
- **`assign`**: Replaces the string's content with new data.
- **`insert`**: Inserts characters at a specified position.
- **`erase`**: Removes characters from the string.
- **`replace`**: Replaces part of the string with new content.
- **`swap`**: Swaps

the contents of two strings.

- **`pop_back`**: Removes the last character from the string.

These modifier functions provide powerful capabilities for manipulating `std::string` objects in C++, enabling tasks such as appending, inserting, erasing, replacing, assigning, and swapping string content efficiently.
