#ifndef COMPLEX_H
#define COMPLEX_H

#include "constants.h"

#include <ostream>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

class Complex{
public:
    double a, b;
    Complex(double a = 0, double b = 0):
        a(a), b(b) {};

    // Addittion of this complex plus another one 
    Complex operator+=(const Complex &other){
        a += other.a;
        b += other.b;
        return *this;
    }


    // Addittion of this complex plus a scalar
    Complex operator+=(const double t){
        a += t;
        return *this;
    }


    // Subtraction of this complex minus another one
    Complex operator-=(const Complex &other){
        a -= other.a;
        b -= other.b;
        return *this;
    }
    

    // Subtraction of this complex minus a scalar
    Complex operator-=(const double t){
        a -= t;
        return *this;
    }


    // Multiplication of this complex times a scalar
    Complex operator*=(const double t){
        a *= t;
        b *= t;
        return *this;
    }


    // Multiplication of this complex times another complex
    Complex operator*=(const Complex &other){
        double tempa = a*other.a - b*other.b;
        double tempb = a*other.b + b*other.a;
        a = tempa;
        b = tempb;
        return *this;
    }


    // Division of this complex by a scalar
    Complex operator/=(const double t){
        double p {1/t};
        a *= p;
        b *= p;
        return *this;
    }


    // Division of this complex by another complex
    Complex operator/=(const Complex &other){
        double temp = 1/(other.a*other.a + other.b*other.b);
        double tempa = a*other.a + b*other.b;
        double tempb = b*other.a - a*other.b;
        a = tempa*temp;
        b = tempb*temp;
        return *this;
    }
};


// out
inline std::ostream &operator<<(std::ostream &os, const Complex &c){
    if(c.a == 0){
        return os << c.b << "i";
    }else if(c.b == 0){
        return os << c.a;
    }else if(c.b > 0){
        return os << c.a << " + " << c.b << "i";
    }else{
        return os << c.a << " - " << std::abs(c.b) << "i";
    }
}


// Addition of two complexes
inline Complex operator+(const Complex &c, const Complex &w){
    return Complex(c.a + w.a, c.b + w.b);
}


// Addition of a complex and a scalar
inline Complex operator+(const Complex &c, const double t){
    return Complex(c.a + t, c.b);
}


// Addition of a complex and a scalar
inline Complex operator+(const double t, const Complex &c){
    return Complex(t + c.a, c.b);
}


// Subtraction of a complex minus a complex
inline Complex operator-(const Complex &c, const Complex &w){
    return Complex(c.a - w.a, c.b - w.b);
}


// Subtraction of a complex minus a scalar
inline Complex operator-(const Complex &c, const double t){
    return Complex(c.a - t, c.b);
}


// Subtraction of a scalar minus a complex
inline Complex operator-(const double t, const Complex &c){
    return Complex(t - c.a, -c.b);
}


// Multiplication of a complex times a scalar
inline Complex operator*(const Complex &c, double t){
    return Complex(c.a*t, c.b*t);
}


// Multiplication of a scalar times a complex
inline Complex operator*(double t, const Complex &c){
    return Complex(t*c.a, t*c.b);
}


// Multiplication of a complex times a complex
inline Complex operator*(const Complex &c, const Complex &w){
    return Complex(c.a*w.a - c.b*w.b, c.a*w.b + c.b*w.a);
}


// Division of a complex by a scalar
inline Complex operator/(const Complex &c, double t){
    double p {1/t};
    return Complex(c.a*p, c.b*p);
}


// Division of a scalar by a complex
inline Complex operator/(const double t, Complex &c){
    double temp = 1/(c.a*c.a + c.b*c.b);
    return Complex(t*c.a*temp, -t*c.b*temp);
}


// Division of a complex by a complex
inline Complex operator/(Complex &c, Complex &w){
    double temp = 1/(w.a*w.a + w.b*w.b);
    return Complex((c.a*w.a + c.b*w.b)*temp, (c.b*w.a - c.a*w.b)*temp);
}


inline bool operator==(const Complex &c, const Complex &w){
    return std::abs(c.a - w.a) <= EPSILON && std::abs(c.b - w.b) <= EPSILON;
}



#endif
