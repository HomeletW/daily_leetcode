//
// Created by Hongcheng Wei on 2024-05-26.
//

#pragma once

// Trick to remove parentheses in macro
// https://stackoverflow.com/a/62984543
#define VANISH
#define DEPAREN(X) ESC(ISH X)
#define ISH(...) ISH __VA_ARGS__
#define ESC(...) ESC_(__VA_ARGS__)
#define ESC_(...) VAN ## __VA_ARGS__

// Count how many parameters was passed
// using the __VA_OPT__ option
#define COUNT(...) COUNT_N(__VA_OPT__(,) __VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define COUNT_N(_, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, N, ...) N

// Reverse VA_ARGS
#define _EXPAND(x) x
#define _REVERSED_1(a) a
#define _REVERSED_2(a, b) b, a
#define _REVERSED_3(a, ...)   _REVERSED_2(__VA_ARGS__), a
#define _REVERSED_4(a, ...)   _REVERSED_3(__VA_ARGS__), a
#define _REVERSED_5(a, ...)   _REVERSED_4(__VA_ARGS__), a
#define _REVERSED_6(a, ...)   _REVERSED_5(__VA_ARGS__), a
#define _REVERSED_7(a, ...)   _REVERSED_6(__VA_ARGS__), a
#define _REVERSED_8(a, ...)   _REVERSED_7(__VA_ARGS__), a
#define _REVERSED_9(a, ...)   _REVERSED_8(__VA_ARGS__), a
#define _REVERSED_10(a, ...)  _REVERSED_9(__VA_ARGS__), a
#define _REVERSED_11(a, ...)  _REVERSED_10(__VA_ARGS__), a
#define _REVERSED_12(a, ...)  _REVERSED_11(__VA_ARGS__), a
#define _REVERSED_13(a, ...)  _REVERSED_12(__VA_ARGS__), a
#define _REVERSED_14(a, ...)  _REVERSED_13(__VA_ARGS__), a
#define _REVERSED_15(a, ...)  _REVERSED_14(__VA_ARGS__), a
#define _REVERSED_16(a, ...)  _REVERSED_15(__VA_ARGS__), a
#define _REVERSED_17(a, ...)  _REVERSED_16(__VA_ARGS__), a
#define _REVERSED_18(a, ...)  _REVERSED_17(__VA_ARGS__), a
#define _REVERSED_19(a, ...)  _REVERSED_18(__VA_ARGS__), a
#define _REVERSED_20(a, ...)  _REVERSED_19(__VA_ARGS__), a
#define _REVERSED_VAR(N, ...) _REVERSED_ ## N (__VA_ARGS__)
#define _REVERSED(N, ...) _REVERSED_VAR(N, __VA_ARGS__)
#define REVERSED(...) _REVERSED(COUNT(__VA_ARGS__), __VA_ARGS__)

// adding one (support upto 20)
#define ADD_ONE_0   1
#define ADD_ONE_1   2
#define ADD_ONE_2   3
#define ADD_ONE_3   4
#define ADD_ONE_4   5
#define ADD_ONE_5   6
#define ADD_ONE_6   7
#define ADD_ONE_7   8
#define ADD_ONE_8   9
#define ADD_ONE_9   10
#define ADD_ONE_10  11
#define ADD_ONE_11  12
#define ADD_ONE_12  13
#define ADD_ONE_13  14
#define ADD_ONE_14  15
#define ADD_ONE_15  16
#define ADD_ONE_16  17
#define ADD_ONE_17  18
#define ADD_ONE_18  19
#define ADD_ONE_19  20
#define ADD_ONE(_V)  ADD_ONE_ ## _V

// subtracting one (support upto 20)
#define SUB_ONE_1   0
#define SUB_ONE_2   1
#define SUB_ONE_3   2
#define SUB_ONE_4   3
#define SUB_ONE_5   4
#define SUB_ONE_6   5
#define SUB_ONE_7   6
#define SUB_ONE_8   7
#define SUB_ONE_9   8
#define SUB_ONE_10  9
#define SUB_ONE_11  10
#define SUB_ONE_12  11
#define SUB_ONE_13  12
#define SUB_ONE_14  13
#define SUB_ONE_15  14
#define SUB_ONE_16  15
#define SUB_ONE_17  16
#define SUB_ONE_18  17
#define SUB_ONE_19  18
#define SUB_ONE_20  19
#define SUB_ONE(_V)  SUB_ONE_ ## _V
