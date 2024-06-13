#include <iostream>
#include <limits>
#include <climits>

int main()
{
    // ## signed
    // Normal variables are signed by default
    short int si = 32767;                // 16 bits, Range: -32768 to 32767
    int i = 2147483649;                  // 32 bits, Range: -2147483648 to 2147483647
    long li = -2147483647;               // 32 bits or 64 bits, Range: -2147483648 to 2147483647 (32 bits) or wider range for 64 bits
    long long lli = 9223372036854775807; // 64 bits, Range: -9223372036854775808 to 9223372036854775807

    std::cout << "short int (-2): " << si << std::endl;
    std::cout << "int (-2): " << i << std::endl;
    std::cout << "long int (-2): " << li << std::endl;
    std::cout << "long long int (-2): " << lli << std::endl;

    // ## unsigned
    unsigned short int usi = -1;      // 16 bits, Range: 0 to 65535
    unsigned int ui = -1;             // 32 bits, Range: 0 to 4294967295
    unsigned long int uli = -1;       // 32 bits, Range: 0 to 4294967295 (may be 18446744073709551615 on some systems)
    unsigned long long int ulli = -1; // 64 bits, Range: 0 to 18446744073709551615

    std::cout << "unsigned short int (-1): " << usi << std::endl;
    std::cout << "unsigned int (-1): " << ui << std::endl;
    std::cout << "unsigned long int (-1): " << uli << std::endl;
    std::cout << "unsigned long long int (-1): " << ulli << std::endl;

    // Test the macros for signed types
    std::cout << "Minimum value of signed short: " << std::numeric_limits<short>::min() << std::endl;
    std::cout << "Maximum value of signed short: " << std::numeric_limits<short>::max() << std::endl;

    std::cout << "Minimum value of signed int: " << INT_MIN << std::endl;
    std::cout << "Maximum value of signed int: " << INT_MAX << std::endl;

    std::cout << "Minimum value of signed long: " << LONG_MIN << std::endl;
    std::cout << "Maximum value of signed long: " << LONG_MAX << std::endl;

    std::cout << "Minimum value of signed long long: " << LLONG_MIN << std::endl;
    std::cout << "Maximum value of signed long long: " << LLONG_MAX << std::endl;

    // Test the macros for unsigned types
    std::cout << "Maximum value of unsigned short: " << std::numeric_limits<unsigned short>::min() << std::endl;
    std::cout << "Maximum value of unsigned int: " << UINT_MAX << std::endl;
    std::cout << "Maximum value of unsigned long: " << ULONG_MAX << std::endl;
    std::cout << "Maximum value of unsigned long long: " << ULLONG_MAX << std::endl;

    return 0;
}
