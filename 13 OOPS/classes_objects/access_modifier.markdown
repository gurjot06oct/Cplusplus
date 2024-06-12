Access modifiers in C++ are keywords used to control the accessibility of class members (data members and member functions) from outside the class. There are three access modifiers in C++: `public`, `private`, and `protected`.

Let's delve into each of them with the help of code examples:

### 1. `public` Access Modifier:

Members declared as `public` are accessible from outside the class. This means that they can be accessed by objects of the class and by functions or code outside the class.

```cpp
class MyClass {
public:
    int publicData;

    void publicMethod() {
        // Code here
    }
};

int main() {
    MyClass obj;
    obj.publicData = 10;  // Accessing public data member
    obj.publicMethod();   // Accessing public member function
    return 0;
}
```

### 2. `private` Access Modifier:

Members declared as `private` are accessible only within the class. They cannot be accessed directly from outside the class, not even by derived classes.

```cpp
class MyClass {
private:
    int privateData;

    void privateMethod() {
        // Code here
    }
public:
    void setData(int value) {
        privateData = value;  // Accessing private data member within the class
    }
};

int main() {
    MyClass obj;
    obj.setData(10);  // Accessing private member through public member function
    // obj.privateData = 10;  // This will cause a compilation error
    // obj.privateMethod();   // This will cause a compilation error
    return 0;
}
```

### 3. `protected` Access Modifier:

Members declared as `protected` are similar to `private` members, but they can be accessed by derived classes.

```cpp
class BaseClass {
protected:
    int protectedData;
};

class DerivedClass : public BaseClass {
public:
    void setData(int value) {
        protectedData = value;  // Accessing protected data member of base class
    }
};

int main() {
    DerivedClass obj;
    obj.setData(10);  // Accessing protected member through public member function
    // obj.protectedData = 10;  // This will cause a compilation error
    return 0;
}
```

### Summary:

- `public`: Accessible from anywhere.
- `private`: Accessible only within the class.
- `protected`: Accessible within the class and by derived classes.

These access modifiers help in encapsulating the implementation details of a class, thereby promoting data hiding and abstraction, which are essential principles of object-oriented programming.
