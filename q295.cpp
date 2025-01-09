/**
 * 295. Find Median from Data Stream
 * https://leetcode.com/problems/find-median-from-data-stream
 *
 * Date: 2025-01-08
 */

#include "my_util.hpp"

using namespace std;

class MedianFinder {
    int total_items;
    std::vector<int> before_items; // a max_heap
    std::vector<int> after_items; // a min_heap
public:
    MedianFinder() : total_items{0}, before_items{}, after_items{} {
    }

    void addNum(int num) {
        if (total_items == 0) {
            before_items.push_back(num);
        } else if (num > before_items.front()) {
            // should add to after_items
            after_items.push_back(num);
            std::push_heap(after_items.begin(), after_items.end(), std::greater<int>{});
            // check balancing
            if (after_items.size() > before_items.size()) {
                // transfer one to before_item
                std::pop_heap(after_items.begin(), after_items.end(), std::greater<int>{});
                before_items.push_back(after_items.back());
                after_items.erase(after_items.end() - 1);
                std::push_heap(before_items.begin(), before_items.end(), std::less<int>{});
            }
        } else {
            // should add to before_items
            before_items.push_back(num);
            std::push_heap(before_items.begin(), before_items.end(), std::less<int>{});
            // check balancing
            if (before_items.size() > after_items.size() + 1) {
                // transfer one to after_item
                std::pop_heap(before_items.begin(), before_items.end(), std::less<int>{});
                after_items.push_back(before_items.back());
                before_items.erase(before_items.end() - 1);
                std::push_heap(after_items.begin(), after_items.end(), std::greater<int>{});
            }
        }
        total_items += 1;
        print_v(before_items, after_items);
    }

    double findMedian() {
        if (total_items % 2 == 0) {
            return before_items.front() / 2. + after_items.front() / 2.;
        } else {
            return before_items.front();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder medianFinder{};
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    print_v(medianFinder.findMedian()); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    print_v(medianFinder.findMedian()); // return 2.0
}
