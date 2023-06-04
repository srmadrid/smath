#ifndef SMATH_VECTOR4_H
#define SMATH_VECTOR4_H

#include "constants.h"
#include "complex.h"

#include <ostream>
#include <cmath>
#include <type_traits>


//------------------------------------------------------------------------------
// Class functions
//------------------------------------------------------------------------------

namespace smath{namespace linear_algebra{

template<class T>
class Vector4_impl{
public:
    static_assert(std::is_arithmetic<T>::value || smath::linear_algebra::is_complex<T>::value,
                  "Vector3 requires a numeric type or a Complex type.");

    T x, y, z, w;
    Vector4_impl(T x = 0, T y = 0, T z = 0, T w = 0): x(x), y(y), z(z), w(w) {};


    // Addition of this vector plus another
    template<class U>
    Vector4_impl operator+=(const Vector4_impl<U> &other){
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }


    // Subtraction of this vector minus another
    template<class U>
    Vector4_impl operator-=(const Vector4_impl<U> &other){
        x -= other.x;
        y -= other.y;
        z -= other.z;
        w -= other.w;
        return *this;
    }


    // Product of this vector times another
    template<class U>
    Vector4_impl operator*=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        x *= t;
        y *= t;
        z *= t;
        w *= t;
        return *this;
    }


    // Division of this vector by a scalar
    template<class U>
    Vector4_impl operator/=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
        x *= p;
        y *= p;
        z *= p;
        w *= p;
        return *this;
    }


    // Returns the modulus of this vector
    double modulus(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            return std::sqrt(x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b + z.a*z.a + z.b+z.b + w.a*w.a + w.b*w.b);
        }else{
            return std::sqrt(x*x + y*y + z*z + w*w);
        }
    }


    // Returns the squared modulus of this vector
    double modulus_squared(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            return (x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b + z.a*z.a + z.b*z.b + w.a*w.a + w.b*w.b);
        }else{
            return (x*x + y*y + z*z + w*w);
        }
    }


    // Normalizes this vector
    void normalize(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            double modulus = 1/std::sqrt(x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b + z.a*z.a + z.b*z.b + w.a*w.a + w.b*w.b);
            x *= modulus;
            y *= modulus;
            z *= modulus;
            w *= modulus;
        }else{
            double modulus = 1/std::sqrt(x*x + y*y + z*z + w*w);
            x *= modulus;
            y *= modulus;
            z *= modulus;
            w *= modulus;
        }
    }
};


// out
template<class T>
inline std::ostream &operator<<(std::ostream &os, const Vector4_impl<T> &v){
    return os << "<" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ">";
}


// Addittion of two vectors
template<class T, class U>
inline Vector4_impl<decltype(T{}+U{})> operator+(const Vector4_impl<T> &v, const Vector4_impl<U> &u){
    return Vector4_impl<decltype(T{}+U{})>(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w);
}


// Subtraction of two vectors
template<class T, class U>
inline Vector4_impl<decltype(T{}+U{})> operator-(const Vector4_impl<T> &v, const Vector4_impl<U> &u){
    return Vector4_impl<decltype(T{}+U{})>(v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w);
}


// Product of a vector times a scalar
template<class T, class U>
inline Vector4_impl<decltype(T{}+U{})> operator*(const Vector4_impl<T> &v, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Vector4_impl<decltype(T{}+U{})>(v.x*t, v.y*t, v.z*t, v.w*t);
}


// Product of a vector times a scalar
template<class T, class U>
inline Vector4_impl<T> operator*(const U t, const Vector4_impl<T> &v){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Vector4_impl<T>(v.x*t, v.y*t, v.z*t, v.w*t);
}


// Division of a vector by a scalar
template<class T, class U>
inline Vector4_impl<T> operator/(const Vector4_impl<T> &v, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
    return Vector4_impl<T>(v.x*p, v.y*p, v.z*p, v.w*p);
}


template<class T, class U>
inline bool operator==(const Vector4_impl<T> &v, const Vector4_impl<U> &u){
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
template<class T, class U>
inline decltype(T{}+U{}) dot(const Vector4_impl<T> &v, const Vector4_impl<U> &u){
    if constexpr(smath::linear_algebra::is_complex<U>::value){
        return (v.x*smath::linear_algebra::complex::conjugate(u.x) + 
                v.y*smath::linear_algebra::complex::conjugate(u.y) +
                v.z*smath::linear_algebra::complex::conjugate(u.z) +
                v.w*smath::linear_algebra::complex::conjugate(u.w));
    }else{
        return (v.x*u.x + v.y*u.y + v.z*u.z + v.w*u.w);
    }
}
}


using Vector4 = Vector4_impl<double>;
using Vector4i = Vector4_impl<int>;
using Vector4f = Vector4_impl<float>;
using Vector4c = Vector4_impl<smath::linear_algebra::Complex>;

}}

#endif
