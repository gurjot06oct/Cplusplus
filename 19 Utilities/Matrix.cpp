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

public:
    // Constructors
    Matrix() : rows(0), cols(0) {}
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

    // Scalar * Matrix (Matrix * Scalar)
    template <typename U>
    Matrix<T> operator*(U scalar) const {
        Matrix<T> result(rows, cols);  // Create a new matrix for the result

        // Multiply each element of the matrix by the scalar
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = data[i][j] * scalar;
            }
        }
        return result;  // Return the resulting matrix
    }

    // Scalar * Matrix (Matrix * Scalar - friend function)
    template <typename U>
    friend Matrix<T> operator*(U scalar, const Matrix<T>& mat) {
        return mat * scalar;  // Reuse the already defined operator
    }

    // Scalar Division: Matrix A / scalar
    template <typename U>
    Matrix operator/(U scalar) const {
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
    
    // Inequality: Matrix A != Matrix B
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
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

    Matrix toREF() const {
        Matrix<T> temp(rows,cols);
        int row = 0;
        for (int col = 0; col < cols && row < rows; col++) {
            // Find the pivot row (largest absolute value in column)
            int pivotRow = row;
            for (int i = row + 1; i < rows; i++) {
                if (abs(temp[i][col]) > abs(temp[pivotRow][col])) {
                    pivotRow = i;
                }
            }

            // If the pivot is zero, skip this column
            if (temp[pivotRow][col] == 0) {
                continue;
            }

            // Swap the current row with the pivot row
            if (pivotRow != row) {
                temp.swapRows(row,pivotRow);
            }

            // Make the pivot element 1 by dividing the entire row by the pivot
            T pivot = temp[row][col];
            for (int i = 0; i < cols; i++) {
                temp[row][i] /= pivot;
            }

            // Eliminate all elements below the pivot in the current column
            for (int i = row + 1; i < rows; i++) {
                if (temp[i][col] != 0) {
                    T factor = temp[i][col];
                    for (int j = 0; j < cols; j++) {
                        temp[i][j] -= factor * temp[row][j];
                    }
                }
            }

            // Move to the next row
            row++;
        }
        return temp;
    }

    void toRREF() {
        // First, convert to Row Echelon Form (REF)
        Matrix<T> temp = toREF();

        int row = rows - 1;
        for (int col = cols - 1; col >= 0 && row >= 0; col--) {
            // Find the row with a non-zero entry in the current column
            if (temp[row][col] != 0) {
                // Make the leading entry in the current row 1 (already done in REF)
                T pivot = temp[row][col];

                // Eliminate all elements above the pivot in the current column
                for (int i = row - 1; i >= 0; i--) {
                    if (temp[i][col] != 0) {
                        T factor = temp[i][col];
                        for (int j = 0; j < cols; j++) {
                            temp[i][j] -= factor * temp[row][j];
                        }
                    }
                }
                row--;  // Move to the previous row
            }
        }
    }

    // Rank calculation using Gaussian elimination
    int rank() const {
        // First, convert the matrix to Row Echelon Form (REF)
        Matrix<T> temp = toREF();

        int _rank = 0;
        // Count the number of non-zero rows in the REF
        for (int row = 0; row < rows; row++) {
            bool isNonZeroRow = false;
            for (int col = 0; col < cols; col++) {
                if ((*this)[row][col] != 0) {
                    isNonZeroRow = true;
                    break;
                }
            }
            if (isNonZeroRow) {
                _rank++;
            }
        }
        return _rank;
    }


    void swapRows(int row1, int row2) {
        if (row1 < 0 || row2 < 0 || row1 >= rows || row2 >= rows) {
            throw std::invalid_argument("Invalid row indices.");
            return;
        }

        // Swap entire rows
        for (int col = 0; col < cols; col++) {
            std::swap(data[row1][col], data[row2][col]);
        }
    }

    void swapColumns(int col1, int col2) {
        if (col1 < 0 || col2 < 0 || col1 >= cols || col2 >= cols) {
            throw std::invalid_argument("Invalid row indices.");
            return;
        }

        // Swap entire columns
        for (int row = 0; row < rows; row++) {
            std::swap(data[row][col1], data[row][col2]);
        }
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
                result[i][j] = i == j;  // Identity matrix
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
    Matrix inverse() const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square to compute inverse.");
        }
        int n = rows;  // Assume 'rows' is the size of the matrix (n x n)

        // Create a copy of the original matrix (A) and the identity matrix (I)
        Matrix augmentedA(*this);  // Copy of the original matrix A
        Matrix I(n, n);            // Identity matrix I
        I.setIdentity();           // Initialize I as the identity matrix

        // Perform Gaussian elimination to convert A to the identity matrix
        for (int i = 0; i < n; i++) {
            // Find the pivot row and swap if necessary
            int maxRow = i;
            for (int j = i + 1; j < n; j++) {
                if (std::abs(augmentedA[j][i]) > std::abs(augmentedA[maxRow][i])) {
                    maxRow = j;
                }
            }

            // If pivot is zero, the matrix is singular (no inverse)
            if (augmentedA[maxRow][i] == 0) {
                throw std::invalid_argument("Matrix is singular and cannot be inverted.");
            }

            // Swap the current row with the pivot row
            augmentedA.swapRows(i, maxRow);
            I.swapRows(i, maxRow);  // Also swap corresponding rows in identity matrix

            // Normalize the pivot row
            double pivot = augmentedA[i][i];
            for (int j = 0; j < n; j++) {
                augmentedA[i][j] /= pivot;
                I[i][j] /= pivot;  // Perform the same row operation on I
            }

            // Eliminate other rows
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    double factor = augmentedA[j][i];
                    for (int k = 0; k < n; k++) {
                        augmentedA[j][k] -= factor * augmentedA[i][k];
                        I[j][k] -= factor * I[i][k];  // Apply same elimination to I
                    }
                }
            }
        }
        return I;
    }

    // Trace: Sum of diagonal elements
    T trace() const {
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square to compute trace.");
        }
        T sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += data[i][i];
        }
        return sum;
    }

    // Adjoint of the matrix (adj(A))
    Matrix adjoint() const {
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

    void setIdentity() {
        // Ensure that the matrix is square (for identity matrix)
        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square to set identity.");
        }

        // Set all elements to 0 initially
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }

        // Set the diagonal elements to 1
        for (int i = 0; i < rows; i++) {
            data[i][i] = 1;
        }
    }

    // Check if the matrix is square
    bool isSquare() const {
        return rows == cols;
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

    // Flatten the matrix into a 1D array
    T*& flatten() const {
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
    Matrix<T> reshape(int newRows, int newCols) const {
        Matrix<T> temp(newRows,newCols);
        if ((rows * cols) != (newRows * newCols)) {
            throw std::invalid_argument("Cannot reshape: number of elements must remain the same!");
            return temp;
        }

        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp[k/newCols][k%newCols] = data[i][j];
                k++;
            }
        }
        return temp;
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
    Matrix<int> some(3,3);
    some.setIdentity();
    return 0;
}
