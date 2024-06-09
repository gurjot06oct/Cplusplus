#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    while (i < 10)
    {
        if (i == 5)
        {
            break; // Exit loop when i is 5
        }
        if (i % 2 == 0)
        {
            ++i;
            continue; // Skip even numbers
        }
        cout << "i = " << i << endl;
        ++i;
    }
    return 0;
}