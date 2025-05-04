// Email: sharon4homework@gmail.com

#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP

#include <iostream>
#include <stdexcept>

namespace sqaremat {

    class SquareMat {
    private:
        int size;          
        double** data;

        void allocateMatrix(); // Helper to allocate memory
        void deallocateMatrix(); // Helper to free memory
        void copyFrom(const SquareMat& other); // Helper for copy logic

    public:
        SquareMat(int n); // Constructor
        SquareMat(const SquareMat& other); // Copy constructor
        SquareMat& operator=(const SquareMat& other); // Copy assignment
        ~SquareMat(); // Destructor

        int getSize() const;

        double* operator[](int row);
        const double* operator[](int row) const;

        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat& other) const;
        SquareMat operator*(double scalar) const;
        friend SquareMat operator*(double scalar, const SquareMat& mat);

        SquareMat operator%(const SquareMat& other) const;
        SquareMat operator%(int scalar) const;

        SquareMat operator/(double scalar) const;
        SquareMat operator^(int power) const;

        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);
        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(double scalar);
        SquareMat& operator/=(double scalar);
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int scalar);

        SquareMat& operator++(); // Prefix ++
        SquareMat operator++(int); // Postfix ++
        SquareMat& operator--(); // Prefix --
        SquareMat operator--(int); // Postfix --

        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;

        SquareMat operator~() const; // Transpose
        double operator!() const; // Determinant

        // Output
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
    };

}

#endif
