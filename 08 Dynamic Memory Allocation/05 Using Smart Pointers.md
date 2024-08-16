## Smart Pointers in C++

Smart pointers in C++ provide automatic and safe memory management. They manage the lifetime of dynamically allocated objects by ensuring proper destruction and deallocation when the smart pointer goes out of scope. The commonly used smart pointers are `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`, defined in the `<memory>` header.

### Example Class

```cpp
class MyClass
{
public:
    MyClass()
    {
        std::cout << "Constructor called!" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "Destructor called!" << std::endl;
    }

    void display() const
    {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};
```

### Using `std::unique_ptr`

```cpp
// Unique Pointer for a Single Object
std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>();
uniquePtr->display();

// Unique Pointer for an Array of Objects
std::unique_ptr<MyClass[]> uniqueArrayPtr = std::make_unique<MyClass[]>(3);
for (int i = 0; i < 3; ++i)
{
    uniqueArrayPtr[i].display();
}
```

Explanation:

- **Unique Pointer for a Single Object**: `std::unique_ptr` manages a single dynamically allocated `MyClass` object. The `std::make_unique<MyClass>()` function creates the object and assigns ownership to `uniquePtr`. When `uniquePtr` goes out of scope, the `MyClass` object is automatically destroyed.
- **Unique Pointer for an Array of Objects**: `std::unique_ptr` can also manage arrays of objects (`MyClass[]` in this case). `std::make_unique<MyClass[]>(3)` creates an array of 3 `MyClass` objects. Each element in `uniqueArrayPtr` can be accessed using array indexing (`uniqueArrayPtr[i]`) to call member functions like `display()`. When `uniqueArrayPtr` goes out of scope, all `MyClass` objects in the array are automatically destroyed.

### Using `std::shared_ptr`

```cpp
// Shared Pointer for a Single Object
std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();
{
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
    sharedPtr2->display();
}
sharedPtr1->display();

// Shared Pointer for an Array of Objects
std::shared_ptr<MyClass> sharedArrayPtr(new MyClass[3], std::default_delete<MyClass[]>());
for (int i = 0; i < 3; ++i)
{
    sharedArrayPtr.get()[i].display();
}
```

Explanation:

- **Shared Pointer for a Single Object**: `std::shared_ptr` allows multiple pointers to manage the same dynamically allocated `MyClass` object. `std::make_shared<MyClass>()` creates the object and assigns ownership to `sharedPtr1`. Additional `shared_ptr` instances (like `sharedPtr2` in the inner scope) can be created from `sharedPtr1`, all sharing ownership. The `MyClass` object is destroyed when the last `shared_ptr` instance (`sharedPtr1` in this case) goes out of scope.
- **Shared Pointer for an Array of Objects**: `std::shared_ptr` can also manage arrays (`new MyClass[3]`). `std::default_delete<MyClass[]>()` is used as the deleter to correctly deallocate the array. The array elements are accessed using `sharedArrayPtr.get()[i]` to call `MyClass` member functions like `display()`. When `sharedArrayPtr` goes out of scope, the entire array of `MyClass` objects is automatically destroyed.

These explanations clarify how `std::unique_ptr` and `std::shared_ptr` manage dynamic memory allocation and deallocation for both single objects and arrays, ensuring proper resource management and preventing memory leaks in C++ programs.
