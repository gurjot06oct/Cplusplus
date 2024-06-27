## Templates

**Overview:**
Templates are a powerful feature in C++ that allow us to write generic functions and classes capable of working with any data type. This avoids the need for duplicating code for different data types.

**How Templates Work:**
Templates are expanded at compile time, similar to macros, but with type-checking. This means that from a single template definition, the compiler can generate multiple versions of a function or class tailored to different data types.

## Function templates

Function templates in C++ are a powerful feature that allows you to write functions that can operate on different data types without having to rewrite the function for each type. Here's a detailed exploration of function templates:

- ### **Syntax and Declaration**

  A function template is declared using the `template` keyword followed by a template parameter list, and then the function signature. The syntax generally looks like this:

  ```cpp
  template <typename T>
  void myFunction(T param) {
      // Function implementation
  }
  ```

  - `template <typename T>` declares a template parameter `T`, which can represent any data type.
  - `T` here acts as a placeholder for the actual type that will be substituted when the function is instantiated with a specific type.

- ### **Instantiation**

  Function templates are not actual functions themselves but serve as blueprints. They are instantiated when used with specific types. For example:

  ```cpp
  myFunction<int>(5);     // Instantiates myFunction with T = int
  myFunction<double>(3.14);   // Instantiates myFunction with T = double
  ```

- ### **Template Argument Deduction**

  In many cases, the compiler can deduce the template arguments automatically from the function arguments. This is called template argument deduction. For example:

  ```cpp
  template <typename T>
  void print(T value) {
      std::cout << value << std::endl;
  }

  print(42);         // Deduces T as int
  print(3.14);       // Deduces T as double
  print("Hello");    // Deduces T as const char*
  ```

## Class Templates

Class templates in C++ are powerful tools for creating generic classes that can work with different data types. They allow you to define a blueprint for a class where one or more types are parameters. Here’s a detailed exploration of class templates:

- ### **Syntax and Declaration**

  Class templates are declared using the `template` keyword followed by a template parameter list enclosed in angle brackets (`<>`). Here’s a basic syntax example:

  ```cpp
  template <typename T>
  class MyContainer {
  public:
      MyContainer();  // Constructor
      void insert(const T& value);
      T get(int index) const;
  private:
      T array[100];
      int size;
  };
  ```

  - `template <typename T>` declares a class template where `T` is a type parameter.
  - Inside the class template, `T` can be used to define member variables, member functions, and nested types.

- ### **Instantiation**

  Class templates are not actual classes but serve as blueprints. They are instantiated with specific types when objects of that type are created. For example:

  ```cpp
  MyContainer<int> intContainer;
  MyContainer<double> doubleContainer;
  ```

  - Here, `MyContainer<int>` and `MyContainer<double>` are instantiations of the `MyContainer` class template with `T` replaced by `int` and `double`, respectively.

- ### **Member Functions**

  Member functions of class templates are defined similarly to regular member functions but can utilize the template parameter `T`. For example:

  ```cpp
  template <typename T>
  void MyContainer<T>::insert(const T& value) {
      array[size++] = value;
  }

  template <typename T>
  T MyContainer<T>::get(int index) const {
      return array[index];
  }
  ```

  - `MyContainer<T>::insert` and `MyContainer<T>::get` are member function templates that operate on elements of type `T`.

- ### **Static Data Members**

  Static data members of class templates are shared among all instances of the template instantiation. They are declared and defined outside the class template definition. For example:

  ```cpp
  template <typename T>
  class MyContainer {
  public:
      static int count; // Declaration
  };

  template <typename T>
  int MyContainer<T>::count = 0; // Definition
  ```

  - `MyContainer<int>::count` and `MyContainer<double>::count` refer to the same static member across different instantiations of `MyContainer`.

- ### **Member Templates**

  Member templates are member functions of a class template that themselves are templates. They allow the function to operate on different types or accept non-type template parameters. For example:

  ```cpp
  template <typename T>
  class MyContainer {
  public:
      template <typename U>
      void insert(const U& value) {
          // Implementation
      }
  };
  ```

  - `MyContainer<T>::insert<U>` is a member function template that can be called with any type `U` as an argument.

- ### **Inheritance with Class Templates**

  Class templates can participate in inheritance hierarchies. Derived classes can inherit from class templates, and derived class templates can inherit from base class templates. For example:

  ```cpp
  template <typename T>
  class Base {
      // Base class template
  };

  template <typename T>
  class Derived : public Base<T> {
      // Derived class template
  };
  ```

## Template Specialization:

Primary Template is the generic template that serves as a blueprint for the compiler. It provides a general implementation that can be used for any type or value. It can be further customized using these specializations.

1. **Full Specialization**: Providing a specialized implementation of a template for a specific data type or set of types.
2. **Partial Specialization**: Specifying a specialized implementation of a template for a subset of possible template arguments.
3. **Variadic Specialization**: Specifying a specialized implementation of a template that can accept a variable number of arguments of different types.

## **Type Traits and SFINAE**

Type traits are often used with class templates to provide compile-time information about types. They are essential in template metaprogramming for conditional compilation based on type properties. Substitution Failure Is Not An Error (SFINAE) principle applies to function templates. This means that if a substitution of template arguments fails during instantiation, it doesn't result in a compilation error unless the template instantiation is actually used.

## **Template and Overloading**

Function templates can participate in function overloading. When a function template and a non-template function match equally well for a given function call, the non-template function is preferred.

Function templates in C++ are fundamental for generic programming and allow for flexible and reusable code that operates seamlessly across different types. Understanding these aspects helps in effectively leveraging the power of templates in C++ development.
