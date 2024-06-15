### Copy and Move Semantics of `std::shared_ptr`

#### Copy Semantics

```cpp
std::shared_ptr<int> ptr1(new int(42));
std::shared_ptr<int> ptr2 = ptr1;
```

**Explanation:**

- **Copying Ownership:** `ptr2` is initialized with `ptr1`, resulting in shared ownership of the integer 42. Both `ptr1` and `ptr2` now point to the same dynamically allocated integer.
- **Reference Count:** The reference count of the managed integer is incremented to 2, indicating that two `std::shared_ptr` instances are sharing ownership of the integer.

#### Move Semantics

```cpp
std::shared_ptr<int> ptr3 = std::move(ptr1);
```

**Explanation:**

- **Moving Ownership:** Ownership of the integer managed by `ptr1` is transferred to `ptr3` using `std::move`. After the move, `ptr1` no longer owns the integer and is set to `nullptr`.
- **Reference Count:** The reference count remains unchanged during the move, ensuring that the resource is still managed properly by `ptr3`.
