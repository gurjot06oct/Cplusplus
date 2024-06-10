Copy and Move semantics of `std::unique_ptr` and `std::shared_ptr`:

- **Copy Semantics**:

  - Copy semantics refer to the behavior of objects when they are copied.
  - For `std::unique_ptr`:
    - It does not support copy semantics because copying a `std::unique_ptr` would result in two pointers owning the same dynamically allocated object, violating its exclusive ownership semantics.
    - Attempting to copy a `std::unique_ptr` will result in a compilation error.
  - For `std::shared_ptr`:
    - It supports copy semantics. When a `std::shared_ptr` is copied, a new instance is created that shares ownership of the same dynamically allocated object.
    - The reference count of the object is incremented, indicating that another `std::shared_ptr` is now referencing the object.

- **Move Semantics**:
  - Move semantics refer to the transfer of ownership from one object to another.
  - Both `std::unique_ptr` and `std::shared_ptr` support move semantics.
  - When an object is moved from one `std::unique_ptr` or `std::shared_ptr` to another, the ownership of the dynamically allocated object is transferred to the new pointer, and the original pointer is set to null.
  - Moving a pointer is typically more efficient than copying because it involves transferring ownership without duplicating the underlying resource.
