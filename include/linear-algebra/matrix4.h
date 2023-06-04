#ifndef SMATH_MATRIX4_H
#define SMATH_MATRIX4_H

#include "vector4.h"
#include "constants.h"
#include "complex.h"

#include <ostream>
#include <type_traits>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

namespace smath{namespace linear_algebra{

template<class T>
class Matrix4_impl{
public:
    static_assert(std::is_arithmetic<T>::value || smath::linear_algebra::is_complex<T>::value,
                  "Matrix4 requires a numeric type or a Complex type.");

    T m00, m01, m02, m03;
    T m10, m11, m12, m13;
    T m20, m21, m22, m23;
    T m30, m31, m32, m33;
    Matrix4_impl(T m00 = 0, T m01 = 0, T m02 = 0, T m03 = 0, 
                 T m10 = 0, T m11 = 0, T m12 = 0, T m13 = 0,
                 T m20 = 0, T m21 = 0, T m22 = 0, T m23 = 0,
                 T m30 = 0, T m31 = 0, T m32 = 0, T m33 = 0):
        m00(m00), m01(m01), m02(m02), m03(m03),
        m10(m10), m11(m11), m12(m12), m13(m13),
        m20(m20), m21(m21), m22(m22), m23(m23),
        m30(m30), m31(m31), m32(m32), m33(m33) {};
    Matrix4_impl(Vector4_impl<T> &v, Vector4_impl<T> &u, Vector4_impl<T> &w, Vector4_impl<T> &q): 
        m00(v.x), m10(v.y), m20(v.z), m30(v.w),
        m01(u.x), m11(u.y), m21(u.z), m31(u.w),
        m02(w.x), m12(w.y), m22(w.z), m32(w.w),
        m03(q.x), m13(q.y), m23(q.z), m33(q.w) {};

    // Addittion of this matrix plus another
    template<class U>
    Matrix4_impl operator+=(const Matrix4_impl<U> &other){
        m00 += other.m00; m01 += other.m01; m02 += other.m02; m03 += other.m03;
        m10 += other.m10; m11 += other.m11; m12 += other.m12; m13 += other.m13;
        m20 += other.m20; m21 += other.m21; m22 += other.m22; m23 += other.m23;
        m30 += other.m30; m31 += other.m31; m32 += other.m32; m33 += other.m33;
        return *this;
    }


    // Subtraction of this matrix minus another
    template<class U>
    Matrix4_impl operator-=(const Matrix4_impl<U> &other){
        m00 -= other.m00; m01 -= other.m01; m02 -= other.m02; m03 -= other.m03;
        m10 -= other.m10; m11 -= other.m11; m12 -= other.m12; m13 -= other.m13;
        m20 -= other.m20; m21 -= other.m21; m22 -= other.m22; m23 -= other.m23;
        m30 -= other.m30; m31 -= other.m31; m32 -= other.m32; m33 -= other.m33;
        return *this;
    }


    // Product of this matrix times a scalar
    template<class U>
    Matrix4_impl operator*=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        m00 *= t; m01 *= t; m02 *= t; m03 *= t;
        m10 *= t; m11 *= t; m12 *= t; m13 *= t;
        m20 *= t; m21 *= t; m22 *= t; m23 *= t;
        m30 *= t; m31 *= t; m32 *= t; m33 *= t;
        return *this;
    }


