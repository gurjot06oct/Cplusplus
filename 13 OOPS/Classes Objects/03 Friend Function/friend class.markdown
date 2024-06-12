### Friend Class:

- A friend class can access private and protected members of other classes where it's declared as a friend.
- To declare a friend class in C++, use the `friend` keyword followed by the class name.
- Example:

```cpp
class A {
    friend class B;
};
```

```cpp
#include <iostream>
using namespace std;

// Declaration of class FriendB
class FriendB;

// Class FriendA with private member numA
class FriendA {
private:
    int numA;

public:
    FriendA() : numA(0) {}

    // Friend declaration for class FriendB
    friend class FriendB;
};

// Class FriendB accessing private member of class FriendA
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
    friendBObj.display(friendAObj); // Accessing private member of class FriendA using friend class FriendB
    return 0;
}
```
