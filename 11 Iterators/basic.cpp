// All iterators in C++ adhere to a set of basic properties, ensuring they can be used in a predictable and standardized manner across various containers and algorithms. These properties are essential for the fundamental operations of iterators. Here are the properties that all iterator categories must support:

// ### Basic Properties of All Iterators

// 1. **Copy-Constructible**:
//     - An iterator must be able to be constructed from another iterator of the same type.
//     - Example:
//       X b(a); // where 'a' is an existing iterator and 'b' is a new iterator and 'X' is an iterator type

// 2. **Copy-Assignable**:
//     - An iterator must be able to be assigned from another iterator of the same type.
//     - Example:
//       b = a; // where both 'a' and 'b' are iterators of the same type

// 3. **Destructible**:
//     - An iterator must support destruction when it goes out of scope.
//     - Automatically handled by the language when the iterator object goes out of scope.

// 4. **Can Be Incremented**:

//     - An iterator must support increment operations to move to the next element.
//     - **Pre-increment**:
//       ++a; // Advances 'a' to the next element
//     - **Post-increment**:
//       a++; // Advances 'a' to the next element, but returns the old value
