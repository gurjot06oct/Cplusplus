// Recursion in C++ is a powerful technique where a function calls itself either directly or indirectly to solve a problem. Recursion offers an elegant solution to certain types of problems, especially those with a hierarchical structure or can be broken down into smaller subproblems of the same type. Here's a detailed explanation of recursion in C++, covering its advanced aspects:

// Basic Structure:
// The structure of a recursive function typically consists of two parts:
// - **Base Case**: A terminating condition that stops the recursion. Without this, the function would call itself infinitely, leading to stack overflow.
// - **Recursive Case**: A section of code where the function calls itself with modified arguments, moving closer to the base case.
#include <iostream>
using namespace std;
int factorial(int n)
{
    // Base case
    if (n <= 1)
    {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}