/**
 * My Printing Utilities.
 *
 * A custom printing utility framework.
 *
 * The main idea is to help me debugging through leetcode questions. For example:
 *      print_v(a, b, vec_c, IndexedVector{vec_d});
 * Turns into:
 *      a: 1
 *      b: 2
 *      c: {hello, world}
 *      d:
 *              {this, is, an, example}
 *       index:  0     1   2   3
 *
 * Headings serves as separators, e.g. separating between iteration counts.
 *      print_vl(h1(i), a, b);
 * Turns into:
 *      ====== i: 0 ======
 *      a: 1
 *      b: 2
 *      ====== i: 1 ======
 *      ...
 *
 * - Support printing of STL containers like vector, maps, sets, pairs, tuples.
 * - Support customized print by specializing struct UtilPrint<T>.
 * - Support printing of variables with the name and it's value through
 *   macros "print_v" and it's variants.
 * - Support printing of heading in the form of "====== text ======".
 *   Text support in headings supports anything that UtilPrint can support.
 * - Also support multi-line heading contents.
 */
#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include <sstream>
#include <vector>
#include <ranges>
#include <concepts>
#include <assert.h>

#include "my_preprocessor_util.hpp"

template<std::ranges::range R, typename Callback>
void for_each(const R &r, Callback &&callback) {
    for (auto &v: r) {
        callback(v);
    }
}

template<typename T>
struct UtilPrint {
    static std::ostream &my_print(std::ostream &os, const T &v) = delete;
};

template<class T>
concept StringLike = std::is_convertible_v<T, std::string_view>;

template<typename T>
concept MyPrintable =requires(std::ostream &os,
                              const T &value
) {
    {
    UtilPrint<T>::my_print(os, value
    )
    } ->
    std::convertible_to<std::ostream &>;
};

template<typename T>
concept Streamable =requires(std::ostream &os, const T &value) {
    { os << value } -> std::convertible_to<std::ostream &>;
};

template<typename T>
std::ostream &print_single(std::ostream &os, const T &v) {
    if constexpr (StringLike<T>) {
        os << std::string_view{v};
    } else if constexpr (MyPrintable<T>) {
        UtilPrint<T>::my_print(os, v);
    } else if constexpr (Streamable<T>) {
        os << v;
    } else {
        //static_assert(false, "failed to print");
    }
    return os;
}

template<>
struct UtilPrint<bool> {
    static std::ostream &my_print(std::ostream &os, const bool &v) {
        os << std::boolalpha << v;
        return os;
    }
};

template<std::ranges::range R>
struct UtilPrint<R> {
    static std::ostream &my_print(std::ostream &os, const R &v) {
        auto iter = std::begin(v);
        if (iter != std::end(v)) {
            os << "{";
            while (true) {
                auto item = *(iter);
                print_single(os, std::forward<decltype(item)>(item));
                if (++iter == std::end(v)) {
                    break;
                } else {
                    os << ", ";
                }
            }
            os << "}";
        } else {
            os << "{}";
        }
        return os;
    }
};

template<typename V1, typename...V>
struct UtilPrint<std::tuple<V1, V...>> {
    static std::ostream &my_print(std::ostream &os, const std::tuple<V1, V...> &v) {
        os << "<";
        ((print_single(os, std::get<0>(v))), ..., (os << ", ", print_single(os, std::forward<V>(v))));
        os << ">";
        return os;
    }
};

template<typename V1, typename V2>
struct UtilPrint<std::pair<V1, V2>> {
    static std::ostream &my_print(std::ostream &os, const std::pair<V1, V2> &v) {
        os << "<";
        print_single(os, v.first);
        os << ", ";
        print_single(os, v.second);
        os << ">";
        return os;
    }
};

template<typename T>
struct IndexedVector {
    const std::vector<T> &vec;
};

