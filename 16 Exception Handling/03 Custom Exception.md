# User-defined Custom Exception with Class in C++

In C++, you can use exception handling with classes, allowing you to throw exceptions of user-defined class types. This is done by creating a custom exception class and throwing an instance of that class.

## Example 1: Exception Handling with a Single Class

### Code:

```cpp
#include <iostream>
using namespace std;

class demo {
};

int main() {
    try {
        throw demo();
    }
    catch (demo d) {
        cout << "Caught exception of demo class \n";
    }
}
```

### Output:

```
Caught exception of demo class
```

### Explanation:

In this example, we have declared an empty class `demo`. In the `try` block, we throw an object of `demo` class type. The `catch` block catches the object and displays a message.

## Example 2: Exception Handling with Two Classes

### Code:

```cpp
#include <iostream>
using namespace std;

class demo1 {
};

class demo2 {
};

int main() {
    for (int i = 1; i <= 2; i++) {
        try {
            if (i == 1)
                throw demo1();
            else if (i == 2)
                throw demo2();
        }
        catch (demo1 d1) {
            cout << "Caught exception of demo1 class \n";
        }
        catch (demo2 d2) {
            cout << "Caught exception of demo2 class \n";
        }
    }
}
```

### Output:

```
Caught exception of demo1 class
Caught exception of demo2 class
```

### Explanation:

In this example, we have two classes, `demo1` and `demo2`. Depending on the value of `i`, we throw an instance of either `demo1` or `demo2`. The `catch` blocks handle the exceptions accordingly.

## Exception Handling with Inheritance

Exception handling can also be implemented with inheritance. When an object thrown by a derived class is caught by the first catch block that matches its type.

### Code:

```cpp
#include <iostream>
using namespace std;

class demo1 {
};

class demo2 : public demo1 {
};

int main() {
    for (int i = 1; i <= 2; i++) {
        try {
            if (i == 1)
                throw demo1();
            else if (i == 2)
                throw demo2();
        }
        catch (demo1 d1) {
            cout << "Caught exception of demo1 class \n";
        }
        catch (demo2 d2) {
            cout << "Caught exception of demo2 class \n";
        }
    }
}
```

### Output:

```
Caught exception of demo1 class
Caught exception of demo1 class
```

### Explanation:

In this program, `demo2` is derived from `demo1`. The catch block for `demo1` is written first. Since `demo1` is the base class for `demo2`, an object thrown of `demo2` class will be handled by the first catch block for `demo1`.

## Exception Handling with Constructor

Exception handling can also be implemented in constructors. Although constructors cannot return values, you can use try and catch blocks within them.

### Code:

```cpp
#include <iostream>
using namespace std;

class demo {
    int num;

public:
    demo(int x) {
        try {
            if (x == 0)
                throw "Zero not allowed";

            num = x;
            show();
        }
        catch (const char* exp) {
            cout << "Exception caught \n";
            cout << exp << endl;
        }
    }

    void show() {
        cout << "Num = " << num << endl;
    }
};

int main() {
    demo(0);
    cout << "Again creating object \n";
    demo(1);
}
```

### Output:

```
Exception caught
Zero not allowed
Again creating object
Num = 1
```

### Explanation:

When `x = 0`, an exception is thrown and the catch block is executed. When `x = 1`, no exception is thrown and the object is created successfully.

## Custom Exception Classes in C++

Custom exception classes in C++ allow developers to define and throw exceptions tailored to specific application requirements or domain-specific errors. Here's an in-depth exploration of creating and utilizing custom exception classes:

### **Creating Custom Exception Classes**

Custom exception classes are typically derived from `std::exception` or its subclasses (`std::runtime_error`, `std::logic_error`, etc.). They encapsulate specific error details and provide meaningful context when exceptions are thrown and caught.

```cpp
#include <stdexcept>
#include <string>

class FileIOException : public std::runtime_error {
public:
    FileIOException(const std::string& filename, const std::string& message)
        : std::runtime_error(message + ": " + filename), filename(filename) {}

    const std::string& getFilename() const noexcept {
        return filename;
    }

private:
    std::string filename;
};

void processFile(const std::string& filename) {
    // Example: Throwing a custom exception
    throw FileIOException(filename, "Error reading file");
}
```

In this example:

- `FileIOException` inherits from `std::runtime_error` and adds a filename member to store additional context about the exception.
- The constructor initializes the base `std::runtime_error` with a formatted message combining the provided message and filename.
- `getFilename()` method allows retrieving the filename associated with the exception.

### **Throwing Custom Exceptions**

Custom exceptions are thrown in situations where specific errors occur that require specialized handling or reporting:

```cpp
void openFile(const std::string& filename) {
    if (!fileExists(filename)) {
        throw FileIOException(filename, "File not found");
    }
    // Open file and proceed with operations
}
```

Here, `openFile()` checks if a file exists and throws a `FileIOException` if it doesn't, providing details about the missing file.

### **Handling Custom Exceptions**

Custom exceptions are caught using `catch` blocks specific to their types, allowing for targeted error handling and recovery:

```cpp
int main() {
    try {
        openFile("example.txt");
    } catch (const FileIOException& e) {
        std::cerr << "File I/O error: " << e.what() << std::endl;
        std::cerr << "Filename: " << e.getFilename() << std::endl;
        // Handle specific error scenario
    } catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
        // Handle other standard exceptions
    } catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
        // Handle unexpected exceptions
    }
    return 0;
}
```

In `main()`, `openFile("example.txt")` may throw a `FileIOException`, which is caught specifically in the `catch (const FileIOException& e)` block. This allows for precise error reporting and handling based on the type and context of the exception.

### **Advanced Techniques with Custom Exceptions**

- **Hierarchical Exception Types**: Define a hierarchy of custom exception classes to categorize errors and handle them at appropriate levels of abstraction.

  ```cpp
  class DatabaseException : public std::runtime_error { /* ... */ };
  class SQLException : public DatabaseException { /* ... */ };
  ```

- **Localization and Internationalization**: Incorporate internationalization support in custom exception messages to provide error details in multiple languages.

- **Exception Propagation**: Propagate custom exceptions up the call stack to centralize error handling and avoid redundant error-checking code.

- **Contextual Information**: Enhance custom exception classes with additional data members or methods to provide more detailed context about errors, aiding in diagnostics and debugging.

#### **Best Practices**

- **Consistency**: Follow naming conventions and design principles consistent with standard library exception classes for clarity and interoperability.
- **Documentation**: Document custom exceptions thoroughly, including their intended usage, possible causes, and recommended handling strategies.

- **Testing**: Implement unit tests to validate the behavior of custom exception classes across expected and edge cases, ensuring robust error handling.

Custom exception classes in C++ empower developers to manage errors effectively, improving code reliability and maintainability by providing specialized error reporting and handling capabilities tailored to specific application requirements.