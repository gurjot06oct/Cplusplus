#include <iostream>

extern int count; // declaration of the same global variable defined in file1.cpp

void modify()
{
    count = 20; // modify the global variable
    std::cout << "Count in file2.cpp: " << count << std::endl;
}
