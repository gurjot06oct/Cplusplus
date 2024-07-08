## Vector STL and Its Properties

The `std::vector` class in the C++ Standard Library is a dynamic array that provides flexible size management and a comprehensive set of member functions for manipulation. It is part of the STL and is widely used due to its efficiency and ease of use.

### Capacity
- **resize**: Changes the size of the vector. If the new size is greater than the current size, new elements are default-initialized. If the new size is smaller, the vector is truncated.
  ```cpp
  std::vector<int> vec = {1, 2, 3};
  vec.resize(5);
  // vec is now {1, 2, 3, 0, 0}
  ```

- **capacity**: Returns the number of elements that the vector can hold before needing to allocate more memory.
  ```cpp
  std::vector<int> vec = {1, 2, 3};
  std::cout << vec.capacity(); // Outputs the capacity of vec
  ```

- **reserve**: Requests that the vector capacity be at least enough to contain `n` elements. If `n` is greater than the current capacity, it reallocates storage.
  ```cpp
  std::vector<int> vec;
  vec.reserve(10);
  std::cout << vec.capacity(); // Outputs 10 or more
  ```

- **shrink_to_fit**: Reduces the capacity of the vector to fit its size and frees unused memory.
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4, 5};
  vec.resize(3);
  vec.shrink_to_fit();
  std::cout << vec.capacity(); // Outputs 3 or more
  ```

### Modifiers
- **assign**: Assigns new contents to the vector, replacing its current contents and modifying its size accordingly.
  ```cpp
  std::vector<int> vec;
  vec.assign(5, 10);
  // vec is now {10, 10, 10, 10, 10}
  ```

- **push_back**: Adds an element to the end of the vector.
  ```cpp
  std::vector<int> vec = {1, 2, 3};
  vec.push_back(4);
  // vec is now {1, 2, 3, 4}
  ```

- **pop_back**: Removes the last element from the vector.
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4};
  vec.pop_back();
  // vec is now {1, 2, 3}
  ```

- **insert**: Inserts elements at the specified position.
  ```cpp
  std::vector<int> vec = {1, 2, 3};
  vec.insert(vec.begin() + 1, 4);
  // vec is now {1, 4, 2, 3}
  ```

- **erase**: Removes elements from the specified position or range.
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4};
  vec.erase(vec.begin() + 1);
  // vec is now {1, 3, 4}
  ```

- **clear**: Removes all elements from the vector.
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4};
  vec.clear();
  // vec is now empty
  ```

- **emplace**: Constructs an element in place at the specified position.
  ```cpp
  std::vector<std::pair<int, int>> vec;
  vec.emplace(vec.begin(), 1, 2);
  // vec contains {(1, 2)}
  ```

- **emplace_back**: Constructs an element in place at the end of the vector.
  ```cpp
  std::vector<std::pair<int, int>> vec;
  vec.emplace_back(1, 2);
  // vec contains {(1, 2)}
  ```