    // Product of this matrix times another
    template<class U>
    Matrix4_impl operator*=(const Matrix4_impl<U> &other){
        T temp00 {m00*other.m00 + m01*other.m10 + m02*other.m20 + m03*other.m30};
        T temp01 {m00*other.m01 + m01*other.m11 + m02*other.m21 + m03*other.m31};
        T temp02 {m00*other.m02 + m01*other.m12 + m02*other.m22 + m03*other.m32};
        T temp03 {m00*other.m03 + m01*other.m13 + m02*other.m23 + m03*other.m33};
        T temp10 {m10*other.m00 + m11*other.m10 + m12*other.m20 + m13*other.m30};
        T temp11 {m10*other.m01 + m11*other.m11 + m12*other.m21 + m13*other.m31};
        T temp12 {m10*other.m02 + m11*other.m12 + m12*other.m22 + m13*other.m32};
        T temp13 {m10*other.m03 + m11*other.m13 + m12*other.m23 + m13*other.m33};
        T temp20 {m20*other.m00 + m21*other.m10 + m22*other.m20 + m23*other.m30};
        T temp21 {m20*other.m01 + m21*other.m11 + m22*other.m21 + m23*other.m31};
        T temp22 {m20*other.m02 + m21*other.m12 + m22*other.m22 + m23*other.m32};
        T temp23 {m20*other.m03 + m21*other.m13 + m22*other.m23 + m23*other.m33};
        T temp30 {m30*other.m00 + m31*other.m10 + m32*other.m20 + m33*other.m30};
        T temp31 {m30*other.m01 + m31*other.m11 + m32*other.m21 + m33*other.m31};
        T temp32 {m30*other.m02 + m31*other.m12 + m32*other.m22 + m33*other.m32};
        T temp33 {m30*other.m03 + m31*other.m13 + m32*other.m23 + m33*other.m33};
        m00 = temp00; 
        m01 = temp01; 
        m02 = temp02;
        m03 = temp03;
        m10 = temp10; 
        m11 = temp11; 
        m12 = temp12;
        m13 = temp13;
        m20 = temp20; 
        m21 = temp21; 
        m22 = temp22;
        m23 = temp23;
        m30 = temp30;
        m31 = temp31;
        m32 = temp32;
        m33 = temp33;
        return *this;
    }


    // Division of this matrix by a scalar
    template<class U>
    Matrix4_impl operator/=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
        m00 *= p; m01 *= p; m02 *= p; m03 *= p;
        m10 *= p; m11 *= p; m12 *= p; m13 *= p;
        m20 *= p; m21 *= p; m22 *= p; m23 *= p;
        m30 *= p; m31 *= p; m32 *= p; m33 *= p;
        return *this;
    }


    // Returns the determinant of this matrix
    T determinant(){
        T result {};
        result = m03*m12*m21*m30 - m02*m13*m21*m30 - m03*m11*m22*m30 + m01*m13*m22*m30+
                 m02*m11*m23*m30 - m01*m12*m23*m30 - m03*m12*m20*m31 + m02*m13*m20*m31+
                 m03*m10*m22*m31 - m00*m13*m22*m31 - m02*m10*m23*m31 + m00*m12*m23*m31+
                 m03*m11*m20*m32 - m01*m13*m20*m32 - m03*m10*m21*m32 + m00*m13*m21*m32+
                 m01*m10*m23*m32 - m00*m11*m23*m32 - m02*m11*m20*m33 + m01*m12*m20*m33+
                 m02*m10*m21*m33 - m00*m12*m21*m33 - m01*m10*m22*m33 + m00*m11*m22*m33;
        return result;
    }


    // Transposes this matrix
    void transpose(){
        T temp {m20};
        m20 = m02; 
        m02 = temp;
        temp = m10;
        m10 = m01;
        m01 = temp;
        temp = m03;
        m03 = m30;
        m30 = temp;
        temp = m21;
        m21 = m12;
        m12 = temp;
        temp = m31;
        m31 = m13;
        m13 = temp;
        temp = m32;
        m32 = m23;
        m23 = temp;
    }


