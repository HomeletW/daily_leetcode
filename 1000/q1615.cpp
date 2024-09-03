/**
 * 1615. Maximal Network Rank
 *
 * https://leetcode.com/problems/maximal-network-rank/description/
 */

#include "my_util.hpp"
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // find the candidates info
        vector<int> degrees(n);
        for (auto & road : roads)
        {
            ++degrees[road[0]];
            ++degrees[road[1]];
        }

        // find the maximum and the second max
        int max_idx = 0, second_max_idx = -1;
        for (int i = 1; i < n; ++i)
        {
            if (degrees[i] >= degrees[max_idx])
            {
                second_max_idx = max_idx;
                max_idx = i;
            }
            else if (second_max_idx == -1 || degrees[i] >= degrees[second_max_idx])
            {
                second_max_idx = i;
            }
        }

        int max_deg = degrees[max_idx], second_max_deg = degrees[second_max_idx];

        // the idea is:
        // - if there is a connection from max -> second_max, the
        //   answer would be deg[max] + deg[second_max] - 1
        // - otherwise, the answer would be deg[max] + deg[second_max]
        //
        // this works because the maximum pair should always contain both
        // the max and second_max

        if (max_deg == second_max_deg)
        {
            // multiple candidates with the same max degree
            // if any pairs of max_deg that doesn't have a connection then no need to -1

            // count the number of candidates with max_deg
            int candidates_count = 0;
            for (int i = 0; i < n; ++i)
            {
                if (degrees[i] == max_deg)
                {
                    ++candidates_count;
                }
            }

            // count the number of connections between pairs of max_deg
            int connection_count = 0;
            for (auto & road : roads)
            {
                int a = road[0], b = road[1];
                if (degrees[a] == max_deg && degrees[b] == max_deg)
                {
                    ++connection_count;
                }
            }

            // the total combination of candidates would be n_choose_2 or n*(n-1)/2
            int total_combination = candidates_count * (candidates_count - 1) / 2;
            if (connection_count < total_combination)
            {
                // it means there are at least one pair that are not adjacent
                return max_deg + max_deg;
            }
            else {
                // all pairs are adjacent
                return max_deg + max_deg - 1;
            }
        }
        else
        {
            // one city with max degree, and potentially multiple cities with second max

            // count the number of second_max
            int candidates_count = 0;
            for (int i = 0; i < n; ++i)
            {
                if (degrees[i] == second_max_deg)
                {
                    ++candidates_count;
                }
            }

            // count the number of connections between max and second_max
            int connection_count = 0;
            for (auto& road : roads)
            {
                int a = road[0], b = road[1];
                // if any of the second_max are adjacent to max,
                if ((a == max_idx && degrees[b] == second_max_deg) || (b == max_idx && degrees[a] == second_max_deg))
                {
                    ++connection_count;
                }
            }

            if (connection_count < candidates_count)
            {
                // at least one pair that was not adjacent
                return max_deg + second_max_deg;
            }
            else
            {
                // all pairs are adjacent
                return max_deg + second_max_deg - 1;
            }
        }
    }
};

int main()
{
//    vector<vector<int>> roads{{0,1},{0,3},{1,2},{1,3}};
//    vector<vector<int>> roads{{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
//    vector<vector<int>> roads{{0,2}, {0, 1}};
    vector<vector<int>> roads{{4,6},{5,2},{3,5},{7,5},{7,6}};
    cout << Solution{}.maximalNetworkRank(8, roads);
}