#include <iostream>

int main()
{
    bool isTrue = true;   // true == 1
    bool isFalse = false; // false == 0

    bool result1 = 5 == isTrue;
    std::cout << "5 == isTrue is " << result1 << std::endl; // Output: 0 (false)

    bool result2 = 5 == isFalse;
    std::cout << "5 == isFalse is " << result2 << std::endl; // Output: 0 (false)

    return 0;
}
