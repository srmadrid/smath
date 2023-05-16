#ifndef MATRIX3_H
#define MATRIX3_H

#include "vector3.h"
#include "constants.h"

#include <ostream>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

class Matrix3{
public:
    double m00, m01, m02;
    double m10, m11, m12;
    double m20, m21, m22;
    Matrix3(double m00 = 0, double m01 = 0, double m02 = 0, 
            double m10 = 0, double m11 = 0, double m12 = 0, 
            double m20 = 0, double m21 = 0, double m22 = 0):
        m00(m00), m01(m01), m02(m02), m10(m10), m11(m11), m12(m12), m20(m20), m21(m21), m22(m22) {};
    Matrix3(Vector3 &v, Vector3 &u, Vector3 &w): 
        m00(v.x), m10(v.y), m20(v.z), m01(u.x), m11(u.y), m21(u.z), m02(w.x), m12(w.y), m22(w.z) {};

    // Addittion of this matrix plus another
    Matrix3 operator+=(const Matrix3 &other){
        m00 += other.m00; m01 += other.m01; m02 += other.m02;
        m10 += other.m10; m11 += other.m11; m12 += other.m12;
        m20 += other.m20; m21 += other.m21; m22 += other.m22;
        return *this;
    }


    // Subtraction of this matrix minus another
    Matrix3 operator-=(const Matrix3 &other){
        m00 -= other.m00; m01 -= other.m01; m02 -= other.m02;
        m10 -= other.m10; m11 -= other.m11; m12 -= other.m12;
        m20 -= other.m20; m21 -= other.m21; m22 -= other.m22;
        return *this;
    }


    // Product of this matrix times a scalar
    Matrix3 operator*=(const double t){
        m00 *= t; m01 *= t; m02 *= t;
        m10 *= t; m11 *= t; m12 *= t;
        m20 *= t; m21 *= t; m22 *= t;
        return *this;
    }


    // Product of this matrix times another
    Matrix3 operator*=(const Matrix3 &other){
        double temp00 {m00*other.m00 + m01*other.m10 + m02*other.m20};
        double temp01 {m00*other.m01 + m01*other.m11 + m02*other.m21};
        double temp02 {m00*other.m02 + m01*other.m12 + m02*other.m22};
        double temp10 {m10*other.m00 + m11*other.m10 + m12*other.m20};
        double temp11 {m10*other.m01 + m11*other.m11 + m12*other.m21};
        double temp12 {m10*other.m02 + m11*other.m12 + m12*other.m22};
        double temp20 {m20*other.m00 + m21*other.m10 + m22*other.m20};
        double temp21 {m20*other.m01 + m21*other.m11 + m22*other.m21};
        double temp22 {m20*other.m02 + m21*other.m12 + m22*other.m22};
        m00 = temp00; 
        m01 = temp01; 
        m02 = temp02;
        m10 = temp10; 
        m11 = temp11; 
        m12 = temp12;
        m20 = temp20; 
        m21 = temp21; 
        m22 = temp22;
        return *this;
    }


    // Division of this matrix by a scalar
    Matrix3 operator/=(const double t){
        double p {1/t};
        m00 *= p; m01 *= p; m02 *= p;
        m10 *= p; m11 *= p; m12 *= p;
        m20 *= p; m21 *= p; m22 *= p;
        return *this;
    }


    // Returns the determinant of this matrix
    double determinant(){
        return m00*m11*m22 + m01*m12*m20 + m02*m10*m21 - m20*m11*m02 - m10*m01*m22 - m00*m21*m12;
    }


    // Transposes this matrix
    void transpose(){
        double temp {m20};
        m20 = m02; m02 = temp;
        temp = m10;
        m10 = m01;
        m01 = temp;
        temp = m21;
        m21 = m12;
        m12 = temp;
    }


