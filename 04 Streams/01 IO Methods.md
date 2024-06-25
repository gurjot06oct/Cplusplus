## I/O Methods

### 1. `cin` and `cout`

**Usage:**

```cpp
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::cout << n;
    return 0;
}
```

**Speed:**

- Standard `cin` and `cout` are relatively slow because they synchronize with C-style I/O (like `scanf` and `printf`).

**Best Practices:**

- Use `std::ios::sync_with_stdio(false);` and `std::cin.tie(NULL);` to speed up `cin` and `cout`.

```cpp
std::ios::sync_with_stdio(false);
std::cin.tie(NULL);
```

These lines of code disable the synchronization between C and C++ standard streams and untie `cin` from `cout`, respectively, leading to faster I/O operations.

### 2. `scanf` and `printf`

**Usage:**

```cpp
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", n);
    return 0;
}
```

**Speed:**

- `scanf` and `printf` are faster than standard `cin` and `cout`.

**Best Practices:**

- Prefer `scanf` and `printf` for simple and formatted I/O where performance is critical.
- Be cautious about format specifiers to avoid undefined behavior.

### 3. `getline`

**Usage:**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::cout << line;
    return 0;
}
```

**Speed:**

- `getline` is slower than `cin` and `scanf` for single integer or floating-point input but useful for reading entire lines.

**Best Practices:**

- Use `getline` for reading lines of text, especially when the input contains spaces.
- For mixing `getline` with `cin`, clear the input buffer using `std::cin.ignore()`.

### 4. File Input/Output

**Usage:**

```cpp
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");
    std::string line;

    while (std::getline(infile, line)) {
        outfile << line << "\n";
    }

    infile.close();
    outfile.close();
    return 0;
}
```

**Speed:**

- File I/O speed depends on the underlying file system and hardware.

**Best Practices:**

- Ensure the file is opened successfully by checking `infile.is_open()`.
- Always close the file after operations.

### 5. Fast Input/Output using `getchar` and `putchar`

**Usage:**

```cpp
#include <cstdio>

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
```

**Speed:**

- `getchar` and `putchar` are very fast, suitable for character-by-character I/O.

**Best Practices:**

- Use for processing large volumes of characters when performance is critical.
- Combine with buffer techniques to further enhance speed.

### 6. Custom Fast Input/Output

**Usage:**

```cpp
#include <iostream>

void fastInput(int &number) {
    number = 0;
    int c = getchar();
    bool negative = false;
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        number = number * 10 + (c - '0');
        c = getchar();
    }
    if (negative) {
        number = -number;
    }
}

void fastOutput(int number) {
    if (number < 0) {
        putchar('-');
        number = -number;
    }
    char buffer[10];
    int i = 0;
    do {
        buffer[i++] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i) {
        putchar(buffer[--i]);
    }
}

int main() {
    int n;
    fastInput(n);
    fastOutput(n);
    return 0;
}
```

**Speed:**

- Custom fast I/O methods using `getchar` and `putchar` are the fastest for integer input/output.

**Best Practices:**

- Implement custom fast I/O for competitive programming.
- Handle edge cases (negative numbers, non-numeric input) properly.

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
