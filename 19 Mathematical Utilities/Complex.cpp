#include <iostream>
#include <stdexcept>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex() : real(0), imag(0) {} // Default constructor
    Complex(double r, double i) : real(r), imag(i) {} // Parameterized constructor
    Complex(const Complex &other) : real(other.real), imag(other.imag) {} // Copy constructor

    // Accessor methods
    double getReal() const { return real; }
    double getImaginary() const { return imag; }

    // Exception handling for division by zero
    class DivisionByZeroException : public std::runtime_error {
    public:
        DivisionByZeroException() : std::runtime_error("Division by zero!") {}
    };

    // Operator overloading
    // Overloading assignment operator
    Complex& operator=(const Complex& other) {
        if (this == &other) return *this; // Self-assignment check
        real = other.real;
        imag = other.imag;
        return *this;
    }

    // Addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                             real * other.imag + imag * other.real);
    }

    // Division
    Complex operator/(const Complex& other) const {
        if (other.real == 0 && other.imag == 0) {
            throw DivisionByZeroException(); // Handle division by zero
        }
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                             (imag * other.real - real * other.imag) / denominator);
    }

    // Unary minus operator
    Complex operator-() const {
        return Complex(-real, -imag);
    }

    // Equality check
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Inequality check
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overload insertion operator for output
    friend std::ostream& operator<<(std::ostream& os, const Complex& num) {
        os << num.real << " + " << num.imag << "i";
        return os;
    }

    // Overload extraction operator for input
    friend std::istream& operator>>(std::istream& is, Complex& num) {
        std::cout << "Enter real part: ";
        is >> num.real;
        std::cout << "Enter imaginary part: ";
        is >> num.imag;
        return is;
    }

    // Get modulus (magnitude) of the complex number
    double modulus() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Get argument (phase angle) of the complex number
    double argument() const {
        return std::atan2(imag, real);
    }

    // Conjugate of the complex number
    Complex conjugate() const {
        return Complex(real, -imag);
    }
};

// Main function for testing the Complex class
int main() {
    try {
        Complex num1(3, 4);
        Complex num2(1, 2);

        std::cout << "Num1: " << num1 << std::endl;
        std::cout << "Num2: " << num2 << std::endl;

        // Addition
        Complex sum = num1 + num2;
        std::cout << "Sum: " << sum << std::endl;

        // Subtraction
        Complex diff = num1 - num2;
        std::cout << "Difference: " << diff << std::endl;

        // Multiplication
        Complex prod = num1 * num2;
        std::cout << "Product: " << prod << std::endl;

        // Division
        Complex div = num1 / num2;
        std::cout << "Division: " << div << std::endl;

        // Modulus
        std::cout << "Modulus of Num1: " << num1.modulus() << std::endl;

        // Argument
        std::cout << "Argument of Num1: " << num1.argument() << std::endl;

        // Conjugate
        Complex conj = num1.conjugate();
        std::cout << "Conjugate of Num1: " << conj << std::endl;

        // Input Complex Number
        Complex num3;
        std::cin >> num3;
        std::cout << "You entered: " << num3 << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
