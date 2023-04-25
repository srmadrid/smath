#ifndef VECTOR4_H
#define VECTOR4_H

#include "constants.h"

#include <ostream>


class Vector4{
public:
    double x, y, z, w;
    Vector4(double x = 0, double y = 0, double z = 0, double w = 0): x(x), y(y), z(z), w(w) {};

    Vector4 operator+=(const Vector4 &other);
    Vector4 operator-=(const Vector4 &other);
    Vector4 operator*=(const double t);
    Vector4 operator/=(const double t);

    double modulus();
    void normalize();
};


std::ostream &operator<<(std::ostream &os, const Vector4 &v);
Vector4 operator+(const Vector4 &v, const Vector4 &u);
Vector4 operator-(const Vector4 &v, const Vector4 &u);
Vector4 operator*(const Vector4 &v, double t);
Vector4 operator*(double t, const Vector4 &v);
Vector4 operator/(const Vector4 &v, double t);
bool operator==(const Vector4 &v, const Vector4 &u);


namespace vector4{

double dot(const Vector4 &v, const Vector4 &u);

}



#endif
