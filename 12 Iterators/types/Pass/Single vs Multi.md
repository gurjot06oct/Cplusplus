# Single-Pass Algorithms

Single-pass algorithms are algorithms that traverse a range of elements exactly once, typically from the beginning to the end. Once an element is processed, it's not revisited during the same traversal. In single-pass algorithms, each element in the sequence is processed in a linear manner, and the algorithm terminates after reaching the end of the range.

## Characteristics:

1. **Sequential Traversal**: Elements are processed sequentially from start to end.
2. **One-Time Processing**: Each element is accessed, processed, and potentially modified or used in computations once.
3. **Efficiency**: These algorithms are efficient in terms of memory usage and processing time, especially for large datasets, as they do not require storing intermediate states.

## Examples:

- Linear search
- Summation of elements in a sequence
- Copying elements from one container to another sequentially

# Multi-Pass Algorithms

Multi-pass algorithms are algorithms that traverse a range of elements more than once. They may revisit elements multiple times during different phases of the algorithm. These algorithms often require storing intermediate states or information about previously processed elements to perform additional operations or analyses.

## Characteristics:

1. **Repeated Traversal**: The algorithm iterates over the range multiple times, potentially in different directions or with varying steps.
2. **Iterative Processing**: Elements may be processed iteratively, with each pass refining or building upon the results of previous passes.
3. **Complexity**: Multi-pass algorithms may have higher memory and computational requirements compared to single-pass algorithms due to the need to store and manipulate intermediate states.

## Examples:

- Sorting algorithms like Bubble Sort, Merge Sort, or Quick Sort, which may involve multiple passes over the dataset to rearrange elements.
- Iterative algorithms for graph traversal or optimization problems, where repeated passes are made to refine solutions or explore alternative paths.
