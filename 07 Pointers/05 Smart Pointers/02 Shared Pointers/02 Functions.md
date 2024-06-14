## Functions Related to `std::shared_ptr`

### `std::make_shared`

`std::make_shared` is a utility function in C++ that creates a `std::shared_ptr` instance and initializes the managed object in a single memory allocation. It's a preferred way to create `std::shared_ptr` instances due to its simplicity, efficiency, and exception safety.

#### Syntax:

```cpp
template<class T, class... Args>
std::shared_ptr<T> make_shared(Args&&... args);
```

#### Usage:

- **Single Allocation:** `std::make_shared` performs a single allocation to create both the control block (which stores the reference count and the custom deleter, if any) and the managed object.
- **Exception Safety:** It ensures exception safety by guaranteeing that the memory allocated for the control block and the object are cleaned up properly in case an exception is thrown during construction.

#### Example:

```cpp
#include <memory>

struct MyStruct {
    int data;
    MyStruct(int val) : data(val) {}
};

int main() {
    // Using make_shared to create a shared_ptr
    auto ptr = std::make_shared<MyStruct>(42);
    return 0;
}
```

#### Explanation:

- `auto ptr = std::make_shared<MyStruct>(42);` creates a `std::shared_ptr` named `ptr` that manages an instance of `MyStruct` initialized with the value `42`.
- The `make_shared` function combines the allocation of the control block and the object itself into a single allocation, improving efficiency and reducing the likelihood of memory leaks.

### `std::allocate_shared`

`std::allocate_shared` is another function template provided by the C++ standard library to create a `std::shared_ptr`. It's similar to `std::make_shared` but allows using a custom allocator for memory allocation.

#### Syntax:

```cpp
template<class T, class Allocator, class... Args>
std::shared_ptr<T> allocate_shared(const Allocator& alloc, Args&&... args);
```

#### Usage:

- **Custom Allocator:** `std::allocate_shared` allows using a custom allocator (`Allocator`) to allocate memory for both the control block and the managed object.
- **Flexibility:** It provides flexibility when a specific memory allocation strategy or a custom allocator needs to be used.

#### Example:

```cpp
#include <memory>

struct MyStruct {
    int data;
    MyStruct(int val) : data(val) {}
};

int main() {
    std::allocator<MyStruct> alloc;
    // Using allocate_shared with a custom allocator
    auto ptr = std::allocate_shared<MyStruct>(alloc, 42);
    return 0;
}
```

#### Explanation:

- `std::allocator<MyStruct> alloc;` creates an instance of `std::allocator` for `MyStruct`.
- `auto ptr = std::allocate_shared<MyStruct>(alloc, 42);` uses `allocate_shared` with the custom allocator `alloc` to allocate memory for a `MyStruct` object initialized with `42`.
- This approach separates the allocation of the control block and the object, allowing more control over memory management but potentially sacrificing some performance benefits compared to `std::make_shared`.

### Key Differences

1. **Memory Allocation:**

   - **`std::make_shared`:** Single allocation for both control block and object, improving efficiency.
   - **`std::allocate_shared`:** Separate allocations for control block and object using a custom allocator if specified, offering flexibility.

2. **Exception Safety:**

   - **`std::make_shared`:** Provides strong exception safety guarantee by performing a single allocation.
   - **`std::allocate_shared`:** Exception safety depends on the allocator used; standard allocators usually provide basic exception safety.

3. **Performance:**

   - **`std::make_shared`:** Generally more efficient due to reduced overhead from a single allocation.
   - **`std::allocate_shared`:** May incur slightly higher overhead due to separate allocations and potentially more complex allocator behavior.

4. **Use Cases:**
   - **`std::make_shared`:** Preferred for most cases due to simplicity, efficiency, and strong exception safety.
   - **`std::allocate_shared`:** Used when a custom allocator is needed or when separate control of memory allocation is required.

In summary, `std::make_shared` is typically the preferred choice for creating `std::shared_ptr` instances due to its simplicity, efficiency, and strong exception safety. On the other hand, `std::allocate_shared` offers flexibility with custom allocators but may not provide the same performance benefits as `std::make_shared` in terms of memory overhead. Choosing between them depends on specific use case requirements regarding memory management and performance considerations.

