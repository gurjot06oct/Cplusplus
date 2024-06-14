## Pointers to Constants and Constant Pointers in C++

In C++, pointers provide powerful mechanisms for manipulating data, including pointers to constant values and constant pointers. Let's explore each concept using practical examples.

### Non-constant Integer Variables

```cpp
int variable_int = 20, another_variable_int = 30;
```

#### Pointer to a Constant Integer

A pointer to a constant integer allows the pointer to point to different integers, but it prohibits modification of the integer's value through the pointer.

```cpp
const int *const_ptr_to_int = &variable_int;
// (*const_ptr_to_int)++; // Error: Cannot modify a constant value
const_ptr_to_int = &another_variable_int;
cout << "Value through const_ptr_to_int: " << *const_ptr_to_int << endl;
```

- **const int \*const_ptr_to_int**: This pointer can be reassigned to point to different integers (`variable_int` and `another_variable_int` in this case). However, attempting to modify the value at the pointed address results in a compilation error.

#### Constant Pointer to an Integer

A constant pointer to an integer maintains the same memory address throughout its lifetime. It allows modification of the integer's value but prevents reassignment of the pointer to point to another memory location.

```cpp
int *const const_ptr_to_variable_int = &variable_int;
(*const_ptr_to_variable_int)++;
// const_ptr_to_variable_int = &another_variable_int; // Error: Cannot change a constant pointer
cout << "Value through const_ptr_to_variable_int: " << *const_ptr_to_variable_int << endl;
```

- **int \*const const_ptr_to_variable_int**: This pointer (`const_ptr_to_variable_int`) always points to `variable_int` and allows modifying the value at `variable_int`. However, attempting to assign `const_ptr_to_variable_int` to point to `another_variable_int` would result in a compilation error.

#### Constant Pointer to a Constant Integer

A constant pointer to a constant integer restricts both the pointer's reassignment and the modification of the integer's value.

```cpp
const int *const const_ptr_to_const_int = &variable_int;
// const_ptr_to_const_int = &another_variable_int; // Error: Cannot change a constant pointer
// (*const_ptr_to_const_int)++; // Error: Cannot modify a constant value
cout << "Value through const_ptr_to_const_int: " << *const_ptr_to_const_int << endl;
```

- **const int \*const const_ptr_to_const_int**: This pointer (`const_ptr_to_const_int`) is initialized to point to `variable_int` and cannot be reassigned to point to `another_variable_int`. Furthermore, any attempt to modify the integer's value through `const_ptr_to_const_int` would result in a compilation error.

### Constant Integer Variables

```cpp
const int constant_int = 20, another_constant_int = 30;
```

#### Pointer to a Constant Integer Pointing to a Constant Value

A pointer to a constant integer pointing to a constant value allows reassignment of the pointer to point to different constant integers but prohibits modification of the values through the pointer.

```cpp
const int *const const_ptr_to_constant_int = &constant_int;
// (*const_ptr_to_constant_int)++; // Error: Cannot modify a constant value
const_ptr_to_constant_int = &another_constant_int;
cout << "Value accessed via const_ptr_to_constant_int (constant_int): " << *const_ptr_to_constant_int << endl;
```

- **const int \*const const_ptr_to_constant_int**: This pointer (`const_ptr_to_constant_int`) is initialized to point to `constant_int` and can later be reassigned to point to `another_constant_int`. However, attempting to modify the values at `*const_ptr_to_constant_int` would result in a compilation error.

#### Invalid Declaration: Constant Pointer to a Non-Constant Integer Pointing to a Constant Value

Attempting to declare a constant pointer to an integer pointing to a constant value is invalid in C++.

```cpp
int * const ptr_const_to_constant_int = &constant_int; // Error: Invalid declaration
```

- **int \* const ptr_const_to_constant_int**: This declaration is invalid because it attempts to assign the address of a constant integer (`constant_int`) to a non-constant integer pointer (`ptr_const_to_constant_int`). In C++, a pointer to a constant integer (`const int \*`) can only point to a constant integer, not vice versa.

#### Constant Pointer to a Constant Integer Pointing to a Constant Value

A constant pointer to a constant integer pointing to a constant value restricts both the pointer's reassignment and the modification of the integer's value.

```cpp
const int *const const_ptr_to_const_constant_int = &constant_int;
// const_ptr_to_const_constant_int = &another_constant_int; // Error: Cannot modify a constant pointer
// (*const_ptr_to_const_constant_int)++; // Error: Cannot modify a constant value
cout << "Value accessed via const_ptr_to_const_constant_int (constant_int): " << *const_ptr_to_const_constant_int << endl;
```

- **const int \*const const_ptr_to_const_constant_int**: This pointer (`const_ptr_to_const_constant_int`) is initialized to point to `constant_int` and cannot be reassigned to point to `another_constant_int`. Furthermore, any attempt to modify the integer's value through `const_ptr_to_const_constant_int` would result in a compilation error.
