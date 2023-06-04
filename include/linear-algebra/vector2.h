#ifndef SMATH_VECTOR2_H
#define SMATH_VECTOR2_H

#include "constants.h"
#include "complex.h"

#include <ostream>
#include <cmath>
#include <type_traits>


//------------------------------------------------------------------------------
// functions
//------------------------------------------------------------------------------

namespace smath{namespace linear_algebra{

template<class T>
class Vector2_impl{
public:
    static_assert(std::is_arithmetic<T>::value || smath::linear_algebra::is_complex<T>::value,
                  "Vector2 requires a numeric type or a Complex type.");

    T x, y;
    Vector2_impl(T x = 0, T y = 0): x(x), y(y) {};


    // Addittion of this vector plus another 
    template<class U>
    Vector2_impl operator+=(const Vector2_impl<U> &other){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        x += other.x;
        y += other.y;
        return *this;
    }


    // Subtraction of this vector minus another
    template<class U>
    Vector2_impl operator-=(const Vector2_impl<U> &other){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        x -= other.x;
        y -= other.y;
        return *this;
    }


    // Product of this vector times a scalar
    template<class U>
    Vector2_impl operator*=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        x *= t;
        y *= t;
        return *this;
    }


    // Division of this vector by a scalar
    template<class U>
    Vector2_impl operator/=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
        x *= p;
        y *= p;
        return *this;
    }


    // Returns the modulus of this vector
    double modulus(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            return std::sqrt(x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b);
        }else{
            return std::sqrt(x*x + y*y);
        }
    }


    // Returns the squared modulus of this vector
    double modulus_squared(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            return (x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b);
        }else{
            return (x*x + y*y);
        }
    }

    // Normalizes this vector
    void normalize(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            double modulus = 1/std::sqrt(x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b);
            x *= modulus;
            y *= modulus;
        }else{
            double modulus = 1/std::sqrt(x*x + y*y);
            x *= modulus;
            y *= modulus;
        }
    }
};


// out
template<class T>
inline std::ostream &operator<<(std::ostream &os, const Vector2_impl<T> &v){
    return os << "<" << v.x << ", " << v.y << ">";
}

// Addition of two vectors
template<class T, class U>
inline Vector2_impl<decltype(T{}+U{})> operator+(const Vector2_impl<T> &v, const Vector2_impl<U> &u){
    return Vector2_impl<decltype(T{}+U{})>(v.x + u.x, v.y + u.y);
}


// Subtraction of two vectors
template<class T, class U>
inline Vector2_impl<decltype(T{}+U{})> operator-(const Vector2_impl<T> &v, const Vector2_impl<U> &u){
    return Vector2_impl<decltype(T{}+U{})>(v.x - u.x, v.y - u.y);
}


// Product of a vector times a scalar
template<class T, class U>
inline Vector2_impl<decltype(T{}+U{})> operator*(const Vector2_impl<T> &v, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Vector2_impl<decltype(T{}+U{})>(v.x*t, v.y*t);
}


// Product of a vector times a scalar
template<class T, class U>
inline Vector2_impl<decltype(T{}+U{})> operator*(const U t, const Vector2_impl<T> &v){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Vector2_impl<decltype(T{}+U{})>(v.x*t, v.y*t);
}


// Division of a vector by a scalar
template<class T, class U>
inline Vector2_impl<decltype(T{}+U{})> operator/(const Vector2_impl<T> &v, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
    return Vector2_impl<decltype(T{}+U{})>(v.x*p, v.y*p);
}


template<class T, class U>
inline bool operator==(const Vector2_impl<T> &v, const Vector2_impl<U> &u){
    return std::abs(v.x - u.x) <= EPSILON &&
           std::abs(v.y - u.y) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace vector2{
// Returns the dot product of two vectors
template<class T, class U>
inline decltype(T{}+U{}) dot(const Vector2_impl<T> &v, const Vector2_impl<U> &u){
    if constexpr(smath::linear_algebra::is_complex<U>::value){
        return (v.x*smath::linear_algebra::complex::conjugate(u.x) + 
                v.y*smath::linear_algebra::complex::conjugate(u.y));
    }else{
        return (v.x*u.x + v.y*u.y);
    }
}


template<class T>
Vector2_impl<T> normalize(Vector2_impl<T> &v){
    if constexpr(smath::linear_algebra::is_complex<T>::value){
        double modulus = 1/std::sqrt(v.x.a*v.x.a + v.x.b*v.x.b + v.y.a*v.y.a + v.y.b*v.y.b);
        return Vector2_impl<T>(v.x*modulus, v.y*modulus);
    }else{
        double modulus = 1/std::sqrt(v.x*v.x + v.y*v.y);
        return Vector2_impl<T>(v.x*modulus, v.y*modulus);
    }
}
}


using Vector2 = Vector2_impl<double>;
using Vector2i = Vector2_impl<int>;
using Vector2f = Vector2_impl<float>;
using Vector2c = Vector2_impl<smath::linear_algebra::Complex>;

}}

#endif
