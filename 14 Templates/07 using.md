### Using Keyword

**Introduction:**

In C++, the `using` keyword serves as a tool for managing namespaces, improving code readability, and avoiding repetitive typing. It allows developers to specify the use of particular namespaces, classes, or functions within their code.

### Basic Usage of `using` Keyword

The `using` keyword can be employed in several ways:

1. **Using for Namespaces:**

   - Allows specifying a namespace to avoid fully qualifying names.

   ```cpp
   #include <iostream>
   using namespace std;

   int main() {
       cout << "Hello, world!";
       return 0;
   }
   ```

   Output:

   ```
   Hello, world!
   ```

2. **Using for Inheritance:**

   - Specifies inheritance from a base class to avoid repetitive typing.

   ```cpp
   #include <iostream>
   using namespace std;

   class Base {
   public:
       int x;
       Base(int a) : x(a) {}
   };

   class Derived : public Base {
   public:
       int y;
       using Base::Base; // Inherit Base's constructor
   };

   int main() {
       Derived d(42);
       d.y = 12;
       cout << d.x << " " << d.y << '\n';
       return 0;
   }
   ```

   Output:

   ```
   42 12
   ```

3. **Using for Aliasing:**

   - Provides an alias for types to simplify their usage.

   ```cpp
   #include <iostream>
   using namespace std;

   using ll = long long; // Alias for long long

   int main() {
       ll a = 5;
       cout << a;
       return 0;
   }
   ```

   Output:

   ```
   5
   ```

4. **Using for Directives:**

   - Directs the compiler to include specific names from a namespace.

   ```cpp
   #include <iostream>
   using std::cout;
   using std::endl;

   int main() {
       cout << "Hello, world!" << endl;
       return 0;
   }
   ```

   Output:

   ```
   Hello, world!
   ```

### Forms of `using` Keyword

- `using namespace std;`: Brings all symbols from the `std` namespace into the current scope.
- `using std::cout;` or `using std::cin;`: Introduces specific symbols like `cout` or `cin` from the `std` namespace.
- `using std::endl;`: Makes only the `endl` symbol available in the current scope.

### Limitations and Best Practices

- The `using` keyword should be used judiciously to prevent name clashes, especially in large codebases.
- Avoid using `using namespace` for entire libraries or global scopes to maintain code clarity and prevent unintended symbol collisions.
- Prefer explicit qualification (`namespace::symbol`) to ensure code clarity and avoid ambiguity.
