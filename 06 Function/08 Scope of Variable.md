## Scope of Variable

### 1. Global Scope

```cpp
int globalVar = 1;
```

- `globalVar` is defined outside any function or namespace, making it accessible from anywhere in the program.

### 2. Namespace Scope

```cpp
namespace MyNamespace
{
    int namespaceVar = 2;

    void namespaceFunction()
    {
        int localVar = 3;
        std::cout << "Local variable inside namespaceFunction: " << localVar << std::endl;
        std::cout << "Namespace variable inside namespaceFunction: " << namespaceVar << std::endl;
        std::cout << "Global variable inside namespaceFunction: " << globalVar << std::endl;
    }
}
```

- `namespaceVar` is defined within `MyNamespace`, making it accessible only within this namespace.
- `namespaceFunction` is also within `MyNamespace`. Inside this function:
  - `localVar` is defined and is only accessible within `namespaceFunction`.
  - `namespaceVar` and `globalVar` are accessed from their respective scopes.

### 3. Function Scope

```cpp
void functionScopeExample()
{
    int functionVar = 4;

    if (true)
    {
        int blockVar = 5;
        std::cout << "Block variable inside if block: " << blockVar << std::endl;
        std::cout << "Function variable inside if block: " << functionVar << std::endl;
        std::cout << "Global variable inside if block: " << globalVar << std::endl;
    }
    std::cout << "Function variable after if block: " << functionVar << std::endl;
}
```

- `functionVar` is defined within `functionScopeExample`, making it accessible throughout this function.
- Inside the `if` block:
  - `blockVar` is defined and is only accessible within this block.
  - `functionVar` and `globalVar` are accessed from their respective scopes.
- After the `if` block, `blockVar` is out of scope and cannot be accessed.

### 4. Main Function

```cpp
int main()
{
    std::cout << "Global variable in main: " << globalVar << std::endl;
    std::cout << "Namespace variable in main: " << MyNamespace::namespaceVar << std::endl;

    MyNamespace::namespaceFunction();
    functionScopeExample();

    return 0;
}
```

- The `main` function demonstrates access to the global and namespace variables.
- It calls `MyNamespace::namespaceFunction()` and `functionScopeExample()`, which in turn demonstrate access to their own local variables and variables from broader scopes.

### Output Explanation

The output of this program will be:

```
Global variable in main: 1
Namespace variable in main: 2
Local variable inside namespaceFunction: 3
Namespace variable inside namespaceFunction: 2
Global variable inside namespaceFunction: 1
Block variable inside if block: 5
Function variable inside if block: 4
Global variable inside if block: 1
Function variable after if block: 4
```

- The values of the variables are printed according to their scopes, demonstrating which variables are accessible at different points in the program.
