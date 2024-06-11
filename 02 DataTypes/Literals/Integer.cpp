#include <iostream>

int main()
{
    // Decimal literals
    short decimal_short = 42;
    unsigned short u_decimal_short = 42U;
    int decimal = 42;
    unsigned int u_decimal = 42u;
    long decimal_long = 42L;
    unsigned long u_decimal_long = 42UL;
    long long decimal_llong = 42LL;
    unsigned long long u_decimal_llong = 42ULL;

    // Octal literals
    short octal_short = 052;
    unsigned short u_octal_short = 052u;
    int octal = 052;
    unsigned int u_octal = 052u;
    long octal_long = 052L;
    unsigned long u_octal_long = 052UL;
    long long octal_llong = 052LL;
    unsigned long long u_octal_llong = 052ULL;

    // Hexadecimal literals
    short hex_short = 0x2A;
    unsigned short u_hex_short = 0x2Au;
    int hex = 0x2A;
    unsigned int u_hex = 0x2Au;
    long hex_long = 0x2AL;
    unsigned long u_hex_long = 0x2AUL;
    long long hex_llong = 0x2ALL;
    unsigned long long u_hex_llong = 0x2AULL;

    // Binary literals (C++14 and later)
    short binary_short = 0b101010;
    unsigned short u_binary_short = 0b101010u;
    int binary = 0b101010;
    unsigned int u_binary = 0b101010u;
    long binary_long = 0b101010L;
    unsigned long u_binary_long = 0b101010UL;
    long long binary_llong = 0b101010LL;
    unsigned long long u_binary_llong = 0b101010ULL;

    // Print all literals
    std::cout << "Decimal Literals:\n";
    std::cout << "short: " << decimal_short << ", unsigned short: " << u_decimal_short << "\n";
    std::cout << "int: " << decimal << ", unsigned int: " << u_decimal << "\n";
    std::cout << "long: " << decimal_long << ", unsigned long: " << u_decimal_long << "\n";
    std::cout << "long long: " << decimal_llong << ", unsigned long long: " << u_decimal_llong << "\n";

    std::cout << "\nOctal Literals:\n";
    std::cout << "short: " << octal_short << ", unsigned short: " << u_octal_short << "\n";
    std::cout << "int: " << octal << ", unsigned int: " << u_octal << "\n";
    std::cout << "long: " << octal_long << ", unsigned long: " << u_octal_long << "\n";
    std::cout << "long long: " << octal_llong << ", unsigned long long: " << u_octal_llong << "\n";

    std::cout << "\nHexadecimal Literals:\n";
    std::cout << "short: " << hex_short << ", unsigned short: " << u_hex_short << "\n";
    std::cout << "int: " << hex << ", unsigned int: " << u_hex << "\n";
    std::cout << "long: " << hex_long << ", unsigned long: " << u_hex_long << "\n";
    std::cout << "long long: " << hex_llong << ", unsigned long long: " << u_hex_llong << "\n";

    std::cout << "\nBinary Literals:\n";
    std::cout << "short: " << binary_short << ", unsigned short: " << u_binary_short << "\n";
    std::cout << "int: " << binary << ", unsigned int: " << u_binary << "\n";
    std::cout << "long: " << binary_long << ", unsigned long: " << u_binary_long << "\n";
    std::cout << "long long: " << binary_llong << ", unsigned long long: " << u_binary_llong << "\n";

    return 0;
}
