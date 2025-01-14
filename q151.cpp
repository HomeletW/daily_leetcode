/**
 * 151. Reverse Words in a String
 * https://leetcode.com/problems/reverse-words-in-a-string
 *
 * Date: 2025-01-11
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string_view> words;
        size_t total_length = 0;
        size_t i = s.find_first_not_of(' ');
        while (i != string::npos) {
            size_t word_start = i, word_end = s.find_first_of(' ', word_start);
            size_t word_length;
            if (word_end != string::npos) {
                word_length = word_end - word_start;
            } else {
                word_length = s.size() - word_start;
            }
            total_length += word_length;
            words.emplace_back(s.c_str() + word_start, word_length);
            i = s.find_first_not_of(' ', word_end);
        }
//        print_v(words, total_length);
        if (words.size() == 0) {
            return "";
        }
        string buf(total_length + words.size() - 1, ' ');
        size_t buf_pos = 0;
//        for (string_view word: std::ranges::views::reverse(words)) {
        for (int i = words.size() - 1; i >= 0; --i) {
            string_view word = words[i];
            buf.replace(buf_pos, word.size(), word);
            buf_pos += word.size() + 1;
        }
        return buf;
    }
};

int main() {
    print_v(Solution().reverseWords("the sky is blue"));
    print_v(Solution().reverseWords("  hello world  "));
    print_v(Solution().reverseWords("a good   example"));
    print_v(Solution().reverseWords(""));
}
