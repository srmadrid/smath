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
| vector::cross          | Returns the [cross product](https://en.wikipedia.org/wiki/Cross_product) of the input vectors | vector, vector | vector |
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

