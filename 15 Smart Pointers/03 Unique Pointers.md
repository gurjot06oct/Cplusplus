### Understanding `std::unique_ptr` in C++

In C++, managing dynamically allocated memory safely and efficiently is crucial to avoid memory leaks and undefined behavior. Smart pointers like `std::unique_ptr` provide a robust mechanism for managing dynamic memory, ensuring automatic deallocation and strong ownership semantics.

#### Introduction to `std::unique_ptr`

`std::unique_ptr` is part of the C++ Standard Library and is designed to manage a dynamically allocated object with exclusive ownership. Unlike raw pointers or other smart pointers like `std::shared_ptr`, a `std::unique_ptr` instance cannot be shared or copied. It ensures that at any given time, exactly one `std::unique_ptr` instance owns the underlying pointer, thus preventing multiple pointers from managing the same object.

#### Key Features and Usage

1. **Creating `std::unique_ptr`:**

   ```cpp
   std::unique_ptr<int> ptr(new int(42));
   ```

   - This creates a `std::unique_ptr` named `ptr` that manages a dynamically allocated integer initialized with the value `42`.
   - The constructor of `std::unique_ptr` takes ownership of the pointer passed to it.

2. **Accessing and Modifying the Managed Object:**

   ```cpp
   *ptr = 100;
   std::cout << "Value: " << *ptr << std::endl;
   ```

   - Dereferencing `ptr` (`*ptr`) allows access to the integer it manages.
   - You can modify the value and access it just like a raw pointer.

3. **Transferring Ownership with Move Semantics:**

   ```cpp
   auto ptr2 = std::move(ptr);
   ```

   - `std::unique_ptr` supports move semantics, allowing the transfer of ownership from one `std::unique_ptr` instance to another.
   - After the move, `ptr` no longer manages the object, and `ptr2` becomes the sole owner.

4. **Sharing Ownership with Copy Semantics:**

   ```cpp
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    std::unique_ptr<int> ptr2 = ptr1; // Compilation error: unique_ptr is non-copyable
   ```

   - `std::unique_ptr` does not support copy semantics. It enforces exclusive ownership, meaning each `std::unique_ptr` instance manages a unique resource. Attempting to directly copy a `std::unique_ptr` instance results in a compilation error because it cannot share ownership of the managed object.

5. **Using `std::make_unique` (C++14 and later):**

   ```cpp
   auto ptr3 = std::make_unique<int>(200);
   ```

   - Prefer `std::make_unique` for creating `std::unique_ptr` instances as it simplifies code and improves exception safety.
   - It constructs the managed object in-place and returns a `std::unique_ptr` owning it.

6. **Automatic Deallocation:**

   - When a `std::unique_ptr` goes out of scope, either due to function return or block exit, the managed object is automatically deleted.
   - This ensures that resources are properly released, preventing memory leaks.

#### Member Functions

1. **Constructor (`std::unique_ptr<T>`):**

   ```cpp
   std::unique_ptr<int> ptr(new int(42));
   ```

   - Constructs a `std::unique_ptr` object that manages a dynamically allocated integer initialized with value `42`.

2. **Destructor (`~std::unique_ptr()`):**

   - Destroys the `std::unique_ptr` object and deallocates the managed memory automatically when the pointer goes out of scope.

3. **Assignment Operator (`operator=`):**

   ```cpp
   std::unique_ptr<int> ptr1(new int(42));
   std::unique_ptr<int> ptr2;
   ptr2 = std::move(ptr1);
   ```

   - Assigns ownership of the managed object from `ptr1` to `ptr2` using move semantics.

4. **`get()` Function:**

   ```cpp
   int* rawPtr = ptr.get();
   ```

   - Returns the raw pointer to the managed object, allowing access to the underlying pointer.

5. **`get_deleter()` Function:**

   ```cpp
   auto deleter = ptr.get_deleter();
   ```

   - Returns the stored deleter function associated with the managed object, if any.

6. **`operator bool()` Function:**

   ```cpp
   if (ptr) {
       // Pointer is not null
   }
   ```

   - Checks if the `std::unique_ptr` is managing a valid (non-null) pointer.

7. **`release()` Function:**

   ```cpp
   int* releasedPtr = ptr.release();
   ```

   - Releases ownership of the managed object and returns the raw pointer, leaving `ptr` as nullptr.

8. **`reset()` Function:**

   ```cpp
   ptr.reset(new int(100));
   ```

   - Resets the `std::unique_ptr` to manage a new object, deallocating the current one if it exists.

9. **`swap()` Function:**

   ```cpp
   std::unique_ptr<int> ptr1(new int(42));
   std::unique_ptr<int> ptr2(new int(100));
   ptr1.swap(ptr2);
   ```

   - Exchanges the contents of `ptr1` and `ptr2`, including ownership of the managed objects.

10. **`operator*` (Dereference Operator):**

    ```cpp
    *ptr = 200;
    ```

    - Dereferences the `std::unique_ptr` to access and modify the value of the managed object.

11. **`operator->` (Member Access Operator):**

    ```cpp
    struct Foo {
        void bar() { std::cout << "Hello from Foo::bar!" << std::endl; }
    };

    std::unique_ptr<Foo> ptr(new Foo);
    ptr->bar(); // Calls Foo's member function bar()
    ```

    - Allows accessing members of the managed object through the `std::unique_ptr`.

12. **`operator[]` (Array Element Access):**

    ```cpp
    std::unique_ptr<int[]> arr(new int[5]);
    arr[0] = 10; // Accesses the first element of the array managed by unique_ptr
    ```

    - Exclusive for `std::unique_ptr` specialized for arrays with runtime length, provides offset access to array elements.

#### Non-Member Function Overloads

1. **`swap()` Function Template:**

   ```cpp
   std::swap(ptr1, ptr2);
   ```

   - Exchanges the contents of two `std::unique_ptr` objects, facilitating efficient swapping of ownership.

2. **Relational Operators (`==`, `!=`, `<`, `<=`, `>`, `>=`):**

   ```cpp
   bool result = (ptr1 < ptr2);
   ```

   - Compares `std::unique_ptr` objects based on the memory addresses of the managed pointers.
