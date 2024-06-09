// Macro Concatenation
// Macros can be used to concatenate tokens, which can be useful in various metaprogramming scenarios.
#define CONCAT(a, b) a##b

// Stringification
// Stringification allows converting a macro argument into a string literal.
#define TO_STRING(x) #x

int main()
{
    int xy = 10;
    int value = CONCAT(x, y); // value is 10

    const char *str = TO_STRING(Hello World !); // str is "Hello World!"
    return 0;
}