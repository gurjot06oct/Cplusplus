// Conditional Compilation
// Macros can control the compilation of code depending on certain conditions, which is particularly useful for platform-specific code.

#include <iostream>
#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM "Windows"
#elif defined(__linux__)
#define PLATFORM "Linux"
#elif defined(__APPLE__)
#define PLATFORM "MacOS"
#else
#define PLATFORM "Unknown"
#endif

// Variadic Macros
// Variadic macros can accept a variable number of arguments, which is useful for functions with flexible arguments.
#define PRINTF(format, ...) printf(format, __VA_ARGS__)

// Recursive Macros and Macro Utilities
// Complex metaprogramming can be achieved by using recursive macros and utility macros for iteration and conditional logic.
#define REPEAT_0(M, ...)
#define REPEAT_1(M, ...) M(1) REPEAT_0(M, __VA_ARGS__)
#define REPEAT_2(M, ...) M(2) REPEAT_1(M, __VA_ARGS__)
#define REPEAT_3(M, ...) M(3) REPEAT_2(M, __VA_ARGS__)

#define REPEAT(N, M, ...) REPEAT_##N(M, __VA_ARGS__)

#define PRINT_NUMBER(N) printf("Number: %d\n", N);

int main()
{
    const char *platform = PLATFORM;
    std::cout << platform << std::endl;

    PRINTF("Hello %s, your age is %d\n", "Alice", 30);

    REPEAT(3, PRINT_NUMBER);
    return 0;
}
