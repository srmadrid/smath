#ifndef MATRIX3_H
#define MATRIX3_H

#include "vector3.h"

#include <ostream>


class Matrix3{
public:
    double m00, m01, m02;
    double m10, m11, m12;
    double m20, m21, m22;
    Matrix3(double m00 = 0, double m01 = 0, double m02 = 0, double m10 = 0, double m11 = 0, double m12 = 0, double m20 = 0, double m21 = 0, double m22 = 0):
        m00(m00), m01(m01), m02(m02), m10(m10), m11(m11), m12(m12), m20(m20), m21(m21), m22(m22) {};
    Matrix3(Vector3 &v, Vector3 &u, Vector3 &w): 
        m00(v.x), m10(v.y), m20(v.z), m01(u.x), m11(u.y), m21(u.z), m02(w.x), m12(w.y), m22(w.z) {};

    Matrix3 operator+=(const Matrix3 &other);
    Matrix3 operator-=(const Matrix3 &other);
    Matrix3 operator*=(const double t);
    Matrix3 operator*=(const Matrix3 &other);
    Matrix3 operator/=(const double t);

    double determinant();
    void transpose();
    void inverse();
};


std::ostream &operator<<(std::ostream &os, const Matrix3 &A);
Matrix3 operator+(const Matrix3 &A, const Matrix3 &B);
Matrix3 operator-(const Matrix3 &A, const Matrix3 &B);
Matrix3 operator*(const Matrix3 &A, double t);
Matrix3 operator*(double t, const Matrix3 &A);
Vector3 operator*(const Matrix3 &A, const Vector3 &v);
Vector3 operator*(const Vector3 &v, const Matrix3 &A);
Matrix3 operator*(const Matrix3 &A, const Matrix3 &B);
Matrix3 operator/(const Matrix3 &A, double t);
bool operator==(const Matrix3 &A, const Matrix3 &B);


namespace matrix3{

Matrix3 identity();
double determinant(Matrix3 &A);
Matrix3 transpose(Matrix3 &A);
Matrix3 inverse(Matrix3 A);

}



#endif