template<typename T>
struct UtilPrint<IndexedVector<T>> {
    static std::ostream &my_print(std::ostream &os, const IndexedVector<T> &v) {
        auto iter = std::begin(v.vec);
        if (iter != std::end(v.vec)) {
            int index = 0;
            std::stringstream indexStrStm;
            os << "\n       "
               << "{";
            while (true) {
                auto item = *(iter);
                std::stringstream itemStrStm;
                print_single(itemStrStm, std::forward<decltype(item)>(item));
                std::string itemStr = itemStrStm.str();
                std::string idxStr = std::to_string(index);
                if (itemStr.size() > idxStr.size()) {
                    idxStr.resize(itemStr.size(), ' ');
                } else {
                    itemStr.resize(idxStr.size(), ' ');
                }
                os << itemStr;
                indexStrStm << idxStr;
                ++index;
                if (++iter == std::end(v.vec)) {
                    break;
                } else {
                    os << ", ";
                    indexStrStm << "  ";
                }
            }
            os << "}"
               << "\n index  " << indexStrStm.str();
        } else {
            os << "{}";
        }
        return os;
    }
};

// *********************************************************************************************************************
// Apis
// *********************************************************************************************************************

template<typename...T>
void print(T &&...t) {
    (print_single(std::cout, std::forward<T>(t)), ...);
}

template<typename...T>
std::string print_to_string(T &&...t) {
    std::stringstream ss;
    (print_single(ss, std::forward<T>(t)), ...);
    return ss.str();
}

template<typename...T>
void print_line(T &&...t) {
    print(std::forward<T>(t)..., "\n");
}

template<typename...T>
void print_item(const char *delim, const char *end, T &&...t) {
    (print(std::forward<T>(t), delim), ..., print(end));
}

#define _var_0(...) ""
#define _var_1(CONN, SEP, _v1) #_v1 CONN, _v1
#define _var_2(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_1(CONN, SEP, __VA_ARGS__)
#define _var_3(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_2(CONN, SEP, __VA_ARGS__)
#define _var_4(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_3(CONN, SEP, __VA_ARGS__)
#define _var_5(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_4(CONN, SEP, __VA_ARGS__)
#define _var_6(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_5(CONN, SEP, __VA_ARGS__)
#define _var_7(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_6(CONN, SEP, __VA_ARGS__)
#define _var_8(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_7(CONN, SEP, __VA_ARGS__)
#define _var_9(CONN, SEP, _v1, ...)  _var_1(CONN, SEP, _v1), SEP, _var_8(CONN, SEP, __VA_ARGS__)
#define _var_10(CONN, SEP, _v1, ...) _var_1(CONN, SEP, _v1), SEP, _var_9(CONN, SEP, __VA_ARGS__)

// count, method, before, after, vars...
#define _print_var_inc(_c, _m, _bef, _conn, _sep, _aft, ...) print##_m (DEPAREN(_bef) _var_##_c (_conn, _sep, __VA_ARGS__) DEPAREN(_aft))
#define _print_var(_c, _m, ...)  _print_var_inc(_c, _m, __VA_ARGS__)

#define print_var_to_string(...) _print_var(COUNT(__VA_ARGS__), _to_string, (), ": ", '\n', (,'\n'), __VA_ARGS__)
#define print_var(...)           _print_var(COUNT(__VA_ARGS__), , (), ": ", '\n', (,'\n'), __VA_ARGS__)
#define print_varl(label, ...)   _print_var(COUNT(__VA_ARGS__), , (label, '\n',), ": ", '\n', (,'\n'), __VA_ARGS__)

#define print_var_oneline_to_string(...) _print_var(COUNT(__VA_ARGS__), _to_string, (), ": ", ", ", (,'\n'), __VA_ARGS__)
#define print_var_oneline(...)           _print_var(COUNT(__VA_ARGS__), , (), ": ", ", ", (, '\n'), __VA_ARGS__)
#define print_varl_oneline(label, ...)   _print_var(COUNT(__VA_ARGS__), , (label, '\n',), ": ", ", ", (,'\n'), __VA_ARGS__)

#define print_v  print_var
#define print_vl print_varl

#define print_vo  print_var_oneline
#define print_vlo print_varl_oneline

// *********************************************************************************************************************
// Utilities
// *********************************************************************************************************************

struct BoxDrawingChar {
    static constexpr char top_left = '+';
    static constexpr char top = '-';
    static constexpr char top_right = '+';
    static constexpr char left = '|';
    static constexpr char right = '|';
    static constexpr char bot_left = '+';
    static constexpr char bot = '-';
    static constexpr char bot_right = '+';
};

