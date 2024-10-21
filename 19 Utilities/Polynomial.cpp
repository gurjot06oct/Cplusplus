#include <iostream>
#include <map>
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iomanip>

class Polynomial {
private:
    // Using a map to store the coefficients, where the key is the exponent and the value is the coefficient.
    std::map<int, double> terms; // Example: 3x^2 + 4x + 5 will be stored as {{2, 3}, {1, 4}, {0, 5}}

public:
    // Constructors
    Polynomial() = default;

    // Construct polynomial from a vector of coefficients (e.g., {5, 4, 3} -> 3x^2 + 4x + 5)
    Polynomial(const std::initializer_list<double>& coeffs) {
        int exp = 0;
        for (double coeff : coeffs) {
            if (coeff != 0) {
                terms[exp] = coeff;
            }
            ++exp;
        }
    }

    // Copy constructor
    Polynomial(const Polynomial& other) : terms(other.terms) {}

    // Move constructor
    Polynomial(Polynomial&& other) noexcept : terms(std::move(other.terms)) {}

    // Copy assignment
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            terms = other.terms;
        }
        return *this;
    }

    // Move assignment
    Polynomial& operator=(Polynomial&& other) noexcept {
        if (this != &other) {
            terms = std::move(other.terms);
        }
        return *this;
    }

    // Get degree of the polynomial (highest exponent)
    int degree() const {
        if (terms.empty()) return -1; // Degree of the zero polynomial is conventionally -1
        return terms.rbegin()->first; // Highest exponent
    }

    // Access coefficient of a specific term (const)
    double operator[](int exp) const {
        auto it = terms.find(exp);
        return (it != terms.end()) ? it->second : 0.0;
    }

    // Access coefficient of a specific term (non-const)
    double& operator[](int exp) {
        return terms[exp];
    }

    // Evaluate the polynomial at a given value of x
    double evaluate(double x) const {
        double result = 0.0;
        for (const auto& [exp, coeff] : terms) {
            result += coeff * std::pow(x, exp);
        }
        return result;
    }

    // Derivative of the polynomial
    Polynomial derivative() const {
        Polynomial result;
        for (const auto& [exp, coeff] : terms) {
            if (exp > 0) {
                result.terms[exp - 1] = coeff * exp;
            }
        }
        return result;
    }

    // Indefinite integral of the polynomial (assumes constant of integration is 0)
    Polynomial integral() const {
        Polynomial result;
        for (const auto& [exp, coeff] : terms) {
            result.terms[exp + 1] = coeff / (exp + 1);
        }
        return result;
    }

    // Normalize the polynomial (remove zero terms)
    void normalize() {
        for (auto it = terms.begin(); it != terms.end();) {
            if (std::abs(it->second) < 1e-9) {
                it = terms.erase(it);
            } else {
                ++it;
            }
        }
    }

    // Overloaded Operators for Polynomial Arithmetic

    // Addition
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result(*this);
        for (const auto& [exp, coeff] : other.terms) {
            result[exp] += coeff;
        }
        result.normalize();
        return result;
    }

    // Subtraction
    Polynomial operator-(const Polynomial& other) const {
        Polynomial result(*this);
        for (const auto& [exp, coeff] : other.terms) {
            result[exp] -= coeff;
        }
        result.normalize();
        return result;
    }

    // Multiplication by another polynomial
    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (const auto& [exp1, coeff1] : terms) {
            for (const auto& [exp2, coeff2] : other.terms) {
                result[exp1 + exp2] += coeff1 * coeff2;
            }
        }
        result.normalize();
        return result;
    }

    // Scalar multiplication
    Polynomial operator*(double scalar) const {
        Polynomial result;
        for (const auto& [exp, coeff] : terms) {
            result[exp] = coeff * scalar;
        }
        result.normalize();
        return result;
    }

    // Comparison operators
    bool operator==(const Polynomial& other) const {
        return terms == other.terms;
    }

    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }

    // Output stream (printing)
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        bool first = true;
        for (auto it = poly.terms.rbegin(); it != poly.terms.rend(); ++it) {
            if (!first && it->second > 0) os << " + ";
            if (it->second < 0) os << " - ";
            if (std::abs(it->second) != 1 || it->first == 0) os << std::abs(it->second);
            if (it->first != 0) os << "x";
            if (it->first > 1) os << "^" << it->first;
            first = false;
        }
        return os;
    }

    // Input stream (reading a polynomial)
    friend std::istream& operator>>(std::istream& is, Polynomial& poly) {
        std::string input;
        std::getline(is, input);
        std::istringstream ss(input);

        double coeff;
        int exp;
        char x, caret;
        while (ss >> coeff) {
            if (ss >> x >> caret >> exp) {
                poly[exp] = coeff;
            } else {
                poly[0] = coeff;
            }
        }
        return is;
    }
};

// Example usage:
int main() {
    Polynomial p1 = {3, 0, -4}; // 3 - 4x^2
    Polynomial p2 = {1, 2};     // 1 + 2x

    Polynomial p3 = p1 + p2;    // Polynomial addition
    Polynomial p4 = p1 * p2;    // Polynomial multiplication

    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "p1 + p2: " << p3 << "\n";
    std::cout << "p1 * p2: " << p4 << "\n";

    std::cout << "p1 evaluated at x = 2: " << p1.evaluate(2) << "\n";
    std::cout << "Derivative of p1: " << p1.derivative() << "\n";
    std::cout << "Integral of p1: " << p1.integral() << "\n";

    return 0;
}
