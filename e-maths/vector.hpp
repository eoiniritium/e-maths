#pragma once

#include "vector.hpp"
#include <vector>
#include <string>
#include <stdexcept>

namespace Linalg {
    class Vector {
        private:
        std::vector<double> vec;

        public:
        Vector(size_t n, double defaultValue = 0) {
            vec = std::vector<double>(n, defaultValue);
        }

        Vector(std::vector<double> vals) {
            vec = vals;
        }

        const double & operator[](size_t idx) const {
            return vec.at(idx);
        }

        double & operator[](size_t idx) {
            return vec.at(idx);
        }

        size_t size() {
            return vec.size();
        }

        Linalg::Vector scale(double scalar) {
            Vector ret(vec.size());

            for(size_t idx = 0; idx < vec.size(); ++idx) {
                ret[idx] = scalar * (*this)[idx];
            }

            return ret;
        }

        double mod() {
            double sum = 0;

            for(size_t i = 0; i < vec.size(); ++i) {
                sum += (*this)[i] * (*this)[i];
            }

            return sqrt(sum);
        }

        double dot(Linalg::Vector &other) {
            if(other.size() != this->size()) {
                throw std::runtime_error("dot: vectors must have the same dimension");
            }

            double sum = 0;

            for(size_t i = 0; i < vec.size(); ++i) {
                sum += (*this)[i] * other[i];
            }

            return sum;
        }

        Linalg::Vector add(Linalg::Vector &other) {
            Linalg::Vector ret(other);

            for(size_t i = 0; i < ret.size(); ++i) {
                ret[i] = ret[i] + (*this)[i];
            }

            return ret;
        }

        Linalg::Vector subtract(Linalg::Vector &other) {
            Linalg::Vector minus = other.scale(-1);
            return other.add(minus);
        }

        std::string string() {
            std::string ret = "( ";

            for(size_t i = 0; i < vec.size(); ++i) {
                ret += std::to_string(vec[i]) + " ";
            }

            return ret + ")";
        }
    };
}