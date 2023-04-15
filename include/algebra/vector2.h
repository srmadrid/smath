#ifndef VECTOR2_H
#define VECTOR2_H



class Vector2{
public:
    double x, y;
    Vector2(double x = 0, double y = 0): x(x), y(y) {};

    Vector2 operator+=(const Vector2 &other);
    Vector2 operator-=(const Vector2 &other);
    Vector2 operator*=(const double t);
    Vector2 operator/=(const double t);

    void print();
    double modulus();
    void normalize();
};


Vector2 operator+(const Vector2 &v, const Vector2 &u);
Vector2 operator-(const Vector2 &v, const Vector2 &u);
Vector2 operator*(const Vector2 &v, double t);
Vector2 operator/(const Vector2 &v, double t);
bool operator==(const Vector2 &v, const Vector2 &u);


namespace algebra{
namespace vector2{

double dot(const Vector2 &v, const Vector2 &u);

}
}



#endif
