/**
 * 135. Candy
 * https://leetcode.com/problems/candy
 *
 * Date: 2024-07-26
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int num_candy = 0;
        int min_rating_index = -1;
        for (int i = 0; i < ratings.size(); ++i) {
            int rating = ratings[i];
            if (min_rating_index == -1) {
                // just started a new iteration
                if (rating != 0) {
                    min_rating_index = i;
                }
                num_candy += 1;  // at least one candy for each child
            } else if (rating < ratings[min_rating_index]) {
                // need to compensate for the previous children
                // that were using the previous min_rating
                num_candy += (i - min_rating_index);
                min_rating_index = i;
            } else {
                if (i == ratings.size()) {

                }
                int next_rating;
                if (i != ratings.size() && rating ) {
                } else {

                }
            }

            if (rating == 0) {
                // reset
            }
        }
    }
};

int main() {

}