    // Inverts this matrix
    void inverse(){
        // calculate and check the determinant
        T det {};
        det = m03*m12*m21*m30 - m02*m13*m21*m30 - m03*m11*m22*m30 + m01*m13*m22*m30+
              m02*m11*m23*m30 - m01*m12*m23*m30 - m03*m12*m20*m31 + m02*m13*m20*m31+
              m03*m10*m22*m31 - m00*m13*m22*m31 - m02*m10*m23*m31 + m00*m12*m23*m31+
              m03*m11*m20*m32 - m01*m13*m20*m32 - m03*m10*m21*m32 + m00*m13*m21*m32+
              m01*m10*m23*m32 - m00*m11*m23*m32 - m02*m11*m20*m33 + m01*m12*m20*m33+
              m02*m10*m21*m33 - m00*m12*m21*m33 - m01*m10*m22*m33 + m00*m11*m22*m33;
        if(det == 0) return;
        det = 1/det;
        
        // inverse
        T temp00 = (m11*m22*m33 + m12*m23*m31 + m13*m21*m32 - m13*m22*m31 - m12*m21*m33 - m11*m23*m32)*det;
        T temp01 = -(m01*m22*m33 + m02*m23*m31 + m03*m21*m32 - m31*m22*m03 - m21*m02*m33 - m01*m32*m23)*det;
        T temp02 = (m01*m12*m33 + m11*m32*m03 + m02*m13*m31 - m31*m12*m03 - m11*m02*m33 - m32*m13*m01)*det;
        T temp03 = -(m01*m12*m23 + m02*m13*m21 + m03*m11*m22 - m21*m12*m03 - m11*m02*m23 - m01*m22*m13)*det;
        T temp10 = -(m10*m22*m33 + m12*m23*m30 + m20*m32*m13 - m30*m22*m13 - m20*m12*m33 - m32*m23*m10)*det;
        T temp11 = (m00*m22*m33 + m02*m23*m30 + m03*m20*m32 - m30*m22*m03 - m20*m02*m33 - m32*m23*m00)*det;
        T temp12 = -(m00*m12*m33 + m02*m13*m30 + m03*m10*m32 - m30*m12*m03 - m10*m02*m33 - m32*m13*m00)*det;
        T temp13 = (m00*m12*m23 + m02*m13*m20 + m10*m22*m03 - m20*m12*m03 - m10*m02*m23 - m00*m22*m13)*det;
        T temp20 = (m10*m21*m33 + m11*m23*m30 + m20*m31*m13 - m30*m21*m13 - m20*m11*m33 - m10*m31*m23)*det;
        T temp21 = -(m00*m21*m33 + m20*m31*m03 + m01*m23*m30 - m30*m21*m03 - m20*m01*m33 - m31*m23*m00)*det;
        T temp22 = (m00*m11*m33 + m10*m31*m03 + m01*m13*m30 - m30*m11*m03 - m10*m01*m33 - m00*m31*m13)*det;
        T temp23 = -(m00*m11*m23 + m01*m13*m20 + m10*m21*m03 - m20*m11*m03 - m10*m01*m23 - m21*m13*m00)*det;
        T temp30 = -(m10*m21*m32 + m11*m22*m30 + m20*m31*m12 - m30*m21*m12 - m20*m11*m32 - m10*m22*m31)*det;
        T temp31 = (m00*m21*m32 + m01*m22*m30 + m20*m31*m02 - m30*m21*m02 - m20*m01*m32 - m31*m22*m00)*det;
        T temp32 = -(m00*m11*m32 + m01*m12*m30 + m10*m31*m02 - m30*m11*m02 - m10*m01*m32 - m31*m12*m00)*det;
        T temp33 = (m00*m11*m22 + m10*m21*m02 + m01*m12*m20 - m20*m11*m02 - m10*m01*m22 - m00*m21*m12)*det;
        m00 = temp00; m01 = temp01; m02 = temp02; m03 = temp03;
        m10 = temp10; m11 = temp11; m12 = temp12; m13 = temp13;
        m20 = temp20; m21 = temp21; m22 = temp22; m23 = temp23;
        m30 = temp30; m31 = temp31; m32 = temp32; m33 = temp33;
    }
};


