# Exception Handling Using Classes in C++

## Problem Statement

1. Create a class `Numbers` which has two data members `a` and `b`.
2. Write iterative functions to find the GCD of two numbers.
3. Write an iterative function to check whether any given number is prime or not. If it is prime, throw an exception to a class `MyPrimeException`.
4. Define your own `MyPrimeException` class.

## Solution

1. Define a class named `Number` with two private data members `a` and `b`.
2. Define two member functions:
   - `int gcd()`: To calculate the GCD of the two numbers.
   - `bool isPrime(int n)`: To check if a given number is prime or not.
3. Use a constructor to initialize the data members.
4. Create another class named `MyPrimeException` which will be used when an exception is thrown.

Below is the implementation to illustrate the concept of exception handling using classes:

```cpp
#include <iostream>
using namespace std;

// Class declaration
class Number {
private:
    int a, b;

public:
    // Constructor
    Number(int x, int y) : a(x), b(y) {}

    // Function to find the GCD of two numbers a and b
    int gcd() {
        int tempA = a, tempB = b; // Use temporary variables to avoid altering original values
        while (tempA != tempB) {
            if (tempA > tempB)
                tempA -= tempB;
            else
                tempB -= tempA;
        }
        return tempA;
    }

    // Function to check if a given number is prime
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i <= n / 2; ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

// Exception class
class MyPrimeException {};

// Driver code
int main() {
    int x = 13, y = 56;
    Number num1(x, y);

    // Print the GCD of x and y
    cout << "GCD is = " << num1.gcd() << endl;

    // Check if x is prime
    if (num1.isPrime(x))
        cout << x << " is a prime number" << endl;

    // Check if y is prime
    if (num1.isPrime(y))
        cout << y << " is a prime number" << endl;

    // Exception handling
    if (num1.isPrime(x) || num1.isPrime(y)) {
        // Try block
        try {
            throw MyPrimeException();
        }
        // Catch block
        catch (MyPrimeException&) {
            cout << "Caught exception of MyPrimeException class." << endl;
        }
    }

    return 0;
}
```

**Output:**

```
GCD is = 1
13 is a prime number
Caught exception of MyPrimeException class.
```

### Explanation

1. **Class Number**:

   - The `Number` class has private data members `a` and `b`.
   - The constructor initializes `a` and `b`.
   - The `gcd()` function calculates the greatest common divisor of `a` and `b` using a simple iterative approach.
   - The `isPrime(int n)` function checks if the given number `n` is prime.

2. **Exception Class**:

   - `MyPrimeException` is an empty class used for exception handling.

3. **Main Function**:
   - Creates an instance of `Number` with `x` and `y`.
   - Prints the GCD of `x` and `y`.
   - Checks if `x` and `y` are prime and throws `MyPrimeException` if any of them are prime.
   - Catches the thrown exception and prints an appropriate message.
