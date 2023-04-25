#include "../../include/linear-algebra/vector3.h"
#include "../../include/linear-algebra/constants.h"

#include <cmath>
#include <string>
#include <iostream>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

// Addition of this vector plus another
Vector3 Vector3::operator+=(const Vector3 &other){
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}


// Subtraction of this vector minus another
Vector3 Vector3::operator-=(const Vector3 &other){
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}


// Product of this vector times another
Vector3 Vector3::operator*=(const double t){
    x *= t;
    y *= t;
    z *= t;
    return *this;
}


// Division of this vector by a scalar
Vector3 Vector3::operator/=(const double t){
    double p {1/t};
    x *= p;
    y *= p;
    z *= p;
    return *this;
}


// Returns the modulus of this vector
double Vector3::modulus(){
    return std::sqrt(x*x + y*y + z*z);
}


// Normalizes this vector
void Vector3::normalize(){
    double modulus {1/this->modulus()};
    x *= modulus;
    y *= modulus;
    z *= modulus;
}


// out
std::ostream &operator<<(std::ostream &os, const Vector3 &v){
    return os << "<" << v.x << ", " << v.y << ", " << v.z << ">";
}


// Addittion of two vectors
Vector3 operator+(const Vector3 &v, const Vector3 &u){
    return Vector3(v.x + u.x, v.y + u.y, v.z + u.z);
}


// Subtraction of two vectors
Vector3 operator-(const Vector3 &v, const Vector3 &u){
    return Vector3(v.x - u.x, v.y - u.y, v.z - u.z);
}


// Product of a vector times a scalar
Vector3 operator*(const Vector3 &v, double t){
    return Vector3(v.x*t, v.y*t, v.z*t);
}


// Product of a vector times a scalar
Vector3 operator*(double t, const Vector3 &v){
    return Vector3(v.x*t, v.y*t, v.z*t);
}


// Division of a vector by a scalar
Vector3 operator/(const Vector3 &v, double t){
    double p {1/t};
    return Vector3(v.x*p, v.y*p, v.z*p);
}


bool operator==(const Vector3 &v, const Vector3 &u){
    return std::abs(v.x - u.x) <= EPSILON &&
           std::abs(v.y - u.y) <= EPSILON &&
           std::abs(v.z - u.z) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace vector3{

// Returns the dot product of the input vectors
double dot(const Vector3 &v, const Vector3 &u){
    return v.x*u.x + v.y*u.y + v.z*u.z;
}


// Returns the cross product of the input vectors
Vector3 cross(const Vector3 &v, const Vector3 &u){
    return Vector3(v.y*u.z - v.z*u.y, v.z*u.x - v.x*u.z, v.x*u.y - v.y*u.x);
}

}
