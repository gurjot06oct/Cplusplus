# Concepts

## **Friendship is not Mutual:**

In C++, when a class declares another class or function as its friend, it grants that entity access to its private and protected members. However, the reverse isn't true. The friend entity does not automatically grant the declaring class access to its private members. This means the friendship is one-sided or asymmetric.

### Example

### 1. FriendA Class Declarations and Declaration

```cpp
class FriendB;

class FriendA {
private:
    int friendAID;

public:
    FriendA() : friendAID(101) {}

    void displayFriendBInfo(FriendB& objFriendB) {
        // Compiler Error! FriendA does not recognize FriendB as a friend, so it cannot access its private members
        cout << "Information accessed by FriendA from FriendB: " << objFriendB.info << endl;
    }
};
```

- We have the declaration of class `FriendA`. It contains a private member `friendAID` and a public member function `displayFriendBInfo`.
- The constructor initializes the private member `friendAID` with a value of 101.
- The `displayFriendBInfo` function attempts to access information held by FriendB using an object of class `FriendB`. However, this results in a compiler error because `FriendA` does not recognize `FriendB` as a friend, preventing access to its private members.

### 2. FriendB Class Definition and Declaration

```cpp
class FriendB {
private:
    string info;

public:
    FriendB() : info("Confidential Information") {}

    friend class FriendA; // FriendA is declared as a friend of FriendB

    void displayFriendAID(FriendA& objFriendA) {
        // No compiler error here
        cout << "FriendA ID accessed by FriendB: " << objFriendA.friendAID << endl;
    }
};
```

- We have the declaration of class `FriendB`. It contains a private member `info` and a public member function `displayFriendAID`.
- The constructor initializes the private member `info` with a value of "Confidential Information".
- The `friend` keyword is used to declare class `FriendA` as a friend of class `FriendB`. This grants class `FriendA` access to the private members of class `FriendB`.
- The `displayFriendAID` function demonstrates accessing the ID of FriendA using an object of class `FriendA`.

### 3. Main Function

```cpp
int main() {
    FriendA alice;
    FriendB bob;
    bob.displayFriendAID(alice); // No compiler error here
    alice.displayFriendBInfo(bob); // Compiler Error! FriendB's member 'info' is private and cannot be accessed by FriendA
    return 0;
}
```

- In the `main` function, objects of classes `FriendA` (Alice) and `FriendB` (Bob) are created.
- `bob.displayFriendAID(alice);` demonstrates accessing the ID of FriendA using an object of class `FriendB`.
- `alice.displayFriendBInfo(bob);` attempts to access information held by FriendB using an object of class `FriendA`, resulting in a compiler error due to the private accessibility of `info` in class `FriendB`.

In this example, `class FriendA` has a member function `displayFriendAID()` that tries to access the private member `y` of `class B` using a `class FriendB` object. However, because `class FriendA` is not declared as a friend of `class FriendB`, it cannot access its private members. This demonstrates that friendship is not mutual, and even though `class FriendB` is a friend of `class FriendA`, the reverse is not automatically true.

## **Friendship is not Inherited:**

When a class (let's call it `FriendClass`) is declared as a friend of another class (let's call it `BaseClass`), `FriendClass` is granted access to the private and protected members of `BaseClass`. This friendship relationship is specific to `BaseClass` and `FriendClass`. It means that `FriendClass` can access the private and protected members of `BaseClass` directly.

However, this friendship does not extend to derived classes of `BaseClass`. If another class (let's call it `DerivedClass`) inherits from `BaseClass`, `FriendClass` will not automatically have access to the private and protected members of `DerivedClass`. Friendship is a specific relationship between the classes explicitly declared as friends; it is not a property that is passed down the inheritance hierarchy.

### Example

The `Parent` class contains a private member `privateData` and a public member `publicData`. The constructor initializes `privateData` to 100. We've declared `accessPrivateData()` as a friend of the `Parent` class.

```cpp
class Parent
{
private:
    int privateData = 100;

public:
    int publicData;
    Parent()
    {
        cout << "Parent class constructor called." << endl;
    }
    friend void accessPrivateData();
};
```

Next, we have a **derived class**, `Child`, which inherits publicly from the `Parent` class. This means that all public members of `Parent` become public members of `Child`.

```cpp
class Child : public Parent
{
private:
    int childPrivateData;

public:
    Child(int value) : Parent(), childPrivateData(value)
    {
        cout << "Child class constructor called." << endl;
    }
};
```

Now, let's discuss how the `accessPrivateData()` function interacts with these classes. Inside `accessPrivateData()`, we create objects of `Parent` and `Child`.

```cpp
void accessPrivateData()
{
    Parent parentObject;
    Child childObject(40);
}
```

Since `accessPrivateData()` is declared as a friend of `Parent`, it can access the private member `privateData` of `Parent`. However, it cannot directly access the private member of `Child`.

**Accessing Private Members with Friend Functions**

1. **Accessing the private member `privateData` of class Parent from the friend function:**
   Inside `accessPrivateData()`, the private member `privateData` of the `Parent` class is accessed directly from an object of the `Parent` class (`parentObject`). Since `accessPrivateData()` is declared as a friend of `Parent`, it can access private members of `Parent` without any compilation errors.

   ```cpp
   cout << "Value of privateData in Parent accessed by friend function: " << parentObject.privateData << endl;
   ```

2. **Accessing `privateData` from an object of class Child:**
   Attempting to access the private member `privateData` of the `Parent` class from an object of the `Child` class (`childObject`) should result in a compilation error. This is because `childObject` only inherits from `Parent` publicly, and private members of a base class are not accessible to derived classes. However, in the case of public inheritance from the base, `Child` can indirectly access `privateData` through `Parent`'s public or protected members, even though `privateData` is not inherited by `Child` directly. This happens because, with public inheritance, `Child` contains a copy of `Parent` that includes all private, public, and protected members. In contrast, attempting to access `privateData` will give an error in the case of protected or private inheritance from the base.

   ```cpp
   cout << "Value of privateData in Child accessed by friend function: " << childObject.privateData << endl;
   ```

3. **Attempting to access the private member `childPrivateData` of class Child:**
   Trying to access the private member `childPrivateData` of the `Child` class from the `accessPrivateData()` function would result in a compilation error. This is because `accessPrivateData()` is declared as a friend of `Parent`, not `Child`, so it cannot access private members of `Child`.

   ```cpp
   // cout << "Value of childPrivateData in Child accessed by friend function: " << childObject.childPrivateData << endl;
   ```
