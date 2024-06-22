# Strings in C++

C++ strings are sequences of characters stored in a char array. They are used to store words, text, numbers, and other types of information. Strings in C++ can be defined using either the `std::string` class or C-style character arrays.

## Strings in C++

### 1. C-Style Strings

C-style strings are plain arrays of characters terminated by a null character (`'\0'`). These strings are inherited from the C language.

**Syntax:**

```cpp
char str[] = "Hello World";
```

**Example:**

```cpp
// C++ Program to demonstrate strings
#include <iostream>
using namespace std;

int main() {
    char s[] = "Hello World";
    cout << s << endl;
    return 0;
}
```

**Output:**

```
Hello World
```

### 2. `std::string` Class

`std::string` is a class introduced in C++ that provides many advantages over conventional C-style strings, such as dynamic size and member functions. It is defined in the `<string>` header file.

**Syntax:**

```cpp
std::string str("Hello World");
```

**Example:**

```cpp
// C++ program to create std::string objects
#include <iostream>
using namespace std;

int main() {
    string str("Hello World");
    cout << str;
    return 0;
}
```

**Output:**

```
Hello World
```

You can also create strings with repeating characters.

**Syntax:**

```cpp
std::string str(number, character);
```

**Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    string str(5, 'g');
    cout << str;
    return 0;
}
```

**Output:**

```
ggggg
```

## Ways to Define a String in C++

Strings in C++ can be defined in several ways, using the standard library's string class or character arrays. Despite being less advanced, character arrays are still widely used for their efficiency and ease of use.

### 1. Using `std::string` Keyword

Using the `string` keyword is convenient because it is easy to write and understand.

**Syntax:**

```cpp
string s = "Hello World";
string s("Hello World");
```

**Example:**

```cpp
// C++ Program to demonstrate use of string keyword
#include <iostream>
using namespace std;

int main() {
    string s = "Hello World";
    string str("Hello World");

    cout << "s = " << s << endl;
    cout << "str = " << str << endl;

    return 0;
}
```

**Output:**

```
s = Hello World
str = Hello World
```

### 2. Using C-Style Strings

C-style strings use library functions like `strcpy()`, `strcmp()`, and `strcat()` for definition and manipulation. This method is more complex but can be useful for legacy code or when performance is critical.

**Syntax:**

```cpp
char s[] = {'g', 'f', 'g', '\0'};
char s[4] = {'g', 'f', 'g', '\0'};
char s[4] = "gfg";
char s[] = "gfg";
```

**Example:**

```cpp
// C++ Program to demonstrate C-style string declaration
#include <iostream>
using namespace std;

int main() {
    char s1[] = { 'g', 'f', 'g', '\0' };
    char s2[4] = { 'g', 'f', 'g', '\0' };
    char s3[4] = "gfg";
    char s4[] = "gfg";

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;

    return 0;
}
```

**Output:**

```
s1 = gfg
s2 = gfg
s3 = gfg
s4 = gfg
```

Another example of C-style string:

```cpp
#include <iostream>
using namespace std;

int main() {
    string S = "Geeks for Geeks";
    cout << "Your string is= " << S << endl;

    return 0;
}
```

**Output:**

```
Your string is= Geeks for Geeks
```

## How to Take String Input in C++

String input means accepting a string from a user. There are different methods for taking input in C++, depending on the use case.

### 1. Using `cin`

The simplest way to take string input is to use the `cin` command along with the stream extraction operator (`>>`).

**Syntax:**

```cpp
cin >> s;
```

**Example:**

```cpp
// C++ Program to demonstrate string input using cin
#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter String" << endl;
    cin >> s;
    cout << "String is: " << s << endl;
    return 0;
}
```

**Output:**

```
Enter String
Hello World
String is: Hello World
```

### 2. Using `getline`

The `getline()` function reads a string from an input stream. It is declared in the `<string>` header file.

**Syntax:**

```cpp
getline(cin, s);
```

**Example:**

```cpp
// C++ Program to demonstrate use of getline function
#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter String" << endl;
    getline(cin, s);
    cout << "String is: " << s << endl;
    return 0;
}
```

**Output:**

```
Enter String
Hello World
String is: Hello World
```

### 3. Using `stringstream`

The `stringstream` class is used to take multiple strings as input at once.

**Syntax:**

```cpp
stringstream stringstream_object(string_name);
```

**Example:**

```cpp
// C++ Program to demonstrate use of stringstream object
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s = "Hello World to the Moon";
    stringstream obj(s);
    string temp;
    while (obj >> temp) {
        cout << temp << endl;
    }
    return 0;
}
```

**Output:**

```
Hello World
to
the
Moon
```

## How to Pass Strings to Functions

Strings can be passed to functions in C++ as character arrays or `std::string` objects.

**Example:**

```cpp
// C++ Program to print string using function
#include <iostream>
using namespace std;

void print_string(string s) {
    cout << "Passed String is: " << s << endl;
}

int main() {
    string s = "Hello World";
    print_string(s);
    return 0;
}
```

**Output:**

```
Passed String is: Hello World
```

## Pointers and Strings

Pointers in C++ represent addresses and allow for dynamic data manipulation. By using pointers, we can access and print strings.

**Example:**

```cpp
// C++ Program to print string using pointers
#include <iostream>
using namespace std;

int main() {
    string s = "Hello World";
    char* p = &s[0];

    while (*p != '\0') {
        cout << *p;
        p++;
    }
    cout << endl;

    return 0;
}
```
