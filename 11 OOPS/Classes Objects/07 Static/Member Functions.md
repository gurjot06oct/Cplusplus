### Static Member Functions

In C++, the `static` keyword can also be used with member functions of a class to create static member functions. Static member functions have certain unique characteristics:

- They are independent of any object of the class.
- They can be called even if no objects of the class exist.
- They can be accessed using the class name through the scope resolution operator.
- They can access only static data members and static member functions inside or outside of the class.
- They have a scope inside the class and cannot access the current object pointer.
- They can be used to determine how many objects of the class have been created.

#### Example:

Let's delve into a C++ program demonstrating the usage of static member functions:

```cpp
#include <iostream>
using namespace std;

class Box
{
private:
    static int length;
    static int breadth;
    static int height;

public:
    static void display()
    {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Height: " << height << endl;
    }
};

// Initialize the static data members
int Box::length = 10;
int Box::breadth = 20;
int Box::height = 30;

// Driver Code
int main()
{
    Box box;

    cout << "Static member function called using object name: \n" << endl;
    box.display();

    cout << "\nStatic member function called using class name: \n" << endl;
    Box::display();

    return 0;
}
```

**Output:**

```
Static member function called using object name:

Length: 10
Breadth: 20
Height: 30

Static member function called using class name:

Length: 10
Breadth: 20
Height: 30
```

#### Explanation:

In the provided example, we have a class `Box` with three static data members: `length`, `breadth`, and `height`. We also have a static member function `display()` that prints the values of these static data members.

In the `main()` function, we create an object of class `Box` and call the `display()` function both using the object name and the class name. In both cases, the static member function is able to access the static data members of the class and print their values.

Static member functions provide a way to perform operations that are not dependent on any particular object of the class, making them useful for operations that are common to all objects of the class.
