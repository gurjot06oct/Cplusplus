### Function Call Operator (`()`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator()` allows the object to be called as if it were a function.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for ()
      int operator()(int x) const {
          return value + x;
      }
  };
  ```

- **Non-Member Function Overloading:**
  The function call operator is typically overloaded as a member function because it inherently acts on the object itself.

### Subscript Operator (`[]`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator[]` allows array-like access to the object's elements.

  ```cpp
  class MyClass {
  private:
      int data[10];

  public:
      MyClass() {
          for(int i = 0; i < 10; ++i) data[i] = i;
      }

      // Member function overloading for []
      int& operator[](int index) {
          return data[index];
      }

      // Const version for read-only access
      const int& operator[](int index) const {
          return data[index];
      }
  };
  ```

- **Non-Member Function Overloading:**
  The subscript operator is also typically overloaded as a member function to directly access the object's internal array.

### Comma Operator (`,`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator,` allows custom behavior for the comma operator.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Member function overloading for ,
      MyClass operator,(const MyClass& rhs) const {
          return MyClass(value + rhs.value);
      }
  };
  ```

- **Non-Member Function Overloading:**
  The `operator,` can be overloaded as a non-member function to combine values from two `MyClass` objects.

  ```cpp
  class MyClass {
  private:
      int value;

  public:
      MyClass(int v = 0) : value(v) {}

      // Declare friend function for non-member overload
      friend MyClass operator,(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  MyClass operator,(const MyClass& lhs, const MyClass& rhs) {
      return MyClass(lhs.value + rhs.value);
  }
  ```

### Usage

```cpp
// Comma Operator (,)
MyClass i39(5), i40(10);
(i39, i40); // Comma operator can sequence expressions, result is i40
i40.print(); // Output: 10

// Function Call Operator ()
MyClass i41(100);
int result = i41(5); // Calling object as a function
std::cout << "Function Call Result: " << result << std::endl;

// Subscript Operator []
MyClass i42(1);
i42[0] = 10; // Setting value using subscript operator
i42[1] = 20;
i42.print(); // Output: 10 20
```
