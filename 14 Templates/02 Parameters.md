## Template Parameters

Template parameters in C++ are the fundamental building blocks that enable the creation of generic classes and functions. They allow you to define templates that can work with different types or values without having to rewrite the code for each specific type or value. Here's a detailed exploration of template parameters:

### 1. **Types of Template Parameters**

Template parameters in C++ can broadly be categorized into three types:

- **Type Parameters**: These represent types and are declared using `typename` or `class` keywords.

  ```cpp
  template <typename T>
  void print(T value) {
      std::cout << value << std::endl;
  }
  ```

  - `T` in this example is a type parameter that can be substituted with any type when the function template `print` is instantiated.

- **Non-type Parameters**: These are constants of integral or enumeration types that can be used as template arguments.

  ```cpp
  template <int N>
  void printNTimes(const std::string& str) {
      for (int i = 0; i < N; ++i) {
          std::cout << str << std::endl;
      }
  }
  ```

  - `N` in this example is a non-type parameter of type `int`, specifying how many times to print the string.

- **Template Template Parameters**: These are templates that themselves take other templates as arguments.

  ```cpp
  template <template <typename> class Container, typename T>
  void printContainer(const Container<T>& cont) {
      for (const auto& elem : cont) {
          std::cout << elem << " ";
      }
      std::cout << std::endl;
  }
  ```

  - `Container` in this example is a template template parameter that accepts a template class (`std::vector`, `std::list`, etc.) which itself takes a single type argument (`T`).

### 2. **Syntax and Usage**

Template parameters are declared within the angle brackets (`<>`) following the `template` keyword before the function or class declaration. They can be used in function templates, class templates, and member functions of class templates.

### 3. **Default Template Arguments**

You can specify default values for template parameters, which are used when the template is instantiated without providing a specific argument for that parameter. For example:

```cpp
template <typename T = int>
void print(T value) {
    std::cout << value << std::endl;
}
```
