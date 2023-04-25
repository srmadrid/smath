#include "../../include/linear-algebra/vector2.h"
#include "../../include/linear-algebra/matrix2.h"
#include "../../include/linear-algebra/constants.h"

#include <cmath>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

// Addittion of this matrix plus another
Matrix2 Matrix2::operator+=(const Matrix2 &other){
    m00 += other.m00; m01 += other.m01;
    m10 += other.m10; m11 += other.m11;
    return *this;
}


// Subtraction of this matrix minus another
Matrix2 Matrix2::operator-=(const Matrix2 &other){
    m00 -= other.m00; m01 -= other.m01;
    m10 -= other.m10; m11 -= other.m11;
    return *this;
}


// Product of this matrix times a scalar
Matrix2 Matrix2::operator*=(const double t){
    m00 *= t; m01 *= t;
    m10 *= t; m11 *= t;
    return *this;
}


// Product of this matrix times another
Matrix2 Matrix2::operator*=(const Matrix2 &other){
    double temp00 {m00*other.m00 + m01*other.m10};
    double temp10 {m10*other.m00 + m11*other.m10};
    double temp01 {m00*other.m01 + m01*other.m11};
    double temp11 {m10*other.m01 + m11*other.m11};
    m00 = temp00; m01 = temp01;
    m10 = temp10; m11 = temp11;
    return *this;
}


// Division of this matrix by a scalar
Matrix2 Matrix2::operator/=(const double t){
    double p = 1/t;
    m00 *= p; m01 *= p;
    m10 *= p, m11 *= p;
    return *this;
}


// returns the determinant of this matrix
double Matrix2::determinant(){
    return m00*m11 - m01*m10;
}


// Transpose this matrix
void Matrix2::transpose(){
    double temp = m01;
    m01 = m10; m10 = temp;
}


// Inverts this matrix
void Matrix2::inverse(){
    double det {m00*m11 - m01*m10};
    if(det == 0) return;
    det = 1/det;
    double temp {m00};
    m00 = m11*det; m01 = -m01*det;
    m10 = -m10*det; m11 = temp*det;
}


// out
std::ostream &operator<<(std::ostream &os, const Matrix2 &A){
    return os << A.m00 << ", " << A.m01 << std::endl <<
                 A.m10 << ", " << A.m11;
}


// Addition of two matrices
Matrix2 operator+(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00 + B.m00, A.m01 + B.m01, A.m10 + B.m10,  A.m11 + B.m11);
}


// Subtraction of two matrices
Matrix2 operator-(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00 - B.m00, A.m01 - B.m01, A.m10 - B.m10, A.m11 - B.m11);
}


// Product of a matrix by a scalar
Matrix2 operator*(const Matrix2 &A, double t){
    return Matrix2(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}


// Product of a matrix by a scalar
Matrix2 operator*(double t, const Matrix2 &A){
    return Matrix2(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}


// Product of a matrix (2x2) times a vector (2x1) -> (2x1)
Vector2 operator*(const Matrix2 &A, const Vector2 &v){
    return Vector2(A.m00*v.x + A.m01*v.y, A.m10*v.x + A.m11*v.y);
}


// Product of a vector (1x2) times a matrix (2x2) -> (1x2)
Vector2 operator*(const Vector2 &v, const Matrix2 &A){
    return Vector2(v.x*A.m00 + v.y*A.m10, v.x*A.m01 + v.y*A.m11);
}


// Product of two matrices (2x2) -> (2x2)
Matrix2 operator*(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00*B.m00 + A.m01*B.m10, A.m00*B.m01 + A.m01*B.m11,
                   A.m10*B.m00 + A.m11*B.m10, A.m10*B.m01 + A.m11*B.m11);
}


// Division of a matrix by a scalar
Matrix2 operator/(const Matrix2 &A, double t){
    double p = 1/t;
    return Matrix2(A.m00*p, A.m01*p, A.m10*p, A.m11*p);
}


bool operator==(const Matrix2 &A, const Matrix2 &B){
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
Matrix2 identity(){
    return Matrix2(1, 0, 0, 1);
}


// Returns the determinant of the input matrix
double determinant(const Matrix2 &A){
    return A.m00*A.m11 - A.m01*A.m10;
}


// Returns the transpose of the input matrix
Matrix2 transpose(const Matrix2 &A){
    return Matrix2(A.m00, A.m10, A.m01, A.m11);
}


// Returns the inverse of the input matrix
Matrix2 inverse(const Matrix2 &A){
    // calculate and check determinant
    double aux {A.m00*A.m11 - A.m01*A.m10};
    if(aux == 0) return A;
    aux = 1/aux;

    // inverse
    return Matrix2(A.m11*aux, -A.m01*aux, -A.m10*aux, A.m00*aux);
}

}

