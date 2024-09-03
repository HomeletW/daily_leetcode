/**
 * 380. Insert Delete GetRandom O(1)
 * https://leetcode.com/problems/insert-delete-getrandom-o1
 */

#include "my_util.hpp"

using namespace std;

class RandomizedSet {
public:
    // use a vector to support O(1) random
    vector<int> v_;
    unordered_map<int, size_t> s_;

    RandomizedSet() : s_{}, v_{} {}

    bool insert(int val) {
        // insert the index into the vector as the value.
        auto [iter, insertTookPlace] = s_.insert(make_pair(val, v_.size()));
        if (!insertTookPlace) {
            return false;
        } else {
            v_.push_back(val);
            return true;
        }
    }

    bool remove(int val) {
        auto iter = s_.find(val);
        if (iter == s_.end()) {
            return false;
        } else {
            // swap the value at back of the vector with the current.
            // make sure to change the pointer of the swapped key as well
            s_[v_.back()] = iter->second;
            v_[iter->second] = v_.back();
            v_.pop_back();
            // remove from the set
            s_.erase(iter);
            return true;
        }
    }

    int getRandom() {
        return v_.at(rand() % v_.size());
    }
};

void test_1() {
    RandomizedSet randomizedSet;
    print_v(randomizedSet.insert(1)); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    print_v(randomizedSet.remove(2)); // Returns false as 2 does not exist in the set.
    print_v(randomizedSet.insert(2)); // Inserts 2 to the set, returns true. Set now contains [1,2].
    print_v(randomizedSet.getRandom()); // getRandom() should return either 1 or 2 randomly.
    print_v(randomizedSet.remove(1)); // Removes 1 from the set, returns true. Set now contains [2].
    print_v(randomizedSet.insert(2)); // 2 was already in the set, so return false.
    print_v(randomizedSet.getRandom()); // Since 2 is the only number in the set, getRandom() will always return 2.
}

void test_2() {
    RandomizedSet randomizedSet;
    print_v(randomizedSet.insert(0));
    print_v(randomizedSet.insert(1));
    print_v(randomizedSet.remove(0));
    print_v(randomizedSet.insert(2));
    print_v(randomizedSet.remove(1));
    print_v(randomizedSet.v_);
    print_v(randomizedSet.s_);
    print_v(randomizedSet.getRandom());
}

int main() {
    test_1();
    print_line(sep);
    test_2();
}
