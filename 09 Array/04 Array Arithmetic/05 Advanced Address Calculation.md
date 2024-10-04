## Address Calculation in Arrays Using Row-Major and Column-Major Orders with Arbitrary-Based Indexing

To compute the address of an element in a multi-dimensional array (2D, 3D, etc.) for both **row-major** and **column-major** order, we can extend the formula to account for arbitrary starting indices in each dimension. This means that each dimension can start at a different index (e.g., -1-based indexing or 3-based indexing), instead of the standard 0-based indexing. Below are the general formulas for both row-major and column-major storage for **arbitrary-based indexing**.

### Notations
- Let $ A $ be the base address of the array.
- Let $ D_1, D_2, ..., D_n $ be the dimensions of an n-dimensional array.
- Let $ L_i $ be the lower bound (starting index) of dimension $ i $.
- Let $ U_i $ be the upper bound of dimension $ i $, so the size of dimension $ i $ is $ U_i - L_i + 1 $.
- Let $ S_i $ be the size of dimension $ i $, i.e., $ S_i = U_i - L_i + 1 $.
- Let $ e $ be the size of each element in the array (in bytes).

We are given the indices $ (i_1, i_2, ..., i_n) $ of the element whose address we want to compute.

### Row-Major Order
In row-major order, the elements are stored row by row, meaning that the last dimension varies fastest. For an arbitrary-based index array, the formula to compute the address of an element $ (i_1, i_2, ..., i_n) $ is as follows:

#### Address Formula (Row-Major with Arbitrary Indices):
$$
\text{Address}(i_1, i_2, ..., i_n) = A + e \times \left( \sum_{k=1}^{n} \left( (i_k - L_k) \times \prod_{j=k+1}^{n} S_j \right) \right)
$$
where $ S_j $ is the size of dimension $ j $, and $ L_j $ is the lower bound (starting index) of dimension $ j $.

#### Explanation:
- The offset $ (i_k - L_k) $ adjusts for the arbitrary starting index in dimension $ k $.
- The term $ \prod_{j=k+1}^{n} S_j $ calculates the cumulative size of the "subarray" corresponding to dimension $ k $.

### Column-Major Order
In column-major order, the elements are stored column by column, meaning that the first dimension varies fastest. For an arbitrary-based index array, the formula to compute the address of an element $ (i_1, i_2, ..., i_n) $ is as follows:

#### Address Formula (Column-Major with Arbitrary Indices):
$$
\text{Address}(i_1, i_2, ..., i_n) = A + e \times \left( \sum_{k=1}^{n} \left( (i_k - L_k) \times \prod_{j=1}^{k-1} S_j \right) \right)
$$
where $ S_j $ is the size of dimension $ j $, and $ L_j $ is the lower bound (starting index) of dimension $ j $.

#### Explanation:
- The offset $ (i_k - L_k) $ adjusts for the arbitrary starting index in dimension $ k $.
- The term $ \prod_{j=1}^{k-1} S_j $ calculates the cumulative size of the "subarray" corresponding to dimensions $ 1 $ through $ k-1 $.

## 2D Array with Arbitrary Indices

Let's prepare the formulas for a **2D array** using arbitrary-based indexing for both **row-major** and **column-major** orders. 

### Notations for 2D Array:
- Let $ A $ be the **base address** of the array.
- Let $ L_1 $ and $ L_2 $ be the **lower bounds** (starting indices) for the two dimensions.
- Let $ U_1 $ and $ U_2 $ be the **upper bounds** for the two dimensions, so the sizes of the dimensions are $ S_1 = U_1 - L_1 + 1 $ and $ S_2 = U_2 - L_2 + 1 $.
- Let $ e $ be the **size** of each element (in bytes).
- Let $ i $ and $ j $ be the indices of the element for which the address is to be calculated.

### Row-Major Order
In **row-major** order, the elements are stored row by row, meaning that the second dimension varies fastest. The address formula for a 2D array with arbitrary-based indexing is:

$$
\text{Address}(i, j) = A + e \times \left( (i - L_1) \times S_2 + (j - L_2) \right)
$$

#### Explanation:
- $ i - L_1 $ adjusts for the arbitrary starting index in the first dimension.
- $ (i - L_1) \times S_2 $ calculates the total number of elements that come before the row where $ i $ is located.
- $ j - L_2 $ adjusts for the arbitrary starting index in the second dimension within the row.

### Column-Major Order
In **column-major** order, the elements are stored column by column, meaning that the first dimension varies fastest. The address formula for a 2D array with arbitrary-based indexing is:

$$
\text{Address}(i, j) = A + e \times \left( (j - L_2) \times S_1 + (i - L_1) \right)
$$

#### Explanation:
- $ j - L_2 $ adjusts for the arbitrary starting index in the second dimension.
- $ (j - L_2) \times S_1 $ calculates the total number of elements that come before the column where $ j $ is located.
- $ i - L_1 $ adjusts for the arbitrary starting index in the first dimension within the column.

### Example

Consider a 2D array with dimensions $ D_1 \times D_2 $ and:
- $ L_1 = -1 $, $ U_1 = 2 $ (so $ S_1 = 4 $)
- $ L_2 = 3 $, $ U_2 = 5 $ (so $ S_2 = 3 $)
- Element size $ e = 4 $ bytes
- Base address $ A = 1000 $

