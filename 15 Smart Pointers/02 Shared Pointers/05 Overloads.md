# Overloads and Functions `std::shared_ptr`

## `swap` for `std::shared_ptr`

### Creating Shared Pointers with Initial Values

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(20);
```

**Explanation:**

- `std::shared_ptr<int> ptr1 = std::make_shared<int>(10);` creates a shared pointer `ptr1` that manages an integer initialized with the value `10`.
- `std::shared_ptr<int> ptr2 = std::make_shared<int>(20);` creates another shared pointer `ptr2` that manages an integer initialized with the value `20`.

### Outputting Initial Values Before Swap

```cpp
std::cout << "Before swap:" << std::endl;
std::cout << "ptr1 points to: " << *ptr1 << std::endl; // Output: 10
std::cout << "ptr2 points to: " << *ptr2 << std::endl; // Output: 20
```

### Swapping the Contents of Pointers

```cpp
std::swap(ptr1, ptr2);
```

**Explanation:**

- `std::swap(ptr1, ptr2);` exchanges the contents of `ptr1` and `ptr2`, effectively swapping their managed objects.

### Outputting Values After Swap

```cpp
std::cout << "After swap:" << std::endl;
std::cout << "ptr1 points to: " << *ptr1 << std::endl; // Output: 20
std::cout << "ptr2 points to: " << *ptr2 << std::endl; // Output: 10
```

## Relational Operators for `std::shared_ptr`

The relational operators (`==`, `!=`, `<`, `<=`, `>`, `>=`) in `std::shared_ptr` behave according to specific rules designed to facilitate their use in standard associative containers and to compare against `nullptr`. Here's a detailed explanation of how each operator works for `std::shared_ptr`:

### Comparison Operators for `std::shared_ptr`

#### `==` and `!=`

- **Definition**: The `==` operator checks if two `shared_ptr` instances point to the same object (i.e., they have the same stored pointer).
- **Behavior**:
  - If both `shared_ptr` instances are `nullptr`, they compare equal (`nullptr == nullptr`).
  - If one `shared_ptr` is `nullptr` and the other points to an object, they compare unequal (`nullptr != shared_ptr`).
  - If both `shared_ptr` instances point to the same object (same stored pointer), they compare equal.
- **Example**:

  ```cpp
  std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
  std::shared_ptr<int> ptr2 = ptr1;

  if (ptr1 == ptr2) {
      // They are equal because they point to the same object
  }
  ```

#### `<`, `<=`, `>`, `>=`

- **Definition**: These operators perform comparison based on the address of the managed object.
- **Behavior**:

  - They compare the raw pointers stored within `shared_ptr`, not the ownership or reference counts.
  - Comparisons are made using `std::less<T*>`, where `T*` is the type pointed to by the `shared_ptr`.
  - `nullptr` is considered less than any non-null pointer.

- **Example**:

  ```cpp
  std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
  std::shared_ptr<int> ptr2 = std::make_shared<int>(100);

  if (ptr1 < ptr2) {
      // Comparison based on the address of the managed objects
  }
  ```

### Comparison Considerations

- **Ownership vs. Raw Pointer Comparison**: These operators compare the raw pointers stored within `shared_ptr`, not the ownership or reference counts. This means two `shared_ptr` instances that manage the same object (same ownership) but are not the same instance (not aliasing) will not compare equal.
- **Use in Standard Containers**: `std::shared_ptr`'s comparison operators are designed to work seamlessly with standard associative containers like `std::set`, `std::map`, and `std::unordered_set`, where ordering or equivalence is determined based on the pointer value rather than the object ownership.

- **Null Pointer Comparison**: `nullptr` is considered less than any non-null pointer. Therefore, comparing a `shared_ptr` initialized with `nullptr` to any non-null `shared_ptr` will return `true` for `<`, `<=`, and `!=`, and `false` for `==`, `>`, and `>=`. `nullptr` is a special constant in C++ that represents a null pointer, which points to no object. In most implementations, `nullptr` is defined as `0` or `NULL`, but it's distinct from integer `0` or `NULL` because it has its own type `nullptr_t`.

### Example Demonstrating Usage

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    std::shared_ptr<int> ptr2 = ptr1;
    std::shared_ptr<int> ptr3 = std::make_shared<int>(100);

    // Comparison using relational operators
    if (ptr1 == ptr2) {
        std::cout << "ptr1 and ptr2 are equal" << std::endl;
    }

    if (ptr1 != ptr3) {
        std::cout << "ptr1 and ptr3 are not equal" << std::endl;
    }

    if (ptr1 < ptr3) {
        std::cout << "ptr1 is less than ptr3" << std::endl;
    }

    if (ptr3 > ptr1) {
        std::cout << "ptr3 is greater than ptr1" << std::endl;
    }

    return 0;
}
```
