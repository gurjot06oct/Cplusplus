// Tail Recursion Optimization:
// Tail recursion occurs when the recursive call is the last operation performed by the function before it returns. Some compilers optimize tail recursive functions into iterative form to avoid stack overflow.

#include <iostream>
using namespace std;

// (Not optimized)
int factorial(int n, int result = 1)
{
    if (n <= 1)
    {
        return result;
    }
    return factorial(n - 1, result * n);
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}