#ifndef VECTOR3_H
#define VECTOR3_H

#include "constants.h"

#include <ostream>


class Vector3{
public:
    double x, y, z;
    Vector3(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {};

    Vector3 operator+=(const Vector3 &other);
    Vector3 operator-=(const Vector3 &other);
    Vector3 operator*=(const double t);
    Vector3 operator/=(const double t);

    double modulus();
    void normalize();
};


std::ostream &operator<<(std::ostream &os, const Vector3 &v);
Vector3 operator+(const Vector3 &v, const Vector3 &u);
Vector3 operator-(const Vector3 &v, const Vector3 &u);
Vector3 operator*(const Vector3 &v, double t);
Vector3 operator*(double t, const Vector3 &v);
Vector3 operator/(const Vector3 &v, double t);
bool operator==(const Vector3 &v, const Vector3 &u);


namespace vector3{

double dot(const Vector3 &v, const Vector3 &u);
Vector3 cross(const Vector3 &v, const Vector3 &u);

}



#endif