// out
template<class T>
inline std::ostream &operator<<(std::ostream &os, const Matrix4_impl<T> &A){
    return os << A.m00 << ", " << A.m01 << ", " << A.m02 << ", " << A.m03 << std::endl <<
                 A.m10 << ", " << A.m11 << ", " << A.m12 << ", " << A.m13 << std::endl << 
                 A.m20 << ", " << A.m21 << ", " << A.m22 << ", " << A.m23 << std::endl <<
                 A.m30 << ", " << A.m31 << ", " << A.m32 << ", " << A.m33;
}


// Addittion of two matrices
template<class T, class U>
inline Matrix4_impl<decltype(T{}+U{})> operator+(const Matrix4_impl<T> &A, const Matrix4_impl<U> &B){
    return Matrix4_impl<decltype(T{}+U{})>(A.m00 + B.m00, A.m01 + B.m01, A.m02 + B.m02, A.m03 + B.m03,
                                           A.m10 + B.m10, A.m11 + B.m11, A.m12 + B.m12, A.m13 + B.m13,
                                           A.m20 + B.m20, A.m21 + B.m21, A.m22 + B.m22, A.m23 + B.m23,
                                           A.m30 + B.m30, A.m31 + B.m31, A.m32 + B.m32, A.m33 + B.m33);
}


// Subtraction of two matrices
template<class T, class U>
inline Matrix4_impl<decltype(T{}+U{})> operator-(const Matrix4_impl<T> &A, const Matrix4_impl<U> &B){
    return Matrix4_impl<decltype(T{}+U{})>(A.m00 - B.m00, A.m01 - B.m01, A.m02 - B.m02, A.m03 - B.m03,
                                           A.m10 - B.m10, A.m11 - B.m11, A.m12 - B.m12, A.m13 - B.m13,
                                           A.m20 - B.m20, A.m21 - B.m21, A.m22 - B.m22, A.m23 - B.m23,
                                           A.m30 - B.m30, A.m31 - B.m31, A.m32 - B.m32, A.m33 - B.m33);
}


// Product of a matrix times a scalar
template<class T, class U>
inline Matrix4_impl<decltype(T{}+U{})> operator*(const Matrix4_impl<T> &A, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Matrix4_impl<decltype(T{}+U{})>(A.m00*t, A.m01*t, A.m02*t, A.m03*t,
                           A.m10*t, A.m11*t, A.m12*t, A.m13*t,
                           A.m20*t, A.m21*t, A.m22*t, A.m23*t,
                           A.m30*t, A.m31*t, A.m32*t, A.m33*t);
}


// Product of a matrix times a scalar
template<class T, class U>
inline Matrix4_impl<decltype(T{}+U{})> operator*(const U t, const Matrix4_impl<T> &A){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Matrix4_impl<decltype(T{}+U{})>(A.m00*t, A.m01*t, A.m02*t, A.m03*t,
                           A.m10*t, A.m11*t, A.m12*t, A.m13*t,
                           A.m20*t, A.m21*t, A.m22*t, A.m23*t,
                           A.m30*t, A.m31*t, A.m32*t, A.m33*t);
}


// Product of a matrix (4x4) times a vector (4x1) -> (4x1)
template<class T, class U>
inline smath::linear_algebra::Vector4_impl<decltype(T{}+U{})> operator*(const Matrix4_impl<T> &A, const smath::linear_algebra::Vector4_impl<U> &v){
    return smath::linear_algebra::Vector4_impl<decltype(T{}+U{})>
                  (A.m00*v.x + A.m01*v.y + A.m02*v.z + A.m03*v.w,
                   A.m10*v.x + A.m11*v.y + A.m12*v.z + A.m13*v.w,
                   A.m20*v.x + A.m21*v.y + A.m22*v.z + A.m23*v.w,
                   A.m30*v.x + A.m31*v.y + A.m32*v.z + A.m33*v.w);
}


