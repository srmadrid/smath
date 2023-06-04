#ifndef SMATH_COMPLEX_H
#define SMATH_COMPLEX_H

#include "constants.h"

#include <cmath>
#include <ostream>
#include <type_traits>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

namespace smath{namespace linear_algebra{

template<class T>
class Complex_impl{
public:
    static_assert(std::is_arithmetic<T>::value, "Complex can only be used with numeric types");

    T a, b;
    Complex_impl(T a = 0, T b = 0):
        a(a), b(b) {};


    // Implicit type conversion
    operator double() const {return a;};


    // Addittion of this complex plus another one 
    template<class U>
    Complex_impl operator+=(const Complex_impl<U> &other){
        a += other.a;
        b += other.b;
        return *this;
    }


    // Addittion of this complex plus a scalar
    Complex_impl operator+=(const double t){
        a += t;
        return *this;
    }


    // Subtraction of this complex minus another one
    template<class U>
    Complex_impl operator-=(const Complex_impl<U> &other){
        a -= other.a;
        b -= other.b;
        return *this;
    }
    

    // Subtraction of this complex minus a scalar
    Complex_impl operator-=(const double t){
        a -= t;
        return *this;
    }


    // Multiplication of this complex times a scalar
    Complex_impl operator*=(const double t){
        a *= t;
        b *= t;
        return *this;
    }


    // Multiplication of this complex times another complex
    template<class U>
    Complex_impl operator*=(const Complex_impl<U> &other){
        T tempa = a*other.a - b*other.b;
        T tempb = a*other.b + b*other.a;
        a = tempa;
        b = tempb;
        return *this;
    }


    // Division of this complex by a scalar
    Complex_impl operator/=(const double t){
        double p {1/t};
        a *= p;
        b *= p;
        return *this;
    }


    // Division of this complex by another complex
    template<class U>
    Complex_impl operator/=(const Complex_impl<U> &other){
        double temp = 1/(other.a*other.a + other.b*other.b);
        T tempa = (a*other.a + b*other.b)*temp;
        T tempb = (b*other.a - a*other.b)*temp;
        a = tempa;
        b = tempb;
        return *this;
    }


    // Returns the modulus of this complex
    double modulus(){
        return std::sqrt(a*a + b*b);
    }


    // Returns the squared modulus of this complex
    double modulus_squared(){
        return a*a + b*b;
    }


    // Conjugates this complex
    void conjugate(){
        b = -b;
    }

};


// out
template<class T>
inline std::ostream &operator<<(std::ostream &os, const Complex_impl<T> &c){
    if(c.a == 0){
        if(c.b == 1){
            return os << "i";
        }else if(c.b == -1){
            return os << "-i";
        }
        return os << c.b << "i";
    }else if(c.b == 0){
        return os << c.a;
    }else if(c.b == 1){
        return os << c.a << " + " << "i";
    }else if(c.b == -1){
        return os << c.a << " - " << "i";
    }else if(c.b > 0){
        return os << c.a << " + " << c.b << "i";
    }else{
        return os << c.a << " - " << std::abs(c.b) << "i";
    }
}


// Addition of two complexes
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator+(const Complex_impl<T> &c, const Complex_impl<U> &w){
    return Complex_impl<decltype(T{}+U{})>(c.a + w.a, c.b + w.b);
}


// Addition of a complex and a scalar
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator+(const Complex_impl<T> &c, const U t){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    return Complex_impl<decltype(T{}+U{})>(c.a + t, c.b);
}


// Addition of a complex and a scalar
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator+(const U t, const Complex_impl<T> &c){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    return Complex_impl<decltype(T{}+U{})>(t + c.a, c.b);
}


// Subtraction of a complex minus a complex
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator-(const Complex_impl<T> &c, const Complex_impl<U> &w){
    return Complex_impl<decltype(T{}+U{})>(c.a - w.a, c.b - w.b);
}


// Subtraction of a complex minus a scalar
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator-(const Complex_impl<T> &c, const U t){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    return Complex_impl<decltype(T{}+U{})>(c.a - t, c.b);
}


// Subtraction of a scalar minus a complex
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator-(const U t, const Complex_impl<T> &c){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    return Complex_impl<decltype(T{}+U{})>(t - c.a, -c.b);
}


// Multiplication of a complex times a scalar
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator*(const Complex_impl<T> &c, U t){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    return Complex_impl<decltype(T{}+U{})>(c.a*t, c.b*t);
}


// Multiplication of a scalar times a complex
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator*(const U t, const Complex_impl<T> &c){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    return Complex_impl<decltype(T{}+U{})>(t*c.a, t*c.b);
}


// Multiplication of a complex times a complex
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator*(const Complex_impl<T> &c, const Complex_impl<U> &w){
    return Complex_impl<decltype(T{}+U{})>(c.a*w.a - c.b*w.b, c.a*w.b + c.b*w.a);
}


// Division of a complex by a scalar
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator/(const Complex_impl<T> &c, const U t){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    double q {static_cast<double>(t)};
    double p {1/q};
    return Complex_impl<decltype(T{}+U{})>(c.a*p, c.b*p);
}


// Division of a scalar by a complex
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator/(const U t, const Complex_impl<T> &c){
    static_assert(std::is_arithmetic<U>::value, "The second argument must be a numeric type.");
    double temp = 1/(c.a*c.a + c.b*c.b);
    return Complex_impl<decltype(T{}+U{})>(t*c.a*temp, -t*c.b*temp);
}


// Division of a complex by a complex
template<class T, class U>
inline Complex_impl<decltype(T{}+U{})> operator/(const Complex_impl<T> &c, const Complex_impl<U> &w){
    double temp = 1/(w.a*w.a + w.b*w.b);
    return Complex_impl<decltype(T{}+U{})>((c.a*w.a + c.b*w.b)*temp, (c.b*w.a - c.a*w.b)*temp);
}


// Equality of two complex numbers
template<class T, class U>
inline bool operator==(const Complex_impl<T> &c, const Complex_impl<U> &w){
    return std::abs(c.a - w.a) <= EPSILON && std::abs(c.b - w.b) <= EPSILON;
}


// Equality of a complex number and a scalar
template<class T>
inline bool operator==(const Complex_impl<T> &c, const double t){
    return std::abs(c.a - t) <= EPSILON && std::abs(c.b) <= EPSILON;
}


// Equality of a complex number and a scalar
template<class T>
inline bool operator==(const double t, const Complex_impl<T> &c){
    return std::abs(c.a - t) <= EPSILON && std::abs(c.b) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace complex{
// Returns the modulus of a complex
template<class T>
inline double modulus(const Complex_impl<T> &c){
    return std::sqrt(c.a*c.a + c.b*c.b);
}


// Returns the squared modulus of a complex
template<class T>
inline double modulus_squared(const Complex_impl<T> &c){
    return (c.a*c.a + c.b*c.b);
}


// Return the conjugate of a complex
template<class T>
inline Complex_impl<T> conjugate(const Complex_impl<T> &c){
    return Complex_impl<T>(c.a, -c.b);
}
}


template<class T>
struct is_complex : std::false_type {};

template<class T>
struct is_complex<Complex_impl<T>> : std::true_type {};


using Complex = Complex_impl<double>;
using Complexi = Complex_impl<int>;
using Complexf = Complex_impl<float>;

}}

#endif
