#pragma once
#include "vector.hpp"
#include <vector>
#include <string>
#include <stdexcept>

namespace Linalg {
    template<typename T>
    struct Pair {
        T first, second;
    };

    class Matrix {
        private:
        std::vector<Linalg::Vector> matrix;

        public:
        Matrix(size_t n, size_t m) {
            matrix = std::vector<Linalg::Vector>(
                n, Linalg::Vector(m)
            );
        }

        static Linalg::Matrix identity(size_t n) {
            Linalg::Matrix id(n, n);

            for(size_t i = 0; i < n; ++i) {
                for(size_t j = 0; j < n; ++j) {
                    id[i][j] = (i == j);
                }
            }

            return id;
        }

        const Linalg::Vector & operator[](size_t idx) const {
            return matrix.at(idx);
        }

        Linalg::Vector & operator[](size_t idx) {
            return matrix.at(idx);
        }

        std::string string() {
            std::string ret = "[\n";

            for(size_t idx = 0; idx < matrix.size(); ++idx) {
                ret += (*this)[idx].string() + "\n";
            }

            return ret + "]";
        }

        Pair<size_t> size() {
            Pair<size_t> ret;
            ret.first = matrix.size();
            ret.second = matrix[0].size();

            return ret;
        }

        double determinant() {
            auto size = this->size();
            if(size.first != size.second) {
                throw std::runtime_error("determinant: matrix must be square");
            }

            return determinant((*this));
        }

        Linalg::Matrix scale(double scalar) {
            auto size = this->size();
            Linalg::Matrix ret(size.first, size.second);

            for(size_t idx = 0; idx < size.first; ++idx) {
                ret[idx] = (*this)[idx].scale(scalar);
            }

            return ret;
        }

        Linalg::Matrix removeRow(size_t rowIdx) {
            bool flag = false;
            size_t n = this->size().first;
            size_t m = this->size().second;
            
            Linalg::Matrix ret(n-1, m);

            size_t idx = 0;
            for(size_t i = 0; i < n; ++i) {
                if(i == rowIdx) { flag = true; continue; }
                
                idx = (flag)*(i-1) + (!flag)*(i);

                ret[idx] = (*this)[i];
            }

            return ret;
        }

        Linalg::Matrix removeCol(size_t colIdx) {
            bool flag = false;
            size_t n = this->size().first;
            size_t m = this->size().second;
            
            Linalg::Matrix ret(n, m-1);

            size_t idx = 0;
            for(size_t i = 0; i < m; ++i) {
                if(i == colIdx) { flag = true; continue; }
                
                idx = (flag)*(i-1) + (!flag)*(i);

                // Copy column over
                for(size_t j = 0; j < n; ++j) {
                    ret[j][idx] = (*this)[j][i];
                }
            }

            return ret;
        }

        Linalg::Matrix removeRowCol(size_t rowIdx, size_t colIdx) {
            return this->removeCol(colIdx).removeRow(rowIdx);
        }

        Linalg::Matrix multiply(Linalg::Matrix &mat) {
            auto sizeL = this->size();
            auto sizeR = mat.size();
            if(sizeL.second != sizeL.first) {
                throw std::runtime_error("matrix multiplication: incompatible sizes");
            }

            size_t n = sizeL.first;
            size_t m = sizeR.second;
            Linalg::Matrix ret(sizeL.first, sizeL.second);

            for(size_t i = 0; i < n; ++i){
                for(size_t j = 0; j < m; ++j) {
                    double entry = 0;
                    for(size_t k = 0; k < sizeL.second; ++k) {
                        entry += (*this)[i][k] * mat[k][j];
                    }

                    ret[i][j] = entry;
                }
            }

            return ret;
        }

        private:
        double determinant(Linalg::Matrix mat) {
            // Base Case
            auto size = mat.size();

            if(size.first == 1 && size.second == 1) {
                return mat[0][0];
            }
            
            double det = 0;

            for(size_t i = 0; i < mat.size().first; ++i) {
                int sgn = 1 - (2 * ((i+2) % 2)); // (-1)^(i+j) where j = 1
                det += sgn * mat[i][0] * determinant(mat.removeRowCol(i, 0));
            }

            return det;
        }
    };
}