// Product of a vector (1x4) times a matrix (4x4) -> (1x4)
template<class T, class U>
inline smath::linear_algebra::Vector4_impl<decltype(T{}+U{})> operator*(const smath::linear_algebra::Vector4_impl<T> &v, const Matrix4_impl<U> &A){
    return smath::linear_algebra::Vector4_impl<decltype(T{}+U{})>
                  (v.x*A.m00 + v.y*A.m10 + v.z*A.m20 + v.w*A.m30,
                   v.x*A.m01 + v.y*A.m11 + v.z*A.m21 + v.w*A.m31,
                   v.x*A.m02 + v.y*A.m12 + v.z*A.m22 + v.w*A.m32,
                   v.x*A.m03 + v.y*A.m13 + v.z*A.m23 + v.w*A.m33);
}


// Product of two matrices (4x4) -> (4x4)
template<class T, class U>
inline Matrix4_impl<decltype(T{}+U{})> operator*(const Matrix4_impl<T> &A, const Matrix4_impl<U> &B){
    return Matrix4_impl<decltype(T{}+U{})>(A.m00*B.m00 + A.m01*B.m10 + A.m02*B.m20 + A.m03*B.m30,
                                           A.m00*B.m01 + A.m01*B.m11 + A.m02*B.m21 + A.m03*B.m31,
                                           A.m00*B.m02 + A.m01*B.m12 + A.m02*B.m22 + A.m03*B.m32,
                                           A.m00*B.m03 + A.m01*B.m13 + A.m02*B.m23 + A.m03*B.m33,
                                           A.m10*B.m00 + A.m11*B.m10 + A.m12*B.m20 + A.m13*B.m30,
                                           A.m10*B.m01 + A.m11*B.m11 + A.m12*B.m21 + A.m13*B.m31,
                                           A.m10*B.m02 + A.m11*B.m12 + A.m12*B.m22 + A.m13*B.m32,
                                           A.m10*B.m03 + A.m11*B.m13 + A.m12*B.m23 + A.m13*B.m33,
                                           A.m20*B.m00 + A.m21*B.m10 + A.m22*B.m20 + A.m23*B.m30,
                                           A.m20*B.m01 + A.m21*B.m11 + A.m22*B.m21 + A.m23*B.m31,
                                           A.m20*B.m02 + A.m21*B.m12 + A.m22*B.m22 + A.m23*B.m32,
                                           A.m20*B.m03 + A.m21*B.m13 + A.m22*B.m23 + A.m23*B.m33,
                                           A.m30*B.m00 + A.m31*B.m10 + A.m32*B.m20 + A.m33*B.m30,
                                           A.m30*B.m01 + A.m31*B.m11 + A.m32*B.m21 + A.m33*B.m31,
                                           A.m30*B.m02 + A.m31*B.m12 + A.m32*B.m22 + A.m33*B.m32,
                                           A.m30*B.m03 + A.m31*B.m13 + A.m32*B.m23 + A.m33*B.m33);
}


// Division of a matrix by a scalar
template<class T, class U>
inline Matrix4_impl<decltype(T{}+U{})> operator/(const Matrix4_impl<T> &A, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
    return Matrix4_impl<decltype(T{}+U{})>(A.m00*p, A.m01*p, A.m02*p, A.m03*p,
                           A.m10*p, A.m11*p, A.m12*p, A.m13*p,
                           A.m20*p, A.m21*p, A.m22*p, A.m23*p,
                           A.m30*p, A.m31*p, A.m32*p, A.m33*p);
}


