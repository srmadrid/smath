#include "../../include/linear-algebra/vector4.h"
#include "../../include/linear-algebra/constants.h"

#include <cmath>
#include <string>
#include <iostream>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

// Addition of this vector plus another
Vector4 Vector4::operator+=(const Vector4 &other){
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}


// Subtraction of this vector minus another
Vector4 Vector4::operator-=(const Vector4 &other){
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}


// Product of this vector times another
Vector4 Vector4::operator*=(const double t){
    x *= t;
    y *= t;
    z *= t;
    w *= t;
    return *this;
}


// Division of this vector by a scalar
Vector4 Vector4::operator/=(const double t){
    double p = 1/t;
    x *= p;
    y *= p;
    z *= p;
    w *= p;
    return *this;
}


// Returns the modulus of this vector
double Vector4::modulus(){
    return std::sqrt(x*x + y*y + z*z + w*w);
}


// Normalizes this vector
void Vector4::normalize(){
    double modulus {1/this->modulus()};
    x *= modulus;
    y *= modulus;
    z *= modulus;
    w *= modulus;
}


// out
std::ostream &operator<<(std::ostream &os, const Vector4 &v){
    return os << "<" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ">";
}


// Addittion of two vectors
Vector4 operator+(const Vector4 &v, const Vector4 &u){
    return Vector4(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w);
}


// Subtraction of two vectors
Vector4 operator-(const Vector4 &v, const Vector4 &u){
    return Vector4(v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w);
}


// Product of a vector times a scalar
Vector4 operator*(const Vector4 &v, double t){
    return Vector4(v.x*t, v.y*t, v.z*t, v.w*t);
}


// Product of a vector times a scalar
Vector4 operator*(double t, const Vector4 &v){
    return Vector4(v.x*t, v.y*t, v.z*t, v.w*t);
}


// Division of a vector by a scalar
Vector4 operator/(const Vector4 &v, double t){
    double p {1/t};
    return Vector4(v.x*p, v.y*p, v.z*p, v.w*p);
}


bool operator==(const Vector4 &v, const Vector4 &u){
    return std::abs(v.x - u.x) <= EPSILON &&
           std::abs(v.y - u.y) <= EPSILON &&
           std::abs(v.z - u.z) <= EPSILON &&
           std::abs(v.w - u.w) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace vector4{

// Returns the dot product of the input vectors
double dot(const Vector4 &v, const Vector4 &u){
    return v.x*u.x + v.y*u.y + v.z*u.z + v.w*u.w;
}

}
