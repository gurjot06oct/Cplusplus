#include <iostream>

int main()
{

    int(*int2DPtr)[10][10] = new int[10][10][10];
    int(*int1DPtr)[10] = *int2DPtr;
    int *int0DPtr = *int1DPtr;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                int2DPtr[i][j][k] = (i + j + k) * 10;
            }
        }
    }

    // Zero to 1D and 2D pointer by changing width
    int(*int_0d_to_1d)[5] = reinterpret_cast<int(*)[5]>(int0DPtr);
    int(*int_0d_to_2d)[10][5] = reinterpret_cast<int(*)[10][5]>(int0DPtr);

    std::cout << *int_0d_to_1d[1] << std::endl;  // 50
    std::cout << **int_0d_to_2d[1] << std::endl; // 50

    // 1D to 0D and 2D pointer
    int *int_1d_to_0d = reinterpret_cast<int *>(int1DPtr);
    int(*int_1d_to_2d)[10] = reinterpret_cast<int(*)[10]>(int1DPtr);

    std::cout << int_1d_to_0d[10] << std::endl; // 10
    std::cout << *int_1d_to_2d[1] << std::endl; // 10

    // 2D to 0D and 1D pointer
    int *int_2d_to_0d = reinterpret_cast<int *>(int2DPtr);
    int(*int_2d_to_1d)[10] = reinterpret_cast<int(*)[10]>(int2DPtr);

    std::cout << int_2d_to_0d[110] << std::endl; // 20
    std::cout << *int_2d_to_1d[1] << std::endl;  // 10

    // Clean up
    delete[] int2DPtr;

    return 0;
}
