//
// Created by Hongcheng Wei on 2023-08-10.
//
#include <iostream>
#include <ranges>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <array>
#include <deque>
#include <limits>
#include <cassert>
#include <concepts>
#include <numeric>
#include <set>
#include <unordered_set>

template<std::ranges::range R, typename Callback>
void for_each(const R &r, Callback &&callback) {
    for (auto &v: r) {
        callback(v);
    }
}

template<typename T>
concept Streamable =requires(std::ostream &os, T value) {
    { os << value } -> std::convertible_to<std::ostream &>;
};

template<typename T>
concept StreamablePair =requires(std::ostream &os, T value) {
    { value.first } -> std::same_as<typename T::first_type &>;
    { value.second } -> std::same_as<typename T::second_type &>;
    requires Streamable<typename T::first_type> || std::ranges::range<typename T::first_type>;
    requires Streamable<typename T::second_type> || std::ranges::range<typename T::second_type>;
};

template<typename T>
void print_single(T &&v);

template<typename R>
void print_range(const R &r) {
    auto iter = std::begin(r);
    if (iter != std::end(r)) {
        std::cout << "{";
        while (true) {
            auto v = *(iter);
            print_single(std::forward<decltype(v)>(v));
            if (++iter == std::end(r)) {
                break;
            } else {
                std::cout << ", ";
            }
        }
        std::cout << "}";
    } else {
        std::cout << "{ }";
    }
}

template<typename T>
void print_single(T &&v) {
    if constexpr (Streamable<T>) {
        std::cout << v;
    } else if constexpr (StreamablePair<T>) {
        std::cout << "<";
        print_single(std::forward<typename T::first_type>(v.first));
        std::cout << ", ";
        print_single(std::forward<typename T::second_type>(v.second));
        std::cout << ">";
    } else if constexpr (std::ranges::range<T>) {
        print_range(std::forward<T>(v));
    } else {
        static_assert(false, "failed to print");
    }
}

template<typename...T>
void print(T &&...t) {
    (print_single(std::forward<T>(t)), ...);
}

template<typename...T>
void print_line(T &&...t) {
    print(std::forward<T>(t)..., "\n");
}

template<typename...T>
void print_item(const char *delim, const char *end, T &&...t) {
    (print(std::forward<T>(t), delim), ..., print(end));
}

static constexpr const char *sep = "================";

#define COUNT_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...)    N
#define COUNT(...)   COUNT_N( __VA_ARGS__, 10, 9, 8, 7, 6, 5 ,4, 3, 2, 1)

#define _print_var_1(_v1) print_line(#_v1 ": ", _v1)
#define _print_var_2(_v1, ...) _print_var_1(_v1); _print_var_1(__VA_ARGS__)
#define _print_var_3(_v1, ...) _print_var_1(_v1); _print_var_2(__VA_ARGS__)
#define _print_var_4(_v1, ...) _print_var_1(_v1); _print_var_3(__VA_ARGS__)
#define _print_var_5(_v1, ...) _print_var_1(_v1); _print_var_4(__VA_ARGS__)
#define _print_var_6(_v1, ...) _print_var_1(_v1); _print_var_5(__VA_ARGS__)
#define _print_var_7(_v1, ...) _print_var_1(_v1); _print_var_6(__VA_ARGS__)
#define _print_var_8(_v1, ...) _print_var_1(_v1); _print_var_7(__VA_ARGS__)
#define _print_var_9(_v1, ...) _print_var_1(_v1); _print_var_8(__VA_ARGS__)

#define _print_var_inc(CT, ...) _print_var_##CT (__VA_ARGS__)
#define _print_var(CT, ...)     _print_var_inc(CT, __VA_ARGS__)
#define print_var(...)          _print_var(COUNT(__VA_ARGS__), __VA_ARGS__)
