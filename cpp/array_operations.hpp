#pragma once

#include <math.h>
#include <limits>
#include <array>
#include <iostream>

using namespace std;


template<int N>
using Vec = conditional<N == 1, double, array<double, N>>::type;



template <int N, int M>
using Func = function<Vec<M>(const Vec<N>&)>;

template <int N1, int N2, int M>
using Func2 = function<Vec<M>(const Vec<N1>&, const Vec<N2>&)>;


template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr) {
    os << '[';
    for (std::size_t i = 0; i < N; ++i) {
        os << arr[i];
        if (i < N - 1) {
            os << ", ";
        }
    }
    os << ']';
    return os;
}


template <typename T, std::size_t N>
std::array<T, N> operator+(const std::array<T, N>& lhs, const std::array<T, N>& rhs) {
    std::array<T, N> result;
    for (std::size_t i = 0; i < N; ++i) {
        result[i] = lhs[i] + rhs[i];
    }
    return result;
}
template <typename T, std::size_t N>
std::array<T, N> operator-(const std::array<T, N>& lhs, const std::array<T, N>& rhs) {
    std::array<T, N> result;
    for (std::size_t i = 0; i < N; ++i) {
        result[i] = lhs[i] - rhs[i];
    }
    return result;
}

template <typename T, std::size_t N>
std::array<T, N> operator*(const std::array<T, N>& lhs, T rhs) {
    std::array<T, N> result;
    for (std::size_t i = 0; i < N; ++i) {
        result[i] = lhs[i] * rhs;
    }
    return result;
}
template <typename T, std::size_t N>
std::array<T, N> operator/(const std::array<T, N>& lhs, T rhs) {
    return lhs * (1/rhs);
}
template <typename T, std::size_t N>
std::array<T, N> operator*(T lhs, const std::array<T, N>& rhs) {
    std::array<T, N> result;
    for (std::size_t i = 0; i < N; ++i) {
        result[i] = lhs * rhs[i];
    }
    return result;
}
template <typename T, std::size_t N>
T operator*(const std::array<T, N>& lhs, const std::array<T, N>& rhs) {
    T result;
    for (std::size_t i = 0; i < N; ++i) {
        result += lhs[i] * rhs[i];
    }
    return result;
}