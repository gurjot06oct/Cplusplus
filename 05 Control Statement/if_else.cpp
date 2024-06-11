#include <iostream>

int main()
{
    int a = 15;

    // if statement
    if (a > 10)
    {
        std::cout << "a is greater than 10 (if statement)" << std::endl;
    }

    // if-else statement
    if (a > 20)
    {
        std::cout << "a is greater than 20 (if-else statement)" << std::endl;
    }
    else
    {
        std::cout << "a is not greater than 20 (if-else statement)" << std::endl;
    }

    // if-else if-else statement
    if (a > 30)
    {
        std::cout << "a is greater than 30 (if-else if-else statement)" << std::endl;
    }
    else if (a > 20)
    {
        std::cout << "a is greater than 20 but less than or equal to 30 (if-else if-else statement)" << std::endl;
    }
    else if (a > 10)
    {
        std::cout << "a is greater than 10 but less than or equal to 20 (if-else if-else statement)" << std::endl;
    }
    else
    {
        std::cout << "a is 10 or less (if-else if-else statement)" << std::endl;
    }

    // Nested if-else statement
    if (a > 10)
    {
        std::cout << "a is greater than 10 (nested if-else statement)" << std::endl;
        if (a > 20)
        {
            std::cout << "a is also greater than 20 (nested if-else statement)" << std::endl;
        }
        else
        {
            std::cout << "a is not greater than 20 (nested if-else statement)" << std::endl;
        }
    }
    else
    {
        std::cout << "a is 10 or less (nested if-else statement)" << std::endl;
        if (a < 5)
        {
            std::cout << "a is also less than 5 (nested if-else statement)" << std::endl;
        }
        else
        {
            std::cout << "a is between 5 and 10 (nested if-else statement)" << std::endl;
        }
    }

    return 0;
}
