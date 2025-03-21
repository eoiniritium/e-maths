#include <iostream>

#include "vector.hpp"

int main() {
    EMaths::Vector<int> vec({1, 2, 3, 4});

    std::cout << vec[0];
    std::cout << (vec.scale(1)).string();

    return 0;
}