We will compute the address of the element at index $ (1, 4) $.

#### 1. **Row-Major Order:**
$$
\text{Address}(1, 4) = 1000 + 4 \times \left( (1 - (-1)) \times 3 + (4 - 3) \right)
= 1000 + 4 \times \left( 2 \times 3 + 1 \right)
= 1000 + 4 \times 7
= 1028
$$

#### 2. **Column-Major Order:**
$$
\text{Address}(1, 4) = 1000 + 4 \times \left( (4 - 3) \times 4 + (1 - (-1)) \right)
= 1000 + 4 \times \left( 1 \times 4 + 2 \right)
= 1000 + 4 \times 6
= 1024
$$

Thus, for the element at index $ (1, 4) $:
- The row-major address is **1028**.
- The column-major address is **1024**.

These are the generalized formulas for a 2D array with arbitrary-based indexing in both row-major and column-major orders.

## 3D Array with Arbitrary Indices

For a **3D array** with arbitrary-based indexing, we can derive the formulas for both **row-major** and **column-major** order. In these formulas, we will use $ i, j, k $ as the indices corresponding to the dimensions.

### Notations for 3D Array:
- Let $ A $ be the **base address** of the array.
- Let $ L_1, L_2, L_3 $ be the **lower bounds** (starting indices) for the three dimensions.
- Let $ U_1, U_2, U_3 $ be the **upper bounds** for the three dimensions, so the sizes of the dimensions are $ S_1 = U_1 - L_1 + 1 $, $ S_2 = U_2 - L_2 + 1 $, and $ S_3 = U_3 - L_3 + 1 $.
- Let $ e $ be the **size** of each element (in bytes).
- Let $ i, j, k $ be the indices of the element for which the address is to be calculated.

### Row-Major Order
In **row-major** order, the elements are stored such that the last dimension varies fastest, followed by the middle dimension, and finally the first dimension varies the slowest. The address formula for a 3D array with arbitrary-based indexing is:

$$
\text{Address}(i, j, k) = A + e \times \left( (i - L_1) \times S_2 \times S_3 + (j - L_2) \times S_3 + (k - L_3) \right)
$$

#### Explanation:
- $ i - L_1 $, $ j - L_2 $, and $ k - L_3 $ adjust for the arbitrary starting indices in the respective dimensions.
- $ (i - L_1) \times S_2 \times S_3 $ calculates the total number of elements in all layers before the layer corresponding to $ i $.
- $ (j - L_2) \times S_3 $ calculates the number of elements before the row corresponding to $ j $ within the current layer.
- $ k - L_3 $ adjusts for the arbitrary starting index within the current row.

### Column-Major Order
In **column-major** order, the elements are stored such that the first dimension varies fastest, followed by the middle dimension, and finally the last dimension varies the slowest. The address formula for a 3D array with arbitrary-based indexing is:

$$
\text{Address}(i, j, k) = A + e \times \left( (k - L_3) \times S_1 \times S_2 + (j - L_2) \times S_1 + (i - L_1) \right)
$$

#### Explanation:
- $ k - L_3 $, $ j - L_2 $, and $ i - L_1 $ adjust for the arbitrary starting indices in the respective dimensions.
- $ (k - L_3) \times S_1 \times S_2 $ calculates the total number of elements in all layers before the slice corresponding to $ k $.
- $ (j - L_2) \times S_1 $ calculates the number of elements before the column corresponding to $ j $ within the current slice.
- $ i - L_1 $ adjusts for the arbitrary starting index within the current column.

### Example

Consider a 3D array with dimensions $ D_1 \times D_2 \times D_3 $ and:
- $ L_1 = -1 $, $ U_1 = 1 $ (so $ S_1 = 3 $)
- $ L_2 = 2 $, $ U_2 = 4 $ (so $ S_2 = 3 $)
- $ L_3 = 0 $, $ U_3 = 2 $ (so $ S_3 = 3 $)
- Element size $ e = 4 $ bytes
- Base address $ A = 2000 $

We will compute the address of the element at index $ (i, j, k) = (0, 3, 1) $.

#### 1. **Row-Major Order:**
$$
\text{Address}(0, 3, 1) = 2000 + 4 \times \left( (0 - (-1)) \times 3 \times 3 + (3 - 2) \times 3 + (1 - 0) \right)
= 2000 + 4 \times \left( 1 \times 9 + 1 \times 3 + 1 \right)
= 2000 + 4 \times 13
= 2052
$$

#### 2. **Column-Major Order:**
$$
\text{Address}(0, 3, 1) = 2000 + 4 \times \left( (1 - 0) \times 3 \times 3 + (3 - 2) \times 3 + (0 - (-1)) \right)
= 2000 + 4 \times \left( 1 \times 9 + 1 \times 3 + 1 \right)
= 2000 + 4 \times 13
= 2052
$$

Thus, for the element at index $ (0, 3, 1) $:
- The row-major address is **2052**.
- The column-major address is **2052**.

These formulas allow the calculation of addresses in a 3D array with arbitrary-based indexing for both row-major and column-major orders.