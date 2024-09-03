/**
 * 383. Ransom Note
 * https://leetcode.com/problems/ransom-note
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (char c: magazine) {
            map[c]++;
        }
        print_var(map);
        for (char c: ransomNote) {
            if (!map.contains(c) || map[c] <= 0) {
                return false;
            } else {
                --map[c];
            }
        }
        return true;
    }
};

int main() {
    print_line(Solution().canConstruct("a", "b"));
    print_line(Solution().canConstruct("aa", "ab"));
    print_line(Solution().canConstruct("aa", "aab"));
}