    // Inverts this matrix
    void inverse(){
        // calculate and check the determinant
        double det {m00*m11*m22 + m01*m12*m20 + m02*m10*m21 - m20*m11*m02 - m10*m01*m22 - m00*m21*m12};
        if(det == 0) return;
        det = 1/det;

        // transpose
        double temp {m20};
        m20 = m02; m02 = temp;
        temp = m10;
        m10 = m01;
        m01 = temp;
        temp = m21;
        m21 = m12;
        m12 = temp;

        // adjugate matrix
        double temp00 {m11*m22 - m12*m21}; double temp01 {-(m10*m22 - m12*m20)}; double temp02 {m10*m21 - m11*m20};
        double temp10 {-(m01*m22 - m21*m02)}; double temp11 {m00*m22 - m02*m20}; double temp12 {-(m00*m21 - m01*m20)};
        double temp20 {m01*m12 - m02*m11}; double temp21 {-(m00*m12 - m02*m10)}; double temp22 {m00*m11 - m10*m01};

        // inverse
        m00 = temp00*det; m01 = temp01*det; m02 = temp02*det;
        m10 = temp10*det; m11 = temp11*det; m12 = temp12*det;
        m20 = temp20*det; m21 = temp21*det; m22 = temp22*det;
    }
};


// out
inline std::ostream &operator<<(std::ostream &os, const Matrix3 &A){
    return os << A.m00 << ", " << A.m01 << ", " << A.m02 << std::endl <<
                 A.m10 << ", " << A.m11 << ", " << A.m12 << std::endl << 
                 A.m20 << ", " << A.m21 << ", " << A.m22;
}


// Addittion of two matrices
inline Matrix3 operator+(const Matrix3 &A, const Matrix3 &B){
    return Matrix3(A.m00 + B.m00, A.m01 + B.m01, A.m02 + B.m02,
                   A.m10 + B.m10, A.m11 + B.m11, A.m12 + B.m12,
                   A.m20 + B.m20, A.m21 + B.m21, A.m22 + B.m22);
}


// Subtraction of two matrices
inline Matrix3 operator-(const Matrix3 &A, const Matrix3 &B){
    return Matrix3(A.m00 - B.m00, A.m01 - B.m01, A.m02 - B.m02,
                   A.m10 - B.m10, A.m11 - B.m11, A.m12 - B.m12,
                   A.m20 - B.m20, A.m21 - B.m21, A.m22 - B.m22);
}


// Product of a matrix times a scalar
inline Matrix3 operator*(const Matrix3 &A, double t){
    return Matrix3(A.m00*t, A.m01*t, A.m02*t,
                   A.m10*t, A.m11*t, A.m12*t,
                   A.m20*t, A.m21*t, A.m22*t);
}


// Product of a matrix times a scalar
inline Matrix3 operator*(double t, const Matrix3 &A){
    return Matrix3(A.m00*t, A.m01*t, A.m02*t,
                   A.m10*t, A.m11*t, A.m12*t,
                   A.m20*t, A.m21*t, A.m22*t);
}


// Product of a matrix (3x3) times a vector (3x1) -> (3x1)
inline Vector3 operator*(const Matrix3 &A, const Vector3 &v){
    return Vector3(A.m00*v.x + A.m01*v.y + A.m02*v.z, A.m10*v.x + A.m11*v.y + A.m12*v.z, A.m20*v.x + A.m21*v.y + A.m22*v.z);
}


// Product of a vector (1x3) times a matrix (3x3) -> (1x3)
inline Vector3 operator*(const Vector3 &v, const Matrix3 &A){
    return Vector3(v.x*A.m00 + v.y*A.m10 + v.z*A.m20, v.x*A.m01 + v.y*A.m11 + v.z*A.m21, v.x*A.m02 + v.y*A.m12 + v.z*A.m22);
}


