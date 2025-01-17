/**
 * List Node generic definitions and my_print framework support.
 *
 * Defines an generic version of the Leetcode ListNode definitions.
 * Usage:
 *      using ListNode = ListNode_generic<int>;
 *
 * To print:
 *      print_v(node_head);
 * Turns into:
 *      node_head: 1 -> 2 -> 3 -> END
 *
 * Also support a macro definitions to quickly define a list.
 * Since the list is allocated on stack, there is no need to manage the memory.
 * Usage:
 *      // define ListNode_generic<int> with head "a0" with the content.
 *      make_list_node(int, a, 5, 4, 3, 2);
 *      print_v(a0);
 * Turns into:
 *      a: 5 -> 4 -> 3 -> 2 -> END
 */

#pragma once

#include "my_util.hpp"
#include "my_preprocessor_util.hpp"


template<typename ListNodeType>
concept ListNodeLike = requires(ListNodeType node) {
    { node.val };
    { node.next } -> std::convertible_to<ListNodeType *>;
    requires std::is_default_constructible_v<ListNodeType>;
    requires requires(decltype(node.val) v) {
        { ListNodeType(v) };
    };
    requires requires(decltype(node.val) v, ListNodeType *next) {
        { ListNodeType(v, next) };
    };
};

template<typename T>
struct ListNode_generic {
    T val;
    ListNode_generic<T> *next;

    ListNode_generic() : val(0), next(nullptr) {}

    ListNode_generic(int x) : val(x), next(nullptr) {}

    ListNode_generic(int x, ListNode_generic<T> *next) : val(x), next(next) {}
};

static_assert(ListNodeLike<ListNode_generic<int>>);

template<ListNodeLike ListNodeType>
struct UtilPrint<ListNodeType> {
    static std::ostream &my_print(std::ostream &os, const ListNodeType &v) {
        const ListNodeType *ptr = std::addressof(v);
        while (ptr != nullptr) {
            print(ptr->val, " -> ");
            ptr = ptr->next;
        }
        os << "END";
        return os;
    }
};

#define _list_node_name(_pre, _i)       _pre ## _i
#define _next_list_node_name_temp(_pre, _i)  _list_node_name(_pre, _i)
#define _next_list_node_name(_pre, _i)  _next_list_node_name_temp(_pre, ADD_ONE(_i))

#define _list_node(_pre, _i, _val)      _list_node_name(_pre, _i) {_val, & _next_list_node_name(_pre, _i)}
#define _list_node_end(_pre, _i, _val)  _list_node_name(_pre, _i) {_val, nullptr}

#define _list_node_1(_pre, _i, _val)        _list_node_end(_pre, _i, _val)
#define _list_node_2(_pre, _i, _val, ...)   _list_node_1 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_3(_pre, _i, _val, ...)   _list_node_2 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_4(_pre, _i, _val, ...)   _list_node_3 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_5(_pre, _i, _val, ...)   _list_node_4 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_6(_pre, _i, _val, ...)   _list_node_5 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_7(_pre, _i, _val, ...)   _list_node_6 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_8(_pre, _i, _val, ...)   _list_node_7 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_9(_pre, _i, _val, ...)   _list_node_8 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_10(_pre, _i, _val, ...)  _list_node_9 (_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_11(_pre, _i, _val, ...)  _list_node_10(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_12(_pre, _i, _val, ...)  _list_node_11(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_13(_pre, _i, _val, ...)  _list_node_12(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_14(_pre, _i, _val, ...)  _list_node_13(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_15(_pre, _i, _val, ...)  _list_node_14(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_16(_pre, _i, _val, ...)  _list_node_15(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_17(_pre, _i, _val, ...)  _list_node_16(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_18(_pre, _i, _val, ...)  _list_node_17(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_19(_pre, _i, _val, ...)  _list_node_18(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)
#define _list_node_20(_pre, _i, _val, ...)  _list_node_19(_pre, ADD_ONE(_i), __VA_ARGS__), _list_node(_pre, _i, _val)

#define _make_list_node_var(_type, _pre, _count, ...) _type _list_node_ ## _count (_pre, 0, __VA_ARGS__)
#define _make_list_node(_type, _pre, _count, ...) _make_list_node_var(_type, _pre, _count, __VA_ARGS__)
#define make_list_node_custom_type(_type, _pre, ...) _make_list_node(_type, _pre, COUNT(__VA_ARGS__), __VA_ARGS__)
#define make_list_node(_type, _pre, ...) _make_list_node(ListNode_generic<_type>, _pre, COUNT(__VA_ARGS__), __VA_ARGS__)
