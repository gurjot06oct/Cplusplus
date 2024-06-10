#include <string>
#include <vector>
// The `typedef` keyword in C++ is used to create an alias for a data type. It allows you to define a new name for an existing data type, which can be particularly useful for simplifying complex type declarations, enhancing code readability, and making code more maintainable.

// typedef existing_data_type new_name;

// Now, wherever you would use `int`, you can use `myInt` instead:
// myInt x = 5;

// Advanced Usage:

// 1. **Function Pointers:** `typedef` can be used to simplify the syntax of function pointers, especially for complex function signatures. For instance:

typedef void (*FuncPtr)(int, int);

// This creates an alias `FuncPtr` for a function pointer that points to a function taking two `int` arguments and returning `void`.

// 2. **Structures and Classes:** `typedef` can make complex structure or class declarations more readable. For instance:
typedef struct
{
    int age;
    std::string name;
} Person;

// This defines a type `Person` which represents a structure with an `age` field of type `int` and a `name` field of type `std::string`.

// 3. **Templates:** `typedef` can be used with templates to create more concise type names. For instance:
template <typename T>
using Vec = std::vector<T>;
// This creates an alias `Vec` for `std::vector<T>`, allowing you to use `Vec` instead of `std::vector` when declaring vectors of a specific type.

// 4. **Enumerations:** `typedef` can simplify the declaration of enumeration types. For example:
typedef enum
{
    RED,
    GREEN,
    BLUE
} Color;

// This creates an alias `Color` for an enumeration type containing three constants: `RED`, `GREEN`, and `BLUE`.
// In modern C++, the `using` keyword can also be used instead of `typedef`, especially for aliasing templates and function pointers, offering a more consistent syntax. For instance, the previous examples can also be written using `using`:

using FuncPtr_ = void (*)(int, int);
using Vec_ = std::vector<int>;
using Color_ = enum { RED_,
                      GREEN_,
                      BLUE_ };