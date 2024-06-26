### Structures in C++:

In C++, structures are user-defined data types that allow you to group together variables of different data types under a single name. This grouping makes it easier to organize and manipulate related data. Unlike classes, structures default to public access, meaning their members are accessible from outside the structure without explicit access specifiers.

```cpp
struct Person
{
    char name[50];
    int age;
    float salary;
};
```

### Self-Referential Structures in C++:

Self-referential structures, also known as linked structures, are structures that contain a pointer to another instance of the same structure type. This concept is commonly used in data structures like linked lists, trees, and graphs.

```cpp
struct Node
{
    int data;
    Node *next;
};
```

### Pointer to Structure in C++:

Pointers to structures in C++ allow you to manipulate structures dynamically and efficiently. You can allocate memory for a structure dynamically using `new` and access its members using the arrow operator `->`.

```cpp
Person *ptrPerson = new Person;
ptrPerson->age = 25;
```
