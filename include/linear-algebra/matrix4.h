#ifndef MATRIX4_H
#define MATRIX4_H

#include "vector4.h"
#include "constants.h"

#include <ostream>


class Matrix4{
public:
    double m00, m01, m02, m03;
    double m10, m11, m12, m13;
    double m20, m21, m22, m23;
    double m30, m31, m32, m33;
    Matrix4(double m00 = 0, double m01 = 0, double m02 = 0, double m03 = 0, 
            double m10 = 0, double m11 = 0, double m12 = 0, double m13 = 0,
            double m20 = 0, double m21 = 0, double m22 = 0, double m23 = 0,
            double m30 = 0, double m31 = 0, double m32 = 0, double m33 = 0):
        m00(m00), m01(m01), m02(m02), m03(m03),
        m10(m10), m11(m11), m12(m12), m13(m13),
        m20(m20), m21(m21), m22(m22), m23(m23),
        m30(m30), m31(m31), m32(m32), m33(m33) {};
    Matrix4(Vector4 &v, Vector4 &u, Vector4 &w, Vector4 &q): 
        m00(v.x), m10(v.y), m20(v.z), m30(v.w),
        m01(u.x), m11(u.y), m21(u.z), m31(u.w),
        m02(w.x), m12(w.y), m22(w.z), m32(w.w),
        m03(q.x), m13(q.y), m23(q.z), m33(q.w) {};

    Matrix4 operator+=(const Matrix4 &other);
    Matrix4 operator-=(const Matrix4 &other);
    Matrix4 operator*=(const double t);
    Matrix4 operator*=(const Matrix4 &other);
    Matrix4 operator/=(const double t);

    double determinant();
    void transpose();
    void inverse();
};


std::ostream &operator<<(std::ostream &os, const Matrix4 &A);
Matrix4 operator+(const Matrix4 &A, const Matrix4 &B);
Matrix4 operator-(const Matrix4 &A, const Matrix4 &B);
Matrix4 operator*(const Matrix4 &A, double t);
Matrix4 operator*(double t, const Matrix4 &A);
Vector4 operator*(const Matrix4 &A, const Vector4 &v);
Vector4 operator*(const Vector4 &v, const Matrix4 &A);
Matrix4 operator*(const Matrix4 &A, const Matrix4 &B);
Matrix4 operator/(const Matrix4 &A, double t);
bool operator==(const Matrix4 &A, const Matrix4 &B);


namespace matrix4{

Matrix4 identity();
double determinant(const Matrix4 &A);
Matrix4 transpose(const Matrix4 &A);
Matrix4 inverse(Matrix4 &A);

}



#endif
