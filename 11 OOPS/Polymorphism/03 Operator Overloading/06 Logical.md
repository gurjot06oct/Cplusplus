## Logical Operators

### 1. Logical AND Operator (`&&`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator&&` applies logical AND to the conditions involving `*this` and `rhs`.

  ```cpp
  class MyClass {
  private:
      bool condition;

  public:
      MyClass(bool cond = false) : condition(cond) {}

      // Member function overloading for &&
      bool operator&&(const MyClass& rhs) const {
          return condition && rhs.condition;
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator&&` is declared as a friend outside the class `MyClass`, allowing it to access `condition` members of both `lhs` and `rhs`.

  ```cpp
  class MyClass {
  private:
      bool condition;

  public:
      MyClass(bool cond = false) : condition(cond) {}

      // Declare friend function for non-member overload
      friend bool operator&&(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator&&(const MyClass& lhs, const MyClass& rhs) {
      return lhs.condition && rhs.condition;
  }
  ```

### 2. Logical OR Operator (`||`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator||` applies logical OR to the conditions involving `*this` and `rhs`.

  ```cpp
  class MyClass {
  private:
      bool condition;

  public:
      MyClass(bool cond = false) : condition(cond) {}

      // Member function overloading for ||
      bool operator||(const MyClass& rhs) const {
          return condition || rhs.condition;
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator||` is declared as a friend outside the class `MyClass`, allowing it to access `condition` members of both `lhs` and `rhs`.

  ```cpp
  class MyClass {
  private:
      bool condition;

  public:
      MyClass(bool cond = false) : condition(cond) {}

      // Declare friend function for non-member overload
      friend bool operator||(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  bool operator||(const MyClass& lhs, const MyClass& rhs) {
      return lhs.condition || rhs.condition;
  }
  ```

### Usage

```cpp
// Logical AND (&&)
MyClass i18(true);
MyClass i19(false);
bool logicalAndResult = (i18 && i19);
std::cout << std::boolalpha << logicalAndResult << std::endl; // Output: Result of i18 && i19

// Logical OR (||)
MyClass i20(true);
MyClass i21(false);
bool logicalOrResult = (i20 || i21);
std::cout << std::boolalpha << logicalOrResult << std::endl; // Output: Result of i20 || i21
```
