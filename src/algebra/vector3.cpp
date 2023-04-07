#include "../../include/algebra/vector3.h"

#include <cmath>
#include <string>
#include <iostream>



Vector3 Vector3::operator+=(const Vector3 &other){
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3 Vector3::operator-=(const Vector3 &other){
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3 Vector3::operator*=(const double t){
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

Vector3 Vector3::operator/=(const double t){
    x /= t;
    y /= t;
    z /= t;
    return *this;
}


void Vector3::print(){
    std::cout << "<" << x << ", " << y << ", " << z << ">" << std::endl;
}

double Vector3::modulus(){
    return std::sqrt(x*x + y*y + z*z);
}

void Vector3::normalize(){
    double modulus {this->modulus()};
    x /= modulus;
    y /= modulus;
    z /= modulus;
}



Vector3 operator+(const Vector3 &v, const Vector3 &u){
    return Vector3(v.x + u.x, v.y + u.y, v.z + u.z);
}

Vector3 operator-(const Vector3 &v, const Vector3 &u){
    return Vector3(v.x - u.x, v.y - u.y, v.z - u.z);
}

Vector3 operator*(const Vector3 &v, double t){
    return Vector3(v.x*t, v.y*t, v.z*t);
}

Vector3 operator/(const Vector3 &v, double t){
    return Vector3(v.x/t, v.y/t, v.z/t);
}


bool operator==(const Vector3 &v, const Vector3 &u){
    return v.x == u.x && v.y == u.y && v.z == u.z;
}


namespace algebra{
namespace vector3{

double dot(const Vector3 &v, const Vector3 &u){
    return v.x*u.x + v.y*u.y + v.z*u.z;
}

Vector3 cross(const Vector3 &v, const Vector3 &u){
    return Vector3(v.y*u.z - v.z*u.y, v.z*u.x - v.x*u.z, v.x*u.y - v.y*u.x);
}

}
}
