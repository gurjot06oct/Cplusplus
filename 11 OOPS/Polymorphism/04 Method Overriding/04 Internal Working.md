### Working of Virtual Functions

A virtual function is a member function in a base class that you expect to override in derived classes. When you declare a function as virtual, you allow derived classes to provide specific implementations for this function. The main advantage is that you can call derived-class methods through base-class pointers or references, enabling dynamic dispatch.

### Vtable (Virtual Table)

A vtable is a mechanism used to support dynamic dispatch of virtual functions. It is essentially a table of function pointers. For each class that has virtual functions (or inherits from a class with virtual functions), the compiler creates a vtable. This table holds pointers to the virtual functions' implementations for that class.

### Vptr (Virtual Pointer)

A vptr is a pointer to the vtable. Each object of a class with virtual functions contains a vptr. During the object's construction, this vptr is set to point to the class's vtable.

### How They Work Together

1. **Class Definition and Compilation:**

   - When a class with virtual functions is defined, the compiler generates a vtable for that class.
   - If the class is derived from a base class with virtual functions, the derived class's vtable will include entries that point to the overridden functions in the derived class.
   - If a derived class does not override a virtual function, the vtable entry will point to the base class's implementation.

2. **Object Construction:**

   - When an object of a class with virtual functions is created, its constructor sets the vptr to point to the class's vtable.
   - For example, if you create an object of a derived class, its vptr will point to the derived class's vtable.

3. **Function Call:**
   - When a virtual function is called on an object, the compiler generates code to use the object's vptr to look up the function pointer in the vtable.
   - It then invokes the function via this function pointer.

### Example to Illustrate

Let's consider an example with a base class `Base` and a derived class `Derived`.

```cpp
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function called\n";
    }

    virtual void display() {
        std::cout << "Base class display function called\n";
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function called\n";
    }

    void display() override {
        std::cout << "Derived class display function called\n";
    }
};

int main() {
    Base* b;
    Derived d;
    b = &d;

    // Virtual function, resolved at runtime
    b->show();
    b->display();

    return 0;
}
```

### Steps and Underlying Mechanism:

1. **Compilation:**

   - The compiler creates a vtable for both `Base` and `Derived`.
   - The `Base` class vtable contains pointers to `Base::show` and `Base::display`.
   - The `Derived` class vtable contains pointers to `Derived::show` and `Derived::display`.

2. **Object Creation:**

   - When `Derived d` is created, its constructor sets the vptr to point to the `Derived` class vtable.

3. **Function Call (`b->show()`):**

   - At runtime, `b` points to `d` (an object of `Derived`).
   - The vptr in `d` points to the `Derived` class vtable.
   - The `show` function is called through the vtable, so `Derived::show` is executed.

4. **Function Call (`b->display()`):**
   - Similarly, the `display` function is called through the vtable, and `Derived::display` is executed.

### Visual Representation

Here's a simplified visual representation of the vtable and vptr:

- **Base Class Vtable:**

  ```
  +---------------+
  | Base::show    |
  +---------------+
  | Base::display |
  +---------------+
  ```

- **Derived Class Vtable:**

  ```
  +------------------+
  | Derived::show    |
  +------------------+
  | Derived::display |
  +------------------+
  ```

- **Object Layout:**
  - `Derived d` object:
    ```
    +------------------------------+
    | vptr -> Derived Class Vtable |
    +------------------------------+
    | Data members of Derived      |
    +------------------------------+
    ```

### Improved Example

```cpp
class BaseClass
{
public:
    void nonVirtualFunction() { cout << "BaseClass nonVirtualFunction\n"; }
    virtual void virtualFunction1() { cout << "BaseClass virtualFunction1\n"; }
    virtual void virtualFunction2() { cout << "BaseClass virtualFunction2\n"; }
    virtual void specialFunction() { cout << "BaseClass specialFunction\n"; }
};

class DerivedClass : public BaseClass
{
public:
    void nonVirtualFunction() { cout << "DerivedClass nonVirtualFunction\n"; }
    void virtualFunction1() override { cout << "DerivedClass virtualFunction1\n"; }
    void specialFunction(int x) { cout << "DerivedClass specialFunction with int\n"; }
};
```

