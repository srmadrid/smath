#ifndef MATRIX2_H
#define MATRIX2_H

#include "vector2.h"
#include "constants.h"

#include <ostream>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

class Matrix2{
public:
    double m00, m01;
    double m10, m11;
    Matrix2(double m00 = 0, double m01 = 0, double m10 = 0, double m11 = 0):
        m00(m00), m01(m01), m10(m10), m11(m11) {};
    Matrix2(Vector2 &v, Vector2 &u): m00(v.x), m10(v.y), m01(u.x), m11(u.y) {};

    // Addittion of this matrix plus another
    Matrix2 operator+=(const Matrix2 &other){
        m00 += other.m00; m01 += other.m01;
        m10 += other.m10; m11 += other.m11;
        return *this;
    }


    // Subtraction of this matrix minus another
    Matrix2 operator-=(const Matrix2 &other){
        m00 -= other.m00; m01 -= other.m01;
        m10 -= other.m10; m11 -= other.m11;
        return *this;
    }


    // Product of this matrix times a scalar
    Matrix2 operator*=(const double t){
        m00 *= t; m01 *= t;
        m10 *= t; m11 *= t;
        return *this;
    }


    // Product of this matrix times another
    Matrix2 operator*=(const Matrix2 &other){
        double temp00 {m00*other.m00 + m01*other.m10};
        double temp10 {m10*other.m00 + m11*other.m10};
        double temp01 {m00*other.m01 + m01*other.m11};
        double temp11 {m10*other.m01 + m11*other.m11};
        m00 = temp00; m01 = temp01;
        m10 = temp10; m11 = temp11;
        return *this;
    }


    // Division of this matrix by a scalar
    Matrix2 operator/=(const double t){
        double p = 1/t;
        m00 *= p; m01 *= p;
        m10 *= p, m11 *= p;
        return *this;
    }


    // returns the determinant of this matrix
    double determinant(){
        return m00*m11 - m01*m10;
    }


    // Transpose this matrix
    void transpose(){
        double temp = m01;
        m01 = m10; m10 = temp;
    }


    // Inverts this matrix
    void inverse(){
        double det {m00*m11 - m01*m10};
        if(det == 0) return;
        det = 1/det;
        double temp {m00};
        m00 = m11*det; m01 = -m01*det;
        m10 = -m10*det; m11 = temp*det;
    }
};


// out
inline std::ostream &operator<<(std::ostream &os, const Matrix2 &A){
    return os << A.m00 << ", " << A.m01 << std::endl <<
                 A.m10 << ", " << A.m11;
}


// Addition of two matrices
inline Matrix2 operator+(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00 + B.m00, A.m01 + B.m01, A.m10 + B.m10,  A.m11 + B.m11);
}


// Subtraction of two matrices
inline Matrix2 operator-(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00 - B.m00, A.m01 - B.m01, A.m10 - B.m10, A.m11 - B.m11);
}


// Product of a matrix by a scalar
inline Matrix2 operator*(const Matrix2 &A, double t){
    return Matrix2(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}


// Product of a matrix by a scalar
inline Matrix2 operator*(double t, const Matrix2 &A){
    return Matrix2(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}


// Product of a matrix (2x2) times a vector (2x1) -> (2x1)
inline Vector2 operator*(const Matrix2 &A, const Vector2 &v){
    return Vector2(A.m00*v.x + A.m01*v.y, A.m10*v.x + A.m11*v.y);
}


// Product of a vector (1x2) times a matrix (2x2) -> (1x2)
inline Vector2 operator*(const Vector2 &v, const Matrix2 &A){
    return Vector2(v.x*A.m00 + v.y*A.m10, v.x*A.m01 + v.y*A.m11);
}


// Product of two matrices (2x2) -> (2x2)
inline Matrix2 operator*(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00*B.m00 + A.m01*B.m10, A.m00*B.m01 + A.m01*B.m11,
                   A.m10*B.m00 + A.m11*B.m10, A.m10*B.m01 + A.m11*B.m11);
}


// Division of a matrix by a scalar
inline Matrix2 operator/(const Matrix2 &A, double t){
    double p = 1/t;
    return Matrix2(A.m00*p, A.m01*p, A.m10*p, A.m11*p);
}


inline bool operator==(const Matrix2 &A, const Matrix2 &B){
    return std::abs(A.m00 - B.m00) <= EPSILON &&
           std::abs(A.m01 - B.m01) <= EPSILON &&
           std::abs(A.m10 - B.m10) <= EPSILON &&
           std::abs(A.m11 - B.m11) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace matrix2{

// Returns the (2x2) identity matrix
inline Matrix2 identity(){
    return Matrix2(1, 0, 0, 1);
}


// Returns the determinant of the input matrix
inline double determinant(const Matrix2 &A){
    return A.m00*A.m11 - A.m01*A.m10;
}


// Returns the transpose of the input matrix
inline Matrix2 transpose(const Matrix2 &A){
    return Matrix2(A.m00, A.m10, A.m01, A.m11);
}


// Returns the inverse of the input matrix
inline Matrix2 inverse(const Matrix2 &A){
    // calculate and check determinant
    double aux {A.m00*A.m11 - A.m01*A.m10};
    if(aux == 0) return A;
    aux = 1/aux;

    // inverse
    return Matrix2(A.m11*aux, -A.m01*aux, -A.m10*aux, A.m00*aux);
}

}



#endif
