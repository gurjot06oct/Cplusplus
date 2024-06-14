## Variable Naming in C++

These are Variable naming rules:

- They don't start with a digit.
- They don't contains a special character.
- They don't contains a hyphen.
- They don't contains a space.
- They are not reserved keywords.

### Valid Variable Names

```cpp
int age;
float salary;
double _grossIncome;
char firstName;
int numberOfStudents;
```

### Invalid Variable Names

```cpp
int 123abc;           // Invalid: starts with a digit
float salary#;        // Invalid: contains a special character
double gross-Income;  // Invalid: contains a hyphen
char first Name;      // Invalid: contains a space
int class;            // Invalid: 'class' is a reserved keyword
```

These lines are commented out because they contain invalid variable names. The reasons for their invalidity are indicated in the comments.

### Use Descriptive Names

```cpp
int studentAge = 20;
float grossSalary = 55000.75;
double netIncome;
char grade = 'A';
int _counter = 0;
```

These variables use descriptive names that convey their purpose, improving code readability. They also follow C++ naming conventions.
