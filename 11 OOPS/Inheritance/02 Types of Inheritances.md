### Types of Inheritance

Inheritance in C++ can take several forms, each with specific characteristics and use cases. Here, we'll delve into each type of inheritance in more detail:

#### 1. Single Inheritance

- **Description:** A derived class inherits from only one base class.
- **Use Case:** This is the most straightforward form of inheritance. It’s used when there is a clear hierarchical relationship between two classes.
- **Example:** A `Car` class derived from a `Vehicle` class.
  - **Base Class:** `class Vehicle { ... };`
  - **Derived Class:** `class Car : public Vehicle { ... };`

#### 2. Multiple Inheritance

- **Description:** A derived class inherits from more than one base class.
- **Constructor and Destructor Order:** Constructors are called in the order in which inheritance is defined in the derived class, and Destructor in reverse of that order.
- **Use Case:** Multiple inheritance is used when a class needs to inherit functionalities from more than one base class.
- **Example:** A `FlyingCar` class derived from both `Car` and `Aircraft` classes.

  - **Base Classes**:
    ```cpp
    class Car { public: void drive() { ... } };
    class Aircraft { public: void fly() { ... } };
    ```
  - **Derived Class**:
    ```cpp
    class FlyingCar : public Car, public Aircraft { ... };
    ```

**Ambiguity:** When two base classes have methods or properties with the same name, it can lead to ambiguity.
**Diamond Problem:** Like multiple inheritance, hybrid inheritance can suffer from the diamond problem, which can be mitigated using virtual inheritance.

**Solutions:**

- **Scope Resolution Operator (`::`):** Used to specify which base class method or property to use.
- **Virtual Inheritance:** Used to solve the diamond problem by ensuring only one instance of the common base class is shared by all derived classes.

#### 3. Multilevel Inheritance

- **Description:** A derived class is derived from another derived class.
- **Use Case:** Used to model a chain of inheritance where each class adds more specific features to the preceding class.
- **Example:** A `RaceCar` class derived from a `Car` class, which in turn is derived from a `Vehicle` class.
  - **Base Class:** `class Vehicle { ... };`
  - **Intermediate Derived Class:** `class Car : public Vehicle { ... };`
  - **Final Derived Class:** `class RaceCar : public Car { ... };`
- **Constructor and Destructor Order:** Constructors and destructors are called in the order of inheritance, from base to derived.

#### 4. Hierarchical Inheritance

- **Description:** Multiple derived classes inherit from a single base class.
- **Use Case:** Used when multiple classes need to share a common set of functionalities defined in a single base class.
- **Example:** `Car`, `Truck`, and `Motorcycle` classes derived from a single `Vehicle` class.
  - **Base Class:** `class Vehicle { ... };`
  - **Derived Classes:**
    ```cpp
    class Car : public Vehicle { ... };
    class Truck : public Vehicle { ... };
    class Motorcycle : public Vehicle { ... };
    ```

**Advantages:**

- **Code Reusability:** Common code is placed in the base class and reused by all derived classes.

#### 5. Hybrid Inheritance

- **Description:** A combination of two or more types of inheritance. It often involves multiple and hierarchical inheritance.
- **Use Case:** Used in complex systems where functionalities need to be inherited from multiple base classes and structured in a hierarchical manner.
- **Example:** A `FlyingCar` class that inherits from `Vehicle` through both `Car` and `Aircraft` classes, with possible hierarchical relationships among them.
- **Combination of Multiple and Hierarchical Inheritance:**
  ```cpp
  class Engine { ... };
  class Vehicle : virtual public Engine { ... };
  class Car : public Vehicle { ... };
  class Aircraft : public Vehicle { ... };
  class FlyingCar : public Car, public Aircraft { ... };
  ```

**Considerations:**

- **Complexity:** Hybrid inheritance can lead to complex and hard-to-maintain code structures.
- **Diamond Problem:** Like multiple inheritance, hybrid inheritance can suffer from the diamond problem, which can be mitigated using virtual inheritance.

### Addressing Common Issues

**Ambiguity Resolution:**

- **Scope Resolution:** Use `BaseClass::method()` to resolve ambiguity.
  ```cpp
  class Base1 { public: void show() { ... } };
  class Base2 { public: void show() { ... } };
  class Derived : public Base1, public Base2 {
    void show() {
      Base1::show();  // Calls show() from Base1
      Base2::show();  // Calls show() from Base2
    }
  };
  ```

**Diamond Problem:**

- **Virtual Inheritance:**
  ```cpp
  class Base { ... };
  class Derived1 : virtual public Base { ... };
  class Derived2 : virtual public Base { ... };
  class FinalDerived : public Derived1, public Derived2 { ... };
  ```