---

### `static_pointer_cast`

```cpp
struct Base { virtual ~Base() = default; };
struct Derived : Base {};

std::shared_ptr<Base> base_ptr = std::make_shared<Derived>();
// Performing a static cast from Base to Derived
std::shared_ptr<Derived> derived_ptr = std::static_pointer_cast<Derived>(base_ptr);
```

**Explanation:**

- `static_pointer_cast` safely casts a `std::shared_ptr<Base>` to a `std::shared_ptr<Derived>`, assuming a known relationship where `Derived` is derived from `Base`.
- **Safety**: Ensures type safety at compile-time, suitable for scenarios where the type relationship is statically known.

---

### `dynamic_pointer_cast`

```cpp
struct Base { virtual ~Base() = default; };
struct Derived : Base { void say_hello() {} };

std::shared_ptr<Base> base_ptr = std::make_shared<Derived>();
// Performing a dynamic cast from Base to Derived
std::shared_ptr<Derived> derived_ptr = std::dynamic_pointer_cast<Derived>(base_ptr);
if (derived_ptr) {
    derived_ptr->say_hello();
} else {
    std::cout << "Cast failed" << std::endl;
}
```

**Explanation:**

- `dynamic_pointer_cast` safely downcasts a `std::shared_ptr<Base>` to a `std::shared_ptr<Derived>`, ensuring runtime type safety by checking the object's actual type.
- **Use Case**: Essential for polymorphic scenarios where the object type may vary at runtime.

---

### `const_pointer_cast`

```cpp
std::shared_ptr<const int> const_ptr = std::make_shared<int>(30);
// Removing the const qualifier from const_ptr
std::shared_ptr<int> mutable_ptr = std::const_pointer_cast<int>(const_ptr);
```

**Explanation:**

- `const_pointer_cast` removes the `const` qualifier from a `std::shared_ptr<const T>`, allowing temporary modification of the object while maintaining shared ownership semantics.
- **Use Case**: Useful when you need to perform operations that modify the object temporarily within a shared ownership context.

---

### `get_deleter`

```cpp
struct MyDeleter { void operator()(int* ptr) { delete ptr; } };

std::shared_ptr<int> ptr(new int(50), MyDeleter());
// Getting the custom deleter from ptr
MyDeleter* deleter = std::get_deleter<MyDeleter>(ptr);
if (deleter) {
    std::cout << "Custom deleter is being used" << std::endl;
}
```

**Explanation:**

- `get_deleter` retrieves the custom deleter associated with a `std::shared_ptr`, allowing access and manipulation of the deleter object.
- **Use Case**: Useful when you need to customize resource management, such as providing a custom cleanup operation for dynamically allocated memory.

---

### `owner_less`

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(60);
std::shared_ptr<int> ptr2 = std::make_shared<int>(70);

std::owner_less<std::shared_ptr<int>> comparator;
if (comparator(ptr1, ptr2)) {
    std::cout << "ptr1 is less than ptr2 in terms of ownership" << std::endl;
} else {
    std::cout << "ptr1 is not less than ptr2 in terms of ownership" << std::endl;
}
```

**Explanation:**

- `owner_less` compares the ownership information of two `std::shared_ptr` instances, facilitating their use as keys in ordered containers (`std::set`, `std::map`).
- **Usage**: Ensures elements are sorted based on their ownership relationships, which is crucial for maintaining a strict weak ordering required by associative containers.

---

### `enable_shared_from_this`

```cpp
class MyClass : public std::enable_shared_from_this<MyClass> {
public:
    std::shared_ptr<MyClass> get_shared() {
        return shared_from_this();
    }
    void say_hello() {}
};

std::shared_ptr<MyClass> my_instance = std::make_shared<MyClass>();
std::shared_ptr<MyClass> my_shared = my_instance->get_shared();
```

**Explanation:**

- `enable_shared_from_this` allows `MyClass` to create additional `std::shared_ptr` instances that share ownership with the existing ones.
- **Use Case**: Ensures that `shared_ptr` instances created from within `MyClass` correctly maintain shared ownership semantics, preventing premature destruction of objects.
