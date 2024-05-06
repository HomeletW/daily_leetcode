//
// Created by Hongcheng Wei on 2024-05-05.
//
#include "my_util.hpp"

int main() {
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
