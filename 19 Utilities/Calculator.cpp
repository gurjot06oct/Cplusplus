#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <cctype>
#include <regex>

class Calculator {
private:
    std::vector<double> previousResults;  // Stores previous results

    // Helper function to return precedence of operators
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    // Helper function to apply an operator to two numbers
    double applyOp(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (b == 0) throw std::runtime_error("Division by zero!");
                return a / b;
            case '^': return pow(a, b);
        }
        return 0;
    }

    // Function to check if a character is an operator
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

public:
    // Constructor
    Calculator() {}

    // Infix to Postfix conversion
    std::string infixToPostfix(const std::string& expression) {
        std::stack<char> operators;
        std::string output;

        for (size_t i = 0; i < expression.length(); ++i) {
            if (isdigit(expression[i]) || expression[i] == '.') {
                // Handle numbers (multiple digits or decimal numbers)
                while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                    output += expression[i++];
                }
                output += ' ';  // Separate numbers in the postfix expression
                --i;
            } else if (expression[i] == '(') {
                operators.push(expression[i]);
            } else if (expression[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    output += operators.top();
                    output += ' ';
                    operators.pop();
                }
                if (!operators.empty()) operators.pop();  // Remove '('
            } else if (isOperator(expression[i])) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                    output += operators.top();
                    output += ' ';
                    operators.pop();
                }
                operators.push(expression[i]);
            }
        }

        // Pop all remaining operators
        while (!operators.empty()) {
            output += operators.top();
            output += ' ';
            operators.pop();
        }

        return output;
    }

    // Function to evaluate a postfix expression
    double evaluatePostfix(const std::string& postfix) {
        std::stack<double> values;
        std::stringstream ss(postfix);
        std::string token;

        while (ss >> token) {
            if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-')) {
                // Token is a number
                values.push(std::stod(token));
            } else if (isOperator(token[0])) {
                // Token is an operator, pop two values and apply the operator
                if (values.size() < 2) throw std::runtime_error("Invalid expression");
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                values.push(applyOp(a, b, token[0]));
            }
        }

        if (values.size() != 1) throw std::runtime_error("Invalid expression");
        return values.top();
    }

    // Function to replace 'prev(index)' with the actual result value
    std::string replacePrevResults(std::string expression) {
        std::regex prevRegex("prev\\((\\d+)\\)");
        std::smatch match;

        // Loop through all matches of prev(index) and replace them
        while (std::regex_search(expression, match, prevRegex)) {
            int index = std::stoi(match[1].str()) - 1;  // Convert to zero-based index

            if (index >= 0 && index < previousResults.size()) {
                // Replace 'prev(index)' with the actual result value
                expression.replace(match.position(0), match.length(0), std::to_string(previousResults[index]));
            } else {
                throw std::out_of_range("Invalid 'prev(index)' value");
            }
        }

        return expression;
    }

    // Calculate an expression (infix form) and store the result
    double calculate(const std::string& expression) {
        std::string updatedExpression = replacePrevResults(expression);  // Replace prev(index) placeholders
        std::string postfix = infixToPostfix(updatedExpression);  // Convert to postfix
        double result = evaluatePostfix(postfix);  // Evaluate the postfix expression
        previousResults.push_back(result);  // Store the result for later use
        return result;
    }

    // Access previous result by index
    double getPreviousResult(size_t index) {
        if (index >= previousResults.size()) throw std::out_of_range("No previous result at this index");
        return previousResults[index];
    }

    // Print all previous results
    void printPreviousResults() const {
        if (previousResults.empty()) {
            std::cout << "No previous results available." << std::endl;
            return;
        }

        std::cout << "Previous results:" << std::endl;
        for (size_t i = 0; i < previousResults.size(); ++i) {
            std::cout << i + 1 << ": " << previousResults[i] << std::endl;
        }
    }
};

// Main function for testing the calculator
int main() {
    Calculator calc;
    std::string input;
    double result;

    while (true) {
        try {
            std::cout << "Enter an expression (or type 'prev' to see previous results, 'quit' to exit): ";
            std::getline(std::cin, input);

            if (input == "quit") break;
            if (input == "prev") {
                calc.printPreviousResults();
                continue;
            }

            // Calculate and output the result
            result = calc.calculate(input);
            std::cout << "Result: " << result << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
