/**
 * 58. Length of Last Word
 * https://leetcode.com/problems/length-of-last-word
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastEnd = s.size();
        while (lastEnd > 0 && s[lastEnd - 1] == ' ') {
            --lastEnd;
        }

        if (lastEnd <= 0) {
            return s.size();  // all word
        }

        int lastStart = lastEnd - 1;
        while (lastStart >= 0 && s[lastStart] != ' ') {
            --lastStart;
        }

        if (lastStart < 0) {
            return lastEnd;
        }

        return lastEnd - lastStart - 1;
    }
};

int main() {
    print_v(Solution().lengthOfLastWord("hello this is a test"));
    print_v(Solution().lengthOfLastWord("hello this is a smalltest"));
    print_v(Solution().lengthOfLastWord("anothertest"));
    print_v(Solution().lengthOfLastWord("   fly me   to   the moon  "));
    print_v(Solution().lengthOfLastWord("a "));
}
