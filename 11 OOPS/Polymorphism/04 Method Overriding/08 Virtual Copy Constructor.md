### Virtual Copy Constructor in C++

#### What is it?

A virtual copy constructor is a design pattern that allows for the creation of a new object by copying an existing object without knowing its exact type at compile time. This is useful in scenarios where the object type is determined at runtime, such as in graphics applications or clipboard managers where different types of objects need to be copied and manipulated.

#### Why is it needed?

In standard C++, a copy constructor requires the exact type of the object to be known at compile time. This poses a problem when dealing with polymorphic objects (objects of a class hierarchy) where the type is only known at runtime. The virtual copy constructor pattern overcomes this limitation by using a virtual `Clone()` method that returns a copy of the object.

### Code Explanation

#### Step-by-step breakdown:

1. **Base Class Definition:**

   - The `Base` class is an abstract base class with a pure virtual method `ChangeAttributes()` and two important methods: a static `Create(int id)` method (acting as a virtual constructor) and a virtual `Clone()` method (acting as a virtual copy constructor).

   ```cpp
   class Base
   {
   public:
       Base() { }
       virtual ~Base() { }
       virtual void ChangeAttributes() = 0;
       static Base *Create(int id);
       virtual Base *Clone() = 0;
   };
   ```

2. **Derived Classes:**

   - `Derived1`, `Derived2`, and `Derived3` are concrete classes that inherit from `Base`. Each class implements the `Clone()` method to return a copy of itself and the `ChangeAttributes()` method to change the object's attributes.

   ```cpp
   class Derived1 : public Base
   {
   public:
       Derived1() { cout << "Derived1 created" << endl; }
       Derived1(const Derived1& rhs) { cout << "Derived1 created by deep copy" << endl; }
       ~Derived1() { cout << "~Derived1 destroyed" << endl; }
       void ChangeAttributes() { cout << "Derived1 Attributes Changed" << endl; }
       Base *Clone() { return new Derived1(*this); }
   };

   // Similar implementations for Derived2 and Derived3
   ```

3. **Static Create Method:**

   - The `Create(int id)` method in the `Base` class returns a new object of the appropriate derived type based on the provided `id`. This allows for the creation of objects at runtime without knowing their exact type at compile time.

   ```cpp
   Base* Base::Create(int id)
   {
       if (id == 1) return new Derived1;
       else if (id == 2) return new Derived2;
       else return new Derived3;
   }
   ```

4. **User Class:**

   - The `User` class demonstrates how to use the `Create` method to instantiate an object based on user input. It also shows how to use the `Clone()` method to create a copy of the object and change its attributes.

   ```cpp
   class User
   {
   public:
       User() : pBase(0)
       {
           int input;
           cout << "Enter ID (1, 2 or 3): ";
           cin >> input;
           while ((input != 1) && (input != 2) && (input != 3))
           {
               cout << "Enter ID (1, 2 or 3 only): ";
               cin >> input;
           }
           pBase = Base::Create(input);
       }

       ~User()
       {
           if (pBase)
           {
               delete pBase;
               pBase = 0;
           }
       }

       void Action()
       {
           Base* pNewBase = pBase->Clone();
           pNewBase->ChangeAttributes();
           delete pNewBase;
       }

   private:
       Base* pBase;
   };
   ```

5. **Main Function:**

   - The `main` function demonstrates the use of the `User` class, which in turn uses the virtual constructor and virtual copy constructor.

   ```cpp
   int main()
   {
       User* user = new User();
       user->Action();
       delete user;
   }
   ```
