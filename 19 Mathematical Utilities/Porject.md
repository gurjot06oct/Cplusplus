### **Project Title**: **Mathematical Utilities System Using Advanced OOP in C++**

---

### **Project Overview:**
The project will be a mathematical utility system that performs operations on several custom data types (classes), including `Matrix`, `Fraction`, `Vector`, `String`, and `Polynomial`. It will utilize various C++ features such as:

- **Type Conversions** (built-in and user-defined)
- **Storage Classes**
- **Streams** (`stringstream`, file I/O, etc.)
- **Lambda Functions**
- **Pointers and Dynamic Memory Allocation**
- **Struct, Enum, and Union**
- **Classes and Objects**
- **Constructors and Destructors**
- **Friend Functions**
- **Static Members**
- **Encapsulation and Abstraction**
- **Inheritance**
- **Polymorphism** (Method Overloading, Operator Overloading, and Method Overriding)
- **Exception Handling**

### **Project Components:**

1. **Custom Data Classes:**
    - `Matrix`
    - `Fraction`
    - `Vector`
    - `String`
    - `Polynomial`

2. **Features:**
    - Arithmetic operations
    - File I/O for reading and writing matrices, polynomials, and vectors
    - String manipulation with custom `String` class
    - Dynamic memory allocation and deallocation for large structures like matrices
    - Exception handling for input validation and operations (e.g., division by zero)

---

### **1. Project Directory Structure**

```plaintext
MathUtilitySystem/
├── include/
│   ├── Matrix.h
│   ├── Fraction.h
│   ├── Vector.h
│   ├── String.h
│   └── Polynomial.h
├── src/
│   ├── Matrix.cpp
│   ├── Fraction.cpp
│   ├── Vector.cpp
│   ├── String.cpp
│   └── Polynomial.cpp
├── main.cpp
├── Makefile
└── README.md
```

---

### **2. Detailed Blueprint of Each Class**

---

#### **2.1. `Matrix` Class**
- **Purpose**: Handles matrix operations like addition, multiplication, inversion, etc.
- **Features**:
    - Dynamic memory allocation for matrices
    - Operator overloading for `+`, `*`, `-`
    - Type conversion from `Vector` (a 1xN matrix)
    - Exception handling for matrix size mismatches
    - File I/O for saving and loading matrices
    - Lambda functions for element-wise matrix operations

##### **Header File (`Matrix.h`):**
```cpp
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>

class Vector; // Forward declaration for type conversion

class Matrix {
private:
    int rows, cols;
    double** data;
    static int objectCount;  // Static member for tracking the number of matrix objects

public:
    // Constructors and Destructor
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    ~Matrix();

    // Static member function
    static int getObjectCount();

    // Operator Overloading
    Matrix operator+(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    double& operator()(int r, int c); // Access matrix element

    // Friend Functions
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    // Type Conversion
    operator Vector();  // Convert matrix to vector if it's 1xN or Nx1

    // Other member functions
    void fillMatrix();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

    // Exception Handling
    class MatrixSizeMismatchException : public std::exception {
        const char* what() const noexcept override;
    };
};

#endif
```

---

#### **2.2. `Fraction` Class**
- **Purpose**: Represents rational numbers (fractions) and supports basic arithmetic.
- **Features**:
    - Operator overloading for `+`, `-`, `*`, `/`
    - Implicit type conversion to `double` for floating-point operations
    - Exception handling for zero denominators
    - Friend functions for I/O operations

##### **Header File (`Fraction.h`):**
```cpp
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructors and Destructor
    Fraction(int n = 0, int d = 1);  // Default constructor
    ~Fraction() {}

    // Operator Overloading
    Fraction operator+(const Fraction& other);
    Fraction operator-(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);

    // Type Conversion
    operator double();  // Convert fraction to double

    // Friend Function
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
    friend std::istream& operator>>(std::istream& is, Fraction& f);

    // Exception Handling
    class DivideByZeroException : public std::exception {
        const char* what() const noexcept override;
    };
};

#endif
```

---

#### **2.3. `Vector` Class**
- **Purpose**: Handles vector operations such as addition, dot product, etc.
- **Features**:
    - Operator overloading for `+`, `*` (dot product), `[]` (indexing)
    - Friend functions for I/O
    - Type conversion from `Matrix`
    - Exception handling for index out of bounds

##### **Header File (`Vector.h`):**
```cpp
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<double> data;

public:
    // Constructors
    Vector(int size = 0);
    ~Vector() {}

    // Operator Overloading
    Vector operator+(const Vector& other);
    double operator*(const Vector& other); // Dot product
    double& operator[](int index);

    // Friend Functions
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend std::istream& operator>>(std::istream& is, Vector& v);

    // Exception Handling
    class IndexOutOfBoundsException : public std::exception {
        const char* what() const noexcept override;
    };
};

#endif
```

---

