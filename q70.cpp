/**
 * 70. Climbing Stairs
 * https://leetcode.com/problems/climbing-stairs
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // DP approach
        vector<int> mem(n + 1, 0);

        mem[0] = 1;
        mem[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            // basically a fib seq
            mem[i] = mem[i - 1] + mem[i - 2];
        }

        print_vl(sep, mem);

        return mem.back();
    }
};

int main() {
    print_line(Solution().climbStairs(2));
    print_line(Solution().climbStairs(3));
    print_line(Solution().climbStairs(45));
}
