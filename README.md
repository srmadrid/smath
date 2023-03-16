# Linear algebra
This small repository holds a .hpp file containing some useful algebra operations using vectors and matrices. 
It is not meant to be taken seriously, as this is a test repository to begin leaning the platform and the workflow. <br/>
To use this repository, simply copy the .hpp file and include it in your file (#include "path/algebra.hpp").

### Functions list:
| Function              | Description                                                            | Input          | Output |
|-----------------------|------------------------------------------------------------------------|----------------|--------|
| vector_print          | Prints the input vector                                                | vector         | void   |
| vector_modulus        | Returns the modulus of the input vector                                | vector         | double |
| vector_scalar         | Returns the result of multiplying the input vector by the input scalar | vector, double | vector |
| vector_dot            | Returns the [dot product](https://en.wikipedia.org/wiki/Dot_product) of the input vectors | vector, vector | double |
| vector_cross          | Returns the [cross product](https://en.wikipedia.org/wiki/Cross_product) of the input vectors | vector, vector | vector |
| vector_projection     | In development                                                         |                |        |
| matrix_print          | Prints the input matrix                                                | matrix         | void   |
| matrix_transpose      | Returns the [transpose](https://en.wikipedia.org/wiki/Transpose) of the input matrix | matrix | matrix |
| matrix_addition       | Returns the result of adding the input matrices                        | matrix, matrix | matrix |
| matrix_subtraction    | Returns the result of subtracting the input matrices                   | matrix, matrix | matrix |
| matrix_multiplication | Returns the result of [multiplying](https://en.wikipedia.org/wiki/Matrix_multiplication) the input matrices | matrix, matrix | matrix |
