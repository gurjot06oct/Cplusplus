Friend functions and classes in C++ offer a mechanism for accessing private and protected members of different classes. Here's a clear breakdown of their functionality and usage:

**Friend Class:**

- A friend class can access private and protected members of other classes where it's declared as a friend.
- To declare a friend class in C++, use the `friend` keyword followed by the class name.
- Example:

```cpp
class A {
    friend class B;
};
```

**Friend Function:**

- A friend function can access private and protected members of a class.
- It can be a global function or a member function of another class.
- Syntax:

```cpp
friend return_type function_name(arguments);    // for a global function
// or
friend return_type class_name::function_name(arguments);    // for a member function of another class
```

**Examples:**

1. Global Function as Friend Function:

```cpp
class A {
    friend void friendFunction(A& obj);
};
```

2. Member Function of Another Class as Friend Function:

```cpp
class A {
    friend void anotherClass::memberFunction(A&);
};
```

**Features:**

- A friend function is not a member function of the class but can access its private and protected members.
- It's declared using the `friend` keyword within the class.
- Can be called like an ordinary function.
- Can be declared in any section of the class (public, private, or protected).

**Advantages:**

- Allows access to private members without inheritance.
- Acts as a bridge between classes, enhancing versatility, especially with overloaded operators.

**Disadvantages:**

- Violates data hiding principles.
- Cannot perform runtime polymorphism in its members.

**Important Points:**

- Use friends sparingly to maintain encapsulation.
- Friendship is not mutual or inherited.
- Not applicable in Java.

By understanding friend functions and classes, you can efficiently manage access to private and protected members in C++.

Let's break down the concept of friend functions and classes with code examples.

**Friend Class:**

```cpp
#include <iostream>
using namespace std;

// Declaration of class B
class B;

// Class A with private member x
class A {
private:
    int x;

public:
    A() : x(0) {}

    // Friend declaration for class B
    friend class B;
};

// Class B accessing private member of class A
class B {
public:
    void display(A& obj) {
        // Accessing private member of class A
        cout << "Value of x in A accessed by B: " << obj.x << endl;
    }
};

int main() {
    A objA;
    B objB;
    objB.display(objA); // Accessing private member of class A using friend class B
    return 0;
}
```

**Friend Function:**

**Global Function as Friend Function:**

```cpp
#include <iostream>
using namespace std;

// Class declaration
class A {
private:
    int x;

public:
    A() : x(0) {}

    // Friend declaration for global function
    friend void friendFunction(A& obj);
};

// Friend function definition
void friendFunction(A& obj) {
    // Accessing private member of class A
    cout << "Value of x in A accessed by friend function: " << obj.x << endl;
}

int main() {
    A objA;
    friendFunction(objA); // Accessing private member of class A using friend function
    return 0;
}
```

**Member Function of Another Class as Friend Function:**

```cpp
#include <iostream>
using namespace std;

// Forward declaration of class B
class B;

// Class A with private member x
class A {
private:
    int x;

public:
    A() : x(0) {}

    // Friend declaration for member function of class B
    friend void B::display(A& obj);
};

// Class B with member function accessing private member of class A
class B {
public:
    void display(A& obj) {
        // Accessing private member of class A
        cout << "Value of x in A accessed by B: " << obj.x << endl;
    }
};

int main() {
    A objA;
    B objB;
    objB.display(objA); // Accessing private member of class A using friend member function of class B
    return 0;
}
```

**Friendship is not Mutual:**

In C++, when a class declares another class or function as its friend, it grants that entity access to its private and protected members. However, the reverse isn't true. The friend entity does not automatically grant the declaring class access to its private members. This means the friendship is one-sided or asymmetric.

