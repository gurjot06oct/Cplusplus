### Bidirectional Iterators

#### Overview

**Bidirectional iterators** provide a versatile means of traversing sequences in both forward and backward directions. Let's explore their features, including how they're utilized in code:

1. **Bidirectional Movement**: Unlike forward iterators, which can only move forward, bidirectional iterators enable traversal in both directions—towards the beginning and the end of the sequence.

2. **Container Support**: Containers such as `list`, `map`, `multimap`, `set`, and `multiset` endorse bidirectional iterators. This implies that iterators declared for these containers inherently become bidirectional iterators.

3. **Salient Features**:

   - **Usability**: Bidirectional iterators are conducive to multi-pass algorithms, facilitating the processing of a container multiple times.
   - **Equality/Inequality Comparison**: Bidirectional iterators support equality (`==`) and inequality (`!=`) comparisons. Two bidirectional iterators are considered equal only if they point to the same position.
   - **Dereferencing**: Accessing the value pointed to by a bidirectional iterator is possible using the `*` and `->` operators. This allows both reading from and writing to the iterator's location.
   - **Incrementing/Decrementing**: Bidirectional iterators support both incrementing and decrementing via the `++` and `--` operators. This allows movement in both forward and backward directions.
   - **Swappable**: The values pointed to by bidirectional iterators can be swapped or exchanged, facilitating efficient manipulation of container elements.

   ```cpp
   // Example demonstrating dereferencing and incrementing/decrementing
   list<int> v1 = {1, 2, 3, 4, 5};
   list<int>::iterator i1;

   for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
       *i1 = 1;  // Assigning values to locations pointed by iterator
   }

   for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
       cout << (*i1) << " ";  // Accessing values at locations pointed by iterator
   }
   ```

4. **Practical Implementation**:

   - **Copying in Reverse**: Algorithms like `std::reverse_copy` rely on bidirectional iterators to copy a range into another range in reverse order. Decrementing, a feature of bidirectional iterators, is essential for traversing the range backward.

   ```cpp
   // Definition of std::reverse_copy()
   template <class BidirectionalIterator, class OutputIterator>
   OutputIterator reverse_copy(BidirectionalIterator first,
                               BidirectionalIterator last,
                               OutputIterator result) {
       while (first != last) {
           *result++ = *--last;
       }
       return result;
   }
   ```

   - **Random Shuffling**: While bidirectional iterators enable movement in both directions, they cannot perform arithmetic operations like addition or subtraction. This limitation restricts their use in algorithms like `std::random_shuffle`, which require random access.

5. **Limitations**:
   - Bidirectional iterators lack support for certain operations such as arithmetic operations (`+`, `-`) and offset dereferencing (`[]`).
   - They also cannot be used with relational operators other than equality (`==`) and inequality (`!=`).

Overall, bidirectional iterators offer a balanced mix of features, making them suitable for a wide range of traversal tasks, as demonstrated in the provided code examples.
