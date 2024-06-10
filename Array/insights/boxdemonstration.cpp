#include <iostream>

int main()
{
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};

    std::cout << "Address of arr: " << arr << std::endl;
    std::cout << "Address of &arr: " << &arr << std::endl;
    std::cout << "Dereference *arr: " << *arr << std::endl;
    std::cout << "Address of arr + 1: " << arr + 1 << std::endl;
    std::cout << "Address of &arr + 1: " << &arr + 1 << std::endl;
    std::cout << "Dereference *(arr + 1) + 1: " << *(arr + 1) + 1 << std::endl;
    std::cout << "Dereference **(arr + 1): " << **(arr + 1) << std::endl;
    std::cout << "Dereference **(&arr + 2): " << **(&arr + 2) << std::endl;

    // Demonstrating the formula *(*(arr + i) + j) = arr[i][j]
    std::cout << "Element at arr[2][3] using formula: " << *(*(arr + 2) + 3) << std::endl; // Should print 14

    return 0;
}
