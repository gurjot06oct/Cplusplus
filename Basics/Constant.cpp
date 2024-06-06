#include <iostream>

// Define constants using 'const' keyword
const int MAX_STUDENTS = 50;
const float PI = 3.14159;
const std::string GREETING = "Hello, world!";

int main()
{
    // Using constants
    int students[MAX_STUDENTS];         // Array with a constant size
    float circleArea = PI * 5 * 5;      // Calculating circle area using PI
    std::cout << GREETING << std::endl; // Outputting a greeting message

    // Attempting to modify a constant (will result in a compilation error)
    // MAX_STUDENTS = 60;

    return 0;
}
