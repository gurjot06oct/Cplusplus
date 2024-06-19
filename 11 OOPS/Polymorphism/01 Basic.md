Polymorphism is a fundamental concept in object-oriented programming (OOP) that allows objects of different classes to be treated as objects of a common superclass. It enables flexibility and extensibility in code by allowing methods to behave differently based on the object that invokes them. This concept greatly enhances code reusability and modularity.

## Types of Polymorphism:

### Compile-time Polymorphism (Static Binding or Early Binding):

#### 1. Method Overloading:

Method overloading allows multiple functions with the same name but different parameter lists to be defined within the same scope. The compiler determines which function to call based on the number, types, and order of arguments passed to the function at compile-time.

#### 2. Operator Overloading:

In C++, operators like `+`, `-`, `*`, etc., can be overloaded to work with user-defined types (objects). This allows the operators to behave differently based on the operand types.

### Runtime Polymorphism (Dynamic Binding or Late Binding):

#### Virtual Functions:

Virtual functions are functions in a base class that are overridden in derived classes. They allow the correct function to be called for an object, regardless of the expression used to make the function call. This is achieved through dynamic dispatch, where the function call is resolved at runtime based on the actual object type.

#### Method Overriding:

Method overriding occurs when a subclass provides a specific implementation of a method that is already defined in its superclass. The decision on which method to invoke is made at runtime based on the object type.
Example:
