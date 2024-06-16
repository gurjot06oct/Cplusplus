### Destructors

#### What is a Destructor?

A destructor is a special member function in C++ that is called automatically when an object is destroyed. It is the last function executed before an object is removed from memory, making it crucial for releasing resources allocated by the object during its lifetime.

#### Key Characteristics of Destructors

- **Naming and Syntax**: A destructor has the same name as the class, prefixed with a tilde (~). For example, the destructor for a class named `Example` would be `~Example()`.
- **Uniqueness**: Each class can have only one destructor. Unlike other functions, destructors cannot be overloaded.
- **No Arguments or Return Type**: Destructors do not take any arguments and do not return any value.
- **Automatic Invocation**: Destructors are automatically called when an object goes out of scope, such as at the end of a function, the end of a block containing local variables, or when the `delete` operator is used.

#### Syntax of Destructors

- **Inside the Class**:

  ```cpp
  ~ClassName() {
      // destructor body
  }
  ```

- **Outside the Class**:
  ```cpp
  ClassName::~ClassName() {
      // destructor body
  }
  ```

#### Usage

1. **Basic Destructor Usage**:
   The below code demonstrates the automatic execution of constructors and destructors when objects are created and destroyed, respectively.

   ```cpp
   #include <iostream>
   using namespace std;

   class Test {
   public:
       Test() { cout << "\nConstructor executed"; }
       ~Test() { cout << "\nDestructor executed"; }
   };

   int main() {
       Test testObject;
       return 0;
   }
   ```

   **Output**:

   ```
   Constructor executed
   Destructor executed
   ```

2. **Multiple Objects**:
   The below code demonstrates the automatic execution of constructors and destructors each time when multiple objects are created and destroyed, respectively.

   ```cpp
   #include <iostream>
   using namespace std;

   class Test {
   public:
       Test() { cout << "\nConstructor executed"; }
       ~Test() { cout << "\nDestructor executed"; }
   };

   int main() {
       Test testObject1, testObject2, testObject3, testObject4;
       return 0;
   }
   ```

   **Output**:

   ```
   Constructor executed
   Constructor executed
   Constructor executed
   Constructor executed
   Destructor executed
   Destructor executed
   Destructor executed
   Destructor executed
   ```

3. **Counting Object Creation and Destruction**:
   The below C++ program demonstrates the number of times constructors and destructors are called.
   **Note:** Objects are destroyed in the reverse order of their creation. In this case, the last object created (`testObject4`) is the first to be destroyed.

   ```cpp
   #include <iostream>
   using namespace std;

   static int objectCount = 0;

   class Test {
   public:
       Test() {
           objectCount++;
           cout << "No. of Object created: " << objectCount << endl;
       }
       ~Test() {
           cout << "No. of Object destroyed: " << objectCount << endl;
           objectCount--;
       }
   };

   int main() {
       Test testObject1, testObject2, testObject3, testObject4;
       return 0;
   }
   ```

   **Output**:

   ```
   No. of Object created: 1
   No. of Object created: 2
   No. of Object created: 3
   No. of Object created: 4
   No. of Object destroyed: 4
   No. of Object destroyed: 3
   No. of Object destroyed: 2
   No. of Object destroyed: 1
   ```

#### Destructor Properties

- **Automatic Invocation**: Called when objects are destroyed.
- **Non-Static and Non-Const**: Cannot be declared as static or const.
- **Non-Return Type**: Does not return any value, not even void.
- **Memory Management**: Essential for classes with dynamic memory allocation to avoid memory leaks.

#### When is a Destructor Called?

A destructor is invoked automatically when:

- The function containing the object ends.
- The program terminates.
- The block containing local variables concludes.
- The `delete` operator is used.

#### Explicitly Calling Destructors

Although destructors are automatically called, they can be invoked explicitly using the following syntax:

```cpp
objectName.~ClassName();
```

#### User-Defined Destructors and Dynamic Memory

When a class includes pointers or dynamically allocated memory, defining a custom destructor is necessary to ensure proper resource management and avoid memory leaks.

#### Virtual Destructors

