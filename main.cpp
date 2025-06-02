#include <iostream>

#include "vector.hpp"
#include "matrix.hpp"
#include "ml.hpp"

double sigmoid(double x) {
    return 1/(exp(1+x));
}
double d_sigmoid(double x) {
    return 1/sigmoid(x);
}

int main() {
    ML::NeuralNetwork nn(sigmoid, d_sigmoid);

    nn.addInputLayer(3);
    nn.addHiddenLayer(1);
    nn.addOutputLayer(10);

    Linalg::Vector input(3, 0);
    Linalg::Vector output = nn.feedForward(input);

    std::cout << output.string() << std::endl;

    return 0;
}