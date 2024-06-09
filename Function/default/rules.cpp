#include <iostream>

// void example(int a, int b = 5, int c) {} // Invalid: Default argument missing for parameter 'c'
void example(int a, int b = 5, int c = 10) {} // Valid
// void example(int a = 0, int b, int c) {} // Invalid: Default argument missing for parameter 'b' and 'c'

int main()
{
    return 0;
}