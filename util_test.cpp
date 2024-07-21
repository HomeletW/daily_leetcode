//
// Created by Hongcheng Wei on 2024-05-05.
//
#include "my_util.hpp"
#include "my_list_node.hpp"
#include "my_tree_node.hpp"

void test_print() {
    print();
    print(1, 2, '\n');
    print_line(1, std::vector{323, 423});
    print_line(std::vector{std::vector{334},
                           std::vector{4523}});
    print_item("DELIM_here", "END_here\n", 2, 3, 4, 5, 6, 7);
    int a = 10;
    auto b = {11, 12, 13};
    auto c = {b, b};
    print_var(a);
    print_var(b);
    print_var(c);

    std::unordered_map<int, const char *> map;
    map[1] = "abc";
    map[2] = "bcd";
    map[5] = "zzz";
    map[342] = "233";
    auto map2 = {map, map};
    std::unordered_map<int, decltype(map)> map3;
    map3[a] = map;
    print_var(map);
    print_var(map2);
    print_var(map3);
}

void test_list_node() {
    make_list_node(int, a, 1, 2, 3, 4, 5, 6);
    make_list_node(int, b, 1, 2, 3, 4, 5, 6);
    make_list_node(int, c, 1, 2, 3, 4, 5, 6);
    print_v(a0, b0, c0);
}

void test_tree_node() {
    auto small = make_tree_node(-1, {100, 200, 300, 400, 500, 600, 700});
    auto a = make_tree_node(-1, {
            1,
            2, 3,
            4, 5, 6, 7,
            8, 9, 10, 11, 12, 13, 14, 15,
            16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
    });
    auto b = make_tree_node(-1, {
            1,
            2, 3,
            4, -1, 6, 7,
            8, 9, -1, -1, -1, -1, -1, 15,
            16, 17, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 30, 31,
            32, 33, 34, 35, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1,
    });
    std::vector<int> v1{3, 21, 2001}, v2{10, 28, 2000};
    auto c = make_tree_node<std::string>("", {
            "1111111111\n222222\n333333\n4445",
            "2222\n4124", "333\n512314\n14124\n51251\n5123",
            print_to_string(IndexedVector{v1}), print_to_string(IndexedVector{v2}), "6\n\n\n123123", "7",
    });
    auto d = make_tree_node(-1, {
            1,
            -1, 3,
            -1, -1, -1, 7,
            -1, -1, -1, -1, -1, -1, -1, 15,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 31
    });
    auto e = make_tree_node(-1, {
            1,
            2, -1,
            4, -1, -1, -1,
            8, -1, -1, -1, -1, -1, -1, -1,
            16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    });
    pretty_print_tree<BoxedTreeNodePrettyPrintConfig, int, wchar_t>(std::wcout, a.get());
    pretty_print_tree<BoxedTreeNodePrettyPrintConfig, int, wchar_t>(std::wcout, b.get());
    pretty_print_tree<BoxedTreeNodePrettyPrintConfig, std::string, wchar_t>(std::wcout, c.get());
    pretty_print_tree<BoxedTreeNodePrettyPrintConfig, int, wchar_t>(std::wcout, d.get());
    pretty_print_tree<BoxedTreeNodePrettyPrintConfig, int, wchar_t>(std::wcout, e.get());
    print_v(*a, *b, *c, *d, *e);
    pretty_print_tree<DefaultTreeNodePrettyPrintConfig, int, char>(std::cout, small.get(), {}, false);
    pretty_print_tree<DefaultTreeNodePrettyPrintConfig, int, char>(std::cout, small.get(), {}, true);
}

int main() {
    std::setlocale(LC_ALL, "");
    std::wcout.imbue(std::locale());
//    test_print();
//    test_list_node();
    test_tree_node();
}
