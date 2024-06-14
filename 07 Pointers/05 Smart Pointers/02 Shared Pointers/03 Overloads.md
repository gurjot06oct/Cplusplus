### Overloads and Functions `std::shared_ptr`

#### Creating Shared Pointers with Initial Values

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(20);
```

**Explanation:**

- `std::shared_ptr<int> ptr1 = std::make_shared<int>(10);` creates a shared pointer `ptr1` that manages an integer initialized with the value `10`.
- `std::shared_ptr<int> ptr2 = std::make_shared<int>(20);` creates another shared pointer `ptr2` that manages an integer initialized with the value `20`.

#### Outputting Initial Values Before Swap

```cpp
std::cout << "Before swap:" << std::endl;
std::cout << "ptr1 points to: " << *ptr1 << std::endl; // Output: 10
std::cout << "ptr2 points to: " << *ptr2 << std::endl; // Output: 20
```

#### Swapping the Contents of Pointers

```cpp
std::swap(ptr1, ptr2);
```

**Explanation:**

- `std::swap(ptr1, ptr2);` exchanges the contents of `ptr1` and `ptr2`, effectively swapping their managed objects.

#### Outputting Values After Swap

```cpp
std::cout << "After swap:" << std::endl;
std::cout << "ptr1 points to: " << *ptr1 << std::endl; // Output: 20
std::cout << "ptr2 points to: " << *ptr2 << std::endl; // Output: 10
```

#### Relational Operators for `std::shared_ptr`

##### Equality (`==`) Operator

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(10);

bool areEqual = (ptr1 == ptr2); // Result: true (1)
```

**Explanation:**

- `bool areEqual = (ptr1 == ptr2);` compares the shared pointers `ptr1` and `ptr2` for equality based on the values they manage.

##### Inequality (`!=`) Operator

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(20);

bool areNotEqual = (ptr1 != ptr2); // Result: true (1)
```

**Explanation:**

- `bool areNotEqual = (ptr1 != ptr2);` compares the shared pointers `ptr1` and `ptr2` for inequality based on the values they manage.

##### Less Than (`<`) Operator

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(20);

bool isLessThan = (ptr1 < ptr2); // Result depends on internal pointer comparison
```

**Explanation:**

- `bool isLessThan = (ptr1 < ptr2);` compares the shared pointers `ptr1` and `ptr2` using the less than operator based on the internal pointer comparison.

##### Less Than or Equal To (`<=`) Operator

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(20);

bool isLessThanOrEqual = (ptr1 <= ptr2); // Result depends on internal pointer comparison
```

**Explanation:**

- `bool isLessThanOrEqual = (ptr1 <= ptr2);` compares the shared pointers `ptr1` and `ptr2` using the less than or equal to operator based on the internal pointer comparison.

##### Greater Than (`>`) Operator

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(20);

bool isGreaterThan = (ptr1 > ptr2); // Result depends on internal pointer comparison
```

**Explanation:**

- `bool isGreaterThan = (ptr1 > ptr2);` compares the shared pointers `ptr1` and `ptr2` using the greater than operator based on the internal pointer comparison.

##### Greater Than or Equal To (`>=`) Operator

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
std::shared_ptr<int> ptr2 = std::make_shared<int>(20);

bool isGreaterThanOrEqual = (ptr1 >= ptr2); // Result depends on internal pointer comparison
```

**Explanation:**

- `bool isGreaterThanOrEqual = (ptr1 >= ptr2);` compares the shared pointers `ptr1` and `ptr2` using the greater than or equal to operator based on the internal pointer comparison.
