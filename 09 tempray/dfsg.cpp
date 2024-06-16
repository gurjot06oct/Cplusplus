#include <iostream>

using namespace std;

int main()
{
    // Dimensions of the 3D array
    const int dim1 = 2;
    const int dim2 = 3;
    const int dim3 = 4;

    // Dynamically allocate memory for the 3D array
    int(*ptr2d)[dim2][dim3] = new int[dim1][dim2][dim3];

    // Initialize the 3D array using nested loops
    int count = 1;
    for (int i = 0; i < dim1; ++i)
    {
        for (int j = 0; j < dim2; ++j)
        {
            for (int k = 0; k < dim3; ++k)
            {
                ptr2d[i][j][k] = count++;
            }
        }
    }

    // Print the 3D array
    for (int i = 0; i < dim1; ++i)
    {
        cout << "Layer " << i + 1 << ":\n";
        for (int j = 0; j < dim2; ++j)
        {
            for (int k = 0; k < dim3; ++k)
            {
                cout << ptr2d[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Free allocated memory
    delete[] ptr2d;

    return 0;
}
