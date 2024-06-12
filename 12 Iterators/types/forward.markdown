### Forward Iterators

#### Overview

Forward iterators combine the functionalities of both input and output iterators. They allow both accessing and modifying values in a sequence. While they support features from both input and output iterators, they still maintain their unidirectional nature.

#### Salient Features

1. **Usability**:

   - Forward iterators can be used in multi-pass algorithms. Operations on a forward iterator that is dereferenceable never make its iterator value non-dereferenceable, enabling algorithms to use multiple copies of an iterator to pass more than once by the same iterator values.

2. **Equality / Inequality Comparison**:

   - Forward iterators can be compared for equality with another iterator.
   - Example:
     ```cpp
     if (A == B) { /* Valid */ }
     if (A != B) { /* Valid */ }
     ```

3. **Dereferencing**:

   - Forward iterators can be dereferenced to access and modify values.
   - Example:
     ```cpp
     *i1 = 1;    // Assigning values using the iterator
     cout << *i1; // Accessing values using the iterator
     ```

4. **Incrementable**:

   - Forward iterators can be incremented to refer to the next element in the sequence.
   - Example:
     ```cpp
     i1++;   // Using post-increment operator
     ++i1;   // Using pre-increment operator
     ```

5. **Swappable**:
   - The values pointed to by forward iterators can be exchanged or swapped.

#### Practical Implementation

Let's explore how forward iterators are practically implemented in STL algorithms:

1. **`std::replace`**:

   - This algorithm replaces all elements in a range that are equal to a particular value with a new value. It utilizes forward iterators, combining both input and output functionalities.
   - Example:

     ```cpp
     #include <algorithm>
     #include <iostream>
     #include <vector>
     using namespace std;

     int main() {
         vector<int> vec = {1, 2, 3, 4, 5};
         replace(vec.begin(), vec.end(), 3, 10); // Replace all occurrences of 3 with 10

         for (int val : vec) {
             cout << val << " ";
         }
         cout << endl;

         return 0;
     }
     ```

2. **`std::reverse_copy`**:

   - This algorithm copies a range into another range in reverse order. Forward iterators are used for both accessing and assigning elements.
   - Example:

     ```cpp
     #include <algorithm>
     #include <iostream>
     #include <vector>
     using namespace std;

     int main() {
         vector<int> vec = {1, 2, 3, 4, 5};
         vector<int> reversed(5);

         reverse_copy(vec.begin(), vec.end(), reversed.begin());

         for (int val : reversed) {
             cout << val << " ";
         }
         cout << endl;

         return 0;
     }
     ```

#### Limitations

Forward iterators have some limitations:

1. **Cannot be Decremented**:

   - Forward iterators do not support decrement operations.
   - Example:
     ```cpp
     --i1; // Not allowed with forward iterators
     ```

2. **Relational Operators**:

   - Forward iterators cannot be used with relational operators like `<`, `<=`, `>`, `>=`.
   - Example:
     ```cpp
     if (A <= B) { /* Not allowed */ }
     ```

3. **Arithmetic Operators**:

   - Forward iterators do not support arithmetic operations like addition or subtraction.
   - Example:
     ```cpp
     i1 + 1; // Not allowed with forward iterators
     ```

4. **Offset Dereference Operator**:
   - Forward iterators do not support the offset dereference operator (`[]`), used for random access.
   - Example:
     ```cpp
     i1[3]; // Not allowed
     ```

### Example Code

Here's an example demonstrating the use of forward iterators:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    // Assigning values to elements using forward iterator
    for (auto i1 = vec.begin(); i1 != vec.end(); ++i1) {
        *i1 = 1;
    }

    // Accessing values of elements using forward iterator
    for (auto i1 = vec.begin(); i1 != vec.end(); ++i1) {
        cout << *i1 << " ";
    }

    return 0;
}
```
