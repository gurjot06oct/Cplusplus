## **Shallow Copy**

In shallow copy, an object is created by directly copying the data of all variables from the original object. While this approach works well for variables residing in the stack memory, it poses challenges when variables are dynamically allocated from the heap memory. If some variables are allocated memory from the heap, then the copied object's variables will reference the same memory locations as the original object.

This situation can lead to ambiguity and runtime errors, such as dangling pointers. Both objects end up pointing to the same memory location, causing changes made by one object to reflect in the other. Consequently, the purpose of creating a replica of the object is not fulfilled by shallow copy.

It's important to note that the C++ compiler implicitly creates a copy constructor and overloads the assignment operator to perform shallow copy at compile time.
Certainly! Let's provide a more complete example that showcases shallow copy in a C++ class.

### Shallow Copy Example

We'll create a `ShallowCopy` class that demonstrates what happens when we perform a shallow copy. Specifically, we'll see how changes to the original object reflect in the copied object due to shared memory.

```cpp
#include <iostream>

class ShallowCopy {
public:
    int* data;

    // Constructor
    ShallowCopy(int value) {
        data = new int(value);
    }

    // Shallow copy constructor
    ShallowCopy(const ShallowCopy& other) {
        data = other.data;
    }

    // Destructor
    ~ShallowCopy() {
        // This destructor can cause issues if the same memory is deleted multiple times
        delete data;
    }

    // Display function
    void display() const {
        std::cout << "Data: " << *data << std::endl;
    }
};

int main() {
    // Create an original object
    ShallowCopy original(42);
    std::cout << "Original object before copy:" << std::endl;
    original.display();

    // Perform shallow copy
    ShallowCopy shallowCopy = original;
    std::cout << "Shallow copy object after copy:" << std::endl;
    shallowCopy.display();

    // Modify the original object
    *original.data = 84;
    std::cout << "Original object after modification:" << std::endl;
    original.display();
    std::cout << "Shallow copy object after modification of original:" << std::endl;
    shallowCopy.display();

    return 0;
}
```

### Explanation

1. **Class Definition:**

   - `ShallowCopy` class has a pointer `data` that points to a dynamically allocated integer.
   - The constructor initializes `data` with a new integer.
   - The shallow copy constructor simply copies the pointer value from `other.data` to `data`, making both objects point to the same memory location.
   - The destructor deletes the allocated memory, which can cause problems if multiple objects try to delete the same memory.

2. **Main Function:**
   - An original `ShallowCopy` object is created with a value of 42.
   - A shallow copy of the original object is created.
   - Modifying the value in the original object reflects in the shallow copy, demonstrating the shared memory.

### Output

```
Original object before copy:
Data: 42
Shallow copy object after copy:
Data: 42
Original object after modification:
Data: 84
Shallow copy object after modification of original:
Data: 84
```

### Issues with Shallow Copy

While this example demonstrates the shallow copy concept, it also highlights a significant issue: both `original` and `shallowCopy` objects share the same memory. When the destructor is called for both objects (at the end of their scope), it will attempt to delete the same memory twice, leading to undefined behavior or a program crash.

### Improved Shallow Copy Handling

To avoid the double deletion problem, you can use smart pointers like `std::shared_ptr` in C++, which handle the memory management more gracefully:

```cpp
#include <iostream>
#include <memory>

class ImprovedShallowCopy {
public:
    std::shared_ptr<int> data;

    ImprovedShallowCopy(int value) {
        data = std::make_shared<int>(value);
    }

    // Shallow copy constructor
    ImprovedShallowCopy(const ImprovedShallowCopy& other) {
        data = other.data;
    }

    void display() const {
        std::cout << "Data: " << *data << std::endl;
    }
};

int main() {
    ImprovedShallowCopy original(42);
    std::cout << "Original object before copy:" << std::endl;
    original.display();

    ImprovedShallowCopy shallowCopy = original;
    std::cout << "Shallow copy object after copy:" << std::endl;
    shallowCopy.display();

    *original.data = 84;
    std::cout << "Original object after modification:" << std::endl;
    original.display();
    std::cout << "Shallow copy object after modification of original:" << std::endl;
    shallowCopy.display();

    return 0;
}
```

Using `std::shared_ptr` ensures that the memory is managed correctly, and the underlying data will only be deleted when the last shared pointer owning the data is destroyed.
