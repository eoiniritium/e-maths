#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

namespace EMaths {
    template <typename T>
    class Vector {
        private:
        std::vector<T> vector;

        public:
        Vector(size_t length) {
            this->vector = std::vector<T>(length);
        }

        Vector(std::vector<T> values) {
            this->vector = values;
        }

        // GET
        const T &operator[](size_t idx) const {
            if(idx < 0 || idx >= this->vector.size()) {
                throw std::out_of_range("Index out of range.");
            }

            return this->vector[idx];
        }

        // SET
        T &operator[](size_t idx) {
            if(idx < 0 || idx >= this->vector.size()) {
                throw std::out_of_range("Index out of range.");
            }

            return this->vector[idx];
        }

        EMaths::Vector<T> operator*(T &scalar) {
            
            EMaths::Vector<T> ret(this->vector.size());
            
            for(size_t i = 0; i < this->vector.size(); ++i) {
                ret[i] = ret[i] * scalar;
            }

            return ret;
        }

        std::string string() {
            size_t n = this->vector.size();

            if(n == 0) { return "()"; }

            std::string ret = "(";

            for(size_t i = 0; i < n - 1; ++i) {
                ret += std::to_string(this->vector[i]) + ", ";
            }

            ret += std::to_string(this->vector[n - 1]) + ")";

            return ret;
        }

        EMaths::Vector<T> scale(T scalar) {
            EMaths::Vector<T> ret(this->vector.size());
            
            for(size_t i = 0; i < this->vector.size(); ++i) {
                ret[i] = ret[i] * scalar;
            }

            return ret;
        }
    };
}