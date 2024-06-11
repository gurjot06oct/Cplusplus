#include <iostream>

int main()
{
    // Normal variables are signed by default
    short int si = 32767;                // 16 bits, Range: -32768 to 32767
    int i = 2147483649;                  // 32 bits, Range: -2147483648 to 2147483647
    long li = -2147483647;               // 32 bits or 64 bits, Range: -2147483648 to 2147483647 (32 bits) or wider range for 64 bits
    long long lli = 9223372036854775807; // 64 bits, Range: -9223372036854775808 to 9223372036854775807

    std::cout << "short int (-2): " << si << std::endl;
    std::cout << "int (-2): " << i << std::endl;
    std::cout << "long int (-2): " << li << std::endl;
    std::cout << "long long int (-2): " << lli << std::endl;

    return 0;
}
