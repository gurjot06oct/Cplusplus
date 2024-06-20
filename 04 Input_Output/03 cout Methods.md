## `cout <<` methods

### `cout.put()`

- Outputs a single character.
- **Example for `put(char c)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char c = 'A';
      cout.put(c); // Outputs 'A'
      cout.put('\n'); // Outputs a newline
      return 0;
  }
  ```

### `cout.write()`

- Outputs a block of characters.
- **Example for `write(const char* s, streamsize n)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char buffer[] = "Hello, World!";
      cout.write(buffer, 13); // Outputs "Hello, World!"
      cout << endl; // Outputs a newline
      return 0;
  }
  ```

### `cout.precision()`

- Sets the decimal precision for floating-point output.
- **Example for `precision(int n)` overload:**

  ```cpp
  #include <iostream>
  #include <iomanip>
  using namespace std;

  int main() {
      double number = 3.14159;
      cout.precision(3);
      cout << "Pi with precision 3: " << number << endl; // Outputs "Pi with precision 3: 3.14"
      return 0;
  }
  ```

### `cout.width()`

- Sets the minimum field width for the next output.
- **Example for `width(int n)` overload:**

  ```cpp
  #include <iostream>
  #include <iomanip>
  using namespace std;

  int main() {
      int number = 123;
      cout.width(6);
      cout << number << endl; // Outputs "   123"
      return 0;
  }
  ```

### `cout.fill()`

- Sets the fill character for width padding.
- **Example for `fill(char c)` overload:**

  ```cpp
  #include <iostream>
  #include <iomanip>
  using namespace std;

  int main() {
      int number = 123;
      cout.width(6);
      cout.fill('*');
      cout << number << endl; // Outputs "***123"
      return 0;
  }
  ```

### `cout.setf()`

- Sets format flags for output.
- **Example for `setf(ios_base::fmtflags flags)` overload:**

  ```cpp
  #include <iostream>
  #include <iomanip>
  using namespace std;

  int main() {
      int number = 255;
      cout.setf(ios::hex, ios::basefield); // Output in hexadecimal
      cout << "Hexadecimal representation: " << number << endl; // Outputs "Hexadecimal representation: ff"
      return 0;
  }
  ```

- **Example for `setf(ios_base::fmtflags flags, ios_base::fmtflags mask)` overload:**

  ```cpp
  #include <iostream>
  #include <iomanip>
  using namespace std;

  int main() {
      double number = 123.456789;
      cout.setf(ios::fixed, ios::floatfield); // Set to fixed-point
      cout.precision(2); // Set precision
      cout << "Fixed-point format with precision 2: " << number << endl;

      return 0;
  }
  ```

### `cout.unsetf()`

- Unsets format flags.
- **Example for `unsetf(ios_base::fmtflags mask)` overload:**

  ```cpp
  #include <iostream>
  #include <iomanip>
  using namespace std;

  int main() {
      double number = 123.456789;
      cout << "Default format: " << number << endl;

      cout.setf(ios::fixed, ios::floatfield); // Set to fixed-point
      cout.precision(2); // Set precision
      cout << "Fixed-point format with precision 2: " << number << endl;

      cout.unsetf(ios::fixed); // Unset fixed-point format
      cout << "Back to default format: " << number << endl;

      return 0;
  }
  ```
