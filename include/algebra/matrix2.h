#ifndef MATRIX2_H
#define MATRIX2_H

#include "vector2.h"


class Matrix2{
public:
    double m00, m01;
    double m10, m11;
    Matrix2(double m00 = 0, double m01 = 0, double m10 = 0, double m11 = 0):
        m00(m00), m01(m01), m10(m10), m11(m11) {};
    Matrix2(Vector2 &v, Vector2 &u): m00(v.x), m10(v.y), m01(u.x), m11(u.y) {};

    Matrix2 operator+=(const Matrix2 &other);
    Matrix2 operator-=(const Matrix2 &other);
    Matrix2 operator*=(const double t);
    Matrix2 operator*=(const Matrix2 &other);
    Matrix2 operator/=(const double t);

    double determinant();
    void transpose();
    void inverse();
};


Matrix2 operator+(const Matrix2 &A, const Matrix2 &B);
Matrix2 operator-(const Matrix2 &A, const Matrix2 &B);
Matrix2 operator*(const Matrix2 &A, double t);
Matrix2 operator*(double t, const Matrix2 &A);
Vector2 operator*(const Matrix2 &A, const Vector2 &v);
Vector2 operator*(const Vector2 &v, const Matrix2 &A);
Matrix2 operator*(const Matrix2 &A, const Matrix2 &B);
Matrix2 operator/(const Matrix2 &A, double t);
bool operator==(const Matrix2 &A, const Matrix2 &B);


namespace matrix2{

Matrix2 identity();
double determinant(Matrix2 &A);
Matrix2 transpose(Matrix2 &A);
Matrix2 inverse(Matrix2 &A);

}



#endif
