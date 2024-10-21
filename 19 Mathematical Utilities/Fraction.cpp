#include <iostream>
#include <sstream>

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
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
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

    // Inequality check
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
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

    // Convert fraction to double
    operator double() const {
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

// Main function for testing
int main() {
    try {
        Fraction f1(3, 4);
        Fraction f2(5, 6);
        Fraction f3;

        std::cout << "Fraction 1: " << f1 << std::endl;
        std::cout << "Fraction 2: " << f2 << std::endl;

        // Addition
        Fraction sum = f1 + f2;
        std::cout << "Sum: " << sum << std::endl;

        // Subtraction
        Fraction diff = f1 - f2;
        std::cout << "Difference: " << diff << std::endl;

        // Multiplication
        Fraction prod = f1 * f2;
        std::cout << "Product: " << prod << std::endl;

        // Division
        Fraction quot = f1 / f2;
        std::cout << "Quotient: " << quot << std::endl;

        // Input Fraction
        std::cout << "Enter a fraction (e.g., 5/7 or 3): ";
        std::cin >> f3;
        std::cout << "You entered: " << f3 << std::endl;

        // Convert to double
        std::cout << "Fraction 1 as double: " << static_cast<double>(f1) << std::endl;

        // Inverse
        Fraction inv = f1.inverse();
        std::cout << "Inverse of Fraction 1: " << inv << std::endl;

        // Absolute value
        Fraction absVal = f1.abs();
        std::cout << "Absolute value of Fraction 1: " << absVal << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
