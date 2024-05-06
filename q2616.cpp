#include <vector>
#include "my_util.hpp"
#include "iostream"

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        std::sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums[0];
        while (low < high)
        {
//            int mid = low + (high - low) / 2;
            int mid = ((unsigned)high + (unsigned)low) >> 1;
            if (canFormPairs(nums, mid, p))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

private:
    bool canFormPairs(vector<int>& nums, int max, int numPairs)
    {
        auto curr = nums.begin(), next = nums.begin() + 1;
        while (next != nums.end())
        {
            if (std::abs(*curr - *next) <= max)
            {
                --numPairs;
                ++next;
                if (next == nums.end())
                {
                    break;
                }
                curr = next;
                ++next;
            }
            else{
                curr = next;
                ++next;
            }
        }
        return numPairs <= 0;
    }
};

int main()
{
    vector<int> nums{10,1,2,7,1,3};
    cout << boolalpha << Solution().minimizeMax(nums, 2) << endl;
}