# SMath

SMath (short for Sergio Math) is a comprehensive, optimized mathematical library with a variety of classes and equations. Its primary purpose is to simplify and optimize mathematical operations like working with complex numbers, vectors, and matrices.

## Template Types

All classes in this library are templatized to allow for flexibility with number types. For example, `Complex_impl<T>` can be used with any numerical type `T`, and default typedefs are provided for `double` (`Complex`), `int` (`Complexi`) and `float`(`Complexf`). This pattern is consistent across all classes in the library.

## Features:

Note: `T` in the output means the most significant type.

### Linear Algebra

#### Complex Class

Complex class handles complex numbers with real and imaginary parts. It is implemented as `Complex_impl<T>`, where T can be any numerical type. Default types provided are `Complex` (double), `Complexi` (int) and `Complexf` (float).

| Function | Description | Input | Output |
|---------|-------------|-------|--------|
| this->modulus | Returns the modulus of the complex number. | this | double |
| this->modulus_squared | Returns the squared modulus of the complex number. | this | double |
| this->conjugate | Conjugates the complex number. | this | void |
| complex::modulus | Returns the modulus of a complex number. | Complex | double |
| complex::modulus_squared | Returns the squared modulus of a complex number. | Complex | double |
| complex::conjugate | Returns the conjugate of a complex number. | Complex | Complex |

##### Initialization

`Complex_impl` numbers are initialized by inputting the real part first and then the imaginary part.

```cpp
Complex_impl<double> c(1.0, 2.0); // Complex number with real part 1.0 and imaginary part 2.0
```

#### Vector Classes

Each vector class deals with vectors in its respective dimensional space. They are implemented as `VectorN_impl<T>`, where N is the dimension, and T can be any numerical type or any `Complex_impl<T>`. Default types provided are `VectorN` (double), `VectorNi` (int), `VectorNf`(float) and `VectorNc` (Complex).

#### Vector2 Class

| Function | Description | Input | Output |
|---------|-------------|-------|--------|
| this->modulus | Returns the modulus of the vector. | this | double |
| this->modulus_squared | Returns the squared modulus of the vector. | this | double |
| this->normalize | Normalizes the vector. | this | void |
| vector2::dot | Returns the dot product of two vectors. | Vector2, Vector2 | T |
| vector2::normalize | Returns a normalized vector. | Vector2 | Vector2 |
| vector2::projection | [Under Development] | TBD | TBD |

#### Vector3 Class

| Function | Description | Input | Output |
|---------|-------------|-------|--------|
| this->modulus | Returns the modulus of the vector. | this | double |
| this->modulus_squared | Returns the squared modulus of the vector. | this | double |
| this->normalize | Normalizes the vector. | this | void |
| vector3::dot | Returns the dot product of two vectors. | Vector3, Vector3 | T |
| vector3::cross | Returns the cross product of two vectors. | Vector3, Vector3 | Vector3 |
| vector3::normalize | Returns a normalized vector. [Under development] | Vector3 | Vector3 |
| vector3::projection | [Under Development] | TBD | TBD |

#### Vector4 Class

| Function | Description | Input | Output |
|---------|-------------|-------|--------|
| this->modulus | Returns the modulus of the vector. | this | double |
| this->modulus_squared | Returns the squared modulus of the vector. | this | double |
| this->normalize | Normalizes the vector. | this | void |
| vector4::dot | Returns the dot product of two vectors. | Vector4, Vector4 | T |
| vector4::normalize | Returns a normalized vector. [Under development] | Vector4 | Vector4 |
| vector4::projection | [Under Development] | TBD | TBD |

##### Initialization

Vectors are initialized by passing in their member values.

```cpp
Vector2_impl<double> v2(1.0, 2.0); // 2D Vector with x=1.0, y=2.0
Vector3_impl<double> v3(1.0, 2.0, 3.0); // 3D Vector with x=1.0, y=2.0, z=3.0
Vector4_impl<double> v4(1.0, 2.0, 3.0, 4.0); // 4D Vector with x=1.0, y=2.0, z=3.0, w=4.0
Vector2_impl<double> v2(Complex(1.0, 2.0), Complex(3.0, 4.0); // 2D Vector with x=1+2i, y=3+4i
```

#### Matrix Classes

Each matrix class deals with matrices in its respective dimensional space. They are implemented as `MatrixN_impl<T>`, where N is the dimensionality of the square matrix, and T can be any numerical type or any `Complex_impl<T>`. Default types provided are `MatrixN` (double) and `MatrixNi` (int).

#### Matrix2 Class

| Function | Description | Input | Output |
|---------|-------------|-------|--------|
| this->determinant | Returns the determinant of the matrix. | this | T |
| this->transpose | Transposes the matrix. | this | void |
| this->inverse | Inverts the matrix. | this | void |
| Matrix2::identity | Returns the identity matrix. | void | Matrix2 |
| Matrix2::determinant | Returns the determinant of a matrix. | Matrix2 | T |
| Matrix2::transpose | Returns the transpose of a matrix. | Matrix2 | Matrix2 |
| Matrix2::inverse | Returns the inverse of a matrix. | Matrix2 | Matrix2 |

