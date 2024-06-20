## `cin >>` methods

### `get()`

- Reads a single character, including whitespace.
- **Example for `get(char& c)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char c;
      cout << "Enter a character: ";
      cin.get(c); // Reads a single character, including whitespace
      cout << "You entered: " << c << endl;
      return 0;
  }
  ```

- **Example for `get(char* s, streamsize n)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char buffer[100];
      cout << "Enter a sentence (up to 99 characters): ";
      cin.get(buffer, 100); // Reads up to 99 characters into buffer
      cout << "You entered: " << buffer << endl;
      return 0;
  }
  ```

- **Example for `get(char* s, streamsize n, char delim)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char buffer[100];
      cout << "Enter a sentence (up to 99 characters): ";
      cin.get(buffer, 100, '\n'); // Reads up to 99 characters until newline
      cout << "You entered: " << buffer << endl;
      return 0;
  }
  ```

### `getline()`

- Reads an entire line of input including spaces, terminated by a newline character (`'\n'`).
- **Example for `getline(char* s, streamsize n)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char buffer[100];
      cout << "Enter a sentence: ";
      cin.getline(buffer, 100); // Reads a line of text, including spaces
      cout << "You entered: " << buffer << endl;
      return 0;
  }
  ```

- **Example for `getline(char* s, streamsize n, char delim)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char buffer[100];
      cout << "Enter a sentence: ";
      cin.getline(buffer, 100, '.'); // Reads a line until '.'
      cout << "You entered: " << buffer << endl;
      return 0;
  }
  ```

### `ignore()`

- Ignores characters in the input buffer up to a specified limit or until a delimiter.
- **Example for `ignore(streamsize n, int delim)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      int number;
      char c;

      cout << "Enter a number: ";
      cin >> number;

      // Ignore up to 100 characters or until '\n'
      cin.ignore(100, '\n');

      cout << "Enter a character: ";
      cin.get(c); // Reads a single character, including whitespace
      cout << "You entered: " << c << endl;

      return 0;
  }
  ```

### `peek()`

- Peeks at the next character in the input stream without extracting it.
- **Example for `peek()` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char nextChar;

      cout << "Enter a character: ";
      cin >> nextChar; // Reads a single character, skipping whitespace

      // Peeks at the next character without extracting it
      char peekedChar = cin.peek();
      cout << "Next character in stream: " << peekedChar << endl;

      return 0;
  }
  ```

### `putback()`

- Puts a character back into the input stream.
- **Example for `putback(char c)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char c;

      cout << "Enter a character: ";
      cin.get(c); // Reads a single character, including whitespace

      // Put the character back into the input stream
      cin.putback(c);

      // Read the character again
      char readAgain;
      cin.get(readAgain);

      cout << "Character read again: " << readAgain << endl;

      return 0;
  }
  ```

### `unget()`

- Puts the last extracted character back into the input stream.
- **Example for `unget()` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char c;

      cout << "Enter a character: ";
      cin.get(c); // Reads a single character, including whitespace

      // Put the character back into the input stream
      cin.unget();

      // Read the character again
      char readAgain;
      cin.get(readAgain);

      cout << "Character read again: " << readAgain << endl;

      return 0;
  }
  ```

### `read()`

- Reads a specified number of characters into a buffer.
- **Example for `read(char* s, streamsize n)` overload:**

  ```cpp
  #include <iostream>
  using namespace std;

  int main() {
      char buffer[100];

      cout << "Enter a sentence: ";
      cin.read(buffer, 100); // Reads up to 100 characters into buffer
      cout << "You entered: " << buffer << endl;

      return 0;
  }
  ```
