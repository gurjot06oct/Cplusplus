// Sure! Let's go through each of these manipulators and format flags in C++ with examples.

// ### Independent Flags (Switch On)

// #### 1. `std::boolalpha`

// This manipulator converts boolean values to their alphanumerical representations (`true` and `false`).

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     bool flag = true;
//     cout << boolalpha << flag << endl; // Outputs "true"
//     return 0;
// }
// ```

// #### 2. `std::showbase`

// This manipulator shows numerical base prefixes for octal (`0`), hexadecimal (`0x`), and binary (`0b` in C++14 and later).

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 255;
//     cout << showbase << hex << n << endl; // Outputs "0xff"
//     return 0;
// }
// ```

// #### 3. `std::showpoint`

// This manipulator forces the display of the decimal point and trailing zeros for floating-point numbers.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     double pi = 3.0;
//     cout << showpoint << pi << endl; // Outputs "3.00000"
//     return 0;
// }
// ```

// #### 4. `std::showpos`

// This manipulator shows the positive sign (`+`) for positive numbers.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 123;
//     cout << showpos << n << endl; // Outputs "+123"
//     return 0;
// }
// ```

// #### 5. `std::skipws`

// This manipulator skips leading whitespace on input operations (default behavior).

// **Usage:**
// ```cpp
// #include <iostream>
// #include <sstream>
// using namespace std;

// int main() {
//     stringstream ss("   123");
//     int n;
//     ss >> skipws >> n;
//     cout << n << endl; // Outputs "123"
//     return 0;
// }
// ```

// #### 6. `std::unitbuf`

// This manipulator forces the stream to flush its buffer after each insertion.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     cout << unitbuf << "This will be flushed immediately." << endl;
//     return 0;
// }
// ```

// #### 7. `std::uppercase`

// This manipulator converts alphabetic characters in floating-point numbers and hexadecimal integers to uppercase.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 255;
//     cout << hex << uppercase << n << endl; // Outputs "FF"
//     return 0;
// }
// ```

// ### Independent Flags (Switch Off)

// #### 1. `std::noboolalpha`

// This manipulator switches off alphanumerical bool values, reverting to numeric representation (`1`/`0`).

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     bool flag = true;
//     cout << noboolalpha << flag << endl; // Outputs "1"
//     return 0;
// }
// ```

// #### 2. `std::noshowbase`

// This manipulator switches off the display of numerical base prefixes.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 255;
//     cout << noshowbase << hex << n << endl; // Outputs "ff"
//     return 0;
// }
// ```

// #### 3. `std::noshowpoint`

// This manipulator switches off the display of the decimal point and trailing zeros.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     double pi = 3.0;
//     cout << noshowpoint << pi << endl; // Outputs "3"
//     return 0;
// }
// ```

// #### 4. `std::noshowpos`

// This manipulator switches off the display of the positive sign.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 123;
//     cout << noshowpos << n << endl; // Outputs "123"
//     return 0;
// }
// ```

// #### 5. `std::noskipws`

// This manipulator switches off the skipping of leading whitespace on input operations.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <sstream>
// using namespace std;

// int main() {
//     stringstream ss("   123");
//     int n;
//     ss >> noskipws >> n; // Will fail to read the number because of leading spaces
//     cout << n << endl; // Outputs "0" because extraction failed
//     return 0;
// }
// ```

// #### 6. `std::nounitbuf`

// This manipulator switches off forced flushes after each insertion.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     cout << nounitbuf << "This will not be flushed immediately." << endl;
//     return 0;
// }
// ```

// #### 7. `std::nouppercase`

// This manipulator switches off the generation of uppercase letters.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 255;
//     cout << hex << nouppercase << n << endl; // Outputs "ff"
//     return 0;
// }
// ```

// ### Numerical Base Format Flags ("basefield" flags)

// #### 1. `std::dec`

// Sets the integer number format to decimal (default format).

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 255;
//     cout << dec << n << endl; // Outputs "255"
//     return 0;
// }
// ```

// #### 2. `std::hex`

// Sets the integer number format to hexadecimal.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 255;
//     cout << hex << n << endl; // Outputs "ff"
//     return 0;
// }
// ```

// #### 3. `std::oct`

// Sets the integer number format to octal.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int n = 255;
//     cout << oct << n << endl; // Outputs "377"
//     return 0;
// }
// ```

// ### Floating-Point Format Flags ("floatfield" flags)

// #### 1. `std::fixed`

// Sets the floating-point number format to fixed-point notation.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     double pi = 3.141592653589793;
//     cout << fixed << setprecision(5) << pi << endl; // Outputs "3.14159"
//     return 0;
// }
// ```

// #### 2. `std::scientific`

// Sets the floating-point number format to scientific notation.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     double pi = 3.141592653589793;
//     cout << scientific << setprecision(5) << pi << endl; // Outputs "3.14159e+00"
//     return 0;
// }
// ```

// ### Adjustment Format Flags ("adjustfield" flags)

// #### 1. `std::internal`

// Adjusts the field by inserting characters at an internal position (padding after the sign).

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     cout << internal << setw(10) << -123 << endl; // Outputs "-       123"
//     return 0;
// }
// ```

// #### 2. `std::left`

// Justifies the output to the left.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     cout << left << setw(10) << 123 << endl; // Outputs "123       "
//     return 0;
// }
// ```

// #### 3. `std::right`

// Justifies the output to the right.

// **Usage:**
// ```cpp
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     cout << right << setw(10) << 123 << endl; // Outputs "       123"
//     return 0;
// }
// ```

// These manipulators provide extensive control over the formatting and display of output in C++ programs, making it easier to create neatly formatted and readable output for various types of data.