template<class T, class U>
inline bool operator==(const Matrix4_impl<T> &A, const Matrix4_impl<U> &B){
    return std::abs(A.m00 - B.m00) <= EPSILON &&
           std::abs(A.m01 - B.m01) <= EPSILON &&
           std::abs(A.m02 - B.m02) <= EPSILON &&
           std::abs(A.m03 - B.m03) <= EPSILON &&
           std::abs(A.m10 - B.m10) <= EPSILON &&
           std::abs(A.m11 - B.m11) <= EPSILON &&
           std::abs(A.m12 - B.m12) <= EPSILON &&
           std::abs(A.m13 - B.m13) <= EPSILON &&
           std::abs(A.m20 - B.m20) <= EPSILON &&
           std::abs(A.m21 - B.m21) <= EPSILON &&
           std::abs(A.m22 - B.m22) <= EPSILON &&
           std::abs(A.m23 - B.m23) <= EPSILON &&
           std::abs(A.m30 - B.m30) <= EPSILON &&
           std::abs(A.m31 - B.m31) <= EPSILON &&
           std::abs(A.m32 - B.m32) <= EPSILON &&
           std::abs(A.m33 - B.m33) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace matrix4{
// Returns the identity matrix (3x3)
template<class T>
inline Matrix4_impl<T> identity(){
    return Matrix4_impl<T>(1, 0, 0, 0,
                           0, 1, 0, 0,
                           0, 0, 1, 0,
                           0, 0, 0, 1);
}


// Returns the determinant of the input matrix
template<class T>
inline T determinant(const Matrix4_impl<T> &A){
    T m00 {A.m00}; T m01 {A.m01}; T m02 {A.m02}; T m03 {A.m03};
    T m10 {A.m10}; T m11 {A.m11}; T m12 {A.m12}; T m13 {A.m13};
    T m20 {A.m20}; T m21 {A.m21}; T m22 {A.m22}; T m23 {A.m23};
    T m30 {A.m30}; T m31 {A.m31}; T m32 {A.m32}; T m33 {A.m33};

    T result {};
    result = m03*m12*m21*m30 - m02*m13*m21*m30 - m03*m11*m22*m30 + m01*m13*m22*m30+
             m02*m11*m23*m30 - m01*m12*m23*m30 - m03*m12*m20*m31 + m02*m13*m20*m31+
             m03*m10*m22*m31 - m00*m13*m22*m31 - m02*m10*m23*m31 + m00*m12*m23*m31+
             m03*m11*m20*m32 - m01*m13*m20*m32 - m03*m10*m21*m32 + m00*m13*m21*m32+
             m01*m10*m23*m32 - m00*m11*m23*m32 - m02*m11*m20*m33 + m01*m12*m20*m33+
             m02*m10*m21*m33 - m00*m12*m21*m33 - m01*m10*m22*m33 + m00*m11*m22*m33;
    return result;
}


// Returns the transpose of the input matrix
template<class T>
inline Matrix4_impl<T> transpose(const Matrix4_impl<T> &A){
    return Matrix4_impl<T>(A.m00, A.m10, A.m20, A.m30,
                           A.m01, A.m11, A.m21, A.m31,
                           A.m02, A.m12, A.m22, A.m32,
                           A.m03, A.m13, A.m23, A.m33);
}


// Returns the inverse of the input matrix
template<class T>
inline Matrix4_impl<T> inverse(Matrix4_impl<T> &A){
    T m00 {A.m00}; T m01 {A.m01}; T m02 {A.m02}; T m03 {A.m03};
    T m10 {A.m10}; T m11 {A.m11}; T m12 {A.m12}; T m13 {A.m13};
    T m20 {A.m20}; T m21 {A.m21}; T m22 {A.m22}; T m23 {A.m23};
    T m30 {A.m30}; T m31 {A.m31}; T m32 {A.m32}; T m33 {A.m33};

    // calculate and check the determinant
    T det {};
    det = m03*m12*m21*m30 - m02*m13*m21*m30 - m03*m11*m22*m30 + m01*m13*m22*m30+
          m02*m11*m23*m30 - m01*m12*m23*m30 - m03*m12*m20*m31 + m02*m13*m20*m31+
          m03*m10*m22*m31 - m00*m13*m22*m31 - m02*m10*m23*m31 + m00*m12*m23*m31+
          m03*m11*m20*m32 - m01*m13*m20*m32 - m03*m10*m21*m32 + m00*m13*m21*m32+
          m01*m10*m23*m32 - m00*m11*m23*m32 - m02*m11*m20*m33 + m01*m12*m20*m33+
          m02*m10*m21*m33 - m00*m12*m21*m33 - m01*m10*m22*m33 + m00*m11*m22*m33;
    if(det == 0) return A;
    det = 1/det;

    // inverse
    T temp00 = (m11*m22*m33 + m12*m23*m31 + m13*m21*m32 - m13*m22*m31 - m12*m21*m33 - m11*m23*m32)*det;
    T temp01 = -(m01*m22*m33 + m02*m23*m31 + m03*m21*m32 - m31*m22*m03 - m21*m02*m33 - m01*m32*m23)*det;
    T temp02 = (m01*m12*m33 + m11*m32*m03 + m02*m13*m31 - m31*m12*m03 - m11*m02*m33 - m32*m13*m01)*det;
    T temp03 = -(m01*m12*m23 + m02*m13*m21 + m03*m11*m22 - m21*m12*m03 - m11*m02*m23 - m01*m22*m13)*det;
    T temp10 = -(m10*m22*m33 + m12*m23*m30 + m20*m32*m13 - m30*m22*m13 - m20*m12*m33 - m32*m23*m10)*det;
    T temp11 = (m00*m22*m33 + m02*m23*m30 + m03*m20*m32 - m30*m22*m03 - m20*m02*m33 - m32*m23*m00)*det;
    T temp12 = -(m00*m12*m33 + m02*m13*m30 + m03*m10*m32 - m30*m12*m03 - m10*m02*m33 - m32*m13*m00)*det;
    T temp13 = (m00*m12*m23 + m02*m13*m20 + m10*m22*m03 - m20*m12*m03 - m10*m02*m23 - m00*m22*m13)*det;
    T temp20 = (m10*m21*m33 + m11*m23*m30 + m20*m31*m13 - m30*m21*m13 - m20*m11*m33 - m10*m31*m23)*det;
    T temp21 = -(m00*m21*m33 + m20*m31*m03 + m01*m23*m30 - m30*m21*m03 - m20*m01*m33 - m31*m23*m00)*det;
    T temp22 = (m00*m11*m33 + m10*m31*m03 + m01*m13*m30 - m30*m11*m03 - m10*m01*m33 - m00*m31*m13)*det;
    T temp23 = -(m00*m11*m23 + m01*m13*m20 + m10*m21*m03 - m20*m11*m03 - m10*m01*m23 - m21*m13*m00)*det;
    T temp30 = -(m10*m21*m32 + m11*m22*m30 + m20*m31*m12 - m30*m21*m12 - m20*m11*m32 - m10*m22*m31)*det;
    T temp31 = (m00*m21*m32 + m01*m22*m30 + m20*m31*m02 - m30*m21*m02 - m20*m01*m32 - m31*m22*m00)*det;
    T temp32 = -(m00*m11*m32 + m01*m12*m30 + m10*m31*m02 - m30*m11*m02 - m10*m01*m32 - m31*m12*m00)*det;
    T temp33 = (m00*m11*m22 + m10*m21*m02 + m01*m12*m20 - m20*m11*m02 - m10*m01*m22 - m00*m21*m12)*det;
    return Matrix4_impl<T>(temp00, temp01, temp02, temp03,
                   temp10, temp11, temp12, temp13,
                   temp20, temp21, temp22, temp23,
                   temp30, temp31, temp32, temp33);
}
}


using Matrix4 = Matrix4_impl<double>;
using Matrix4i = Matrix4_impl<int>;
using Matrix4f = Matrix4_impl<float>;
using Matrix4c = Matrix4_impl<smath::linear_algebra::Complex>;

}}

#endif
