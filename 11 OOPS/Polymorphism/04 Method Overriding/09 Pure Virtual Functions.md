### Pure Virtual Functions and Abstract Classes in C++

In C++, an abstract class is a class that cannot be instantiated and is typically used as a base class. Abstract classes are created when we cannot provide implementations for all functions in the base class because the exact implementation depends on the derived classes. A classic example is a `Shape` class with a pure virtual function `draw()`. While the `Shape` class itself cannot define how to draw a shape, every derived class like `Circle` or `Square` will have its own implementation of `draw()`.

### Pure Virtual Functions

A pure virtual function is a function declared in a base class that must be overridden in derived classes. It is specified by assigning `0` in the declaration.

```cpp
// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
};
```

Derived classes must override pure virtual functions; otherwise, they also become abstract.

### Complete Example

```cpp
#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
};

// Derived class implementing the pure virtual function
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    // We cannot instantiate Shape because it is abstract
    // Shape s; // Error

    // Creating an object of derived class
    Circle c;
    c.draw(); // Output: Drawing Circle

    return 0;
}
```

### Key Points

1. **Abstract Classes and Pure Virtual Functions:**

   - A class is abstract if it has at least one pure virtual function.
   - Abstract classes cannot be instantiated directly.

   ```cpp
   class Animal {
   public:
       virtual void move() = 0; // Pure virtual function
   };
   ```

2. **Pointers and References of Abstract Classes:**

   - We can have pointers and references to abstract classes.

   ```cpp
   class Animal {
   public:
       virtual void move() = 0;
   };

   class Dog : public Animal {
   public:
       void move() override {
           cout << "Dog runs" << endl;
       }
   };

   int main() {
       Animal* animal = new Dog();
       animal->move(); // Output: Dog runs
       delete animal;
       return 0;
   }
   ```

3. **Derived Classes Inheriting Pure Virtual Functions:**

   - If a derived class does not override a pure virtual function, it also becomes abstract.

   ```cpp
   class Animal {
   public:
       virtual void move() = 0;
   };

   class Bird : public Animal {
       // No override for move(), Bird is also abstract
   };
   ```

4. **Constructors in Abstract Classes:**

   - Abstract classes can have constructors.

   ```cpp
   class Base {
   protected:
       int x;
   public:
       Base(int i) : x(i) {
           cout << "Base constructor called" << endl;
       }
       virtual void display() = 0;
   };

   class Derived : public Base {
       int y;
   public:
       Derived(int i, int j) : Base(i), y(j) {}
       void display() override {
           cout << "x = " << x << ", y = " << y << endl;
       }
   };

   int main() {
       Derived d(4, 5);
       d.display(); // Output: x = 4, y = 5

       Base* ptr = new Derived(6, 7);
       ptr->display(); // Output: x = 6, y = 7
       delete ptr;

       return 0;
   }
   ```

5. **Abstract Classes with `struct` Keyword:**

   - An abstract class can also be defined using the `struct` keyword.

   ```cpp
   struct Shape {
       virtual void draw() = 0;
   };
   ```
