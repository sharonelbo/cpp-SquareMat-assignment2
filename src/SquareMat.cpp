// Email: sharon4homework@gmail.com

#include "../include/SquareMat.hpp"
#include <cmath>

namespace sqaremat {

    // Helper functions
    void SquareMat::allocateMatrix() {
        data = new double*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                data[i][j] = 0.0;
            }
        }
    }

    void SquareMat::deallocateMatrix() {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void SquareMat::copyFrom(const SquareMat& other) {
        size = other.size;
        allocateMatrix();
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] = other.data[i][j];
    }

    // Constructors and Destructor

    SquareMat::SquareMat(int n) : size(n) {
        if (n <= 0) throw std::invalid_argument("Matrix size must be positive");
        allocateMatrix();
    }

    SquareMat::SquareMat(const SquareMat& other) {
        copyFrom(other);
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this != &other) {
            deallocateMatrix();
            copyFrom(other);
        }
        return *this;
    }

    SquareMat::~SquareMat() {
        deallocateMatrix();
    }

    // Accessors

    int SquareMat::getSize() const {
        return size;
    }

    double* SquareMat::operator[](int row) {
        if (row < 0 || row >= size) throw std::out_of_range("Row index out of range");
        return data[row];
    }

    const double* SquareMat::operator[](int row) const {
        if (row < 0 || row >= size) throw std::out_of_range("Row index out of range");
        return data[row];
    }

    // Operators

    // Add 2 matrices 
    SquareMat SquareMat::operator+(const SquareMat& other) const {
        if (size != other.size) throw std::invalid_argument("Matrix sizes do not match for addition");
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Subtract 2 matrices
    SquareMat SquareMat::operator-(const SquareMat& other) const {
        if (size != other.size) throw std::invalid_argument("Matrix sizes do not match for subtraction");
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // Unary minus
    SquareMat SquareMat::operator-() const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = -data[i][j];
        return result;
    }

    // Multiply 2 matrices
    SquareMat SquareMat::operator*(const SquareMat& other) const {
        if (size != other.size) throw std::invalid_argument("Matrix sizes do not match for multiplication");
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Multiply matrix by scalar
    SquareMat SquareMat::operator*(double scalar) const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = data[i][j] * scalar;
        return result;
    }

    SquareMat operator*(double scalar, const SquareMat& mat) {
        return mat * scalar;
    }

    // Multiply one cell in matrix A by the same cell in matrix B 
    SquareMat SquareMat::operator%(const SquareMat& other) const {
        if (size != other.size) throw std::invalid_argument("Matrix sizes do not match for element-wise multiplication");
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = data[i][j] * other.data[i][j];
        return result;
    }

    // Modulu by scalar
    SquareMat SquareMat::operator%(int scalar) const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = std::fmod(data[i][j], scalar);
        return result;
    }

    // Divide by scalar
    SquareMat SquareMat::operator/(double scalar) const {
        if (scalar == 0.0) throw std::invalid_argument("Division by zero");
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[i][j] = data[i][j] / scalar;
        return result;
    }

    // Raises the matrix to a power by repeatedly multiplying the matrix by itself
    SquareMat SquareMat::operator^(int power) const {
        if (power < 0) throw std::invalid_argument("Negative powers are not supported");
        if (power == 0) {
            SquareMat identity(size);
            for (int i = 0; i < size; ++i)
                identity[i][i] = 1.0;
            return identity;
        }
        SquareMat result(*this);
        for (int p = 1; p < power; ++p) {
            result = result * (*this);
        }
        return result;
    }

    // Calculate determinant
    double SquareMat::operator!() const {
        if (size == 1) return data[0][0];
        if (size == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];

        double det = 0.0;
        for (int col = 0; col < size; ++col) {
            SquareMat minor(size - 1);
            for (int i = 1; i < size; ++i) {
                int mCol = 0;
                for (int j = 0; j < size; ++j) {
                    if (j == col) continue;
                    minor[i - 1][mCol++] = data[i][j];
                }
            }
            det += (col % 2 == 0 ? 1 : -1) * data[0][col] * !minor;
        }
        return det;
    }

    // Add 2 matrices and updates the original matrix
    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        *this = *this + other;
        return *this;
    }

    // Subtract 2 matrices and updates the original matrix
    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        *this = *this - other;
        return *this;
    }

    // Multiply 2 matrices and updates the original matrix
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        *this = *this % other;
        return *this;
    }

    // Multiply matrix by scalar and updates the original matrix
    SquareMat& SquareMat::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    // Divide matrix by scalar and updates the original matrix
    SquareMat& SquareMat::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    // Modulu matrix by scalar and updates the original matrix
    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        *this = *this % other;
        return *this;
    }

    SquareMat& SquareMat::operator%=(int scalar) {
        *this = *this % scalar;
        return *this;
    }

    // Preincrement by 1
    SquareMat& SquareMat::operator++() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                ++data[i][j];
        return *this;
    }

    // Postincrement by 1
    SquareMat SquareMat::operator++(int) {
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    // Predecrement by 1
    SquareMat& SquareMat::operator--() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                --data[i][j];
        return *this;
    }
    
    // Postdecrement by 1
    SquareMat SquareMat::operator--(int) {
        SquareMat temp(*this);
        --(*this);
        return temp;
    }

    // Transpose
    SquareMat SquareMat::operator~() const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result[j][i] = data[i][j];
        return result;
    }

    // Check if the sum 2 matrices is equal
    bool SquareMat::operator==(const SquareMat& other) const {
        if (size != other.size) return false;
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                sum1 += data[i][j];
                sum2 += other.data[i][j];
            }
        return std::abs(sum1 - sum2) < 1e-9;
    }

    // Check if the sum 2 matrices is not equal
    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }

    // Check if the sum of matrix A is lower than the sum of matrix B
    bool SquareMat::operator<(const SquareMat& other) const {
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                sum1 += data[i][j];
                sum2 += other.data[i][j];
            }
        return sum1 < sum2;
    }

    // Check if the sum of matrix A is lower or equal than the sum of matrix B
    bool SquareMat::operator<=(const SquareMat& other) const {
        return *this < other || *this == other;
    }

    // Check if the sum of matrix A is greater than the sum of matrix B
    bool SquareMat::operator>(const SquareMat& other) const {
        return !(*this <= other);
    }

    // Check if the sum of matrix A is greater or equal to the sum of matrix B
    bool SquareMat::operator>=(const SquareMat& other) const {
        return !(*this < other);
    }

    // Print
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << '\n';
        }
        return os;
    }

}
