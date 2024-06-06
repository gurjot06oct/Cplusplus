#include <iostream>

int main()
{

    unsigned short int usi = -1;      // 16 bits, Range: 0 to 65535
    unsigned int ui = -1;             // 32 bits, Range: 0 to 4294967295
    unsigned long int uli = -1;       // 32 bits, Range: 0 to 4294967295 (may be 18446744073709551615 on some systems)
    unsigned long long int ulli = -1; // 64 bits, Range: 0 to 18446744073709551615

    std::cout << "unsigned short int (-1): " << usi << std::endl;
    std::cout << "unsigned int (-1): " << ui << std::endl;
    std::cout << "unsigned long int (-1): " << uli << std::endl;
    std::cout << "unsigned long long int (-1): " << ulli << std::endl;

    return 0;
}
