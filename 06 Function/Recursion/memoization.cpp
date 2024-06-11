// Memoization:
// Memoization is a technique to improve the efficiency of recursive algorithms by storing the results of expensive function calls and reusing them when the same inputs occur again.

#include <iostream>
#include <unordered_map>

using namespace std;
std::unordered_map<int, int> memo;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}