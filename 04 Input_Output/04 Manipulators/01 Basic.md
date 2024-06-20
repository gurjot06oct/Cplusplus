## Basic Manipulators

### `std::setiosflags`

This manipulator sets specific format flags on a stream.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setiosflags(ios::showpos | ios::uppercase);
    cout << hex << 255 << endl;  // Outputs "+FF"
    return 0;
}
```

### `std::resetiosflags`

This manipulator resets specific format flags on a stream.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setiosflags(ios::showpos) << 255 << endl;  // Outputs "+255"
    cout << resetiosflags(ios::showpos) << 255 << endl;  // Outputs "255"
    return 0;
}
```

### `std::setbase`

This manipulator sets the numerical base (decimal, octal, or hexadecimal) for integer input/output.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setbase(16) << 255 << endl;  // Outputs "ff"
    return 0;
}
```

### `std::setfill`

This manipulator sets the fill character used for padding in output.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setfill('*') << setw(10) << 123 << endl;  // Outputs "*******123"
    return 0;
}
```

### `std::setprecision`

This manipulator sets the number of digits to be used for floating-point output.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.141592653589793;
    cout << setprecision(5) << pi << endl;  // Outputs "3.1416"
    return 0;
}
```

### `std::setw`

This manipulator sets the width of the next input/output field.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setw(10) << 123 << endl;  // Outputs "       123" (7 leading spaces)
    return 0;
}
```

### `std::get_money`

This manipulator extracts a monetary value from an input stream.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    istringstream iss("$123.45");
    long double money;
    iss >> get_money(money);
    cout << "Extracted money: " << money << endl;  // Outputs "Extracted money: 123.45"
    return 0;
}
```

### `std::put_money`

This manipulator inserts a monetary value into an output stream.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long double money = 123.45;
    cout << put_money(money) << endl;  // Outputs "$123.45"
    return 0;
}
```

### `std::get_time`

This manipulator extracts a time value from an input stream.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

int main() {
    istringstream iss("12:34:56");
    tm time;
    iss >> get_time(&time, "%H:%M:%S");
    cout << "Extracted time: " << put_time(&time, "%H:%M:%S") << endl;  // Outputs "Extracted time: 12:34:56"
    return 0;
}
```

### `std::put_time`

This manipulator inserts a time value into an output stream.

**Usage:**

```cpp
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    time_t t = time(0);
    tm* now = localtime(&t);
    cout << put_time(now, "%Y-%m-%d %H:%M:%S") << endl;  // Outputs the current date and time
    return 0;
}
```

### Summary

- **Manipulators for Setting and Resetting Flags:**

  - `std::setiosflags`: Sets specific format flags.
  - `std::resetiosflags`: Resets specific format flags.

- **Manipulators for Numeric Bases and Formatting:**

  - `std::setbase`: Sets the numerical base for integer input/output.
  - `std::setfill`: Sets the fill character for padding.
  - `std::setprecision`: Sets the decimal precision for floating-point output.
  - `std::setw`: Sets the width of the next input/output field.

- **Manipulators for Monetary Values:**

  - `std::get_money`: Extracts a monetary value from an input stream.
  - `std::put_money`: Inserts a monetary value into an output stream.

- **Manipulators for Date and Time:**
  - `std::get_time`: Extracts a time value from an input stream.
  - `std::put_time`: Inserts a time value into an output stream.

These manipulators provide a wide range of formatting options, allowing you to control the appearance of input and output in your C++ programs with great precision.
