## Bitwise Operators

### 1. Bitwise AND Operator (`&`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator&` performs bitwise AND operation between `*this` and `rhs`.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Member function overloading for bitwise AND (&)
      MyClass operator&(const MyClass& rhs) const {
          return MyClass(data & rhs.data);
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator&` is declared as a friend outside the class `MyClass`, accessing `data` members of both `lhs` and `rhs` for bitwise AND operation.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Declare friend function for non-member overload
      friend MyClass operator&(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  MyClass operator&(const MyClass& lhs, const MyClass& rhs) {
      return MyClass(lhs.data & rhs.data);
  }
  ```

### 2. Bitwise OR Operator (`|`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator|` performs bitwise OR operation between `*this` and `rhs`.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Member function overloading for bitwise OR (|)
      MyClass operator|(const MyClass& rhs) const {
          return MyClass(data | rhs.data);
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator|` is declared as a friend outside the class `MyClass`, accessing `data` members of both `lhs` and `rhs` for bitwise OR operation.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Declare friend function for non-member overload
      friend MyClass operator|(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  MyClass operator|(const MyClass& lhs, const MyClass& rhs) {
      return MyClass(lhs.data | rhs.data);
  }
  ```

### 3. Bitwise XOR Operator (`^`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator^` performs bitwise XOR operation between `*this` and `rhs`.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Member function overloading for bitwise XOR (^)
      MyClass operator^(const MyClass& rhs) const {
          return MyClass(data ^ rhs.data);
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator^` is declared as a friend outside the class `MyClass`, accessing `data` members of both `lhs` and `rhs` for bitwise XOR operation.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Declare friend function for non-member overload
      friend MyClass operator^(const MyClass& lhs, const MyClass& rhs);
  };

  // Define friend function outside the class
  MyClass operator^(const MyClass& lhs, const MyClass& rhs) {
      return MyClass(lhs.data ^ rhs.data);
  }
  ```

### 4. Left Shift Operator (`<<`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator<<` performs left shift operation on `data` of `*this` by `rhs`.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Member function overloading for left shift (<<)
      MyClass operator<<(int rhs) const {
          return MyClass(data << rhs);
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator<<` is declared as a friend outside the class `MyClass`, allowing left shift operation on `data` members of `lhs` by `rhs`.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Declare friend function for non-member overload
      friend MyClass operator<<(const MyClass& lhs, int rhs);
  };

  // Define friend function outside the class
  MyClass operator<<(const MyClass& lhs, int rhs) {
      return MyClass(lhs.data << rhs);
  }
  ```

### 5. Right Shift Operator (`>>`)

- **Member Function Overloading:**
  Inside the class `MyClass`, the `operator>>` performs right shift operation on `data` of `*this` by `rhs`.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Member function overloading for right shift (>>)
      MyClass operator>>(int rhs) const {
          return MyClass(data >> rhs);
      }
  };
  ```

- **Non-Member Function Overloading (Friend Function):**
  The `operator>>` is declared as a friend outside the class `MyClass`, allowing right shift operation on `data` members of `lhs` by `rhs`.

  ```cpp
  class MyClass {
  private:
      int data;

  public:
      MyClass(int d = 0) : data(d) {}

      // Declare friend function for non-member overload
      friend MyClass operator>>(const MyClass& lhs, int rhs);
  };

  // Define friend function outside the class
  MyClass operator>>(const MyClass& lhs, int rhs) {
      return MyClass(lhs.data >> rhs);
  }
  ```

### Usage

```cpp
// Bitwise AND (&)
MyClass i22(12);
MyClass i23(9);
MyClass i24;
i24 = i22 & i23;
i24.print(); // Output: Result of bitwise AND of i22 and i23

// Bitwise OR (|)
MyClass i25(12);
MyClass i26(9);
MyClass i27;
i27 = i25 | i26;
i27.print(); // Output: Result of bitwise OR of i25 and i26

// Bitwise XOR (^)
MyClass i28(12);
MyClass i29(9);
MyClass i30;
i30 = i28 ^ i29;
i30.print(); // Output: Result of bitwise XOR of i28 and i29

// Left Shift (<<)
MyClass i31(5);
int shiftAmount = 2;
MyClass i32;
i32 = i31 << shiftAmount;
i32.print(); // Output: Result of left shift of i31 by shiftAmount

// Right Shift (>>)
MyClass i33(20);
int shiftAmount2 = 2;
MyClass i34;
i34 = i33 >> shiftAmount2;
i34.print(); // Output: Result of right shift of i33 by shiftAmount2
```
