The `extern` storage class in C/C++ is used to declare a global variable or a function that is defined in another file or later in the same file. It essentially extends the visibility of the C variables and C functions across multiple files. Here's a detailed explanation of the `extern` storage class, covering its properties like scope, default value, memory location, and lifetime:

### Properties of `extern` Storage Class in C++

- **Scope:** Global across multiple files.
- **Default Value:** Initialized to zero (or null for pointers) if not explicitly initialized.
- **Memory Location:** Stored in global (or static) memory.
- **Lifetime:** From the point of definition until the end of the program.

Compile and link these files together:
g++ -c file1.cpp -o file1.o
g++ -c file2.cpp -o file2.o
g++ -c main.cpp -o main.o
g++ file1.o file2.o main.o -o myprogram
