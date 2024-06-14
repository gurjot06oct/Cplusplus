## Using Constants in C++

### Defining Constants

```cpp
// Define constants using 'const' keyword
const int MAX_STUDENTS = 50;
const float PI = 3.14159;
const std::string GREETING = "Hello, world!";
```

Constants are defined using the `const` keyword. They are initialized with a value that cannot be modified later in the program.

### Usage of Constants

```cpp
// Using constants
int students[MAX_STUDENTS];         // Array with a constant size
float circleArea = PI * 5 * 5;      // Calculating circle area using PI
std::cout << GREETING << std::endl; // Outputting a greeting message
```

- `MAX_STUDENTS` is used to define the size of an array.
- `PI` is used to calculate the area of a circle.
- `GREETING` is used to output a greeting message to the console.

### Attempt to Modify a Constant

```cpp
// Attempting to modify a constant (will result in a compilation error)
// MAX_STUDENTS = 60;
```

Attempting to modify a constant will result in a compilation error. The line `// MAX_STUDENTS = 60;` is commented out to indicate that such an operation is invalid.
