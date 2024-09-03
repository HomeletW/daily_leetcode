/**
 * 767. Reorganize String
 * https://leetcode.com/problems/reorganize-string/
 */

#include "my_util.hpp"
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        /**
         * observations:
         * - if any particular letter appears more than half, then it impossible to reorganize
         */

        // count the appearance of each letter
        unordered_map<char, int> counts;
        vector<char> heap;
        for (char c : s)
        {
            if (!counts.contains(c))
            {
                heap.push_back(c);
            }
            ++counts[c];
        }

        // create a heap from that data
        auto cmp = [&](char a, char b){ return counts[a] < counts[b]; };
        make_heap(heap.begin(), heap.end(), cmp);

        // populate the result, each time pushing in heap order
        string result;

        // push the max first
        char resv = heap.front();
        pop_heap(heap.begin(), heap.end(), cmp);
        heap.pop_back();
        result.push_back(resv);
        --counts[resv];

        while (!heap.empty())
        {
            char max = heap.front();
            pop_heap(heap.begin(), heap.end(), cmp);
            if (counts[max] == 0)
            {
                heap.pop_back();
                continue;
            }
            result.push_back(max);
            --counts[max];

            // swap in the resv and the back, now the back becomes resv
            swap(heap.back(), resv);
            push_heap(heap.begin(), heap.end(), cmp);
        }

        if (counts[resv] != 0)
        {
            if (result.back() != resv)
            {
                result.push_back(resv);
                if (--counts[resv] != 0)
                {
                    return "";
                }
            }
            else
            {
                return "";
            }
        }
        return result;
    }
};

int main()
{
    cout << Solution().reorganizeString("aaab") << endl;
}