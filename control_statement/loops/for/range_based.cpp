#include <iostream>
using namespace std;

// Range-Based `for` Loop (C++11 and later)

// C++11 introduced range-based `for` loops, which provide a more concise way to iterate over all the elements in a container (like arrays, vectors, etc.).

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    for (int value : arr)
    { // Range-based for loop
        cout << value << endl;
    }
    return 0;
}