```cpp
#include <iostream>
using namespace std;

// Forward declaration of class B
class B;

// Class A with a private member 'x' and a member function
class A {
private:
    int x;

public:
    A() : x(10) {}

    // Member function to access private member of class B using class B object
    void displayB(B& objB) {
        // Trying to access private member 'y' of class B using class B object
        // This will result in a compilation error because class A is not a friend of class B
        // and cannot access its private members.
        cout << "Value of 'y' in B accessed by A: " << objB.y << endl; // Compilation Error!
    }
};

// Class B with a private member 'y'
class B {
private:
    int y;

public:
    B() : y(20) {}

    // Friend declaration for class A
    friend class A;

    // Member function to access private member 'x' of class A
    void displayA(A& objA) {
        // Accessing the private member 'x' of class A using class A object
        cout << "Value of 'x' in A accessed by B: " << objA.x << endl;
    }
};

int main() {
    A objA;
    B objB;
    objB.displayA(objA); // Accessing private member 'x' of class A using class B object
    objA.displayB(objB); // Trying to access private member 'y' of class B using class A object
    return 0;
}
```

In this example, `class A` has a member function `displayB()` that tries to access the private member `y` of `class B` using a `class B` object. However, because `class A` is not declared as a friend of `class B`, it cannot access its private members. This demonstrates that friendship is not mutual, and even though `class B` is a friend of `class A`, the reverse is not automatically true.

**Friendship is not Inherited:**

In this example, we have a base class A with a friend function, and a derived class B. Even though B is derived from A, it does not inherit the friendship status of the friend function from class A.

```cpp
#include <iostream>
using namespace std;

// Base class
class Base
{
private:
    int x = 100;

public:
    int y;
    // Base class constructor
    Base()
    {
        cout << "Base class constructor called." << endl;
    }
    friend void friendFunction(); // Declaring friend function
};

// Derived class
class Derived : public Base
{
private:
    int z;

public:
    // Derived class constructor
    Derived(int value) : Base(), z(40)
    {
        cout << "Derived class constructor called." << endl;
        // Attempting to access private member 'x' of class Base from class Derived
        // This will result in a compilation error since 'x' is private in class Base
        // cout << "Value of x in Base accessed by Derived: " << x << endl;
    }
};

// Friend function definition
void friendFunction()
{
    Base objBase;
    Derived objDerived(40);

    // Accessing private member 'x' of class Base from the friend function
    cout << "Value of x in Base accessed by friend function: " << objBase.x << endl; // No Error: function is friend of Base

    // Accessing 'x', the private member of class Base, from an object of class Derived
    // This is a bug, as 'objDerived' has not inherited `x` cause it is a private member
    cout << "Value of x in Derived accessed by friend function: " << objDerived.x << endl; // No Error: function is friend of Base

    // Attempting to access private member 'z' of class Derived
    // This will result in a compilation error since 'friendFunction' is not a friend of class Derived
    // cout << "Value of x in B accessed by friend function: " << objDerived.z << endl;

    // You can also assign values to `objBase.x` and members `objDerived.x` if needed
}

int main()
{
    friendFunction();
    return 0;
}
```

The bug in the code lies in the `friendFunction` accessing the private member `x` of the `Derived` class. Let's clarify the issue:

1. **Private Member Access in Derived Class**: In C++, private members of a base class are not directly accessible by derived classes. Even though `Derived` is derived from `Base`, the private member `x` of `Base` is not inherited by `Derived`. Therefore, attempting to access `x` from `Derived` should result in a compilation error.

2. **Friend Function Access**: The `friendFunction` is declared as a friend of the `Base` class. This means it has access to the private members of `Base`. However, it doesn't have direct access to the private members of derived classes of `Base`, such as `Derived`.

3. **Bug Description**: Despite not inheriting the private member `x`, the `friendFunction` erroneously accesses `x` from an object of the `Derived` class (`objDerived`). This behavior contradicts the principles of inheritance and encapsulation in C++, leading to unexpected results.

4. **Expected Behavior**: The `friendFunction` should only access the private members of the `Base` class, not the private members of classes derived from `Base`. Therefore, attempting to access `x` from `objDerived` in `friendFunction` should result in a compilation error.

The bug arises from `friendFunction` being able to access the private member `x` of the `Derived` class, which it shouldn't have access to due to the private nature of inheritance.
