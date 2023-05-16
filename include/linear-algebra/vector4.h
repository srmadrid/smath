#ifndef VECTOR4_H
#define VECTOR4_H

#include "constants.h"

#include <ostream>
#include <cmath>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

class Vector4{
public:
    double x, y, z, w;
    Vector4(double x = 0, double y = 0, double z = 0, double w = 0): x(x), y(y), z(z), w(w) {};

    // Addition of this vector plus another
    Vector4 operator+=(const Vector4 &other){
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }


    // Subtraction of this vector minus another
    Vector4 operator-=(const Vector4 &other){
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }


    // Product of this vector times another
    Vector4 operator*=(const double t){
        x *= t;
        y *= t;
        z *= t;
        w *= t;
        return *this;
    }


    // Division of this vector by a scalar
    Vector4 operator/=(const double t){
        double p = 1/t;
        x *= p;
        y *= p;
        z *= p;
        w *= p;
        return *this;
    }


    // Returns the modulus of this vector
    double modulus(){
        return std::sqrt(x*x + y*y + z*z + w*w);
    }


    // Normalizes this vector
    void normalize(){
        double modulus {1/this->modulus()};
        x *= modulus;
        y *= modulus;
        z *= modulus;
        w *= modulus;
    }
};


// out
inline std::ostream &operator<<(std::ostream &os, const Vector4 &v){
    return os << "<" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ">";
}


// Addittion of two vectors
inline Vector4 operator+(const Vector4 &v, const Vector4 &u){
    return Vector4(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w);
}


// Subtraction of two vectors
inline Vector4 operator-(const Vector4 &v, const Vector4 &u){
    return Vector4(v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w);
}


// Product of a vector times a scalar
inline Vector4 operator*(const Vector4 &v, double t){
    return Vector4(v.x*t, v.y*t, v.z*t, v.w*t);
}


// Product of a vector times a scalar
inline Vector4 operator*(double t, const Vector4 &v){
    return Vector4(v.x*t, v.y*t, v.z*t, v.w*t);
}


// Division of a vector by a scalar
inline Vector4 operator/(const Vector4 &v, double t){
    double p {1/t};
    return Vector4(v.x*p, v.y*p, v.z*p, v.w*p);
}


inline bool operator==(const Vector4 &v, const Vector4 &u){
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
inline double dot(const Vector4 &v, const Vector4 &u){
    return v.x*u.x + v.y*u.y + v.z*u.z + v.w*u.w;
}

}



#endif
