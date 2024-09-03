/**
 * 3. Longest Substring Without Repeating Characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        int longest = 0;
        int left = 0, right = 0;
        unordered_map<char, int> idx_map; // char -> last seen index
        while (right < s.size()) {
            char c = s[right];
            auto iter = idx_map.find(c);
            if (iter != idx_map.end()) {
                if (iter->second >= left) {
                    // already seen this char, unique substring has ended
                    // start new from that index onwards
                    left = iter->second + 1;
                }
                iter->second = right;
            } else {
                idx_map[c] = right;
            }
            longest = max(longest, right - left + 1);
            ++right;
        }

        return longest;
    }
};

int main() {
    print_v(Solution().lengthOfLongestSubstring("abcabcbb"));  // 3
    print_v(Solution().lengthOfLongestSubstring("bbbbb"));  // 1
    print_v(Solution().lengthOfLongestSubstring("pwwkew")); // 3
    print_v(Solution().lengthOfLongestSubstring("")); // 0
    print_v(Solution().lengthOfLongestSubstring("ckilbkd")); // 5
    print_v(Solution().lengthOfLongestSubstring("jxdlnaaij")); // 6
    print_v(Solution().lengthOfLongestSubstring("blqsearxxxbiwqa")); // 8
    print_v(Solution().lengthOfLongestSubstring("tmmzuxt")); // 5
}
