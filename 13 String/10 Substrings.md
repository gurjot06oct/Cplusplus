### Substring in C++

The `substr()` function in C++ is essential for performing various string operations like concatenation, appending, and more. It creates a new string initialized with a copy of a substring from the original string. In C++, this functionality is provided by the `<string>` header.

#### Syntax:

```cpp
string substr(size_t pos, size_t len) const;
```

- **pos:** Position of the first character to be copied.
- **len:** Length of the substring.
- **size_t:** Unsigned integral type.

#### Return Value:

Returns a new string object containing the specified substring.

#### Example:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello, world!";
    string r = s1.substr(7, 5); // Copies "world"
    cout << "Substring is: " << r << endl;
    return 0;
}
```

**Output:**

```
Substring is: world
```

#### Time Complexity:

- **Time Complexity:** O(len), where `len` is the length of the substring being copied.

#### Auxiliary Space:

- **Auxiliary Space:** O(len), additional space proportional to the length of the substring.

#### More Examples:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello world";
    cout << s.substr(0, 5) << endl;    // Output: "hello"
    cout << s.substr(6) << endl;       // Output: "world"
    cout << s.substr(6, 3) << endl;    // Output: "wor"
    return 0;
}
```

### Important Points to Remember:

- Indexing starts from 0 in C++ strings.
- If `pos` equals the string length, an empty string is returned.
- If `pos` exceeds the string length, `std::out_of_range` exception is thrown.
- If `len` is greater than the remaining length from `pos`, the substring includes characters up to the end of the string.
- If `len` is not provided, the substring includes characters from `pos` to the end of the string.

### Applications of Substring

1. **Extract everything after a Character:**

```cpp
string s = "dog:cat";
int pos = s.find(":");
string sub = s.substr(pos + 1); // Extracts "cat"
```

2. **Extract everything before a Character:**

```cpp
string s = "dog:cat";
int pos = s.find(":");
string sub = s.substr(0, pos); // Extracts "dog"
```

3. **Print all Substrings of a Given String:**

```cpp
#include <iostream>
#include <string>
using namespace std;

void printAllSubstrings(string s) {
    for (int i = 0; i < s.length(); ++i) {
        for (int len = 1; len <= s.length() - i; ++len) {
            cout << s.substr(i, len) << endl;
        }
    }
}

int main() {
    string s = "abcd";
    printAllSubstrings(s);
    return 0;
}
```

**Output:**

```
a
ab
abc
abcd
b
bc
bcd
c
cd
d
```

#### Time Complexity:

- **Time Complexity:** O(N^3), where N is the length of the string.

#### Auxiliary Space:

- **Auxiliary Space:** O(1), constant extra space.

4. **Sum of all Substrings of a String Representing a Number:**

```cpp
#include <iostream>
#include <string>
using namespace std;

int sumOfSubstrings(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int len = 1; len <= s.length() - i; ++len) {
            string sub = s.substr(i, len);
            sum += stoi(sub);
        }
    }
    return sum;
}

int main() {
    string num = "1234";
    cout << sumOfSubstrings(num) << endl; // Output: 1670
    return 0;
}
```

#### Time Complexity:

- **Time Complexity:** O(N^3), where N is the length of the string.

#### Auxiliary Space:

- **Auxiliary Space:** O(N), additional space for storing integers.

5. **Print the Maximum Value of all Substrings:**

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printMaxSubstring(string s) {
    vector<int> substrings;
    for (int i = 0; i < s.length(); ++i) {
        for (int len = 1; len <= s.length() - i; ++len) {
            string sub = s.substr(i, len);
            substrings.push_back(stoi(sub));
        }
    }
    cout << *max_element(substrings.begin(), substrings.end()) << endl;
}

int main() {
    string s = "823";
    printMaxSubstring(s); // Output: 823
    return 0;
}
```

#### Time Complexity:

- **Time Complexity:** O(N^3), where N is the length of the string.

#### Auxiliary Space:

- **Auxiliary Space:** O(N!), additional space for storing integers.

### Other Applications of Substring

- **Text Searching:** Used in search engines to find matches in text.
- **Text Parsing:** Breaks down strings into smaller parts for analysis.
- **Text Manipulation:** Used in find-and-replace operations within text documents.
- **Natural Language Processing:** Identifies words and phrases in text data.
- **Pattern Recognition:** Detects patterns in data such as financial trends or image recognition.
- **Password Security:** Used to verify password matches efficiently.

Substring operations are fundamental in C++ for various string manipulation tasks, providing flexibility and efficiency in handling string data. Understanding these operations is crucial for effective development and problem-solving in C++.
