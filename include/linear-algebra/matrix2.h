#ifndef SMATH_MATRIX2_H
#define SMATH_MATRIX2_H

#include "vector2.h"
#include "constants.h"
#include "complex.h"

#include <ostream>
#include <type_traits>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

namespace smath{namespace linear_algebra{

template<class T>
class Matrix2_impl{
public:
    static_assert(std::is_arithmetic<T>::value || smath::linear_algebra::is_complex<T>::value,
                  "Matrix2 requires a numeric type or a Complex type.");

    T m00, m01;
    T m10, m11;
    Matrix2_impl(T m00 = 0, T m01 = 0, T m10 = 0, T m11 = 0):
        m00(m00), m01(m01), m10(m10), m11(m11) {};
    Matrix2_impl(smath::linear_algebra::Vector2_impl<T> &v, smath::linear_algebra::Vector2_impl<T> &u): 
        m00(v.x), m10(v.y), m01(u.x), m11(u.y) {};


    // Addittion of this matrix plus another
    template<class U>
    Matrix2_impl operator+=(const Matrix2_impl<U> &other){
        m00 += other.m00; m01 += other.m01;
        m10 += other.m10; m11 += other.m11;
        return *this;
    }


    // Subtraction of this matrix minus another
    template<class U>
    Matrix2_impl operator-=(const Matrix2_impl<U> &other){
        m00 -= other.m00; m01 -= other.m01;
        m10 -= other.m10; m11 -= other.m11;
        return *this;
    }


    // Product of this matrix times a scalar
    template<class U>
    Matrix2_impl operator*=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        m00 *= t; m01 *= t;
        m10 *= t; m11 *= t;
        return *this;
    }


    // Product of this matrix times another
    template<class U>
    Matrix2_impl operator*=(const Matrix2_impl<U> &other){
        decltype(T{}+U{}) temp00 {m00*other.m00 + m01*other.m10};
        decltype(T{}+U{}) temp10 {m10*other.m00 + m11*other.m10};
        decltype(T{}+U{}) temp01 {m00*other.m01 + m01*other.m11};
        decltype(T{}+U{}) temp11 {m10*other.m01 + m11*other.m11};
        m00 = temp00; m01 = temp01;
        m10 = temp10; m11 = temp11;
        return *this;
    }


    // Division of this matrix by a scalar
    template<class U>
    Matrix2_impl operator/=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
        m00 *= p; m01 *= p;
        m10 *= p, m11 *= p;
        return *this;
    }


    // returns the determinant of this matrix
    T determinant(){
        return m00*m11 - m01*m10;
    }


    // Transpose this matrix
    void transpose(){
        T temp = m01;
        m01 = m10; m10 = temp;
    }


    // Inverts this matrix
    void inverse(){
        T det {m00*m11 - m01*m10};
        if(det == 0) return;
        det = 1/det;
        T temp {m00};
        m00 = m11*det; m01 = -m01*det;
        m10 = -m10*det; m11 = temp*det;
    }
};


// out
template<class T>
inline std::ostream &operator<<(std::ostream &os, const Matrix2_impl<T> &A){
    return os << A.m00 << ", " << A.m01 << std::endl <<
                 A.m10 << ", " << A.m11;
}


// Addition of two matrices
template<class T, class U>
inline Matrix2_impl<decltype(T{}+U{})> operator+(const Matrix2_impl<T> &A, const Matrix2_impl<U> &B){
    return Matrix2_impl<decltype(T{}+U{})>(A.m00 + B.m00, A.m01 + B.m01, A.m10 + B.m10,  A.m11 + B.m11);
}


// Subtraction of two matrices
template<class T, class U>
inline Matrix2_impl<decltype(T{}+U{})> operator-(const Matrix2_impl<T> &A, const Matrix2_impl<U> &B){
    return Matrix2_impl<decltype(T{}+U{})>(A.m00 - B.m00, A.m01 - B.m01, A.m10 - B.m10, A.m11 - B.m11);
}


// Product of a matrix by a scalar
template<class T, class U>
inline Matrix2_impl<decltype(T{}+U{})> operator*(const Matrix2_impl<T> &A, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Matrix2_impl<decltype(T{}+U{})>(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}


// Product of a matrix by a scalar
template<class T, class U>
inline Matrix2_impl<decltype(T{}+U{})> operator*(const U t, const Matrix2_impl<T> &A){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Matrix2_impl<decltype(T{}+U{})>(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}


// Product of a matrix (2x2) times a vector (2x1) -> (2x1)
template<class T, class U>
inline smath::linear_algebra::Vector2_impl<decltype(T{}+U{})> operator*(const Matrix2_impl<T> &A, const smath::linear_algebra::Vector2_impl<U> &v){
    return smath::linear_algebra::Vector2_impl<decltype(T{}+U{})>(A.m00*v.x + A.m01*v.y, A.m10*v.x + A.m11*v.y);
}


// Product of a vector (1x2) times a matrix (2x2) -> (1x2)
template<class T, class U>
inline smath::linear_algebra::Vector2_impl<decltype(T{}+U{})> operator*(const smath::linear_algebra::Vector2_impl<T> &v, const Matrix2_impl<U> &A){
    return smath::linear_algebra::Vector2_impl<decltype(T{}+U{})>(v.x*A.m00 + v.y*A.m10, v.x*A.m01 + v.y*A.m11);
}


// Product of two matrices (2x2) -> (2x2)
template<class T, class U>
inline Matrix2_impl<decltype(T{}+U{})> operator*(const Matrix2_impl<T> &A, const Matrix2_impl<U> &B){
    return Matrix2_impl<decltype(T{}+U{})>(A.m00*B.m00 + A.m01*B.m10, A.m00*B.m01 + A.m01*B.m11,
                   A.m10*B.m00 + A.m11*B.m10, A.m10*B.m01 + A.m11*B.m11);
}


// Division of a matrix by a scalar
template<class T, class U>
inline Matrix2_impl<decltype(T{}+U{})> operator/(const Matrix2_impl<T> &A, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
    return Matrix2_impl<decltype(T{}+U{})>(A.m00*p, A.m01*p, A.m10*p, A.m11*p);
}


template<class T, class U>
inline bool operator==(const Matrix2_impl<T> &A, const Matrix2_impl<U> &B){
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
template<class T>
inline Matrix2_impl<T> identity(){
    return Matrix2_impl<T>(1, 0, 0, 1);
}


// Returns the determinant of the input matrix
template<class T>
inline T determinant(const Matrix2_impl<T> &A){
    return A.m00*A.m11 - A.m01*A.m10;
}


// Returns the transpose of the input matrix
template<class T>
inline Matrix2_impl<T> transpose(const Matrix2_impl<T> &A){
    return Matrix2_impl<T>(A.m00, A.m10, A.m01, A.m11);
}


// Returns the inverse of the input matrix
template<class T>
inline Matrix2_impl<T> inverse(const Matrix2_impl<T> &A){
    // calculate and check determinant
    T aux {A.m00*A.m11 - A.m01*A.m10};
    if(aux == 0) return A;
    aux = 1/aux;

    // inverse
    return Matrix2_impl<T>(A.m11*aux, -A.m01*aux, -A.m10*aux, A.m00*aux);
}
}


using Matrix2 = Matrix2_impl<double>;
using Matrix2i = Matrix2_impl<int>;
using Matrix2f = Matrix2_impl<float>;
using Matrix2c = Matrix2_impl<smath::linear_algebra::Complex>;

}}

#endif
