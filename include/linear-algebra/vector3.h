#ifndef SMATH_VECTOR3_H
#define SMATH_VECTOR3_H

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
class Vector3_impl{
public:
    static_assert(std::is_arithmetic<T>::value || smath::linear_algebra::is_complex<T>::value,
                  "Vector3 requires a numeric type or a Complex type.");

    T x, y, z;
    Vector3_impl(T x = 0, T y = 0, T z = 0): x(x), y(y), z(z) {};

    
    // Addition of this vector plus another
    template<class U>
    Vector3_impl operator+=(const Vector3_impl<U> &other){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }


    // Subtraction of this vector minus another
    template<class U>
    Vector3_impl operator-=(const Vector3_impl<U> &other){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }


    // Product of this vector times a scalar
    template<class U>
    Vector3_impl operator*=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }


    // Division of this vector by a scalar
    template<class U>
    Vector3_impl operator/=(const U t){
        static_assert(std::is_arithmetic<U>::value || (smath::linear_algebra::is_complex<U>::value && smath::linear_algebra::is_complex<T>::value), "The second argument must be a numeric or complex type. It can only be complex if the vector is already complex");
        decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
        x *= p;
        y *= p;
        z *= p;
        return *this;
    }


    // Returns the modulus of this vector
    double modulus(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            return std::sqrt(x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b + z.a*z.a + z.b+z.b);
        }else{
            return std::sqrt(x*x + y*y + z*z);
        }
    }


    // Returns the squared modulus of this vector
    double modulus_squared(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            return (x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b + z.a*z.a + z.b*z.b);
        }else{
            return (x*x + y*y + z*z);
        }
    }


    // Normalizes this vector
    void normalize(){
        if constexpr(smath::linear_algebra::is_complex<T>::value){
            double modulus = 1/std::sqrt(x.a*x.a + x.b*x.b + y.a*y.a + y.b*y.b + z.a*z.a + z.b*z.b);
            x *= modulus;
            y *= modulus;
            z *= modulus;
        }else{
            double modulus = 1/std::sqrt(x*x + y*y + z*z);
            x *= modulus;
            y *= modulus;
            z *= modulus;
        }
    }
};


// out
template<class T>
inline std::ostream &operator<<(std::ostream &os, const Vector3_impl<T> &v){
    return os << "<" << v.x << ", " << v.y << ", " << v.z << ">";
}


// Addittion of two vectors
template<class T, class U>
inline Vector3_impl<decltype(T{}+U{})> operator+(const Vector3_impl<T> &v, const Vector3_impl<U> &u){
    return Vector3_impl<decltype(T{}+U{})>(v.x + u.x, v.y + u.y, v.z + u.z);
}


// Subtraction of two vectors
template<class T, class U>
inline Vector3_impl<decltype(T{}+U{})> operator-(const Vector3_impl<T> &v, const Vector3_impl<U> &u){
    return Vector3_impl<decltype(T{}+U{})>(v.x - u.x, v.y - u.y, v.z - u.z);
}


// Product of a vector times a scalar
template<class T, class U>
inline Vector3_impl<decltype(T{}+U{})> operator*(const Vector3_impl<T> &v, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Vector3_impl<decltype(T{}+U{})>(v.x*t, v.y*t, v.z*t);
}


// Product of a vector times a scalar
template<class T, class U>
inline Vector3_impl<decltype(T{}+U{})> operator*(const U t, const Vector3_impl<T> &v){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    return Vector3_impl<decltype(T{}+U{})>(v.x*t, v.y*t, v.z*t);
}


// Division of a vector by a scalar
template<class T, class U>
inline Vector3_impl<decltype(T{}+U{})> operator/(const Vector3_impl<T> &v, const U t){
    static_assert(std::is_arithmetic<U>::value || smath::linear_algebra::is_complex<U>::value, "The second argument must be a numeric or complex type.");
    decltype(T{}+U{}+double{}) p {1/static_cast<decltype(T{}+U{}+double{})>(t)};
    return Vector3_impl<decltype(T{}+U{})>(v.x*p, v.y*p, v.z*p);
}


template<class T, class U>
inline bool operator==(const Vector3_impl<T> &v, const Vector3_impl<U> &u){
    return std::abs(v.x - u.x) <= EPSILON &&
           std::abs(v.y - u.y) <= EPSILON &&
           std::abs(v.z - u.z) <= EPSILON;
}


//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------

namespace vector3{

// Returns the dot product of the input vectors
template<class T, class U>
inline decltype(T{}+U{}) dot(const Vector3_impl<T> &v, const Vector3_impl<U> &u){
    if constexpr(smath::linear_algebra::is_complex<U>::value){
        return (v.x*smath::linear_algebra::complex::conjugate(u.x) + 
                v.y*smath::linear_algebra::complex::conjugate(u.y) +
                v.z*smath::linear_algebra::complex::conjugate(u.z));
    }else{
        return (v.x*u.x + v.y*u.y + v.z*u.z);
    }
}


// Returns the cross product of the input vectors
template<class T, class U>
inline Vector3_impl<decltype(T{}+U{})> cross(const Vector3_impl<T> &v, const Vector3_impl<U> &u){
    return Vector3_impl<decltype(T{}+U{})>(v.y*u.z - v.z*u.y, v.z*u.x - v.x*u.z, v.x*u.y - v.y*u.x);
}
}


using Vector3 = Vector3_impl<double>;
using Vector3i = Vector3_impl<int>;
using Vector3f = Vector3_impl<float>;
using Vector3c = Vector3_impl<smath::linear_algebra::Complex>;

}}

#endif
