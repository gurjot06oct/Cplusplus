## Theory of Nested Box Structures for representing Arrays

The theory of nested box structures for representing arrays provides a visual and conceptual framework to understand multidimensional arrays, their elements, and how they are nested within each other. Here's a summary of the key concepts and notation used:

### Nested Box Model Representation

The nested box model visually represents how elements are structured within an N-dimensional array. Each dimension adds a layer or frame of nested boxes around the elements of the previous dimension.

### Basic Elements and Notation

- **Elementary Box (Cell)**: Represents a single element within the array structure.
- **Frame**: A collection of cells or sub-frames, analogous to a row or column in 2D arrays.
- **Main Frame**: Encapsulates the elements of the second-to-last dimension, serving as the highest level of the array structure.

### Dimensions and Levels

In the conceptual framework of N-dimensional arrays represented by nested boxes:

- **Nested Boxes Represent Each Level of Dimension**: Each dimension of the array adds another frame around the existing structure, including `0` Dimension. For example, in a 2D array, each row and column forms a distinct frame within the overall array structure.

- **Visualizing Dimensions**: Visualize each dimension as adding a new layer or frame of nested boxes around the elements of the previous dimension. This visualization helps in understanding how elements are organized and accessed within the array.

The theory categorizes arrays into different dimensions:

- **0D Array**: A single element.
  ```
  +--+
  | 1|
  +--+
  ```
- **1D Array**: A linear collection of elements.
  ```
  +----------------------------+
  |  +--+ +--+ +--+ +--+ +--+  |
  |  | 1| | 2| | 3| | 4| | 5|  |
  |  +--+ +--+ +--+ +--+ +--+  |
  +----------------------------+
  ```
- **2D Array**: A grid of 1D arrays.

  ```
  +------------------------------------------------------------------+
  |  +----------------------------+  +----------------------------+  |
  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |
  |  |  | 1| | 2| | 3| | 4| | 5|  |  |  | 6| | 7| | 8| | 9| |10|  |  |
  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |
  |  +----------------------------+  +----------------------------+  |
  +------------------------------------------------------------------+
  ```

- **3D Array**: Layers of 2D arrays.

  ```
  +------------------------------------------------------------------------+
  |                                                                        |
  |  +------------------------------------------------------------------+  |
  |  |  +----------------------------+  +----------------------------+  |  |
  |  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
  |  |  |  | 1| | 2| | 3| | 4| | 5|  |  |  | 6| | 7| | 8| | 9| |10|  |  |  |
  |  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
  |  |  +----------------------------+  +----------------------------+  |  |
  |  +------------------------------------------------------------------+  |
  |                                                                        |
  |  +------------------------------------------------------------------+  |
  |  |  +----------------------------+  +----------------------------+  |  |
  |  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
  |  |  |  |11| |12| |13| |14| |15|  |  |  |16| |17| |18| |19| |20|  |  |  |
  |  |  |  +--+ +--+ +--+ +--+ +--+  |  |  +--+ +--+ +--+ +--+ +--+  |  |  |
  |  |  +----------------------------+  +----------------------------+  |  |
  |  +------------------------------------------------------------------+  |
  +------------------------------------------------------------------------+
  ```

- **nD Array**: \( n \)-dimensional collection of \( (n-1) \)-dimensional arrays.

### Dereferencing (`*`) and Referencing (`&`)

- **Dereferencing (Going Into a Box `*`)**: Pointing to elements or sub-arrays within a specific dimension. It involves navigating deeper into the nested boxes to retrieve values.

- **Referencing (Going Out of a Box `&`)**: Pointing the address of the outer array that encompasses the current array or element. It signifies moving outward from a specific element or sub-array to access the encompassing structure.

- **Analogous to Physical Boxes**:

  - Each dereferencing step (`*`) is like opening a box to look inside and retrieve a value.
  - Each Referencing step (`&`) is like closing an open box which you where observing.

- **Referencing (`&`) at the Main Frame (Last Level)**: At the outermost dimension (main frame), referencing (`&`) behaves uniquely because there are no further outer dimensions to reference, meaning no further enclosing box to close.

- **Address of Array and Referencing**: Each level of dimensionality returns the base address of that dimension. Dereferencing continues recursively through each dimension of the array. At each step, it returns the base address of the array at that particular dimension.

## Array Structures

### Static Arrays:

- Static arrays utilize total nested box model.

### Dynamic Arrays

Dynamic arrays can be represented in different ways:

- **Method 1: Single-Level Pointer**: In this method, dynamic arrays do not utilize a nested box structure.

- **Method 2: Two-Dimensional Pointer**: Here, dynamic arrays utilize a partial nested box structure.
