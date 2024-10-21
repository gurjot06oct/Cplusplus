#include <iostream>
#include <sstream>
using namespace std;
class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    // Private helper function to reduce fraction
    void reduce() {
        int GCD = gcd(numerator, denominator);
        numerator /= GCD;
        denominator /= GCD;

        // Keep denominator positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    int expo(int base, int pow) const {
        int result = 1;
        if(pow==1) return base;
        while(pow) {
            if (pow & 1) 
                result = result * base;
            base = base * base;
            pow >>= 1;
        }
        return result;
    }

public:
    // Exception classes
    class DivisionByZeroException : public std::runtime_error {
    public:
        DivisionByZeroException() : std::runtime_error("Division by zero!") {}
    };

    class InvalidFractionException : public std::runtime_error {
    public:
        InvalidFractionException() : std::runtime_error("Invalid fraction input!") {}
    };

    // Constructors
    Fraction(int num=0, int denom=1) : numerator(num), denominator(denom)  {
        if (denominator == 0) throw DivisionByZeroException();
        reduce();
    }

    // Copy constructor
    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

    // Accessor methods
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Operator Overloading
    // Assignment operator
    Fraction& operator=(const Fraction& other) {
        if (this == &other) return *this; // Self-assignment check
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }
    Fraction& operator=(const int& value) {
        numerator = value;
        denominator = 1;
        return *this;
    }
    // Addition
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Subtraction
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Multiplication
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Division
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) throw DivisionByZeroException();
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    // Exponentiation
    Fraction operator^(int n) const {
        if (n == 0){
            return Fraction(1,1);
        };
        if(n<0) return Fraction(expo(denominator,-n), expo(numerator,-n));
        return Fraction(expo(numerator,n), expo(denominator,n));
    }

    // Unary minus operator
    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }

    // Equality check
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
    bool operator==(const int& value) const {
        return numerator == value && denominator == 1;
    }

    // Inequality check
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    bool operator!=(const int& value) const {
        return !(*this == value);
    }
    
    // Less than
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    // Greater than
    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    // Less than or equal to
    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    // Greater than or equal to
    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // Overload the addition assignment operator (+=)
    Fraction& operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + denominator * other.numerator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

    // Overload the subtraction assignment operator (-=)
    Fraction& operator-=(const Fraction& other) {
        numerator = numerator * other.denominator - denominator * other.numerator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

    // Overload the multiplication assignment operator (*=)
    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }

    // Overload the division assignment operator (/=)
    Fraction& operator/=(const Fraction& other) {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        reduce();
        return *this;
    }
    
    // Overload stream insertion operator for output
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        if (fraction.denominator == 1)
            os << fraction.numerator;
        else
            os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    // Overload stream extraction operator for input
    friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
        std::string input;
        is >> input;
        std::stringstream ss(input);
        int num, denom = 1;

        if (ss >> num) {
            if (ss.peek() == '/') {
                ss.ignore();
                if (!(ss >> denom)) throw InvalidFractionException();
            }
            if (denom == 0) throw DivisionByZeroException();
        } else {
            throw InvalidFractionException();
        }

        fraction = Fraction(num, denom);
        return is;
    }

    // Convert fraction to double (explicit only)
    explicit operator double() const {
        return static_cast<double>(numerator) / denominator;
    }

    // Inverse of the fraction
    Fraction inverse() const {
        if (numerator == 0) throw DivisionByZeroException();
        return Fraction(denominator, numerator);
    }

    // Get absolute value of the fraction
    Fraction abs() const {
        return Fraction(std::abs(numerator), std::abs(denominator));
    }
};

int main() {
    // Test Constructors
    Fraction f1;  // Default constructor (should be 0/1)
    Fraction f2(3, 4);  // Constructor with parameters (3/4)
    Fraction f3(f2);  // Copy constructor (copy of f2)
    
    cout << "f1: " << f1 << endl;  // Output: 0
    cout << "f2: " << f2 << endl;  // Output: 3/4
    cout << "f3 (copy of f2): " << f3 << endl;  // Output: 3/4

    // Test assignment operator
    f1 = f2;
    cout << "After assignment, f1: " << f1 << endl;  // Output: 3/4
    
    // Test arithmetic operations
    Fraction f4 = f2 + Fraction(1, 4);  // 3/4 + 1/4 = 1
    cout << "f2 + 1/4 = " << f4 << endl;  // Output: 1

    Fraction f5 = f2 - Fraction(1, 2);  // 3/4 - 1/2 = 1/4
    cout << "f2 - 1/2 = " << f5 << endl;  // Output: 1/4

    Fraction f6 = f2 * Fraction(2, 3);  // 3/4 * 2/3 = 1/2
    cout << "f2 * 2/3 = " << f6 << endl;  // Output: 1/2

    Fraction f7 = f2 / Fraction(3, 2);  // 3/4 / 3/2 = 1/2
    cout << "f2 / 3/2 = " << f7 << endl;  // Output: 1/2

    // Test exponentiation
    Fraction f8 = f2 ^ 2;  // (3/4)^2 = 9/16
    cout << "f2 ^ 2 = " << f8 << endl;  // Output: 9/16

    Fraction f9 = f2 ^ -2;  // (3/4)^(-2) = 16/9
    cout << "f2 ^ -2 = " << f9 << endl;  // Output: 16/9

    // Test unary minus
    Fraction f10 = -f2;  // Negation
    cout << "-f2 = " << f10 << endl;  // Output: -3/4

    // Test compound assignment operators
    f2 += Fraction(1, 4);  // f2 += 1/4
    cout << "f2 += 1/4, f2: " << f2 << endl;  // Output: 1

    f2 -= Fraction(1, 4);  // f2 -= 1/4
    cout << "f2 -= 1/4, f2: " << f2 << endl;  // Output: 3/4

    f2 *= Fraction(2, 3);  // f2 *= 2/3
    cout << "f2 *= 2/3, f2: " << f2 << endl;  // Output: 1/2

    f2 /= Fraction(1, 2);  // f2 /= 1/2
    cout << "f2 /= 1/2, f2: " << f2 << endl;  // Output: 1

    // Test comparison operators
    cout << boolalpha;
    cout << "f2 == 1: " << (f2 == 1) << endl;  // Output: true
    cout << "f2 != 1: " << (f2 != 1) << endl;  // Output: false
    cout << "f5 < f6: " << (f5 < f6) << endl;  // Output: true
    cout << "f5 > f6: " << (f5 > f6) << endl;  // Output: false
    cout << "f5 <= f6: " << (f5 <= f6) << endl;  // Output: true
    cout << "f5 >= f6: " << (f5 >= f6) << endl;  // Output: false

    // Test double conversion
    double d = static_cast<double>(f2);
    cout << "f2 as double: " << d << endl;  // Output: 1.0

    // Test inverse and abs
    Fraction f11 = f6.inverse();  // Inverse of 1/2 should be 2/1
    cout << "Inverse of f6: " << f11 << endl;  // Output: 2

    Fraction f12 = f10.abs();  // Absolute value of -3/4 is 3/4
    cout << "Absolute value of f10: " << f12 << endl;  // Output: 3/4

    // Test input
    Fraction f13;
    cout << "Enter a fraction (e.g., 3/5): ";
    cin >> f13;
    cout << "You entered: " << f13 << endl;

    // Test exception handling
    try {
        Fraction f14(1, 0);  // This should throw a DivisionByZeroException
    } catch (const Fraction::DivisionByZeroException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        Fraction f15;
        stringstream ss("3/x");  // Invalid input
        ss >> f15;
    } catch (const Fraction::InvalidFractionException& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    return 0;
}