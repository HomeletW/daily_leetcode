/**
 * 69. Sqrt(x)
 * https://leetcode.com/problems/sqrtx
 *
 * Date: 2024-09-03
 */

#include <math.h>
#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        // use binary search approach
        int left = 1, right = x;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;  // avoid overflow
            int val = x / mid;  // avoid overflow
//            print_vl(h2v(left, right), mid, val);
            if (val == mid) {
                return mid;
            } else if (val > mid) {
                left = mid;
            } else {
                right = mid;
            }
        }
//        print_vl(h2v(left, right));
        return left;
    }
};

int main() {
    print_v(Solution().mySqrt(4));
    print_v(Solution().mySqrt(8));
    print_v(Solution().mySqrt(132));
    for (int i = 1; i < 10000; ++i) {
        int v = Solution().mySqrt(i);
        int real_v = static_cast<int>(std::sqrt(i));
        if (v != real_v) {
            print_line("Error on ", i, ", returned ", v, ", should be ", real_v);
        }
    }
}
