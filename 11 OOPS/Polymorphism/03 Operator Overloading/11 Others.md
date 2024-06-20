## Other Operators

### 1. Type Conversion Conversion Operator (`operator typename()`)

- **Member Function Overloading**: Type conversion operator (`operator typename()`) allows implicit conversion of an object of `MyClass` to `int`.

```cpp
class MyClass {
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // Type conversion operator to int
    operator int() const {
        return value; // Implicit conversion to int
    }
};
```

- **Usage Example**:

```cpp
MyClass obj(42);
int intValue = obj; // Implicitly converts MyClass object to int
int intValue_casted = static_cast<int>(obj); // Explicitly converts MyClass object to int
std::cout << "Converted int value: " << intValue << std::endl; // Output: 42
std::cout << "Converted int value using casting: " << intValue_casted << std::endl; // Output: 42
```

### Dereferencing (`->`)

- **Member Function Overloading**: Overloading the `->` operator allows an object to behave like a pointer to another object, enabling access to members of the pointed object.

```cpp
#include <iostream>

class MyClass {
public:
    void print() {
        std::cout << "Printing from MyClass" << std::endl;
    }

    // Overload -> operator to return pointer to the object
    MyClass* operator->() {
        return this;
    }
};
```

- **Explanation**: In the `MyClass` example above, the `->` operator is overloaded as a member function. The function `operator->()` is defined to return a pointer to the object itself (`this`). This allows instances of `MyClass` to be used with the `->` operator, mimicking the behavior of a pointer to access member functions and variables.

- **Usage Example**:

```cpp
MyClass obj;
obj->print(); // Output: Printing from MyClass
```

### 3. Dynamic memory allocation (`new`, `delete`)

- **Member Function Overloading**: Customizes dynamic memory allocation (`new` and `delete`) for instances of `MyClass`.

```cpp
#include <iostream>

class MyClass {
public:
    void* operator new(size_t size) {
        std::cout << "Custom new operator: Allocating " << size << " bytes" << std::endl;
        return ::operator new(size); // Use global new for allocation
    }

    void operator delete(void* ptr) {
        std::cout << "Custom delete operator: Deallocating memory" << std::endl;
        ::operator delete(ptr); // Use global delete for deallocation
    }
};
```

- **Usage Example**:

```cpp
MyClass* ptr = new MyClass(); // Custom new operator: Allocating sizeof(MyClass) bytes
delete ptr; // Custom delete operator: Deallocating memory
```