struct BoxDrawingWideChar {
    static constexpr wchar_t top_left = L'┌';
    static constexpr wchar_t top = L'─';
    static constexpr wchar_t top_right = L'┐';
    static constexpr wchar_t left = L'│';
    static constexpr wchar_t right = L'│';
    static constexpr wchar_t bot_left = L'└';
    static constexpr wchar_t bot = L'─';
    static constexpr wchar_t bot_right = L'┘';

    static constexpr wchar_t vertical_left = L'┤';
    static constexpr wchar_t vertical_right = L'├';
    static constexpr wchar_t horizontal_top = L'┴';
    static constexpr wchar_t horizontal_down = L'┬';
    static constexpr wchar_t cross = L'┼';
};

template<typename CharT>
static constexpr size_t get_max_line_length(const std::basic_string_view<CharT> &str) {
    size_t lastPos = str.find_first_of('\n');
    if (lastPos == std::string_view::npos) {
        return str.size();
    } else {
        size_t maxLength = lastPos;
        while (lastPos != str.size()) {
            int thisPos = str.find_first_of('\n', lastPos + 1);
            if (thisPos == std::string::npos) {
                thisPos = str.size();
            }
            maxLength = std::max(maxLength, thisPos - (lastPos + 1));
            lastPos = thisPos;
        }
        return maxLength;
    }
}

template<typename CharT>
static constexpr auto get_next_line(const std::basic_string_view<CharT> &str, size_t &lastPos) {
    if (lastPos == str.size()) {
        return std::basic_string_view<CharT>{};
    } else {
        size_t thisLineStart = lastPos == std::string_view::npos ? 0 : lastPos + 1;
        size_t thisLineEnd = str.find_first_of('\n', thisLineStart);
        if (thisLineEnd == std::string::npos) {
            lastPos = str.size();
            return str.substr(thisLineStart, str.size() - thisLineStart);
        } else {
            lastPos = thisLineEnd;
            return str.substr(thisLineStart, thisLineEnd - thisLineStart);
        }
    }
}

template<typename CharT, typename BoxChar, bool align_left, bool align_right, bool align_center>
static auto make_boxed(const std::basic_string_view<CharT> &str, BoxChar boxChar = {}) {
    //static_assert(align_left + align_right + align_center == 1);
    size_t length = get_max_line_length(str) + 2;
    size_t lastPos = std::basic_string_view<CharT>::npos;

    std::basic_stringstream<CharT> ss;

    ss << boxChar.top_left;
    for (size_t i = 0; i < length; ++i) ss << boxChar.top;
    ss << boxChar.top_right << '\n';

    while (lastPos != str.size()) {
        auto strThisLine = get_next_line(str, lastPos);

        size_t left_pad, right_pad;
        if constexpr (align_left) {
            left_pad = 1;
            right_pad = length - 1 - strThisLine.size();
        } else if constexpr (align_right) {
            left_pad = length - 1 - strThisLine.size();
            right_pad = 1;
        } else if constexpr (align_center) {
            left_pad = (length - strThisLine.size()) / 2;
            right_pad = (length - strThisLine.size()) - left_pad;
        } else {
            //static_assert(false);
        }

        ss << boxChar.left;
        for (size_t i = 0; i < left_pad; ++i) ss << ' ';
        ss << strThisLine;
        for (size_t i = 0; i < right_pad; ++i) ss << ' ';
        ss << boxChar.right << '\n';
    }

    ss << boxChar.bot_left;
    for (size_t i = 0; i < length; ++i) ss << boxChar.bot;
    ss << boxChar.bot_right;

    return ss.str();
}

