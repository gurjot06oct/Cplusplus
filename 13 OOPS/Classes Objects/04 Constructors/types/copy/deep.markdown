**Understanding Deep Copy**

In deep copy, an object is created by copying data of all variables, including dynamically allocated memory resources, with identical values to the original object. To perform a deep copy, a custom copy constructor needs to be explicitly defined, ensuring proper allocation and copying of dynamic memory resources. Additionally, it's crucial to allocate memory dynamically to variables in other constructors to maintain consistency.

Let's explore an implementation of deep copy in C++:

```cpp
#include <iostream>
using namespace std;

// Box Class
class Box {
private:
    int length;
    int* breadth;
    int height;

public:
    // Constructor
    Box() {
        breadth = new int;
    }

    // Function to set the dimensions of the Box
    void setDimensions(int len, int brea, int heig) {
        length = len;
        *breadth = brea;
        height = heig;
    }

    // Function to display the dimensions of the Box
    void showData() {
        cout << "Length = " << length
             << "\nBreadth = " << *breadth
             << "\nHeight = " << height
             << endl;
    }

    // Custom deep copy constructor
    Box(const Box& sample) {
        length = sample.length;
        height = sample.height;
        breadth = new int;
        *breadth = *(sample.breadth); // Deep copy
    }

    // Destructor
    ~Box() {
        delete breadth;
    }

    // Function to modify breadth
    void setBreadth(int newBreadth) {
        *breadth = newBreadth;
    }
};

// Driver Code
int main() {
    // Create the first box
    Box first;

    // Set the dimensions of the first box
    first.setDimensions(12, 14, 16);

    // Display the dimensions of the first box
    cout << "First Box (Original):" << endl;
    first.showData();

    // Perform deep copy to create the second box
    Box second = first;

    // Display the dimensions of the second box
    cout << "\nSecond Box (Deep Copy of First Box):" << endl;
    second.showData();

    // Modify the breadth of the second box
    second.setBreadth(20);

    // Display the modified dimensions of the second box
    cout << "\nModified Second Box:" << endl;
    second.showData();

    // Display the dimensions of the first box again
    cout << "\nFirst Box (Original After Modification of Second Box):" << endl;
    first.showData();

    return 0;
}
```

**Output:**

```
First Box (Original):
Length = 12
Breadth = 14
Height = 16

Second Box (Deep Copy of First Box):
Length = 12
Breadth = 14
Height = 16

Modified Second Box:
Length = 12
Breadth = 20
Height = 16

First Box (Original After Modification of Second Box):
Length = 12
Breadth = 14
Height = 16
```
