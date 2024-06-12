## **Understanding Shallow Copy**

In shallow copy, an object is created by directly copying the data of all variables from the original object. While this approach works well for variables residing in the stack memory, it poses challenges when variables are dynamically allocated from the heap memory. If some variables are allocated memory from the heap, then the copied object's variables will reference the same memory locations as the original object.

This situation can lead to ambiguity and runtime errors, such as dangling pointers. Both objects end up pointing to the same memory location, causing changes made by one object to reflect in the other. Consequently, the purpose of creating a replica of the object is not fulfilled by shallow copy.

It's important to note that the C++ compiler implicitly creates a copy constructor and overloads the assignment operator to perform shallow copy at compile time.

```cpp
#include <iostream>
using namespace std;

// Class representing a Box
class Box {
private:
    int length;
    int width;
    int height;

public:
    // Function to set the dimensions of the Box
    void setDimensions(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }

    // Function to display the dimensions of the Box
    void displayDimensions() {
        cout << "Length = " << length << "\nWidth = " << width << "\nHeight = " << height << endl;
    }
};

// Driver code
int main() {
    // Creating Box objects
    Box originalBox, copiedBox;

    // Setting dimensions for the original Box
    originalBox.setDimensions(14, 12, 16);
    cout << "Original Box Dimensions:" << endl;
    originalBox.displayDimensions();

    // Creating a copy of the original Box using copy constructor
    Box copiedBoxUsingCopyConstructor = originalBox;
    cout << "\nBox Copied Using Copy Constructor:" << endl;
    copiedBoxUsingCopyConstructor.displayDimensions();

    // Creating a copy of the original Box using default assignment operator
    copiedBox = originalBox;
    cout << "\nBox Copied Using Default Assignment Operator:" << endl;
    copiedBox.displayDimensions();

    // Modifying the original Box
    originalBox.setDimensions(10, 8, 6);

    // Displaying dimensions after modification
    cout << "\nOriginal Box Dimensions After Modification:" << endl;
    originalBox.displayDimensions();

    // Displaying copied Box dimensions after modification
    cout << "\nCopied Box Dimensions After Modification:" << endl;
    copiedBox.displayDimensions();

    // Displaying copied Box using copy constructor dimensions after modification
    cout << "\nCopied Box Using Copy Constructor Dimensions After Modification:" << endl;
    copiedBoxUsingCopyConstructor.displayDimensions();

    return 0;
}
```

**Output:**

```
Original Box Dimensions:
Length = 14
Width = 12
Height = 16

Box Copied Using Copy Constructor:
Length = 14
Width = 12
Height = 16

Box Copied Using Default Assignment Operator:
Length = 14
Width = 12
Height = 16

Original Box Dimensions After Modification:
Length = 10
Width = 8
Height = 6

Copied Box Dimensions After Modification:
Length = 14
Width = 12
Height = 16

Copied Box Using Copy Constructor Dimensions After Modification:
Length = 14
Width = 12
Height = 16
```
