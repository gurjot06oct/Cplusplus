## `std::shared_ptr` in Smart Pointers

The `std::shared_ptr` is a smart pointer provided by the C++ Standard Library that manages the lifetime of an object through reference counting. Multiple `std::shared_ptr` instances can own the same object, and the object is destroyed when the last `std::shared_ptr` owning it is destroyed or reset. This is particularly useful for managing dynamically allocated objects without worrying about memory leaks.

### Basic Usage

Here is a basic example of how to use `std::shared_ptr`:

```cpp
#include <memory>
#include <iostream>

struct MyStruct {
    int data;
    MyStruct(int val) : data(val) {
        std::cout << "MyStruct constructed with value: " << data << std::endl;
    }
    ~MyStruct() {
        std::cout << "MyStruct destroyed with value: " << data << std::endl;
    }
};

int main() {
    // Create a shared_ptr
    std::shared_ptr<MyStruct> ptr1 = std::make_shared<MyStruct>(10);
    std::cout << "ptr1 data: " << ptr1->data << std::endl;

    // Create another shared_ptr sharing the same object
    std::shared_ptr<MyStruct> ptr2 = ptr1;
    std::cout << "ptr2 data: " << ptr2->data << std::endl;

    return 0;
}
```

In this example:

- `ptr1` and `ptr2` both share ownership of the same `MyStruct` object.
- The object is destroyed only when both `ptr1` and `ptr2` go out of scope.

### Member Functions of `std::shared_ptr`

#### Constructor

The `std::shared_ptr` can be constructed in various ways:

```cpp
std::shared_ptr<MyStruct> ptr1(new MyStruct(10)); // Using new
std::shared_ptr<MyStruct> ptr2 = std::make_shared<MyStruct>(20); // Using make_shared
```

#### Destructor

The destructor of `std::shared_ptr` decrements the reference count. If the reference count becomes zero, the managed object is deleted:

```cpp
{
    std::shared_ptr<MyStruct> ptr = std::make_shared<MyStruct>(30);
    // ptr goes out of scope here and MyStruct object is destroyed
}
```

#### `operator=`

Assignment operator for `std::shared_ptr`:

```cpp
std::shared_ptr<MyStruct> ptr3 = std::make_shared<MyStruct>(40);
std::shared_ptr<MyStruct> ptr4;
ptr4 = ptr3; // ptr4 now shares ownership with ptr3
```

#### `swap`

Swaps the contents of two `std::shared_ptr` objects:

```cpp
std::shared_ptr<MyStruct> ptr5 = std::make_shared<MyStruct>(50);
std::shared_ptr<MyStruct> ptr6 = std::make_shared<MyStruct>(60);
ptr5.swap(ptr6); // Now ptr5 holds the object with value 60 and ptr6 holds the object with value 50
```

#### `reset`

Resets the `std::shared_ptr` to manage a new object or to be empty:

```cpp
ptr5.reset(new MyStruct(70)); // ptr5 now points to a new MyStruct object with value 70
ptr6.reset(); // ptr6 is now empty
```

#### `get`

Returns the raw pointer managed by the `std::shared_ptr`:

```cpp
MyStruct* raw_ptr = ptr5.get();
std::cout << "Raw pointer data: " << raw_ptr->data << std::endl;
```

#### `operator*` and `operator->`

Dereferences the `std::shared_ptr` to access the managed object:

```cpp
std::cout << "ptr5 data: " << (*ptr5).data << std::endl;
std::cout << "ptr5 data: " << ptr5->data << std::endl;
```

#### `use_count`

Returns the number of `std::shared_ptr` instances managing the current object:

```cpp
std::cout << "Use count: " << ptr5.use_count() << std::endl;
```

#### `unique`

Checks if the `std::shared_ptr` is the only one managing the current object:

```cpp
if (ptr5.unique()) {
    std::cout << "ptr5 is unique" << std::endl;
}
```

#### `operator bool`

Checks if the `std::shared_ptr` is not null:

```cpp
if (ptr5) {
    std::cout << "ptr5 is not null" << std::endl;
}
```

#### `owner_before`

Compares the ownership of two `std::shared_ptr` objects:

```cpp
std::shared_ptr<MyStruct> ptr7 = std::make_shared<MyStruct>(80);
if (ptr5.owner_before(ptr7)) {
    std::cout << "ptr5 owner before ptr7" << std::endl;
}
```