#### **2.4. `String` Class**
- **Purpose**: Custom string class that handles basic string operations and supports dynamic memory management.
- **Features**:
    - Operator overloading for concatenation (`+`), assignment (`=`), and comparison (`==`)
    - Dynamic memory allocation for string manipulation
    - Exception handling for null pointer access
    - Friend functions for I/O

##### **Header File (`String.h`):**
```cpp
#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    char* str;

public:
    // Constructors and Destructor
    String(const char* s = "");
    String(const String& other);
    ~String();

    // Operator Overloading
    String operator+(const String& other);
    String& operator=(const String& other);
    bool operator==(const String& other);

    // Friend Function
    friend std::ostream& operator<<(std::ostream& os, const String& s);

    // Exception Handling
    class NullPointerException : public std::exception {
        const char* what() const noexcept override;
    };
};

#endif
```

---

#### **2.5. `Polynomial` Class**
- **Purpose**: Handles polynomials and supports basic operations like addition, multiplication, evaluation, etc.
- **Features**:
    - Operator overloading for `+`, `*`
    - Custom exception for invalid operations
    - Type conversion from `Vector`
    - Friend functions for I/O

##### **Header File (`Polynomial.h`):**
```cpp
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

class Polynomial {
private:
    std::vector<double> coefficients;

public:
    // Constructors and Destructor
    Polynomial(const std::vector<double>& coeffs);
    ~Polynomial() {}

    // Operator Overloading
    Polynomial operator+(const Polynomial& other);
    Polynomial operator*(const Polynomial& other);
    double operator()(double x);  // Evaluate polynomial at x

    // Friend Functions
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    // Exception Handling
    class InvalidPolynomialOperationException : public std::exception {
        const char* what() const noexcept override;
    };
};

#endif
```

---

### **3. Main Program (`main.cpp`)**

In the main program, you will use these classes to perform various operations such as matrix manipulations, polynomial evaluations, and handling exceptions. The main program will also demonstrate:

- **Type conversions** between custom data types
- **Lambda functions** to iterate over matrices and vectors
- **File I/O** to save and load matrices, polynomials, etc.

##### **Main File (`main.cpp`):**
```cpp
#include "Matrix.h"
#include "Fraction.h"
#include "Vector.h"
#include "String.h"
#include "Polynomial.h"
#include <iostream>

int main() {
    try {
        // Create and manipulate matrices
        Matrix m1(3, 3);
        m1.fillMatrix();
        Matrix m2(3, 3);
        m2.fillMatrix();
        Matrix m3 = m1 + m2;
        std::cout << "Matrix Addition Result:\n" << m

3;

        // Perform operations on fractions
        Fraction f1(1, 2);
        Fraction f2(2, 3);
        Fraction f3 = f1 + f2;
        std::cout << "Fraction Addition Result: " << f3 << std::endl;

        // Vector operations
        Vector v1(3);
        Vector v2(3);
        Vector v3 = v1 + v2;
        std::cout << "Vector Addition Result: " << v3 << std::endl;

        // Polynomial evaluation
        Polynomial p({1, -3, 2}); // Represents 1x^2 - 3x + 2
        std::cout << "Polynomial Evaluation at x=2: " << p(2) << std::endl;

        // Demonstrate lambda function with matrices
        auto scaleMatrix = [](Matrix& mat, double factor) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    mat(i, j) *= factor;
                }
            }
        };

        scaleMatrix(m1, 2.0);
        std::cout << "Matrix after scaling:\n" << m1;

        // File I/O
        m1.saveToFile("matrix.txt");
        m2.loadFromFile("matrix.txt");

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
```

---

### **4. Key C++ Features Integration**

- **Type Conversions**: Implement conversions between `Matrix` and `Vector`, and between `Fraction` and `double`.
- **Storage Classes**: Use `static` members to keep track of object counts or cache values.
- **Streams**: Use `fstream` for file I/O and `stringstream` for string parsing within classes like `Polynomial` or `Matrix`.
- **Lambda Functions**: Used in the main function to perform element-wise operations on matrices.
- **Dynamic Memory Allocation**: Classes like `Matrix` and `String` will dynamically allocate and manage memory.
- **Exception Handling**: Handle errors such as matrix size mismatches, division by zero in `Fraction`, and invalid index access in `Vector`.
- **Polymorphism**: Overload operators (`+`, `*`, `-`, `=`, `[]`) and provide type conversions.

---

### **5. Makefile**
```Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDE = -I./include
SRC = ./src/Matrix.cpp ./src/Fraction.cpp ./src/Vector.cpp ./src/String.cpp ./src/Polynomial.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = MathUtilitySystem

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
```

---

### **6. Project Highlights**
- **Modular Design**: Each class is independently implemented and well-encapsulated, adhering to OOP principles.
- **Exception-Safe**: Classes implement robust exception handling for invalid operations.
- **Dynamic Memory Management**: Custom data types (like `Matrix` and `String`) manage memory dynamically, with safe allocation and deallocation.
- **Polymorphism and Operator Overloading**: The project makes use of method overloading, operator overloading, and method overriding.

This project covers a broad range of modern C++ features, and it is extendable for further operations or additional custom classes.