#include "../../include/algebra/vector2.h"
#include "../../include/algebra/matrix2.h"


Matrix2 Matrix2::operator+=(const Matrix2 &other){
    m00 += other.m00; m01 += other.m01;
    m10 += other.m10; m11 += other.m11;
    return *this;
}

Matrix2 Matrix2::operator-=(const Matrix2 &other){
    m00 -= other.m00; m01 -= other.m01;
    m10 -= other.m10; m11 -= other.m11;
    return *this;
}

Matrix2 Matrix2::operator*=(const double t){
    m00 *= t; m01 *= t;
    m10 *= t; m11 *= t;
    return *this;
}

Matrix2 Matrix2::operator*=(const Matrix2 &other){
    double temp00 {m00*other.m00 + m01*other.m10};
    double temp10 {m10*other.m00 + m11*other.m10};
    double temp01 {m00*other.m01 + m01*other.m11};
    double temp11 {m10*other.m01 + m11*other.m11};
    m00 = temp00; m01 = temp01;
    m10 = temp10; m11 = temp11;
    return *this;
}

Matrix2 Matrix2::operator/=(const double t){
    double p = 1/t;
    m00 *= p; m01 *= p;
    m10 *= p, m11 *= p;
    return *this;
}

double Matrix2::determinant(){
    return m00*m11 - m01*m10;
}

void Matrix2::transpose(){
    double temp = m00;
    m00 = m11; m11 = temp;
}

void Matrix2::inverse(){
    double det {m00*m11 - m01*m10};
    if(det == 0) return;
    det = 1/det;
    double temp {m00};
    m00 = m11*det; m01 = -m01*det;
    m10 = -m10*det; m11 = temp*det;
}

Matrix2 operator+(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00 + B.m00, A.m01 + B.m01, A.m10 + B.m10,  A.m11 + B.m11);
}

Matrix2 operator-(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00 - B.m00, A.m01 - B.m01, A.m10 - B.m10, A.m11 - B.m11);
}

Matrix2 operator*(const Matrix2 &A, double t){
    return Matrix2(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}

Matrix2 operator*(double t, const Matrix2 &A){
    return Matrix2(A.m00*t, A.m01*t, A.m10*t, A.m11*t);
}

Vector2 operator*(const Matrix2 &A, const Vector2 &v){
    return Vector2(A.m00*v.x + A.m01*v.y, A.m10*v.x + A.m11*v.y);
}

Vector2 operator*(const Vector2 &v, const Matrix2 &A){
    return Vector2(v.x*A.m00 + v.y*A.m10, v.x*A.m01 + v.y*A.m11);
}

Matrix2 operator*(const Matrix2 &A, const Matrix2 &B){
    return Matrix2(A.m00*B.m00 + A.m01*B.m10, A.m00*B.m01 + A.m01*B.m11,
                   A.m10*B.m00 + A.m11*B.m10, A.m10*B.m01 + A.m11*B.m11);
}

Matrix2 operator/(const Matrix2 &A, double t){
    double p = 1/t;
    return Matrix2(A.m00*p, A.m01*p, A.m10*p, A.m11*p);
}

bool operator==(const Matrix2 &A, const Matrix2 &B){
    return A.m00 == B.m00 && A.m01 == B.m01 && A.m10 == B.m10 && A.m11 == B.m11;
}


namespace matrix2{

Matrix2 identity(){
    return Matrix2(1, 0, 0, 1);
}

double determinant(Matrix2 &A){
    return A.m00*A.m11 - A.m01*A.m10;
}

Matrix2 transpose(Matrix2 &A){
    return Matrix2(A.m00, A.m10, A.m01, A.m11);
}

Matrix2 inverse(Matrix2 &A){
    double aux {A.m00*A.m11 - A.m01*A.m10};
    if(aux == 0) return A;
    aux = 1/aux;
    return Matrix2(A.m11*aux, -A.m01*aux, -A.m10*aux, A.m00*aux);
}

}