// Product of two matrices (3x3) -> (3x3)
inline Matrix3 operator*(const Matrix3 &A, const Matrix3 &B){
    return Matrix3(A.m00*B.m00 + A.m01*B.m10 + A.m02*B.m20, 
                   A.m00*B.m01 + A.m01*B.m11 + A.m02*B.m21, 
                   A.m00*B.m02 + A.m01*B.m12 + A.m02*B.m22,
                   A.m10*B.m00 + A.m11*B.m10 + A.m12*B.m20, 
                   A.m10*B.m01 + A.m11*B.m11 + A.m12*B.m21, 
                   A.m10*B.m02 + A.m11*B.m12 + A.m12*B.m22,
                   A.m20*B.m00 + A.m21*B.m10 + A.m22*B.m20, 
                   A.m20*B.m01 + A.m21*B.m11 + A.m22*B.m21, 
                   A.m20*B.m02 + A.m21*B.m12 + A.m22*B.m22);
}


// Division of a matrix by a scalar
inline Matrix3 operator/(const Matrix3 &A, double t){
    double p {1/t};
    return Matrix3(A.m00*p, A.m01*p, A.m02*p,
                   A.m10*p, A.m11*p, A.m12*p,
                   A.m20*p, A.m21*p, A.m22*p);
}


inline bool operator==(const Matrix3 &A, const Matrix3 &B){
    return std::abs(A.m00 - B.m00) <= EPSILON &&
           std::abs(A.m01 - B.m01) <= EPSILON &&
           std::abs(A.m02 - B.m02) <= EPSILON &&
           std::abs(A.m10 - B.m10) <= EPSILON &&
           std::abs(A.m11 - B.m11) <= EPSILON &&
           std::abs(A.m12 - B.m12) <= EPSILON &&
           std::abs(A.m20 - B.m20) <= EPSILON &&
           std::abs(A.m21 - B.m21) <= EPSILON &&
           std::abs(A.m22 - B.m22) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace matrix3{

// Returns the identity matrix (3x3)
inline Matrix3 identity(){
    return Matrix3(1, 0, 0,
                   0, 1, 0,
                   0, 0, 1);
}


// Returns the determinant of the input matrix
inline double determinant(const Matrix3 &A){
    return A.m00*A.m11*A.m22 + A.m01*A.m12*A.m20 + A.m02*A.m10*A.m21 - A.m20*A.m11*A.m02 - A.m10*A.m01*A.m22 - A.m00*A.m21*A.m12;
}


// Returns the transpose of the input matrix
inline Matrix3 transpose(const Matrix3 &A){
    return Matrix3(A.m00, A.m10, A.m20,
                   A.m01, A.m11, A.m21,
                   A.m02, A.m12, A.m22);
}


// Returns the inverse of the input matrix
inline Matrix3 inverse(Matrix3 A){
    // calculate and check the determinant
    double det {A.m00*A.m11*A.m22 + A.m01*A.m12*A.m20 + A.m02*A.m10*A.m21 - A.m20*A.m11*A.m02 - A.m10*A.m01*A.m22 - A.m00*A.m21*A.m12};
    if(det == 0) return A;
    det = 1/det;

    // transpose
    double temp {A.m20};
    A.m20 = A.m02; A.m02 = temp;
    temp = A.m10;
    A.m10 = A.m01; A.m01 = temp;
    temp = A.m21;
    A.m21 = A.m12; A.m12 = temp;

    // adjugate matrix
    double temp00 {A.m11*A.m22 - A.m12*A.m21}; double temp01 {-(A.m10*A.m22 - A.m12*A.m20)}; double temp02 {A.m10*A.m21 - A.m11*A.m20};
    double temp10 {-(A.m01*A.m22 - A.m21*A.m02)}; double temp11 {A.m00*A.m22 - A.m02*A.m20}; double temp12 {-(A.m00*A.m21 - A.m01*A.m20)};
    double temp20 {A.m01*A.m12 - A.m02*A.m11}; double temp21 {-(A.m00*A.m12 - A.m02*A.m10)}; double temp22 {A.m00*A.m11 - A.m10*A.m01};

    // inverse
    return Matrix3(temp00*det, temp01*det, temp02*det,
                   temp10*det, temp11*det, temp12*det,
                   temp20*det, temp21*det, temp22*det);
}

}



#endif
