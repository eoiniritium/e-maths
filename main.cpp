#include <iostream>

#include "vector.hpp"
#include "matrix.hpp"

int main() {
    Linalg::Matrix matrix(2, 2);

    // Row 1
    matrix[0][0] = 1;
    matrix[0][1] = 2;

    // Row 2
    matrix[1][0] = 3;
    matrix[1][1] = 4;

    auto id = Linalg::Matrix::identity(2).scale(1);

    std::cout << id.string() << std::endl;
    std::cout << id.add(matrix).string() << std::endl;

    return 0;
}