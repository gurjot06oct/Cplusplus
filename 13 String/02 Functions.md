# Functions for String Conversion and Manipulation in C++

C++ provides a variety of functions to convert between strings and numerical values, as well as functions to access elements in a string. Below is an overview of these functions.

## Convert from Strings

These functions convert strings to various numerical types. They are defined in the `<string>` header file.

### 1. `stoi`

Converts a string to an integer.

**Syntax:**

```cpp
int stoi(const std::string& str, size_t* idx = 0, int base = 10);
```

### 2. `stol`

Converts a string to a `long int`.

**Syntax:**

```cpp
long stol(const std::string& str, size_t* idx = 0, int base = 10);
```

### 3. `stoul`

Converts a string to an `unsigned long`.

**Syntax:**

```cpp
unsigned long stoul(const std::string& str, size_t* idx = 0, int base = 10);
```

### 4. `stoll`

Converts a string to a `long long`.

**Syntax:**

```cpp
long long stoll(const std::string& str, size_t* idx = 0, int base = 10);
```

### 5. `stoull`

Converts a string to an `unsigned long long`.

**Syntax:**

```cpp
unsigned long long stoull(const std::string& str, size_t* idx = 0, int base = 10);
```

### 6. `stof`

Converts a string to a `float`.

**Syntax:**

```cpp
float stof(const std::string& str, size_t* idx = 0);
```

### 7. `stod`

Converts a string to a `double`.

**Syntax:**

```cpp
double stod(const std::string& str, size_t* idx = 0);
```

### 8. `stold`

Converts a string to a `long double`.

**Syntax:**

```cpp
long double stold(const std::string& str, size_t* idx = 0);
```

## Convert to Strings

These functions convert numerical values to strings. They are also defined in the `<string>` header file.

### 1. `to_string`

Converts a numerical value to a `std::string`.

**Syntax:**

```cpp
std::string to_string(int val);
std::string to_string(long val);
std::string to_string(long long val);
std::string to_string(unsigned val);
std::string to_string(unsigned long val);
std::string to_string(unsigned long long val);
std::string to_string(float val);
std::string to_string(double val);
std::string to_string(long double val);
```

### 2. `to_wstring`

Converts a numerical value to a `std::wstring`.

**Syntax:**

```cpp
std::wstring to_wstring(int val);
std::wstring to_wstring(long val);
std::wstring to_wstring(long long val);
std::wstring to_wstring(unsigned val);
std::wstring to_wstring(unsigned long val);
std::wstring to_wstring(unsigned long long val);
std::wstring to_wstring(float val);
std::wstring to_wstring(double val);
std::wstring to_wstring(long double val);
```

### `std::begin` and `std::end`

These functions provide iterators to access elements in a string.

#### `std::begin`

- **Purpose**: Returns an iterator to the first element of the container.
- **Syntax**:

  ```cpp
  template< class C >
  auto begin( C& c ) -> decltype(c.begin());

  template< class T, size_t N >
  T* begin( T (&array)[N] );
  ```

- **Usage**:
  ```cpp
  int arr[] = {10, 20, 30, 40, 50};
  auto it = std::begin(arr); // 'it' is now an iterator pointing to the first element (10)
  ```

#### `std::end`

- **Purpose**: Returns an iterator to one past the last element of the container.
- **Syntax**:

  ```cpp
  template< class C >
  auto end( C& c ) -> decltype(c.end());

  template< class T, size_t N >
  T* end( T (&array)[N] );
  ```

- **Usage**:
  ```cpp
  int arr[] = {10, 20, 30, 40, 50};
  auto it = std::end(arr); // 'it' is now an iterator pointing past the last element
  ```

### Example Usage

Here is an example demonstrating the use of `std::begin` and `std::end` with an array and a `std::vector`.

```cpp
// std::begin / std::end example
#include <iostream>     // std::cout
#include <vector>       // std::vector, std::begin, std::end

int main() {
    int foo[] = {10, 20, 30, 40, 50}; // Array of integers
    std::vector<int> bar;             // Vector of integers

    // Iterate over the array 'foo' and insert elements into the vector 'bar'
    for (auto it = std::begin(foo); it != std::end(foo); ++it) {
        bar.push_back(*it);
    }

    // Iterate over the vector 'bar' and print its contents
    std::cout << "bar contains:";
    for (auto it = std::begin(bar); it != std::end(bar); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';

    return 0;
}
```

**Output:**

```
bar contains: 10 20 30 40 50
```

### Explanation

1. **Array Initialization**:

   ```cpp
   int foo[] = {10, 20, 30, 40, 50};
   ```

   An array `foo` is initialized with the values `{10, 20, 30, 40, 50}`.

2. **Vector Declaration**:

   ```cpp
   std::vector<int> bar;
   ```

   A vector `bar` is declared to store integers.

3. **Using `std::begin` and `std::end` with Array**:

   ```cpp
   for (auto it = std::begin(foo); it != std::end(foo); ++it) {
       bar.push_back(*it);
   }
   ```

   This loop uses `std::begin(foo)` to get an iterator to the start of the array and `std::end(foo)` to get an iterator to the end of the array. The loop iterates through each element of `foo` and inserts it into the vector `bar`.

4. **Using `std::begin` and `std::end` with Vector**:
   ```cpp
   std::cout << "bar contains:";
   for (auto it = std::begin(bar); it != std::end(bar); ++it) {
       std::cout << ' ' << *it;
   }
   std::cout << '\n';
   ```
   This loop uses `std::begin(bar)` and `std::end(bar)` to iterate through each element of the vector `bar` and prints its contents.
