#include <iostream>
#include <string>

int main()
{
    int choice = 2;
    int outerChoice = 1;
    int innerChoice = 2;
    char color = 'g';

    // Basic switch statement
    switch (choice)
    {
    case 1:
        std::cout << "You chose option 1" << std::endl;
        break;
    case 2:
        std::cout << "You chose option 2" << std::endl;
        break;
    case 3:
        std::cout << "You chose option 3" << std::endl;
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
    }

    // Switch statement with multiple cases and fall-through
    switch (choice)
    {
    case 1:
    case 2:
        std::cout << "You chose either option 1 or 2" << std::endl;
        // No break statement, fall through to the next case
    case 3:
        std::cout << "You chose option 3" << std::endl;
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
    }

    // Switch statement with nested switch
    switch (outerChoice)
    {
    case 1:
        switch (innerChoice)
        {
        case 1:
            std::cout << "Outer choice is 1, Inner choice is 1" << std::endl;
            break;
        case 2:
            std::cout << "Outer choice is 1, Inner choice is 2" << std::endl;
            break;
        default:
            std::cout << "Outer choice is 1, Invalid inner choice" << std::endl;
        }
        break;
    case 2:
        std::cout << "Outer choice is 2" << std::endl;
        break;
    default:
        std::cout << "Invalid outer choice" << std::endl;
    }

    // Switch statement with string expression (requires C++17 or later)
    switch (color)
    {
    case 'r':
        std::cout << "The color is red" << std::endl;
        break;
    case 'g':
        std::cout << "The color is green" << std::endl;
        break;
    default:
        std::cout << "The color is not red or green" << std::endl;
    }

    return 0;
}
