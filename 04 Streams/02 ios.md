### The `ios` Class Hierarchy (`<ios>`)

The `ios` class hierarchy forms the foundation for all I/O stream operations in C++. This hierarchy includes the `ios_base` class and the `ios` class, which provide essential functionalities and state management for streams. Here's an in-depth look at each of these classes and their functionalities.

#### State Management

`ios_base` maintains the state of the stream, which includes checking for errors and the current formatting state.

- **Checking Stream State**:

  ```cpp
  #include <iostream>
  #include <fstream>

  std::ifstream file("nonexistent.txt");
  if (!file) {
      std::cerr << "Error opening file" << std::endl;
  }
  ```

- **State Flags**:
  - `good()`: No errors.
  - `eof()`: End of file reached.
  - `fail()`: Logical error on I/O operation.
  - `bad()`: Read/write error on I/O operation.
  ```cpp
  if (file.good()) {
      // No errors
  } else if (file.eof()) {
      // End of file reached
  } else if (file.fail()) {
      // Logical error
  } else if (file.bad()) {
      // Read/write error
  }
  ```

### `ios` Class

The `ios` class inherits from `ios_base` and adds stream-specific functionalities. It acts as a base class for `istream` and `ostream`.

#### Tie Streams

`ios` provides the `tie` functionality, which links one stream to another, ensuring that the linked stream is flushed before any I/O operation on the tying stream.

- **Tying Streams**:

  ```cpp
  #include <iostream>
  #include <fstream>

  std::ofstream logFile("log.txt");
  std::cin.tie(&logFile);  // Tie cin to logFile

  int num;
  std::cin >> num;
  // logFile is flushed before reading from cin
  ```

#### Exception Handling

`ios` provides mechanisms to set and handle exceptions.

- **Setting Exceptions**:

  ```cpp
  #include <iostream>
  #include <fstream>

  std::ifstream file("data.txt");
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
      file.open("nonexistent.txt");
  } catch (const std::ios_base::failure& e) {
      std::cerr << "Exception opening file: " << e.what() << std::endl;
  }
  ```

#### Stream Buffers

The `ios` class associates a stream with a stream buffer (`streambuf`). This buffer manages the actual I/O.

- **Accessing Stream Buffers**:

  ```cpp
  #include <iostream>
  #include <sstream>

  std::stringstream ss;
  std::streambuf* pbuf = ss.rdbuf();
  pbuf->sputn("Hello, World!", 13);  // Directly manipulate the buffer

  std::cout << ss.str() << std::endl;  // Outputs: Hello, World!
  ```
