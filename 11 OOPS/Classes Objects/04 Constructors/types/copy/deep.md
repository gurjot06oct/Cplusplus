## **Deep Copy**

In deep copy, an object is created by copying data of all variables, including dynamically allocated memory resources, with identical values to the original object. To perform a deep copy, a custom copy constructor needs to be explicitly defined, ensuring proper allocation and copying of dynamic memory resources. Additionally, it's crucial to allocate memory dynamically to variables in other constructors to maintain consistency.
In C++, shallow copy and deep copy refer to how data is copied from one object to another. Let's illustrate the difference with an example involving a class that contains a pointer to a dynamically allocated array. We will see how modifying the original object affects the shallow and deep copies.

Sure! To address potential memory management issues in the deep copy program, we need to ensure that the memory allocated for each `DeepCopy` object is managed correctly, avoiding double deletion and ensuring proper resource cleanup.

### Deep Copy Example with Proper Memory Management

```cpp
#include <iostream>

class DeepCopy {
public:
    int* data;

    // Constructor
    DeepCopy(int value) {
        data = new int(value);
    }

    // Deep copy constructor
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data);
    }

    // Copy assignment operator
    DeepCopy& operator=(const DeepCopy& other) {
        if (this != &other) {
            // Free existing resource
            delete data;
            // Allocate new memory and copy the data
            data = new int(*other.data);
        }
        return *this;
    }

    // Destructor
    ~DeepCopy() {
        delete data;
    }

    // Display function
    void display() const {
        std::cout << "Data: " << *data << std::endl;
    }
};

int main() {
    // Create an original object
    DeepCopy original(42);
    std::cout << "Original object before copy:" << std::endl;
    original.display();

    // Perform deep copy using copy constructor
    DeepCopy deepCopy1 = original;
    std::cout << "Deep copy object (using copy constructor) after copy:" << std::endl;
    deepCopy1.display();

    // Modify the original object
    *original.data = 84;
    std::cout << "Original object after modification:" << std::endl;
    original.display();
    std::cout << "Deep copy object (using copy constructor) after modification of original:" << std::endl;
    deepCopy1.display();

    // Perform deep copy using copy assignment operator
    DeepCopy deepCopy2(0); // Initialize with some value
    deepCopy2 = original;
    std::cout << "Deep copy object (using copy assignment operator) after copy:" << std::endl;
    deepCopy2.display();

    // Modify the original object again
    *original.data = 21;
    std::cout << "Original object after second modification:" << std::endl;
    original.display();
    std::cout << "Deep copy object (using copy assignment operator) after second modification of original:" << std::endl;
    deepCopy2.display();

    return 0;
}
```

### Explanation

1. **Class Definition:**

   - `DeepCopy` class has a pointer `data` that points to a dynamically allocated integer.
   - The constructor initializes `data` with a new integer.
   - The deep copy constructor allocates new memory and copies the value pointed to by `other.data`.
   - The copy assignment operator ensures proper deep copying and resource management by deleting existing resources before allocating and copying new data.
   - The destructor deletes the allocated memory to avoid memory leaks.

2. **Main Function:**
   - An original `DeepCopy` object is created with a value of 42.
   - A deep copy of the original object is created using the copy constructor.
   - Modifying the value in the original object does not affect the deep copy, demonstrating separate memory.
   - A deep copy is also performed using the copy assignment operator to show how assignment works.

### Output

```
Original object before copy:
Data: 42
Deep copy object (using copy constructor) after copy:
Data: 42
Original object after modification:
Data: 84
Deep copy object (using copy constructor) after modification of original:
Data: 42
Deep copy object (using copy assignment operator) after copy:
Data: 84
Original object after second modification:
Data: 21
Deep copy object (using copy assignment operator) after second modification of original:
Data: 84
```

### Summary

- **Deep Copy Constructor:** Allocates new memory and copies the value, ensuring separate memory locations.
- **Copy Assignment Operator:** Deletes existing data, allocates new memory, and copies the value, ensuring proper resource management.
- **Destructor:** Ensures allocated memory is properly released, avoiding memory leaks.

This approach ensures that deep copies are correctly handled, with each object managing its own memory, avoiding issues like double deletion or memory leaks.
