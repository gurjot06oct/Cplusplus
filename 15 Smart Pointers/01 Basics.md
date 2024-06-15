## Smart Pointers

Smart pointers in C++ are objects that act like pointers but provide automatic memory management. They were introduced to address common pitfalls of raw pointers, such as memory leaks and dangling pointers. Smart pointers ensure that memory allocated dynamically is properly deallocated when it is no longer needed, thus reducing the risk of memory leaks and other memory-related errors.

The types of smart pointers in C++ are:

1. `std::unique_ptr`
2. `std::shared_ptr`
3. `std::weak_ptr`

## Key Features of Smart Pointers:

### 1. **Automatic Resource Management**

- Smart pointers automatically release the managed memory when they go out of scope. This helps in preventing memory leaks and dangling pointers.

### 2. **Ownership Semantics**

- Different types of smart pointers (e.g., `unique_ptr`, `shared_ptr`, `weak_ptr`) provide different ownership semantics:
  - **`unique_ptr`:** Represents exclusive ownership of the resource. Only one `unique_ptr` can own the resource at a time.
  - **`shared_ptr`:** Allows multiple smart pointers to share ownership of a resource. The resource is deallocated when the last `shared_ptr` owning it is destroyed.
  - **`weak_ptr`:** Provides a non-owning reference to a resource managed by `shared_ptr`. It does not affect the reference count.

### 3. **Automatic Deallocation**

- Smart pointers use RAII (Resource Acquisition Is Initialization) principles to ensure that resources are properly deallocated when the smart pointer goes out of scope.

### 4. **Type Safety**

- Smart pointers are strongly typed, ensuring that the correct destructors are called for the managed objects.

### 5. **Custom Deleters**

- Smart pointers allow specifying custom deleters to define how the managed object should be destroyed, providing flexibility in resource management.

### 6. **Thread Safety**

- `shared_ptr` and `weak_ptr` provide some level of thread safety for their reference counting mechanism. However, the object itself must be protected for concurrent access.
