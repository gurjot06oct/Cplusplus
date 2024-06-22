### Member Constants

1. **`npos`**
   - **Purpose**: Represents the maximum value for `size_t`, used as a special value by various member functions to indicate a position past the end of the string.
   - **Usage**: Typically returned by member functions when the requested substring or character is not found within the string.
   - **Example**:
     ```cpp
     std::string str = "Hello, World!";
     size_t pos = str.find("Geeks"); // pos will be std::string::npos (not found)
     ```

### Non-member Function Overloads

1. **`operator+`**

   - **Purpose**: Concatenates two strings.
   - **Syntax**:
     ```cpp
     std::string operator+(const std::string& lhs, const std::string& rhs);
     ```
   - **Usage**:
     ```cpp
     std::string str1 = "Hello";
     std::string str2 = "World";
     std::string result = str1 + " " + str2; // result is "Hello World"
     ```

2. **Relational Operators**

   - **Purpose**: Compares two strings lexicographically.
   - **Syntax**: Overloads `operator==`, `operator!=`, `operator<`, `operator<=`, `operator>`, and `operator>=`.
   - **Usage**:
     ```cpp
     std::string str1 = "apple";
     std::string str2 = "banana";
     if (str1 < str2) {
         std::cout << str1 << " is less than " << str2 << std::endl;
     }
     ```

3. **`swap`**

   - **Purpose**: Exchanges the values of two strings.
   - **Syntax**:
     ```cpp
     void swap(std::string& lhs, std::string& rhs) noexcept;
     ```
   - **Usage**:
     ```cpp
     std::string str1 = "Hello";
     std::string str2 = "World";
     std::swap(str1, str2);
     ```

4. **`operator>>`**

   - **Purpose**: Extracts a string from an input stream.
   - **Syntax**:
     ```cpp
     std::istream& operator>>(std::istream& is, std::string& str);
     ```
   - **Usage**:
     ```cpp
     std::string str;
     std::cin >> str; // Reads input into str
     ```

5. **`operator<<`**

   - **Purpose**: Inserts a string into an output stream.
   - **Syntax**:
     ```cpp
     std::ostream& operator<<(std::ostream& os, const std::string& str);
     ```
   - **Usage**:
     ```cpp
     std::string str = "Hello, World!";
     std::cout << str; // Outputs "Hello, World!" to the console
     ```

6. **`getline`**
   - **Purpose**: Reads a line from an input stream into a string.
   - **Syntax**:
     ```cpp
     std::istream& getline(std::istream& is, std::string& str, char delim = '\n');
     ```
   - **Usage**:
     ```cpp
     std::string str;
     std::getline(std::cin, str); // Reads a line of input into str
     ```

These member constants and non-member function overloads provide additional functionality and flexibility when working with `std::string` objects in C++, allowing operations such as concatenation, comparison, swapping, stream insertion/extraction, and input handling.
