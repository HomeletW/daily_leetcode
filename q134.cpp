/**
 * 134. Gas Station
 * https://leetcode.com/problems/gas-station
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int current_gas = 0;
        int step = 0, i = 0;
        while (i < gas.size() && step < gas.size()) {
            int pos = (i + step) % gas.size();
            current_gas += gas[pos];
            current_gas -= cost[pos];
            ++step;

            while (i < gas.size() && current_gas < 0) {
                // the current start point could not make it
                // try the next start point
                current_gas -= gas[i];
                current_gas += cost[i];
                ++i;
                --step;
            }
        }

        if (i < gas.size()) {
            return i;
        } else {
            return -1;
        }
    }

    int canCompleteCircuit_slow(vector<int> &gas, vector<int> &cost) {
        for (int i = 0; i < gas.size(); ++i) {
            if (canCompleteCircuit_from_i(i, gas, cost)) {
                return i;
            }
        }
        return -1;
    }

    bool canCompleteCircuit_from_i(int i, const vector<int> &gas, const vector<int> &cost) {
        int current_gas = 0;
        int step = 0;
        while (step < gas.size()) {
            int pos = (i + step) % gas.size();
            current_gas += gas[pos];
            current_gas -= cost[pos];
            if (current_gas < 0) {
                return false;
            }
            ++step;
        }
        return true;
    }
};

int main() {
    vector<int> gas1{1, 2, 3, 4, 5}, gas2{2, 3, 4};
    vector<int> cost1{3, 4, 5, 1, 2}, cost2{3, 4, 3};
    print_v(Solution().canCompleteCircuit(gas1, cost1));
    print_v(Solution().canCompleteCircuit(gas2, cost2));
}
