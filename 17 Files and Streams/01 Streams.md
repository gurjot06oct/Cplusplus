## Streams

In C++, streams are a powerful abstraction used for input and output operations. They provide a consistent interface for handling different types of I/O, such as reading from or writing to files, standard input (keyboard), and standard output (screen). C++ provides a variety of stream classes, all of which are part of the `<iostream>` and `<fstream>` libraries. Here’s a detailed explanation of streams in C++:

### 1. Stream Classes

C++ stream classes can be categorized into input streams, output streams, and stream buffers.

#### Input Streams

- **`istream`**: Base class for input streams. It provides functionalities for reading from standard input (e.g., `cin`).
- **`ifstream`**: Derived from `istream`, used for reading from files.

#### Output Streams

- **`ostream`**: Base class for output streams. It provides functionalities for writing to standard output (e.g., `cout`).
- **`ofstream`**: Derived from `ostream`, used for writing to files.

#### Stream Buffers

- **`streambuf`**: Base class for stream buffers. Manages the internal buffer that holds data during I/O operations.
- **`filebuf`**: Derived from `streambuf`, used for file I/O operations.

### 2. Standard Streams

C++ provides several predefined stream objects for standard input, output, and error handling:

- **`cin`**: Standard input stream (usually the keyboard).
- **`cout`**: Standard output stream (usually the screen).
- **`cerr`**: Standard error stream, unbuffered (usually the screen).
- **`clog`**: Standard error stream, buffered (usually the screen).

### 3. Basic Operations

#### Input Operations

Input operations are performed using the `>>` operator (extraction operator).

```cpp
#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x; // Reading from standard input
    cout << "You entered: " << x << endl;
    return 0;
}
```

#### Output Operations

Output operations are performed using the `<<` operator (insertion operator).

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl; // Writing to standard output
    return 0;
}
```

### 4. File I/O

To read from and write to files, you use `ifstream` and `ofstream` respectively.

#### Writing to a File

```cpp
#include <fstream>
using namespace std;

int main() {
    ofstream outfile("example.txt"); // Open a file for writing
    if (outfile.is_open()) {
        outfile << "Hello, File!" << endl;
        outfile.close(); // Close the file
    } else {
        cout << "Unable to open file";
    }
    return 0;
}
```

#### Reading from a File

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream infile("example.txt"); // Open a file for reading
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) { // Read line by line
            cout << line << endl;
        }
        infile.close(); // Close the file
    } else {
        cout << "Unable to open file";
    }
    return 0;
}
```

### 5. Stream States and Error Handling

Streams have state flags that indicate the status of I/O operations:

- **`good()`**: Returns true if no errors.
- **`eof()`**: Returns true if the end of the file is reached.
- **`fail()`**: Returns true for non-fatal I/O errors.
- **`bad()`**: Returns true for fatal I/O errors.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream infile("example.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
        if (infile.eof()) {
            cout << "End of file reached." << endl;
        } else if (infile.fail()) {
            cout << "Logical error on i/o operation." << endl;
        } else if (infile.bad()) {
            cout << "Read/writing error on i/o operation." << endl;
        }
        infile.close();
    } else {
        cout << "Unable to open file";
    }
    return 0;
}
```

### 6. Manipulators

C++ provides manipulators to format I/O operations, such as `endl`, `setw`, `setprecision`, etc.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159;
    cout << "Default: " << pi << endl;
    cout << "Fixed: " << fixed << setprecision(2) << pi << endl;
    cout << "Scientific: " << scientific << pi << endl;
    return 0;
}
```
