#pragma once

#include "vector.hpp"
#include <vector>
#include <string>

namespace Linalg {
    class Vector {
        private:
        std::vector<double> vec;

        public:
        Vector(size_t n) {
            vec = std::vector<double>(n, 0);
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

        Vector scale(double scalar) {
            Vector ret(vec.size());

            for(size_t idx = 0; idx < vec.size(); ++idx) {
                ret[idx] = scalar * (*this)[idx];
            }

            return ret;
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