In classes with virtual functions, it's recommended to declare destructors as virtual to ensure the correct destructor is called for derived classes, preventing resource leaks.

Destructors play a vital role in C++ by ensuring proper cleanup of resources, particularly in classes that manage dynamic memory. Understanding how and when destructors are called, as well as their proper implementation, is essential for effective C++ programming.

### Private Destructors

In C++, destructors with the access modifier set as private are termed Private Destructors. These destructors offer a means to control the destruction of objects within a class, ensuring that objects cannot be destroyed except through designated methods or functions.

#### Purpose of Private Destructors

The primary purpose of a private destructor is to manage the destruction of objects in a controlled manner. By making the destructor private, developers can restrict the ways in which objects are destructed, preventing potential issues like dangling references or accidental deletion.

#### Behavior of Private Destructors

When a destructor is declared private, its accessibility is limited to within the class itself. This means that objects of the class cannot be destructed from outside the class scope. Let's explore some scenarios to understand the behavior of private destructors:

1. **Compilation with Private Destructor**:

   ```cpp
   #include <iostream>
   using namespace std;

   class Test {
   private:
       ~Test() {}
   };

   int main() {}
   ```

   **Output**: _(No output)_  
   This code compiles and executes without errors. It demonstrates that defining a private destructor doesn't result in a compiler error.

2. **Compilation Failure due to Private Destructor**:

   ```cpp
   #include <iostream>
   using namespace std;

   class Test {
   private:
       ~Test() {}
   };

   int main() {
       Test instance;
   }
   ```

   **Output**:

   ```
   prog.cpp: In function ‘int main()’:
   prog.cpp:11:14: error: ‘Test::~Test()’ is private within this context
       Test instance;
                 ^
   prog.cpp:6:9: note: declared private here
       ~Test() {}
       ^~~~~~
   ```

   The above code fails to compile because the destructor is private, and objects of the class cannot be destructed from outside.

3. **Creating a Pointer to Class with Private Destructor**:

   ```cpp
   #include <iostream>
   using namespace std;

   class Test {
   private:
       ~Test() {}
   };

   int main() {
       Test* instancePtr;
   }
   ```

   **Output**: _(No output)_  
   This code compiles successfully as it merely declares a pointer of type `Test*` without creating an object.

4. **Dynamic Allocation with Private Destructor**:

   ```cpp
   #include <iostream>
   using namespace std;

   class Test {
   private:
       ~Test() {}
   };

   int main() {
       Test* instancePtr = new Test;
   }
   ```

   **Output**: _(No output)_  
   Even with dynamic memory allocation, the code compiles without errors. However, it's crucial to note that the responsibility of deleting dynamically allocated objects lies with the programmer.

5. **Friend Function for Destructing**:

   ```cpp
   #include <iostream>
   using namespace std;

   class Test {
   private:
       ~Test() { cout << "Destructor called" << endl; }
       friend void destroyTestInstance(Test*);
   };

   void destroyTestInstance(Test* ptr) { delete ptr; }

   int main() {
       Test* instancePtr = new Test;
       destroyTestInstance(instancePtr);
       return 0;
   }
   ```

   **Output**:

   ```
   Destructor called
   ```

   Here, a friend function `destroyTestInstance` is declared to destruct objects of the class `Test`. This approach provides controlled access for object destruction.

6. **Using Class Instance Method**:

   ```cpp
   #include <iostream>
   using namespace std;

   class Parent {
   private:
       ~Parent() { cout << "Destructor called" << endl; }

   public:
       Parent() { cout << "Constructor called" << endl; }
       void destroy() { delete this; }
   };

   int main() {
       Parent* parentInstance = new Parent;
       parentInstance->destroy();
       return 0;
   }
   ```

   **Output**:

   ```
   Constructor called
   Destructor called
   ```

   This method showcases how private destructors can be utilized in conjunction with class instance methods to manage object destruction.

#### Conclusion

Private destructors in C++ offer a mechanism to regulate the destruction of objects, providing more control over memory management and preventing potential issues such as dangling references. By leveraging private destructors, developers can ensure safe and controlled object destruction within their classes.