#### Matrix3 Class

| Function | Description | Input | Output |
|---------|-------------|-------|--------|
| this->determinant | Returns the determinant of the matrix. | this | T |
| this->transpose | Transposes the matrix. | this | void |
| this->inverse | Inverts the matrix. | this | void |
| Matrix3::identity | Returns the identity matrix. | void | Matrix3 |
| Matrix3::determinant | Returns the determinant of a matrix. | Matrix3 | T |
| Matrix3::transpose | Returns the transpose of a matrix. | Matrix3 | Matrix3 |
| Matrix3::inverse | Returns the inverse of a matrix. | Matrix3 | Matrix3 |

#### Matrix4 Class

| Function | Description | Input | Output |
|---------|-------------|-------|--------|
| this->determinant | Returns the determinant of the matrix. | this | T |
| this->transpose | Transposes the matrix. | this | void |
| this->inverse | Inverts the matrix. | this | void |
| Matrix4::identity | Returns the identity matrix. | void | Matrix4 |
| Matrix4::determinant | Returns the determinant of a matrix. | Matrix4 | T |
| Matrix4::transpose | Returns the transpose of a matrix. | Matrix4 | Matrix4 |
| Matrix4::inverse | Returns the inverse of a matrix. | Matrix4 | Matrix4 |

Matrices are initialized by passing in their members row by row. You can pass all the members directly, or use vectors to form the columns.

```cpp
// Direct initialization
Matrix2 m2(1, 2, 3, 4); // 2x2 Matrix with first row = 1.0, 2.0 and second row = 3.0, 4.0
Matrix3 m3(1, 2, 3, 4, 5, 6, 7, 8, 9); // 3x3 Matrix
Matrix4 m4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16); // 4x4 

// Initialization with vectors forming columns
Vector2_impl<double> v2_1(1.0, 3.0);
Vector2_impl<double> v2_2(2.0, 4.0);
Matrix2_impl<double> m2_v(v2_1, v2_2); // Equivalent to m2

Vector3_impl<double> v3_1(1.0, 4.0, 7.0);
Vector3_impl<double> v3_2(2.0, 5.0, 8.0);
Vector3_impl<double> v3_3(3.0, 6.0, 9.0);
Matrix3_impl<double> m3_v(v3_1, v3_2, v3_3); // Equivalent to m3

Vector4_impl<double> v4_1(1.0, 5.0, 9.0, 13.0);
Vector4_impl<double> v4_2(2.0, 6.0, 10.0, 14.0);
Vector4_impl<double> v4_3(3.0, 7.0, 11.0, 15.0);
Vector4_impl<double> v4_4(4.0, 8.0, 12.0, 16.0);
Matrix4_impl<double> m4_v(v4_1, v4_2, v4_3, v4_4); // Equivalent to m4
```

## Interoperability and Type Promotion

In SMath, all classes are interoperable, regardless of the type `T` with which they are initialized. This allows you to perform operations between different types of objects and the library will automatically manage the type conversions.

One of the key features of this library is Type Promotion, which ensures that the resulting object from any operation will always be of the most significant type involved in the operation.

For example, if you multiply a `Matrix4_impl<Complex_impl<int>>` with a `double`, the type of the Complex elements in the matrix will be automatically promoted to `Complex_impl<double>`.

```cpp
Matrix4_impl<Complex_impl<int>> m; 
double d = 2.0;
auto result = m * d;  // result is Matrix4_impl<Complex_impl<double>>
```

Similarly, if you multiply a `Matrix4_impl<Complex>` with a `Vector4_impl<double>`, the result will be a `Vector4_impl<Complex>`.

```cpp
Matrix4_impl<Complex> m; 
Vector4_impl<double> v;
auto result = m * v;  // result is Vector4_impl<Complex>
```

And if you divide a `Vector2_impl<int>` by a double, the result will be a `Vector2_impl<double>`. If you divide it by a Complex, the result will be a `Vector2_impl<Complex>`.

```cpp
Vector2_impl<int> v; 
double d = 2.0; 
auto result = v / d;  // result is Vector2_impl<double>

Complex c;
auto result_complex = v / c;  // result is Vector2_impl<Complex>
```

Note: When operating on matrices or vectors using assignment operators (+=, -=, ...), the values will always be cast to the initial type of the data structure. E.g. if we have `A<int> += B<Complex>`, the result will be a `Matrix<int>` assigned to A.

These work the same with the preset typedefs explained above. The examples are verbose on purpose.

## Examples

```cpp
// For complex numbers
Complex c(1.0, 2.0); // Complex number with real part 1.0 and imaginary part 2.0
T mod = c.modulus(); // calculate modulus

// For vectors
Vector2 v(3.0, 4.0); // Vector2 with x=3.0 and y=4.0
v.normalize();  // normalize the vector in place

// For matrices
Matrix2 m(1, 2, 3, 4); // Matrix2 with rows 1, 2 and 3, 4
m.transpose();  // transpose the matrix in place
```
