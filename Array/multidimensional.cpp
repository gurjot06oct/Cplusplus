#include <iostream>

int main()
{
    // Syntax
    // data_type array_name[dimension1_size][dimension2_size]...[dimensionN_size];
    // data_type array_name[dimension1_size][dimension2_size]...[dimensionN_size] = {
    //     {value11, value12, ..., value1N},
    //     {value21, value22, ..., value2N},
    //     ...
    //     {valueM1, valueM2, ..., valueMN}
    // };

    // Define constants for the number of rows and columns in the matrix
    const int rows = 3;
    const int cols = 3;

    // Declare and initialize a 3x3 matrix using a multidimensional array
    int matrix[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Print the matrix
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            // Access each element of the matrix using indices i and j
            std::cout << matrix[i][j] << " ";
        }
        // Move to the next line after printing each row
        std::cout << std::endl;
    }

    return 0;
}
