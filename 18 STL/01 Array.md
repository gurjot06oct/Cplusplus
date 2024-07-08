## Array Class in STL

The `std::array` class in the C++ Standard Library is a container that encapsulates fixed-size arrays. It provides a more modern and flexible alternative to traditional C-style arrays by offering bounds checking, better integration with the rest of the STL, and a suite of member functions for common operations.

### Accessing Elements
- **operator[]**: Allows direct access to an element using the array index. It does not perform bounds checking.
  ```cpp
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::cout << arr[2]; // Outputs 3
  ```

- **at**: Provides access to an element with bounds checking. If the index is out of range, it throws an `std::out_of_range` exception.
  ```cpp
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::cout << arr.at(2); // Outputs 3
  ```

- **front**: Returns a reference to the first element in the array.
  ```cpp
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::cout << arr.front(); // Outputs 1
  ```

- **back**: Returns a reference to the last element in the array.
  ```cpp
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::cout << arr.back(); // Outputs 5
  ```

- **data**: Returns a pointer to the underlying array serving as the element storage.
  ```cpp
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  int* p = arr.data();
  std::cout << *p; // Outputs 1
  ```

### Modifiers
- **fill**: Fills the entire array with the specified value.
  ```cpp
  std::array<int, 5> arr;
  arr.fill(10);
  for (int i : arr) std::cout << i << " "; // Outputs 10 10 10 10 10
  ```

- **swap**: Exchanges the contents of two arrays of the same type and size.
  ```cpp
  std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  std::array<int, 5> arr2 = {6, 7, 8, 9, 10};
  arr1.swap(arr2);
  for (int i : arr1) std::cout << i << " "; // Outputs 6 7 8 9 10
  ```

### Non-member Function Overloads
- **get (array)**: Provides access to an element using a tuple-like interface.
  ```cpp
  std::array<int, 3> arr = {1, 2, 3};
  std::cout << std::get<1>(arr); // Outputs 2
  ```

- **relational operators (array)**: Enables comparison operations (==, !=, <, >, <=, >=) for arrays.
  ```cpp
  std::array<int, 3> arr1 = {1, 2, 3};
  std::array<int, 3> arr2 = {1, 2, 4};
  std::cout << (arr1 < arr2); // Outputs 1 (true)
  ```

### Non-member Class Specializations
- **tuple_element<array>**: Provides the type of the element at a given position in the array, facilitating tuple-like access.
  ```cpp
  std::array<int, 3> arr = {1, 2, 3};
  std::tuple_element<1, decltype(arr)>::type x = arr[1];
  std::cout << x; // Outputs 2
  ```

- **tuple_size<array>**: Returns the number of elements in the array, enabling compile-time introspection.
  ```cpp
  std::array<int, 3> arr = {1, 2, 3};
  std::cout << std::tuple_size<decltype(arr)>::value; // Outputs 3
  ```