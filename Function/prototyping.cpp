#include <iostream>

// Function Declaration (Prototyping)
bool even(int);

// Function definition: Checks if a number is odd
bool odd(int n)
{
    if (n == 0)
        return false; // Base case: 0 is not odd
    else
        return even(n - 1); // Recursively call 'even' function
}

// Function definition: Checks if a number is even
bool even(int n)
{
    if (n == 0)
        return true; // Base case: 0 is even
    else
        return odd(n - 1); // Recursively call 'odd' function
}

int main()
{
    int number = 5;

    // Calling the 'even' function
    if (even(number))
        std::cout << number << " is even." << std::endl;
    else
        std::cout << number << " is odd." << std::endl;

    return 0;
}
