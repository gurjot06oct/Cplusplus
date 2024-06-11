#include <iostream>

int main()
{
    int rows, cols;

    // Taking dimensions from the user
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Dynamically allocate memory for the 2D array
    int **array = new int *[rows];
    for (int i = 0; i < rows; ++i)
        array[i] = new int[cols];

    // Set values to i * j
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            array[i][j] = i * j;

    // Print the array
    std::cout << "The 2D array is:" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            std::cout << array[i][j] << " ";
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; ++i)
        delete[] array[i];
    delete[] array;

    return 0;
}
