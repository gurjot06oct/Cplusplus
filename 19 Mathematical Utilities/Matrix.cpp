#include <iostream>

class Matrix {
private:
    int** data;  // Pointer to hold the dynamic 2D array
    int rows, cols;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        // Allocate memory for the dynamic 2D array
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }

        // Initialize elements as Identity matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = i==j;
            }
        }
    }
    // Copy Constructor
    Matrix(const Matrix& other){
        rows = other.rows;
        cols = other.cols;
        // Allocate memory for the dynamic 2D array
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
        // Copy all elements from `other` Matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other[i][j];
            }
        }
    }
    // Destructor to free allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];  // Delete each row
        }
        delete[] data;  // Delete the array of row pointers
    }

    // Overload the `operator[]` to access rows
    int* operator[](int i) {
        if (i >= 0 && i < rows) {
            return data[i];  // Return the i-th row
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
            return nullptr;
        }
    }

    // Overload the `operator[]` for const access
    const int* operator[](int i) const {
        if (i >= 0 && i < rows) {
            return data[i];  // Return the i-th row
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
            return nullptr;
        }
    }

    // Overload addition operator (+)
    Matrix operator+(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrices must have the same dimensions for addition!" << std::endl;
            return *this;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j]= data[i][j] + other[i][j];
            }
        }
        return result;
    }

    // Overload subtraction operator (-)
    Matrix operator-(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrices must have the same dimensions for subtraction!" << std::endl;
            return *this;
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j]= data[i][j] - other[i][j];
            }
        }
        return result;
    }

    // Overload assignment operator (=)
    Matrix& operator=(const Matrix &other) {
        if (this == &other) return *this; // Check for self-assignment

        // Free the existing memory
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Allocate new memory for the new matrix
        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }

        // Copy elements from the other matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other[i][j];
            }
        }

        return *this;
    }

    // Overload addition assignment operator (+=)
    Matrix& operator+=(const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrices must have the same dimensions for addition!" << std::endl;
            return *this;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] += other[i][j];
            }
        }

        return *this;
    }

    // Overload subtraction assignment operator (-=)
    Matrix& operator-=(const Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrices must have the same dimensions for subtraction!" << std::endl;
            return *this;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] -= other[i][j];
            }
        }

        return *this;
    }

    // Friend function to overload the input (>>) operator
    friend std::istream& operator>>(std::istream& in, Matrix& m) {
        std::cout << "Enter elements of the matrix (" << m.rows << "x" << m.cols << "):" << std::endl;
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                in >> m.data[i][j];
            }
        }
        return in;
    }

    // Friend function to overload the output (<<) operator
    friend std::ostream& operator<<(std::ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                out << m.data[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }
};

int main() {
    // Create two matrices
    Matrix A(2, 2);
    Matrix B(2, 2);

    // Take input for Matrix A
    std::cout << "Enter the elements of Matrix A:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            std::cout << "Element at (" << i << "," << j << "): ";
            std::cin >> value;
            A.set(i, j, value);
        }
    }

    // Take input for Matrix B
    std::cout << "Enter the elements of Matrix B:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            std::cout << "Element at (" << i << "," << j << "): ";
            std::cin >> value;
            B.set(i, j, value);
        }
    }

    // Display both matrices
    std::cout << "Matrix A:" << std::endl;
    A.display();
    std::cout << "Matrix B:" << std::endl;
    B.display();

    // Add matrices
    Matrix C = A + B;
    std::cout << "Matrix C (A + B):" << std::endl;
    C.display();

    // Subtract matrices
    Matrix D = A - B;
    std::cout << "Matrix D (A - B):" << std::endl;
    D.display();

    // Assign B to A
    A = B;
    std::cout << "Matrix A after A = B:" << std::endl;
    A.display();

    // Add B to A using +=
    A += B;
    std::cout << "Matrix A after A += B:" << std::endl;
    A.display();

    // Subtract B from A using -=
    A -= B;
    std::cout << "Matrix A after A -= B:" << std::endl;
    A.display();

    return 0;
}
