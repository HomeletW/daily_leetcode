/**
 * 89. Gray Code
 * https://leetcode.com/problems/gray-code/description/
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{};
        grayCode_rec(n, res);
        return res;
    }

    void grayCode_rec(int n, vector<int> &res) {
        if (n == 1) {
            res.push_back(0b0);
            res.push_back(0b1);
            return;
        } else {
            grayCode_rec(n - 1, res);
            // appending in reverse,
            int nthbit = 1 << (n - 1);
            for (int i = res.size() - 1; i >= 0; --i) {
                res.push_back(res[i] | nthbit);
            }
        }
    }
};

vector<string> toBinary(const vector<int> &vec) {
    vector<string> ret;
    for (int i = 0; i < vec.size(); ++i) {
        std::stringstream ss;
        ss << "0b" << std::bitset<8>(vec[i]);
        ret.emplace_back(ss.str());
    }
    return ret;
}

int main() {
    auto res1 = Solution().grayCode(2);
    auto res2 = Solution().grayCode(5);
    print_line(toBinary(res1));
    print_line(toBinary(res2));
}