template<bool align_left, bool align_right, bool align_center>
static constexpr auto make_heading(const std::string_view &title, size_t lineSize, char styleChar) {
    //static_assert(align_left + align_right + align_center == 1);

    if (title.size() == 0) {
        return std::string(lineSize, styleChar);
    }

    std::string storage;
    size_t titleSize, titleIndex = 0, storageIndex = 0;

    size_t next = title.find_first_of('\n', 0);
    if (next == std::string_view::npos) {
        titleSize = title.size();
    } else {
        titleSize = next;
    }

    bool firstLine = true;
    while (true) {
        size_t titleThisSeg = titleSize - titleIndex;
        if (titleThisSeg == 0) {
            // handles the case of consecutive newlines
            // should be converted to an empty line
            size_t totalSize = storage.size() + lineSize + (!firstLine);
            storage.resize(totalSize, styleChar);
            if (!firstLine)
                storage[storageIndex++] = '\n';
            storageIndex += lineSize;
        } else {
            size_t numLine = titleThisSeg / (lineSize - 6) + (titleThisSeg % (lineSize - 6) != 0);
            assert(numLine >= 1);

            size_t totalSize = storage.size() + numLine * (lineSize + 1) - firstLine;
            storage.resize(totalSize, '\0');

            for (size_t line = 0; line < numLine; ++line) {
                // pad at least 2 on each side, plus two space around the title
                assert(lineSize > 6 && "requires at least 6 character in length");
                size_t titleThisLine = std::min(titleSize - titleIndex, lineSize - 6);

                size_t left_pad, right_pad;
                if constexpr (align_left) {
                    left_pad = 2;
                    right_pad = lineSize - 4 - titleThisLine;
                } else if constexpr (align_right) {
                    left_pad = lineSize - 4 - titleThisLine;
                    right_pad = 2;
                } else if constexpr (align_center) {
                    left_pad = (lineSize - 2 - titleThisLine) / 2;
                    right_pad = (lineSize - 2 - titleThisLine) - left_pad;
                } else {
                    //static_assert(false);
                }

                assert(left_pad >= 2);
                assert(right_pad >= 2);
                assert(left_pad + right_pad + titleThisLine + 2 == lineSize);

                if (!firstLine)
                    storage[storageIndex++] = '\n';
                for (size_t i = 0; i < left_pad; ++i)
                    storage[storageIndex++] = styleChar;
                storage[storageIndex++] = ' ';
                for (size_t i = 0; i < titleThisLine; ++i)
                    storage[storageIndex++] = title[titleIndex++];
                storage[storageIndex++] = ' ';
                for (size_t i = 0; i < right_pad; ++i)
                    storage[storageIndex++] = styleChar;
            }
        }

        assert(storageIndex == storage.size());
        assert(titleIndex == titleSize);

        // if exhausted all titles, should skip
        if (titleSize == title.size()) {
            break;
        }

        ++titleIndex;  // skip the newline
        // handle the case that title ends with '\n'
        if (titleSize + 1 == title.size()) {
            break;
        }

        next = title.find_first_of('\n', titleSize + 1);
        if (next == std::string_view::npos) {
            titleSize = title.size();
        } else {
            titleSize = next;
        }
        firstLine = false;
    }

    assert(titleIndex == title.size());  // should have exhausted all characters in title
    return storage;
}

#define HEADING_STYLE_1 '='
#define HEADING_STYLE_2 '-'
#define HEADING_STYLE_3 '.'

#define HEADING_ALIGN_LEFT   <true, false, false>
#define HEADING_ALIGN_RIGHT  <false, true, false>
#define HEADING_ALIGN_CENTER <false, false, true>

static size_t heading_length = 55;

#define heading(_t, _s, _a) make_heading HEADING_ALIGN_##_a (_t, heading_length, HEADING_STYLE_##_s)

#define h1(...) heading(print_to_string(__VA_ARGS__), 1, CENTER)
#define h2(...) heading(print_to_string(__VA_ARGS__), 2, CENTER)
#define h3(...) heading(print_to_string(__VA_ARGS__), 3, CENTER)

#define _heading_var(...) _print_var(COUNT(__VA_ARGS__), _to_string, (), ": ", ", ", (), __VA_ARGS__)
#define h1v(...) heading(_heading_var(__VA_ARGS__), 1, CENTER)
#define h2v(...) heading(_heading_var(__VA_ARGS__), 2, CENTER)
#define h3v(...) heading(_heading_var(__VA_ARGS__), 3, CENTER)

#define _enclosed_heading_var(...) _print_var(COUNT(__VA_ARGS__), _to_string, ('\n',), ": ", ", ", (,'\n'), __VA_ARGS__)
#define enclosed_h1v(...) heading(_enclosed_heading_var(__VA_ARGS__), 1, CENTER)
#define enclosed_h2v(...) heading(_enclosed_heading_var(__VA_ARGS__), 2, CENTER)
#define enclosed_h3v(...) heading(_enclosed_heading_var(__VA_ARGS__), 3, CENTER)

#define sep h1()
#define bef h1("before")
#define aft h1("after")
