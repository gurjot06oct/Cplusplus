## Friend Functions
Friend functions and classes in C++ offer a mechanism for accessing private and protected members of different classes. Here's a clear breakdown of their functionality and usage:

### Friend Function:

- A friend function can access private and protected members of a class.
- It can be a global function or a member function of another class.
- Syntax:

**Features:**

- A friend function is not a member function of the class but can access its private and protected members.
- It's declared using the `friend` keyword within the class.
- Can be called like an ordinary function.
- Can be declared in any section of the class (public, private, or protected).

By understanding friend functions and classes, you can efficiently manage access to private and protected members in C++.

**Global Function as Friend Function:**

```cpp
#include <iostream>
using namespace std;

// Class declaration
class FriendB;

class FriendA {
private:
    int numA;

public:
    FriendA() : numA(0) {}

    // Friend declaration for global function
    friend void friendFunction(FriendA& obj);
};

// Friend function definition
void friendFunction(FriendA& obj) {
    // Accessing private member of class FriendA
    cout << "Value of numA in FriendA accessed by friend function: " << obj.numA << endl;
}

int main() {
    FriendA friendAObj;
    friendFunction(friendAObj); // Accessing private member of class FriendA using friend function
    return 0;
}

```

**Member Function of Another Class as Friend Function:**

```cpp
#include <iostream>
using namespace std;

// Forward declaration of class FriendB
class FriendB;

// Class FriendA with private member numA
class FriendA {
private:
    int numA;

public:
    FriendA() : numA(0) {}

    // Friend declaration for member function of class FriendB
    friend void FriendB::display(FriendA& obj);
};

// Class FriendB with member function accessing private member of class FriendA
class FriendB {
public:
    void display(FriendA& obj) {
        // Accessing private member of class FriendA
        cout << "Value of numA in FriendA accessed by FriendB: " << obj.numA << endl;
    }
};

int main() {
    FriendA friendAObj;
    FriendB friendBObj;
    friendBObj.display(friendAObj); // Accessing private member of class FriendA using friend member function of class FriendB
    return 0;
}

```

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
