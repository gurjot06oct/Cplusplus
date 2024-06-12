## Pointer to an object

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
