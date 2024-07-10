# Structure Conversion Arithmetic

## Array with Dimensions and Index Variables

### 1D Array:

- Dimension: `[m]`
- Index variable: $ i $

### 2D Array:

- Dimension: `[p][q]`
- Index variables: $ x $ (row index), $ y $ (column index)

### 3D Array:

- Dimension: `[r][s][t]`
- Index variables: $ l $ (layer index), $ u $ (row index), $ v $ (column index)

---

## 1D to 2D Array Conversion

**Conversion:**

- You have a 1D array `arr1D` of size `m`.
- Imagine 1D array of size `m`, as 2D array of `[1][m]`.
- Then, reinterpret this as a 2D array `arr2D` of `[p][q]`.

**Calculate `x` and `y` from `i`:**

- $x = \frac{\text{i}}{q}$
- $y = \text{i} \% q$

## 1D to 3D Array Conversion

**Conversion:**

- You have a 1D array `arr1D` of size `m`.
- Imagine 1D array of size `m`, as 3D array of `[1][1][m]`.
- Then, reinterpret this as a 3D array `arr3D` of `[r][s][t]`.

**Calculate `l`, `u`, and `v` from `i`:**

- $l = \frac{\text{i}}{s \times t}$
- $u = \frac{\left(\text{i}\% (s \times t)\right)}{t} = \left( \frac{\text{i}}{t} \right) \% s$
- $v = \left(\text{i}\% (s \times t)\right) \% t = \text{i} \% t$

## 2D to 1D Array Conversion

**Conversion Formulas:**

- You have a 2D array `arr2D` of `[p][q]`.
- Then, reinterpret this as a 2D array of `[1][m]`.
- Dereference this 2D array of `[1][m]` to get 1D array with of size `p*q`.

**Calculate `i` from `x` and `y`:**

- Flatten the 2D indices into a 1D index: $i = x \times q + y$

## 2D to 3D Array Conversion

**Conversion Formulas:**

- You have a 2D array `arr2D` of `[p][q]`.
- Imagine 2D array of `[p][q]`, as 3D array of `[1][p][q]`.
- Then, reinterpret this as a 3D array `arr3D` of `[r][s][t]`.

**Calculate `l`, `u`, and `v` from `x` and `y`:**

- Flatten the 2D indices into a 1D index: $\text{flat\_index} = x \times q + y$.
- Invert the 2D index into 3D coordinates:
  - $x = \frac{\text{flat\_index}}{s \times t}$
  - $y = \frac{\left(\text{flat\_index}\% (s \times t)\right)}{t} = \left( \frac{\text{flat\_index}}{t} \right) \% s$
  - $z = \left(\text{flat\_index}\% (s \times t)\right) \% t = \text{flat\_index} \% t$

## 3D to 1D Array Conversion

**Conversion Formulas:**

- You have a 3D array `arr3D` of `[r][s][t]`.
- Then, reinterpret this as a 3D array of `[1][1][m]`.
- Double Dereference this 3D array of `[1][1][m]` to get 1D array with of size `r*s*t`.

**Calculate `i` from `l`, `u`, and `v`:**

- Flatten the 3D indices into a 1D index: $ i = l \times s \times t + u \times t + v $.

## 3D to 2D Array Conversion

**Conversion Formulas:**

- You have a 3D array `arr3D` of `[r][s][t]`.
- Then, reinterpret this as a 3D array of `[1][p][q]`.
- Dereference this 3D array of `[1][p][q]` to get 2D array with of `[p][q]`.

**Calculate `x` and `y` from `l`, `u`, and `v`:**

- Flatten the 3D indices into a 1D index: $ i = l \times s \times t + u \times t + v $.
- Invert the 3D index into 2D coordinates:
  - $x = \frac{\text{flat\_index}}{p \times q}$
  - $y = \frac{\left(\text{flat\_index}\% (p \times q)\right)}{q} = \left( \frac{\text{flat\_index}}{q} \right) \% p$
  - $z = \left(\text{flat\_index}\% (p \times q)\right) \% q = \text{flat\_index} \% q$
