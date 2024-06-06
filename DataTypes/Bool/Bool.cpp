#include <iostream>

int main()
{
    // Declaration and initialization of bool variables
    bool isTrue = true;
    bool isFalse = false;

    // Outputting bool variables
    std::cout << "isTrue: " << isTrue << std::endl;   // Output: 1 (true)
    std::cout << "isFalse: " << isFalse << std::endl; // Output: 0 (false)

    // Size of bool data type
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl; // Output: 1 byte

    // Logical operations with bool
    bool result = (3 > 2);                           // Comparison operation
    std::cout << "3 > 2 is " << result << std::endl; // Output: 1 (true)

    // Logical NOT operator (!)
    bool notResult = !isTrue;
    std::cout << "Logical NOT of isTrue: " << notResult << std::endl; // Output: 0 (false)

    // Logical AND operator (&&)
    bool andResult = isTrue && isFalse;
    std::cout << "Logical AND of isTrue and isFalse: " << andResult << std::endl; // Output: 0 (false)

    // Logical OR operator (||)
    bool orResult = isTrue || isFalse;
    std::cout << "Logical OR of isTrue and isFalse: " << orResult << std::endl; // Output: 1 (true)

    return 0;
}
