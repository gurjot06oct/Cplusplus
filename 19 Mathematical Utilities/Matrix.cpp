#include <iostream>
template <typename T>
class Matrix {
private:
    T** data;  // Pointer to hold the dynamic 2D array
    int rows, cols;

    // Helper function for calculating determinant (recursive)
    T calculateDeterminant(T** mat, int n) const {
        if (n == 1) return mat[0][0];
        if (n == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

        T det = 0;
        T** temp = new T*[n];
        for (int i = 0; i < n; ++i) {
            temp[i] = new T[n];
        }

        for (int p = 0; p < n; ++p) {
            // Create the submatrix for the determinant calculation
            int h = 0;
            for (int i = 1; i < n; ++i) {
                int k = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == p) continue;
                    temp[h][k++] = mat[i][j];
                }
                h++;
            }

            // Add or subtract based on position (cofactor expansion)
            det += (p % 2 == 0 ? 1 : -1) * mat[0][p] * calculateDeterminant(temp, n - 1);
        }

        // Clean up the dynamically allocated memory for temp matrix
        for (int i = 0; i < n; ++i) {
            delete[] temp[i];
        }
        delete[] temp;

        return det;
    }

    // Gaussian elimination to find rank
    int gaussianElimination(Matrix<T>& temp) const {
        int rank = temp.rows;
        int row = 0, col = 0;

        while (row < rank && col < rank) {
            if (temp[row][col] == 0) {
                bool found = false;
                for (int i = row + 1; i < rank; ++i) {
                    if (temp[i][col] != 0) {
                        for (int j = 0; j < rank; ++j) {
                            T tempVal = temp[row][j];
                            temp[row][j] = temp[i][j];
                            temp[i][j] = tempVal;
                        }
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    col++;
                    continue;
                }
            }

            T inv = 1 / temp[row][col];
            for (int i = col; i < rank; ++i) {
                temp[row][i] *= inv;
            }

            for (int i = 0; i < rank; ++i) {
                if (i != row && temp[i][col] != 0) {
                    T factor = temp[i][col];
                    for (int j = col; j < rank; ++j) {
                        temp[i][j] -= factor * temp[row][j];
                    }
                }
            }
            row++;
            col++;
        }

        // Count non-zero rows
        int nonZeroRows = 0;
        for (int i = 0; i < rank; ++i) {
            bool isNonZero = false;
            for (int j = 0; j < rank; ++j) {
                if (temp[i][j] != 0) {
                    isNonZero = true;
                    break;
                }
            }
            if (isNonZero) {
                nonZeroRows++;
            }
        }

        return nonZeroRows;
    }
public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        // Allocate memory for the dynamic 2D array
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols]{};
        }
    }
    // Copy Constructor
    Matrix(const Matrix& other){
        if(rows != other.rows || cols != other.cols){
            rows = other.rows;
            cols = other.cols;
            // Allocate memory for the dynamic 2D array
            data = new T*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new T[cols];
            }
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
    T* operator[](int i) {
        if (i >= 0 && i < rows) {
            return data[i];  // Return the i-th row
        } else {
            throw std::invalid_argument("Index out of bounds!");
        }
    }

    // Overload the `operator[]` for const access
    const T* operator[](int i) const {
        if (i >= 0 && i < rows) {
            return data[i];  // Return the i-th row
        } else {
            throw std::invalid_argument("Index out of bounds!");
        }
    }

    // Overload addition operator (+)
    Matrix operator+(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition!");
        }
        Matrix<T> result(rows, cols);
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
            throw std::invalid_argument("Matrices must have the same dimensions for subtraction!");
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j]= data[i][j] - other[i][j];
            }
        }
        return result;
    }

    // Matrix Multiplication: Matrix A * Matrix B
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions do not allow multiplication");
        }

        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Scalar Multiplication: Matrix A * scalar
    Matrix operator*(T scalar) const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Scalar Division: Matrix A / scalar
    Matrix operator/(T scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Matrix Division by zero");
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] / scalar;
            }
        }
        return result;
    }

    // Transpose: A^T
    Matrix transpose() const {
        Matrix<T> result(cols, rows);  // Transposed matrix has flipped dimensions
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][i] = data[i][j];
            }
        }
        return result;
    }

    // Negation: -Matrix A
    Matrix operator-() const {
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = -data[i][j];
            }
        }
        return result;
    }

    // Equality: Matrix A == Matrix B
    bool operator==(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Overload assignment operator (=)
    Matrix& operator=(const Matrix &other) {
        if (this == &other) return *this; // Check for self-assignment
        if(rows != other.rows || cols != other.cols){
            // Free the existing memory
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;

            // Allocate new memory for the new matrix
            rows = other.rows;
            cols = other.cols;
            data = new T*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new T[cols];
            }
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
        *this=*this+other;
        return *this;
    }

    // Overload subtraction assignment operator (-=)
    Matrix& operator-=(const Matrix &other) {
        *this=*this-other;
        return *this;
    }
    
    // Overload subtraction assignment operator (*=)
    Matrix& operator*=(const Matrix &other) {
        *this=(*this)*other;
        return *this;
    }

    // Overload subtraction assignment operator (/=)
    Matrix& operator/=(const double& scalar) {
        *this=*this/scalar;
        return *this;
    }

    // Overload operator^ for matrix exponentiation (binary exponentiation)
    Matrix operator^(int n) const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square for exponentiation");
        }

        // Start with the identity matrix (A^0 = I)
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = (i == j) ? 1 : 0;  // Identity matrix
            }
        }

        // Start with the matrix itself
        Matrix<T> base = *this;

        // Iteratively apply binary exponentiation
        while (n > 0) {
            // If n is odd, multiply result by the base matrix
            if (n % 2 == 1) {
                result = result * base;
            }

            // Square the base matrix (A^2, A^4, A^8, etc.)
            base = base * base;

            // Right shift n by 1 (divide n by 2)
            n /= 2;
        }

        return result;
    }

    // Utility function to calculate determinant
    T determinant() const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square to compute determinant.");
        }
        return calculateDeterminant(data, rows);
    }

    // Utility function to calculate the inverse of the matrix
    Matrix<T> inverse() const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square to compute inverse.");
        }

        T det = determinant();
        if (det == 0) {
            throw std::invalid_argument("Matrix is singular and cannot be inverted.");
        }

        Matrix<T> adj = adjoint();
        Matrix<T> inv(rows, cols);

        // Divide adjoint by determinant to get inverse
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                inv[i][j] = adj[i][j] / det;
            }
        }

        return inv;
    }

    // Rank calculation using Gaussian elimination
    int rank() const {
        Matrix<T> temp = *this;
        return gaussianElimination(temp);
    }

    // Trace: Sum of diagonal elements
    T trace() const {
        T sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += data[i][i];
        }
        return sum;
    }

    // Adjoint of the matrix (adj(A))
    Matrix<T> adjoint() const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square to compute adjoint.");
        }
        
        Matrix<T> adj(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                adj[i][j] = cofactor(i, j);
            }
        }
        return adj.transpose();
    }

    // Cofactor of a specific element
    T cofactor(int row, int col) const {
        return (row + col) % 2 == 0 ? minor(row, col) : -minor(row, col);
    }

    // Minor matrix: Get the determinant of the submatrix after removing a row and column
    T minor(int row, int col) const {
        Matrix<T> submatrix(rows - 1, cols - 1);

        int subi = 0;
        for (int i = 0; i < rows; ++i) {
            if (i == row) continue;

            int subj = 0;
            for (int j = 0; j < cols; ++j) {
                if (j == col) continue;

                submatrix[subi][subj] = data[i][j];
                subj++;
            }
            subi++;
        }

        return submatrix.determinant();
    }

    // Check if the matrix is square
    bool isSquare() const {
        return rows == cols;
    }

    // Check if the matrix is symmetric (A == A^T)
    bool isSymmetric() const {
        if (!isSquare()) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] != data[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Check if the matrix is an identity matrix
    bool isIdentity() const {
        if (!isSquare()) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Check if the matrix is diagonal
    bool isDiagonal() const {
        if (!isSquare()) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i != j && data[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // Check if the matrix is upper triangular
    bool isUpperTriangular() const {
        if (!isSquare()) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i > j && data[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // Check if the matrix is lower triangular
    bool isLowerTriangular() const {
        if (!isSquare()) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i < j && data[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    // Check if the matrix is singular (determinant is 0)
    bool isSingular() const {
        return determinant() == 0;
    }

        // Rotate the matrix by 90, 180, or 270 degrees
    void rotate(int degrees) {
        if (!isSquare()) {
            std::cout << "Matrix must be square for rotation!" << std::endl;
            return;
        }

        if (degrees == 90) {
            transpose();
            reverseRows();
        } else if (degrees == 180) {
            reverseRows();
            reverseColumns();
        } else if (degrees == 270) {
            transpose();
            reverseColumns();
        } else {
            std::cout << "Invalid rotation degree!" << std::endl;
        }
    }

    // Resize the matrix (new number of rows and columns)
    void resize(int newRows, int newCols) {
        T** newData = new T*[newRows];
        for (int i = 0; i < newRows; ++i) {
            newData[i] = new T[newCols];
        }

        // Copy existing elements (fits within new size)
        int copyRows = std::min(newRows, rows);
        int copyCols = std::min(newCols, cols);

        for (int i = 0; i < copyRows; ++i) {
            for (int j = 0; j < copyCols; ++j) {
                newData[i][j] = data[i][j];
            }
        }

        // Clean up old data
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Update matrix dimensions
        rows = newRows;
        cols = newCols;
        data = newData;
    }

    // Flatten the matrix into a 1D array
    T* flatten() const {
        T* flatArray = new T[rows * cols];
        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                flatArray[k++] = data[i][j];
            }
        }
        return flatArray;
    }

    // Reshape the matrix while keeping the data
    bool reshape(int newRows, int newCols) {
        if (rows * cols != newRows * newCols) {
            std::cout << "Cannot reshape: number of elements must remain the same!" << std::endl;
            return false;
        }

        T* flatData = flatten();
        resize(newRows, newCols);

        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = flatData[k++];
            }
        }

        delete[] flatData;
        return true;
    }

    // Concatenate matrices horizontally (side by side)
    Matrix<T> concatenateHorizontally(const Matrix<T>& other) const {
        if (rows != other.rows) {
            std::cout << "Matrix dimensions must match for horizontal concatenation!" << std::endl;
            throw std::invalid_argument("Row dimensions do not match!");
        }

        Matrix<T> result(rows, cols + other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j];
            }
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][cols + j] = other.data[i][j];
            }
        }
        return result;
    }

    // Concatenate matrices vertically (one on top of the other)
    Matrix<T> concatenateVertically(const Matrix<T>& other) const {
        if (cols != other.cols) {
            std::cout << "Matrix dimensions must match for vertical concatenation!" << std::endl;
            throw std::invalid_argument("Column dimensions do not match!");
        }

        Matrix<T> result(rows + other.rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j];
            }
        }
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[rows + i][j] = other.data[i][j];
            }
        }
        return result;
    }

    void reverseRows() {
        for (int i = 0; i < rows; ++i) {
            int left = 0, right = cols - 1;
            while (left < right) {
                T temp = data[i][left];
                data[i][left] = data[i][right];
                data[i][right] = temp;
                left++;
                right--;
            }
        }
    }

    void reverseColumns() {
        for (int i = 0; i < cols; ++i) {
            int top = 0, bottom = rows - 1;
            while (top < bottom) {
                T temp = data[top][i];
                data[top][i] = data[bottom][i];
                data[bottom][i] = temp;
                top++;
                bottom--;
            }
        }
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
    return 0;
}
