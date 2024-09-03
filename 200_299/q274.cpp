/**
 * 274. H-Index
 * https://leetcode.com/problems/h-index
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        if (citations.empty()) {
            return 0;
        }
        std::sort(citations.begin(), citations.end());
        print_var(citations);
        int res = 0;
        for (int i = citations.size() - 1; i >= 0; --i) {
            int j = citations.size() - i;
            if (citations[i] >= j) {  // citation need to be larger than the number of paper
                res = max(res, j);
            }
        }
        return res;
    }
};

int main() {
//    vector<int> citations{3, 0, 6, 1, 5};
//    vector<int> citations{1, 3, 1};
    vector<int> citations{100};
    print_line(sep, Solution().hIndex(citations));
}
