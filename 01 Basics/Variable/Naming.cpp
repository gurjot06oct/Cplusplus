#include <iostream>

int main()
{
    // Valid variable names
    int age;
    float salary;
    double _grossIncome;
    char firstName;
    int numberOfStudents;

    // Invalid variable names
    // int 123abc;           // Invalid: starts with a digit
    // float salary#;        // Invalid: contains a special character
    // double gross-Income;  // Invalid: contains a hyphen
    // char first Name;      // Invalid: contains a space
    // int class;            // Invalid: 'class' is a reserved keyword

    // Use descriptive names
    int studentAge = 20;
    float grossSalary = 55000.75;
    double netIncome;
    char grade = 'A';
    int _counter = 0;

    // Display variable values
    std::cout << "Student Age: " << studentAge << std::endl;
    std::cout << "Gross Salary: " << grossSalary << std::endl;
    std::cout << "Grade: " << grade << std::endl;

    return 0;
}
