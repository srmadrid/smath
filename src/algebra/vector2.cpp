#include "../../include/algebra/vector2.h"

#include <cmath>
#include <string>
#include <iostream>



Vector2 Vector2::operator+=(const Vector2 &other){
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator-=(const Vector2 &other){
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2 Vector2::operator*=(const double t){
    x *= t;
    y *= t;
    return *this;
}

Vector2 Vector2::operator/=(const double t){
    x /= t;
    y /= t;
    return *this;
}


void Vector2::print(){
    std::cout << "<" << x << ", " << y << ">" << std::endl;
}

double Vector2::modulus(){
    return std::sqrt(x*x + y*y);
}

void Vector2::normalize(){
    double modulus {this->modulus()};
    x /= modulus;
    y /= modulus;
}



Vector2 operator+(const Vector2 &v, const Vector2 &u){
    return Vector2(v.x + u.x, v.y + u.y);
}

Vector2 operator-(const Vector2 &v, const Vector2 &u){
    return Vector2(v.x - u.x, v.y - u.y);
}

Vector2 operator*(const Vector2 &v, double t){
    return Vector2(v.x*t, v.y*t);
}

Vector2 operator/(const Vector2 &v, double t){
    return Vector2(v.x/t, v.y/t);
}


bool operator==(const Vector2 &v, const Vector2 &u){
    return v.x == u.x && v.y == u.y;
}


namespace algebra{
namespace vector2{

double dot(const Vector2 &v, const Vector2 &u){
    return v.x*u.x + v.y*u.y;
}

}
}
