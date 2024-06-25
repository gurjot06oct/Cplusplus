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

## Conclusion

Using user-defined custom exceptions in C++ allows you to handle specific error conditions in a more controlled and descriptive manner. By leveraging class-based exceptions, you can create more robust and maintainable error-handling mechanisms in your programs.
