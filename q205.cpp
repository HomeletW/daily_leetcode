/**
 * 205. Isomorphic Strings
 * https://leetcode.com/problems/isomorphic-strings
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        // store the s -> t mapping and the t -> s mapping as wel
        // since char is at most 256, an optimization could be
        // to use an pre-sized array as the mapping, and storing
        // the index
        map<char, char> replacement;  // s -> t
        set<char> mapping;  // for checking if two char mapped to the same
        for (int i = 0; i < s.size(); ++i) {
            auto iter = replacement.find(s[i]);
            if (iter == replacement.end()) {
                replacement[s[i]] = t[i];
                auto pair = mapping.insert(t[i]);
                if (!pair.second) {
                    return false;
                }
            } else {
                if (iter->second != t[i]) {
                    return false;
                }
            }
            print_v(replacement, mapping);
        }

        return true;
    }
};

int main() {
    print_v(Solution().isIsomorphic("add", "egg"));
    print_v(Solution().isIsomorphic("foo", "bar"));
    print_v(Solution().isIsomorphic("paper", "title"));
    print_v(Solution().isIsomorphic("badc", "baba"));
}
