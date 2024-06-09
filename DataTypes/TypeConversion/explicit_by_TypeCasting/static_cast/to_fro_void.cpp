#include <iostream>

int main()
{
    int num = 10;
    void *voidPtr = static_cast<void *>(&num); // Converting int pointer to void pointer

    // Now, let's convert the void pointer back to int pointer
    int *intPtr = static_cast<int *>(voidPtr);

    // Accessing the value through the int pointer
    std::cout << "Value of num: " << *intPtr << std::endl;

    return 0;
}
