# Pointer to an object

```cpp
#include <iostream>

class MyClass {
public:
    void myFunction() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

int main() {
    MyClass obj;
    MyClass *ptr = &obj; // Pointer to MyClass object

    // Accessing member function using pointer
    ptr->myFunction();

    return 0;
}
```

In this example, `ptr` is a pointer to an object of type `MyClass`. To access the member function `myFunction()` through the pointer `ptr`, you use the arrow operator `->`. This operator dereferences the pointer and accesses the member function of the object it points to.

Remember that if `ptr` is a null pointer, trying to access a member function through it will result in undefined behavior, so always make sure your pointers are properly initialized before use.

## `this` Pointer

"this" is a special keyword that represents a pointer to the current object instance within a member function of a class. It's implicitly passed as a hidden argument to all member function calls.

Here's an example to illustrate its usage:

```cpp
#include <iostream>

class MyClass {
public:
    int x;

    MyClass(int x) {
        // "this" pointer is used to distinguish between the parameter x and the data member x
        this->x = x;
    }

    void printX() {
        std::cout << "The value of x is: " << this->x << std::endl;
    }

    void setX(int x) {
        // "this" pointer is optional here but can be used for clarity
        this->x = x;
    }
};

int main() {
    MyClass obj(5);
    obj.printX(); // Output: The value of x is: 5

    obj.setX(10);
    obj.printX(); // Output: The value of x is: 10

    return 0;
}
```

In the constructor `MyClass(int x)`, `this->x` is used to assign the value of the constructor parameter `x` to the data member `x`. This helps to distinguish between the parameter `x` and the data member `x`.

In the member function `printX()`, `this->x` is used to access the data member `x`.

In the member function `setX(int x)`, `this->x` is again used to assign the value of the parameter `x` to the data member `x`.

In this example, using `this` is optional, but it can improve code clarity, especially when there's ambiguity between class members and local variables or parameters.

### Chained function calls using `this`

Chained function calls using the `this` pointer are a convenient way to perform multiple operations on the same object in a single expression. Let's illustrate this concept with a simple example:

```cpp
#include <iostream>
using namespace std;

class MyClass {
private:
    int x;
public:
    MyClass(int x = 0) : x(x) {}

    MyClass& increment() {
        // Increment the value of x by 1
        ++this->x;
        // Return a reference to the calling object
        return *this;
    }

    MyClass& multiply(int factor) {
        // Multiply the value of x by the provided factor
        this->x *= factor;
        // Return a reference to the calling object
        return *this;
    }

    void print() const {
        cout << "x = " << x << endl;
    }
};

int main() {
    MyClass obj(5);

    // Chained function calls
    obj.increment().multiply(3).print();

    return 0;
}
```

In this example:

- We have a `MyClass` with a private data member `x`.
- There are two member functions: `increment()` and `multiply(int factor)`, both returning a reference to `MyClass`.
- In each member function, `this` pointer is implicitly used to access the data member `x` of the current object.
- Both member functions modify the state of the object and return a reference to the object itself, enabling chaining.
- In `main()`, we create an object `obj` with an initial value of `5`.
- We then chain calls to `increment()` (which increments `x` by 1) and `multiply(3)` (which multiplies `x` by 3) functions.
- Finally, we call the `print()` function to display the updated value of `x`.

Output:

```
x = 18
```

This chaining technique can make the code more concise and readable, especially when performing multiple operations on the same object.

## Using Scope Resolution

Using the scope operator `::` with class member pointers and variable access can be a bit complex but it's a powerful feature of C++ that allows for dynamic member access and manipulation. Here's a detailed explanation and an example to illustrate its usage.

### Basics

1. **Scope Operator (`::`)**: Used to access static members of a class or a namespace.

2. **Class Member Pointers**: Pointers that can point to a member (variable or function) of a class.

### Example

Consider the following class:

```cpp
#include <iostream>

class MyClass {
public:
    int myVar;
    void myFunction() {
        std::cout << "myFunction called\n";
    }
};

int main() {
    MyClass obj;
    obj.myVar = 10;

    // Pointer to member variable
    int MyClass::*pVar = &MyClass::myVar;

    // Accessing member variable using the pointer
    std::cout << "Value of myVar: " << obj.*pVar << std::endl;

    // Pointer to member function
    void (MyClass::*pFunc)() = &MyClass::myFunction;

    // Calling member function using the pointer
    (obj.*pFunc)();

    return 0;
}
```

### Explanation

1. **Pointer to Member Variable**:

   - `int MyClass::*pVar = &MyClass::myVar;`: This creates a pointer `pVar` that points to the member variable `myVar` of `MyClass`.
   - `obj.*pVar`: This accesses the value of `myVar` in the object `obj` using the pointer `pVar`.

2. **Pointer to Member Function**:
   - `void (MyClass::*pFunc)() = &MyClass::myFunction;`: This creates a pointer `pFunc` that points to the member function `myFunction` of `MyClass`.
   - `(obj.*pFunc)();`: This calls the member function `myFunction` in the object `obj` using the pointer `pFunc`.

### Detailed Steps

1. **Define the Class**: `MyClass` with a member variable `myVar` and a member function `myFunction`.

2. **Create an Object**: `MyClass obj;` creates an instance of `MyClass`.

3. **Assign Values**: `obj.myVar = 10;` assigns a value to the member variable.

4. **Pointer to Member Variable**:

   - `int MyClass::*pVar = &MyClass::myVar;` declares a pointer to a member variable of `MyClass`.
   - `std::cout << "Value of myVar: " << obj.*pVar << std::endl;` accesses the value using the pointer.

5. **Pointer to Member Function**:
   - `void (MyClass::*pFunc)() = &MyClass::myFunction;` declares a pointer to a member function of `MyClass`.
   - `(obj.*pFunc)();` calls the function using the pointer.

By understanding and utilizing these pointers, you can dynamically access and manipulate class members in a powerful and flexible way.
