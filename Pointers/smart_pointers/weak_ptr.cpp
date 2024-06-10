// ### `std::weak_ptr`:
// `std::weak_ptr` is a special-case smart pointer designed to be used in conjunction with `std::shared_ptr`. It provides access to an object owned by one or more `std::shared_ptr` instances without participating in reference counting. `std::weak_ptr` is used when there is a need to observe an object without requiring it to remain alive. It is also required in certain cases to break circular references between `std::shared_ptr` instances. `std::weak_ptr` is declared in the `<memory>` header file.

// ### Key Features and Characteristics of `std::weak_ptr`:

// 1. **Observation Without Ownership**:
//    - Unlike `std::shared_ptr`, `std::weak_ptr` does not contribute to the reference count of the dynamically allocated object. It allows observing the object without taking ownership.

// 2. **Prevention of Circular References**:
//    - `std::weak_ptr` is often used to break circular references between `std::shared_ptr` instances. Circular references can lead to memory leaks because they prevent objects from being deallocated when they are no longer needed. By using `std::weak_ptr`, you can break such cycles and ensure proper memory management.

// 3. **Weak Locking**:
//    - To access the object pointed to by a `std::weak_ptr`, you need to perform a weak lock (or "lock" operation). This operation returns a `std::shared_ptr` that shares ownership of the object if it is still alive, or an empty `std::shared_ptr` if the object has been deleted.

// 4. **Lifetime Management**:
//    - Since `std::weak_ptr` does not hold strong ownership of the object, it is important to ensure that the object it observes remains valid during its lifetime. Typically, `std::weak_ptr` instances are used in scenarios where the object is managed by `std::shared_ptr` instances with longer lifetimes.

#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);
    std::weak_ptr<int> weakPtr = sharedPtr;

    // Weak locking to access the object
    if (auto lockedPtr = weakPtr.lock())
    {
        std::cout << "Value through weakPtr: " << *lockedPtr << std::endl;
    }
    else
    {
        std::cout << "Object has been deleted" << std::endl;
    }

    // Releasing the shared_ptr
    sharedPtr.reset();

    // Attempting to access the object through weak_ptr after deletion
    if (auto lockedPtr = weakPtr.lock())
    {
        std::cout << "Value through weakPtr: " << *lockedPtr << std::endl;
    }
    else
    {
        std::cout << "Object has been deleted" << std::endl;
    }

    return 0;
}

// In this example:
// - We create a `std::shared_ptr<int>` named `sharedPtr` to manage a dynamically allocated integer.
// - We create a `std::weak_ptr<int>` named `weakPtr` to observe the same object without taking ownership.
// - We perform weak locking (`lock()`) to access the object through `weakPtr`. If the object is still valid, we print its value; otherwise, we indicate that the object has been deleted.
// - After releasing the `std::shared_ptr`, we attempt to access the object through `weakPtr` again. Since the object has been deleted, the weak lock returns an empty `std::shared_ptr`.
