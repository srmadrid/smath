# SMath
This is a library of header files containing various mathematical equations. The name is short for Sergio Math.
It is my first repository, and its intention is for me to get used to the git and github workflow.

## Functions list:
### Algebra
#### Vector: generalized for vectors of any dimensions
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| vector::print          | Prints the input vector                                                | vector         | void   |
| vector::addition       | Returns the result of adding the input vectors                         | vector, vector | vector |
| vector::subtraction    | Returns the result of subtracting the input vectors                    | vector, vector | vector |
| vector::modulus        | Returns the modulus of the input vector                                | vector         | double |
| vector::scalar         | Returns the result of multiplying the input vector by the input scalar | vector, double | vector |
| vector::dot            | Returns the [dot product](https://en.wikipedia.org/wiki/Dot_product) of the input vectors | vector, vector | double |
| vector::projection     | In development             |                |        |

#### Matrix: generalized for matrices of any dimensions
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| matrix::print          | Prints the input matrix                                                | matrix         | void   |
| matrix::identity       | Returns the identity matrix of the specified dimensions (n x m)        | int, int       | matrix |
| matrix::transpose      | Returns the [transpose](https://en.wikipedia.org/wiki/Transpose) of the input matrix | matrix | matrix |
| matrix::addition       | Returns the result of adding the input matrices                        | matrix, matrix | matrix |
| matrix::subtraction    | Returns the result of subtracting the input matrices                   | matrix, matrix | matrix |
| matrix::scalar         | Returns the result of multiplying the input matrix by the input scalar | matrix, double | matrix |
| matrix::multiplication | Returns the result of [multiplying](https://en.wikipedia.org/wiki/Matrix_multiplication) the input matrices | matrix, matrix | matrix |
| matrix::power          | Returns the result of calculating the xth power of the input matrix; if x is 0, returns the identity matrix with the size of the input matrix | matrix, int    | matrix |

#### Vector2: class of vectors of 2 dimensions. Optimized
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| this->print          | Prints the vector                                                | this         | void   |
| this->modulus        | Returns the modulus of the vector                                | this           | double |
| Vector2::dot            | Returns the [dot product](https://en.wikipedia.org/wiki/Dot_product) of the input vectors | vector, vector | double |
| Vector2::projection     | In development             |                |        |

#### Vector3: class of vectors of 3 dimensions. Optimized
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
