## Comparison Operator

### 1. Equality Operator (`==`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator==` compares the `value` of the current object (`*this`) with the `value` of the `rhs` object.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for ==
      bool operator==(const MyClass& rhs) const {
          return value == rhs.value;
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator==` function is declared as a friend outside the class `MyClass`, allowing it to access private members. It performs the same comparison using the `value` members of `lhs` and `rhs`.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Declare friend function for non-member overload
      friend bool operator==(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator==(const MyClass& lhs, const MyClass& rhs) {
      return lhs.value == rhs.value;
  }
  ```

### 2. Inequality Operator (`!=`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator!=` uses `operator==` to check if `*this` is not equal to `rhs`.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for !=
      bool operator!=(const MyClass& rhs) const {
          return !(*this == rhs); // Reuses operator==
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator!=` is declared as a friend outside the class `MyClass`, reusing `operator==` to determine if `lhs` is not equal to `rhs`.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Declare friend function for non-member overload
      friend bool operator!=(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator!=(const MyClass& lhs, const MyClass& rhs) {
      return !(lhs == rhs); // Reuses operator==
  }
  ```

### 3. Less Than Operator (`<`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator<` compares `value` of `*this` with `rhs.value`.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for <
      bool operator<(const MyClass& rhs) const {
          return value < rhs.value;
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator<` is declared as a friend outside the class `MyClass`, accessing `value` members of both `lhs` and `rhs` for comparison.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Declare friend function for non-member overload
      friend bool operator<(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator<(const MyClass& lhs, const MyClass& rhs) {
      return lhs.value < rhs.value;
  }
  ```

### 4. Less Than or Equal To Operator (`<=`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator<=` compares `value` of `*this` with `rhs.value`.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for <=
      bool operator<=(const MyClass& rhs) const {
          return value <= rhs.value;
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator<=` is declared as a friend outside the class `MyClass`, accessing `value` members of both `lhs` and `rhs` for comparison.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Declare friend function for non-member overload
      friend bool operator<=(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator<=(const MyClass& lhs, const MyClass& rhs) {
      return lhs.value <= rhs.value;
  }
  ```

### 5. Greater Than Operator (`>`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator>` compares `value` of `*this` with `rhs.value`.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for >
      bool operator>(const MyClass& rhs) const {
          return value > rhs.value;
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator>` is declared as a friend outside the class `MyClass`, accessing `value` members of both `lhs` and `rhs` for comparison.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Declare friend function for non-member overload
      friend bool operator>(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator>(const MyClass& lhs, const MyClass& rhs) {
      return lhs.value > rhs.value;
  }
  ```

### 6. Greater Than or Equal To Operator (`>=`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator>=` compares `value` of `*this` with `rhs.value`.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for >=
      bool operator>=(const MyClass& rhs) const {
          return value >= rhs.value;
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator>=` is declared as a friend outside the class `MyClass`, accessing `value` members of both `lhs` and `rhs` for comparison.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Declare friend function for non-member overload
      friend bool operator>=(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator>=(const MyClass& lhs, const MyClass& rhs) {
      return lhs.value >= rhs.value;
  }
  ```

### Usage

```cpp
// Comparison Operators (==, !=, <, <=, >, >=)
MyClass i16(25);
MyClass i17(30);
bool isEqual = (i16 == i17);
std::cout << std::boolalpha << isEqual << std::endl; // Output: Result of i16 == i17

bool isNotEqual = (i16 != i17);
std::cout << std::boolalpha << isNotEqual << std::endl; // Output: Result of i16 != i17

bool isLessThan = (i16 < i17);
std::cout << std::boolalpha << isLessThan << std::endl; // Output: Result of i16 < i17

bool isLessThanOrEqual = (i16 <= i17);
std::cout << std::boolalpha << isLessThanOrEqual << std::endl; // Output: Result of i16 <= i17

bool isGreaterThan = (i16 > i17);
std::cout << std::boolalpha << isGreaterThan << std::endl; // Output: Result of i16 > i17

bool isGreaterThanOrEqual = (i16 >= i17);
std::cout << std::boolalpha << isGreaterThanOrEqual << std::endl; // Output: Result of i16 >= i17
```
