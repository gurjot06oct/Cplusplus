## Introduction to Iterators

An **iterator** is an object that allows traversal through a container, particularly in a sequential manner. Iterators abstract the idea of navigating through a collection of elements and provide a uniform interface to access elements without exposing the underlying representation of the container.

### Basic Operations

There are two fundamental operations that any iterator supports:

- **Dereference (`*`)**: This operation allows access to the element the iterator is currently pointing to.
- **Increment (`++`)**: This operation advances the iterator to the next element in the container.

All iterators in C++ adhere to a set of basic properties, ensuring they can be used in a predictable and standardized manner across various containers and algorithms. These properties are essential for the fundamental operations of iterators. Here are the properties that all iterator categories must support:

### Basic Properties of All Iterators

1. **Copy-Constructible**:

   - An iterator must be able to be constructed from another iterator of the same type.
   - Example:
     X b(a); // where 'a' is an existing iterator and 'b' is a new iterator and 'X' is an iterator type

2. **Copy-Assignable**:

   - An iterator must be able to be assigned from another iterator of the same type.
   - Example:
     b = a; // where both 'a' and 'b' are iterators of the same type

3. **Destructible**:

   - An iterator must support destruction when it goes out of scope.
   - Automatically handled by the language when the iterator object goes out of scope.

4. **Can Be Incremented**:

   - An iterator must support increment operations to move to the next element.
   - **Pre-increment**:
     ++a; // Advances 'a' to the next element
   - **Post-increment**:
     a++; // Advances 'a' to the next element, but returns the old value

### Categories of Iterators

Iterators are categorized based on the functionality they support. These categories define the range of operations that can be performed on the iterators. Here are the five categories:

#### Input Iterators

- **Purpose**: Used for reading data from a sequence.
- **Operations**: Supports `*` for dereferencing and `++` for incrementing.
- **Characteristics**:
  - Read-only access.
  - Can be compared for equality.
  - Allows single-pass access (no backtracking).

#### Output Iterators

- **Purpose**: Used for writing data to a sequence.
- **Operations**: Supports `*` for dereferencing and `++` for incrementing.
- **Characteristics**:
  - Write-only access.
  - Can only be used for a single pass (cannot re-read or backtrack).
  - Often used in conjunction with algorithms that produce output, like `std::copy`.

#### Forward Iterators

- **Purpose**: Combine the capabilities of input and output iterators.
- **Operations**: Supports `*` for dereferencing, `++` for incrementing.
- **Characteristics**:
  - Read/write access.
  - Supports multiple passes over the sequence.
  - Guarantees only forward movement (no decrementing).

#### Bidirectional Iterators

- **Purpose**: Extend forward iterators by allowing backward traversal.
- **Operations**: Supports `*` for dereferencing, `++` for incrementing, and `--` for decrementing.
- **Characteristics**:
  - Read/write access.
  - Supports both forward and backward traversal.

#### Random Access Iterators

- **Purpose**: Provide the highest level of iterator functionality, allowing direct access to any element in the sequence.
- **Operations**: Supports all operations of bidirectional iterators, plus arithmetic operations like addition and subtraction.
- **Characteristics**:
  - Read/write access.
  - Constant time complexity for moving to any position (`it + n` or `it - n`).
  - Supports comparison operators (`<`, `>`, `<=`, `>=`).

### Examples of Iterators in Standard Containers

- **Input Iterators**: `istream_iterator`
- **Output Iterators**: `ostream_iterator`
- **Forward Iterators**: `forward_list` iterator
- **Bidirectional Iterators**: `list`, `set`, `map` iterators
- **Random Access Iterators**: `vector`, `deque`, `array` iterators

### Special Considerations

- **Iterator Validity**: Operations on iterators can invalidate them (e.g., modifying the container structure while iterating).
- **Const Iterators**: `const_iterator` types provide read-only access, ensuring the elements are not modified.
- **Algorithms**: Standard algorithms (e.g., `std::sort`, `std::copy`, `std::find`) work seamlessly with iterators, allowing flexible and efficient manipulation of containers.

### Custom Iterators

Beyond standard library containers, custom iterators can be implemented to work with user-defined data structures. Implementing an iterator involves defining the iterator class with the appropriate operations (`*`, `++`, and optionally others) and ensuring it adheres to the iterator category requirements.
