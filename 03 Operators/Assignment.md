### Assignment Operators in C++

Assignment operators in C++ are efficient tools for combining operations with assignment in a single step. They enhance code clarity and reduce redundancy by performing arithmetic or bitwise operations directly on variables.

#### Initializing Variables

Let's begin by initializing three integer variables: `numA`, `numB`, and `numC`.

#### Compound Assignment Operator Examples

##### `+=` Operator

The `+=` operator adds the value of `numB` to `numA` and assigns the result to `numA`.

```cpp
numA += numB; // numA = numA + numB -> numA = 10 + 5 = 15
std::cout << "numA += numB -> numA = " << numA << std::endl;
```

##### `-=` Operator

The `-=` operator subtracts the value of `numC` from `numB` and assigns the result to `numB`.

```cpp
numB -= numC; // numB = numB - numC -> numB = 5 - 2 = 3
std::cout << "numB -= numC -> numB = " << numB << std::endl;
```

##### `*=` Operator

The `*=` operator multiplies `numC` by 3 and assigns the result back to `numC`.

```cpp
numC *= 3; // numC = numC * 3 -> numC = 2 * 3 = 6
std::cout << "numC *= 3 -> numC = " << numC << std::endl;
```

##### `/=` Operator

The `/=` operator divides `numA` by `numC` using integer division and assigns the quotient back to `numA`.

```cpp
numA /= numC; // numA = numA / numC -> numA = 15 / 6 = 2 (integer division)
std::cout << "numA /= numC -> numA = " << numA << std::endl;
```

##### `%=` Operator

The `%=` operator calculates the remainder when `numB` is divided by 2 and assigns the result back to `numB`.

```cpp
numB %= 2; // numB = numB % 2 -> numB = 3 % 2 = 1
std::cout << "numB %= 2 -> numB = " << numB << std::endl;
```

##### `<<=` Operator

The `<<=` operator shifts `numA` left by 1 bit and assigns the result back to `numA`.

```cpp
numA <<= 1; // numA = numA << 1 -> numA = 2 << 1 = 4
std::cout << "numA <<= 1 -> numA = " << numA << std::endl;
```

##### `>>=` Operator

The `>>=` operator shifts `numB` right by 1 bit and assigns the result back to `numB`.

```cpp
numB >>= 1; // numB = numB >> 1 -> numB = 1 >> 1 = 0
std::cout << "numB >>= 1 -> numB = " << numB << std::endl;
```

##### `&=` Operator

The `&=` operator performs a bitwise AND operation between `numC` and 4 and assigns the result back to `numC`.

```cpp
numC &= 4; // numC = numC & 4 -> numC = 6 & 4 = 4
std::cout << "numC &= 4 -> numC = " << numC << std::endl;
```

#### Chained Assignments

Chained assignments demonstrate sequential operations on multiple variables.

```cpp
int x, y, z;
x = y = z = 10;
std::cout << "\nChained assignment: x = y = z = 10 -> x = " << x << ", y = " << y << ", z = " << z << std::endl;
```

##### Mixed Chained Assignments

Mixed chained assignments combine arithmetic operations sequentially.

```cpp
x -= y += z;
std::cout << "Mixed chained assignment: x -= y += z -> x = " << x << ", y = " << y << ", z = " << z << std::endl;
```

##### More Complex Chained Assignment Example

Complex chained assignments illustrate compound operations involving multiple variables.

```cpp
numA += numB *= numC;
std::cout << "Chained assignment example: numA += numB *= numC -> numA = " << numA << ", numB = " << numB << ", numC = " << numC << std::endl;

numB /= numC -= 1;
std::cout << "Chained assignment with decrement: numB /= numC -= 1 -> numB = " << numB << ", numC = " << numC << std::endl;

numA %= numB |= 1;
std::cout << "Chained assignment with bitwise OR: numA %= numB |= 1 -> numA = " << numA << ", numB = " << numB << ", numC = " << numC << std::endl;

return 0;
```

Compound assignment operators in C++ provide a concise and efficient way to combine operations with assignment, enhancing code readability and maintainability. Understanding their usage is crucial for writing efficient and clear C++ programs.
