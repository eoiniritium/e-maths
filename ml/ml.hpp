#pragma once

#include "vector.hpp"
#include <vector>
#include <functional>

namespace ML {

    class Layer {
        public:
        Linalg::Vector activation;
        Linalg::Vector biases;

        Layer(size_t dimension) : activation(dimension), biases(dimension){}

        size_t dimension() {
            return activation.size();
        }
    };

    class Weights {
        public:
        std::vector<Linalg::Vector> weights;

        Weights(size_t inputDimension, size_t outputDimension) {
            for(size_t i = 0; i < outputDimension; ++i) {
                weights.push_back(Linalg::Vector(inputDimension, 1/static_cast<double>(inputDimension)));
            }
        }
    };

    class NeuralNetwork {
        private:
        std::vector<ML::Layer> layers;
        std::vector<ML::Weights> weights;

        std::function<double(double)> activationFunction;
        std::function<double(double)> activationFunctionDerivative;

        public:
        NeuralNetwork(std::function<double(double)> activationFunction, std::function<double(double)> activationFunctionDerivative) {
            this->activationFunction = activationFunction;
            this->activationFunctionDerivative = activationFunctionDerivative;
        }

        void addInputLayer(size_t dimension) { addLayer(dimension); }

        void addHiddenLayer(size_t dimension) { addLayer(dimension); }

        void addOutputLayer(size_t dimension) { 

            // Make connections between each layer
            for(size_t i = 0; i < layers.size() - 1; ++i) {
                weights.push_back(ML::Weights(layers[i].dimension(), layers[i+1].dimension()));
            }

            weights.push_back(ML::Weights(layers.back().dimension(), dimension));

            // Add output Layer
            addLayer(dimension);
        }

        Linalg::Vector feedForward(Linalg::Vector input) {
            layers[0].activation = input;

            for(size_t idxLayer = 0; idxLayer < layers.size() - 1; ++idxLayer) {

                ML::Layer *currLayer = &(layers[idxLayer]);
                ML::Layer *nextLayer = &(layers[idxLayer + 1]);
                for(size_t idxNode = 0; idxNode < nextLayer->dimension(); ++idxNode) {
                    nextLayer->activation[idxNode] = activationFunction(
                        (currLayer->activation).dot(weights[idxLayer].weights[idxNode]) + nextLayer->biases[idxNode]
                    );
                }
            }

            return layers.back().activation;
        }

        void train(double learningRate) {

        }

        private:
        void addLayer(size_t dimension) {
            layers.push_back(ML::Layer(dimension));
        }

        Linalg::Vector error(Linalg::Vector input, Linalg::Vector expected) {
            Linalg::Vector errorVector = feedForward(input).subtract(expected);

            return errorVector;
        }

        void backPropogation(Linalg::Vector input, Linalg::Vector expected, double learningRate) {
            Linalg::Vector error = feedForward(input).subtract(expected);
            for(size_t idxLayer = layers.size()-1; idxLayer >= 0; --idxLayer) {
                // SKIPPING BIASES FOR NOW

                for(size_t nodeIDX = 0; nodeIDX < layers[idxLayer].dimension(); ++nodeIDX) {
                    double partialNodeError = 
                }
            }
        }
    };
}