/**
 * 76. Minimum Window Substring
 * https://leetcode.com/problems/minimum-window-substring
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;

        // load all characters in t in the map
        for (char c: t) {
            ++t_map[c];
        }

        int left = 0, right = 0;
        int counter = 0; // counting how many t has included in [left, right]
        int best_head = 0;                             // record the current shortest substr head
        int best_length = numeric_limits<int>::max();  // record the current shortest substr length

        while (right <= s.size()) {
            // move right pointer till [left, right] contains all t
            if (t_map[s[right]] > 0) {
                ++counter;
            }
            --t_map[s[right]];
            ++right;

            while (counter == t.size()) {
                // at this point [left, right] should contain all t,
                // and in t_map, all t's char are at most zeros

                // checks the current best
                int current_length = right - left;
                if (current_length < best_length) {
                    best_head = left;
                    best_length = current_length;
                }

                // now moves left pointer as long as [left, right] contains all t

                // once a char is about to reach > 0, this means some t char has lost
                // the reason why only t char could reach > 0 is because initially
                // they were populated in the map, but other chars arn't
                if (t_map[s[left]] == 0) {
                    --counter;
                }
                ++t_map[s[left]];
                ++left;
            }
        }

        if (best_length == numeric_limits<int>::max()) {
            return "";
        } else {
            return s.substr(best_head, best_length);
        }
    }
};

int main() {
    print_v(Solution().minWindow("ADOBECODEBANC", "ABC"));
    print_v(Solution().minWindow("a", "a"));
    print_v(Solution().minWindow("a", "aa"));
}
