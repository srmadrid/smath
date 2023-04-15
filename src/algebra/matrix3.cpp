#include "../../include/algebra/matrix3.h"

#include <iostream>
#include <ostream>


Matrix3 Matrix3::operator+=(const Matrix3 &other){
    m00 += other.m00; m01 += other.m01; m02 += other.m02;
    m10 += other.m10; m11 += other.m11; m12 += other.m12;
    m20 += other.m20; m21 += other.m21; m22 += other.m22;
    return *this;
}


Matrix3 Matrix3::operator-=(const Matrix3 &other){
    m00 -= other.m00; m01 -= other.m01; m02 -= other.m02;
    m10 -= other.m10; m11 -= other.m11; m12 -= other.m12;
    m20 -= other.m20; m21 -= other.m21; m22 -= other.m22;
    return *this;
}


Matrix3 Matrix3::operator*=(const double t){
    m00 *= t; m01 *= t; m02 *= t;
    m10 *= t; m11 *= t; m12 *= t;
    m20 *= t; m21 *= t; m22 *= t;
    return *this;
}


Matrix3 Matrix3::operator*=(const Matrix3 &other){
    return *this;
}


Matrix3 Matrix3::operator/=(const double t){
    double p {1/t};
    m00 *= p; m01 *= p; m02 *= p;
    m10 *= p; m11 *= p; m12 *= p;
    m20 *= p; m21 *= p; m22 *= p;
    return *this;
}


double Matrix3::determinant(){
    return m00*m11*m22 + m01*m12*m20 + m02*m10*m21 - m20*m11*m02 - m10*m01*m22 - m00*m21*m12;
}


void Matrix3::transpose(){
    double temp {m20};
    m20 = m02; m02 = temp;
    temp = m10;
    m10 = m01;
    m01 = temp;
    temp = m21;
    m21 = m12;
    m12 = temp;
}


void Matrix3::inverse(){
    // calculate and check determinant
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


std::ostream &operator<<(std::ostream &os, const Matrix3 &A){
    return os << A.m00 << ", " << A.m01 << ", " << A.m02 << std::endl <<
                 A.m10 << ", " << A.m11 << ", " << A.m12 << std::endl << 
                 A.m20 << ", " << A.m21 << ", " << A.m22;
}

Matrix3 operator+(const Matrix3 &A, const Matrix3 &B){
    return Matrix3(A.m00 + B.m00, A.m01 + B.m01, A.m02 + B.m02,
                   A.m10 + B.m10, A.m11 + B.m11, A.m12 + B.m12,
                   A.m20 + B.m20, A.m21 + B.m21, A.m22 + B.m22);
}


Matrix3 operator-(const Matrix3 &A, const Matrix3 &B){
    return Matrix3(A.m00 - B.m00, A.m01 - B.m01, A.m02 - B.m02,
                   A.m10 - B.m10, A.m11 - B.m11, A.m12 - B.m12,
                   A.m20 - B.m20, A.m21 - B.m21, A.m22 - B.m22);
}


Matrix3 operator*(const Matrix3 &A, double t){
    return Matrix3(A.m00*t, A.m01*t, A.m02*t,
                   A.m10*t, A.m11*t, A.m12*t,
                   A.m20*t, A.m21*t, A.m22*t);
}


Matrix3 operator*(double t, const Matrix3 &A){
    return Matrix3(A.m00*t, A.m01*t, A.m02*t,
                   A.m10*t, A.m11*t, A.m12*t,
                   A.m20*t, A.m21*t, A.m22*t);
}


Vector3 operator*(const Matrix3 &A, const Vector3 &v);
Vector3 operator*(const Vector3 &v, const Matrix3 &A);
Matrix3 operator*(const Matrix3 &A, const Matrix3 &B);
Matrix3 operator/(const Matrix3 &A, double t){
    double p {1/t};
    return Matrix3(A.m00*p, A.m01*p, A.m02*p,
                   A.m10*p, A.m11*p, A.m12*p,
                   A.m20*p, A.m21*p, A.m22*p);
}


bool operator==(const Matrix3 &A, const Matrix3 &B);


namespace matrix3{

Matrix3 identity(){
    return Matrix3(1, 0, 0,
                   0, 1, 0,
                   0, 0, 1);
}


double determinant(Matrix3 &A){
    return A.m00*A.m11*A.m22 + A.m01*A.m12*A.m20 + A.m02*A.m10*A.m21 - A.m20*A.m11*A.m02 - A.m10*A.m01*A.m22 - A.m00*A.m21*A.m12;
}


Matrix3 transpose(Matrix3 &A){
    return Matrix3(A.m00, A.m10, A.m20,
                   A.m01, A.m11, A.m21,
                   A.m02, A.m12, A.m22);
}


Matrix3 inverse(Matrix3 A){
    // calculate and check determinant
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
