#include <limits>

// Macros for signed types
#define SHORT_MIN std::numeric_limits<short>::min()
#define SHORT_MAX std::numeric_limits<short>::max()

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()

#define LONG_MIN std::numeric_limits<long>::min()
#define LONG_MAX std::numeric_limits<long>::max()

#define LLONG_MIN std::numeric_limits<long long>::min()
#define LLONG_MAX std::numeric_limits<long long>::max()

// Macros for unsigned types
#define USHORT_MAX std::numeric_limits<unsigned short>::max()
#define UINT_MAX std::numeric_limits<unsigned int>::max()
#define ULONG_MAX std::numeric_limits<unsigned long>::max()
#define ULLONG_MAX std::numeric_limits<unsigned long long>::max()

#include <iostream>

int main()
{
    // Test the macros for signed types
    std::cout << "Minimum value of signed short: " << SHORT_MIN << std::endl;
    std::cout << "Maximum value of signed short: " << SHORT_MAX << std::endl;

    std::cout << "Minimum value of signed int: " << INT_MIN << std::endl;
    std::cout << "Maximum value of signed int: " << INT_MAX << std::endl;

    std::cout << "Minimum value of signed long: " << LONG_MIN << std::endl;
    std::cout << "Maximum value of signed long: " << LONG_MAX << std::endl;

    std::cout << "Minimum value of signed long long: " << LLONG_MIN << std::endl;
    std::cout << "Maximum value of signed long long: " << LLONG_MAX << std::endl;

    // Test the macros for unsigned types
    std::cout << "Maximum value of unsigned short: " << USHORT_MAX << std::endl;
    std::cout << "Maximum value of unsigned int: " << UINT_MAX << std::endl;
    std::cout << "Maximum value of unsigned long: " << ULONG_MAX << std::endl;
    std::cout << "Maximum value of unsigned long long: " << ULLONG_MAX << std::endl;

    return 0;
}
