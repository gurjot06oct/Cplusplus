#include <iostream>

using namespace std;

int main()
{
    // Dimensions of the 3D array
    int dim1 = 2;
    int dim2 = 3;
    int dim3 = 4;

    // Step 1: Allocate memory for the first dimension (array of pointers to pointers)
    int ***arr = new int **[dim1];

    // Step 2: Allocate memory for the second dimension (array of pointers)

    // Step 3: Allocate memory for the third dimension (actual data)
    for (int i = 0; i < dim1; ++i)
    {
        arr[i] = new int *[dim2];
        for (int j = 0; j < dim2; ++j)
        {
            arr[i][j] = new int[dim3];
        }
    }

    // Optional: Initialize the 3D array
    int count = 1;
    for (int i = 0; i < dim1; ++i)
    {
        for (int j = 0; j < dim2; ++j)
        {
            for (int k = 0; k < dim3; ++k)
            {
                arr[i][j][k] = count++;
            }
        }
    }

    // Step 4: Accessing and printing elements
    for (int i = 0; i < dim1; ++i)
    {
        cout << "Layer " << i + 1 << ":\n";
        for (int j = 0; j < dim2; ++j)
        {
            for (int k = 0; k < dim3; ++k)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Step 5: Free allocated memory in reverse order of allocation
    for (int i = 0; i < dim1; ++i)
    {
        for (int j = 0; j < dim2; ++j)
        {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
