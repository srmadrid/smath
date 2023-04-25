# SMath
This is a library of header files containing various mathematical equations. The name is short for Sergio Math.
It is my first repository, and its intention is for me to get used to the git and github workflow.

## Functions list:
### Algebra
#### Vector2: class of vectors of 2 dimensions. Optimized.
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| this->print          | Prints the vector                                                | this         | void   |
| this->modulus        | Returns the modulus of the vector                                | this           | double |
| Vector2::dot            | Returns the [dot product](https://en.wikipedia.org/wiki/Dot_product) of the input vectors | vector, vector | double |
| Vector2::projection     | In development             |                |        |

#### Vector3: class of vectors of 3 dimensions. Optimized.
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| this->print          | Prints the vector                                                | this           | void   |
| this->modulus        | Returns the modulus of the vector                                | this | double |
| Vector3::dot            | Returns the [dot product](https://en.wikipedia.org/wiki/Dot_product) of the input vectors | Vector3, Vector3 | double |
| Vector3::cross          | Returns the [cross product](https://en.wikipedia.org/wiki/Cross_product) of the input vectors | Vector3, Vector3 | Vector3 |
| Vector3::projection     | In development             |                |        |

#### Matrix2: class of 2x2 matrices. Optimized.
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| this->determinant    | Returns the determinant of the marix                             | this           | double |
| this->transpose      | Transposes the matrix                                            | this | void   |
| this->inverse        | Inverts the matrix                                               | this | void   |
| Matrix2::identity       | Returns the identity                                          | void | Matrix2 |
| Matrix2::determinant    | Returns the determinant of the input matrix | Matrix2 | Double |
| Matrix2::transpose      | Returns the transpose of the input matrix | Matrix2 | Matrix2 |
| Matrix2::inverse       | Returns the inverse of the input matrix | Matrix2 | Matrix2 |

#### Matrix3: class of 3x3 matrices. Optimized.
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| this->determinant    | Returns the determinant of the marix                             | this           | double |
| this->transpose      | Transposes the matrix                                            | this | void   |
| this->inverse        | Inverts the matrix                                               | this | void   |
| Matrix3::identity       | Returns the identity                                          | void | Matrix3 |
| Matrix3::determinant    | Returns the determinant of the input matrix | Matrix3 | Double |
| Matrix3::transpose      | Returns the transpose of the input matrix | Matrix3 | Matrix3 |
| Matrix3::inverse       | Returns the inverse of the input matrix | Matrix3 | Matrix3 |

#### Matrix4: class of 4x4 matrices. Optimized.
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| this->determinant    | Returns the determinant of the marix                             | this           | double |
| this->transpose      | Transposes the matrix                                            | this | void   |
| this->inverse        | Inverts the matrix                                               | this | void   |
| Matrix4::identity       | Returns the identity                                          | void | Matrix4 |
| Matrix4::determinant    | Returns the determinant of the input matrix | Matrix4 | Double |
| Matrix4::transpose      | Returns the transpose of the input matrix | Matrix4 | Matrix4 |
| Matrix4::inverse       | Returns the inverse of the input matrix | Matrix4 | Matrix4 |


## How to compile:
The library comes with precompiled binaries, located in the lib/ folder. There you will find a binary for the entire library (smath.a), and one for each submodule (linear-algebra.a, ...).

### Compile from scratch
If you want to compile the library yourself, follow these steps:
1. Create a build/ directory: ```mkdir build```
2. Navigate to the build/ directory: ```cd build```
3. Run CMake to generate build files: ```cmake ..```
4. Finally, build the project using make: ```make```
