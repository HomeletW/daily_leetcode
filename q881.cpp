/**
 *
 */

#include "my_util.hpp"
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        // assume all people are under limit
        vector<int> sortedPeople{people.begin(), people.end()};
        std::sort(sortedPeople.begin(), sortedPeople.end());

        print_var(sortedPeople);
        // pair smallest and largest together
        int count = 0;
        size_t left = 0, right = sortedPeople.size() - 1;
        while (left <= right) {
            print_var(sep, left, right, count);
            if (left == right) {
                // put the last person in one boat
                ++count;
                break;
            }
            if (sortedPeople[left] + sortedPeople[right] <= limit) {
                // pair left and right into one boat
                ++left;
                --right;
            } else {
                // put the right into one boat
                --right;
            }
            ++count;
        }

        return count;
    }
};

int main() {
    std::vector<int> v1{1, 2, 3, 1};
    std::cout << Solution().numRescueBoats(v1, 3) << "\n";
    print_var(v1);
}
