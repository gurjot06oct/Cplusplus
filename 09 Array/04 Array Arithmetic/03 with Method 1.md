# Why Method 1 do not utilize a nested frame structure

let's create a visualization for a 3D array with dimensions [2][2][5]. Here, we'll focus on showing how the memory addresses are not contiguous due to the different levels of pointers involved.

### 3D Array Explanation and Visualization

#### Memory Allocation

1. **Top-Level Pointer (p)**:
   - `p` points to an array of 2 pointers to pointers (`p1`).
2. **Second-Level Pointers (p1)**:

   - Each `p1` points to an array of 2 pointers to integers (`p2`).

3. **Third-Level Pointers (p2)**:
   - Each `p2` points to an array of 5 integers.

#### Diagram

We'll represent the pointers and their allocated memory visually, using hypothetical memory addresses to demonstrate non-contiguous allocation.

- Assuming size(`int*`) is 8 bytes and size(`int`) is 4 bytes.

```
p (Address: 101)
|
|----> (Address: 1001)
|       |
|       |----> (Address: 2001)
|       |       |----> [0, 1, 2, 3, 4] (int array) (Addresses: 3001 to 3020)
|       |
|       |----> (Address: 2009)
|               |----> [5, 6, 7, 8, 9] (int array) (Addresses: 4001 to 4020)
|
|----> (Address: 1009)
        |
        |----> (Address: 2017)
        |       |----> [10, 11, 12, 13, 14] (int array) (Addresses: 5001 to 5020)
        |
        |----> (Address: 2025)
                |----> [15, 16, 17, 18, 19] (int array) (Addresses: 6001 to 6020)
```

#### Detailed Memory Layout

Let's use specific memory addresses for clarity:

- `p` is allocated at `101`
- `p[0]` points to `1001` and `2009`
  - `p[0][0]` points to `3001` to `3020`
  - `p[0][1]` points to `4001` to `4020`
- `p[1]` points to `2017` and `2025`
  - `p[1][0]` points to `5001` to `5020`
  - `p[1][1]` points to `6001` to `6020`

This shows that the pointers at each level have different memory addresses, and the integers at the lowest level are contiguous within their own allocation blocks, but not across different blocks.

This visualization effectively demonstrates how 3D arrays and pointers work in C/C++, highlighting the non-contiguous nature of the memory allocation due to which they do not utilize a nested frame structure.
