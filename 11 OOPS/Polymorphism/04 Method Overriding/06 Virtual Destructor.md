## Virtual Destructors

In C++, a virtual destructor is a destructor that is declared with the `virtual` keyword in a base class. The purpose of making a destructor virtual is to ensure that the destructor of the most derived class is called when an object is deleted through a pointer to the base class. This is crucial for proper cleanup of resources in polymorphic class hierarchies.

### Why Use Virtual Destructors?

Consider a scenario where you have a base class `Base` and a derived class `Derived`. If you allocate an object of type `Derived` using a pointer to `Base`, and later delete that object using that pointer, without a virtual destructor, only the destructor of `Base` would be called. This means any resources allocated in `Derived` would not be properly cleaned up, leading to potential resource leaks or undefined behavior.

```cpp
class Base {
public:
    virtual ~Base() {
        // Base class destructor
    }
};

class Derived : public Base {
public:
    ~Derived() {
        // Derived class destructor
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Without virtual destructor, only Base's destructor would be called
    return 0;
}
```

### How Virtual Destructors Work

- **Polymorphic Behavior**: When you delete an object through a pointer to a base class that has a virtual destructor, the C++ runtime determines the actual type of the object and calls the destructor of that type. This is achieved through the vtable (virtual table) mechanism, where the vtable of the object's actual type is consulted to find the correct destructor to call.
- **Cleanup Responsibility**: This ensures that all destructors up the inheritance hierarchy are called in the correct order, allowing each class to clean up its resources properly. This is especially important in cases where derived classes allocate resources that need explicit deallocation.

- **Base Class Responsibility**: Even though derived classes override the virtual destructor, it's still a good practice to define the base class destructor as virtual. This way, if any derived class further subclasses, the correct destructor will still be called.

### When to Use Virtual Destructors

You should declare a destructor virtual in a base class if:

- Your class is designed to be inherited from.
- You have functions that are `virtual` in the base class and you expect these functions to be overridden in derived classes.
- Your class manages resources (like dynamically allocated memory, file handles, database connections) that need proper cleanup.
- You are uncertain about the future use of your class and want to ensure proper cleanup in potential future derived classes.
