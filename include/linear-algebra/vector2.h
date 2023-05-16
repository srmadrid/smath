#ifndef VECTOR2_H
#define VECTOR2_H

#include "constants.h"

#include <ostream>
#include <cmath>


//------------------------------------------------------------------------------
// functions
//------------------------------------------------------------------------------

class Vector2{
public:
    double x, y;
    Vector2(double x = 0, double y = 0): x(x), y(y) {};

    // Addittion of this vector plus another 
    Vector2 operator+=(const Vector2 &other){
        x += other.x;
        y += other.y;
        return *this;
    }


    // Subtraction of this vector minus another
    Vector2 operator-=(const Vector2 &other){
        x -= other.x;
        y -= other.y;
        return *this;
    }


    // Product of this vector times a scalar
    Vector2 operator*=(const double t){
        x *= t;
        y *= t;
        return *this;
    }


    // Division of this vector by a scalar
    Vector2 operator/=(const double t){
        double p {1/t};
        x *= p;
        y *= p;
        return *this;
    }


    // Returns the modulus of this vector
    double modulus(){
        return std::sqrt(x*x + y*y);
    }


    // Normalizes this vector
    void normalize(){
        double modulus {1/this->modulus()};
        x *= modulus;
        y *= modulus;
    }
};


// out
inline std::ostream &operator<<(std::ostream &os, const Vector2 &v){
    return os << "<" << v.x << ", " << v.y << ">";
}

// Addition of two vectors
inline Vector2 operator+(const Vector2 &v, const Vector2 &u){
    return Vector2(v.x + u.x, v.y + u.y);
}


// Subtraction of two vectors
inline Vector2 operator-(const Vector2 &v, const Vector2 &u){
    return Vector2(v.x - u.x, v.y - u.y);
}


// Product of a vector times a scalar
inline Vector2 operator*(const Vector2 &v, double t){
    return Vector2(v.x*t, v.y*t);
}


// Product of a vector times a scalar
inline Vector2 operator*(double t, const Vector2 &v){
    return Vector2(v.x*t, v.y*t);
}


// Division of a vector by a scalar
inline Vector2 operator/(const Vector2 &v, double t){
    double p {1/t};
    return Vector2(v.x*p, v.y*p);
}


inline bool operator==(const Vector2 &v, const Vector2 &u){
    return std::abs(v.x - u.x) <= EPSILON &&
           std::abs(v.y - u.y) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace vector2{

// Returns the dot product of two vectors
inline double dot(const Vector2 &v, const Vector2 &u){
    return v.x*u.x + v.y*u.y;
}

}



#endif
