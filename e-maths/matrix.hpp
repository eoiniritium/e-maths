#pragma once
#include "vector.hpp"
#include <vector>

namespace EMaths {
    template <typename T>
    class Matrix {
        private:
        std::vector<Emaths::Vector<T>> matx;

        public:
        Matrix(size_t n, size_t m) {
            for(size_t i = 0; i < m; ++i) {
                this->matx.push_back(Emaths::Vector<T>(n));
            }
        }

        Matrix(std::vector<std::vector<T>> matrix) {
            size_t n = matrix.size();
            size_t m = matrix[0].size();

            for(size_t j = 0; j < m; ++j) {
                Emaths::Vector<T> column(n);

                for(size_t i = 0; i < n; ++i) {
                    column[i] = matrix[i][j];
                }

                this->matx.push_back(column);
            }
        }

        Matrix(std::vector<EMaths::Vector<T>> matrix) {
            this->matx = matrix;
        }

        template <typename S>
        static mult(S scalar, EMaths::Matrix<S> matrix) {

        }
    };
}