- **BaseClass vtable**:

  ```
  [0] virtualFunction1 -> BaseClass::virtualFunction1
  [1] virtualFunction2 -> BaseClass::virtualFunction2
  [2] specialFunction  -> BaseClass::specialFunction
  ```

- **DerivedClass vtable**:
  ```
  [0] virtualFunction1 -> DerivedClass::virtualFunction1
  [1] virtualFunction2 -> BaseClass::virtualFunction2
  [2] specialFunction  -> BaseClass::specialFunction
  ```

### Explanation with the vtable

When you create an object of `DerivedClass`, the object's `vptr` points to the `DerivedClass` vtable.

```cpp
DerivedClass derivedObj;
BaseClass *basePtr = &derivedObj;
```

- `derivedObj` has its `vptr` pointing to `DerivedClass` vtable.
- `basePtr` is a pointer to `BaseClass`, but it points to `derivedObj`.

#### Function Calls

1. **Non-Virtual Function Call**:

   ```cpp
   basePtr->nonVirtualFunction();
   ```

   - This call is resolved at compile time (early binding) because `nonVirtualFunction` is not present in `DerivedClass` vtable.
   - The call invokes `BaseClass::nonVirtualFunction` regardless of the actual object type.

2. **Virtual Function Calls**:

   ```cpp
   basePtr->virtualFunction1();
   ```

   - This call is resolved at runtime (late binding) using the vtable.
   - The `vptr` in `derivedObj` points to `DerivedClass` vtable.
   - The vtable entry for `virtualFunction1` points to `DerivedClass::virtualFunction1`.
   - Thus, `DerivedClass::virtualFunction1` is called.

   ```cpp
   basePtr->virtualFunction2();
   ```

   - This call is also resolved at runtime.
   - The `vptr` points to `DerivedClass` vtable.
   - The vtable entry for `virtualFunction2` points to `BaseClass::virtualFunction2`.
   - Thus, `BaseClass::virtualFunction2` is called.

   ```cpp
   basePtr->specialFunction();
   ```

   - This call is resolved at runtime.
   - The `vptr` points to `DerivedClass` vtable.
   - The vtable entry for `specialFunction` points to `BaseClass::specialFunction`.
   - Thus, `BaseClass::specialFunction` is called.

3. **Illegal Function Call**:

   ```cpp
   basePtr->specialFunction(5);
   ```

   When attempting to call `basePtr->specialFunction(5);`, the following steps explain why a compilation error occurs:

   1. **Early Binding (Compile-Time Resolution)**:

   - Early binding happens during compilation when the compiler determines which function to call based on the static type of the pointer or object.
   - In the line `basePtr->specialFunction(5);`, `basePtr` is of type `BaseClass*`.

   2. **Function Resolution in BaseClass**:

   - The compiler looks for a function named `specialFunction` in `BaseClass`.
   - In `BaseClass`, there is a virtual function `virtual void specialFunction()`.
   - However, there is no function `specialFunction(int)` defined in `BaseClass`.

   3. **No Matching Function in BaseClass**:

   - Since `specialFunction(int)` is not declared or defined in `BaseClass`, the compiler cannot resolve the call `basePtr->specialFunction(5);`.

   4. **Compilation Error**:

   - Consequently, the compiler generates an error because it cannot find a suitable `specialFunction(int)` in `BaseClass` that matches the call `basePtr->specialFunction(5);`.

### Summary

- **Virtual Function:** Declared with the `virtual` keyword in the base class to allow overriding in derived classes.
- **Vtable:** A table of function pointers created by the compiler for each class with virtual functions.
- **Vptr:** A pointer within each object pointing to the class's vtable, set during object construction.
- **Dynamic Dispatch:** Achieved by using the vptr to look up the correct function in the vtable at runtime, enabling polymorphism.
