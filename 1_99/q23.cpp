/**
 * 23. Merge k Sorted Lists
 * https://leetcode.com/problems/merge-k-sorted-lists
 */

#include "my_util.hpp"
#include "my_preprocessor_util.hpp"
#include "my_list_node.hpp"

using namespace std;

using ListNode = ListNode_generic<int>;

template<>
struct UtilPrint<ListNode *> {
    static std::ostream &my_print(std::ostream &os, ListNode *const &v) {
        if (v != nullptr) {
            os << *v;
        } else {
            os << "nullptr";
        }
        return os;
    }
};

class Solution {
public:
    struct ListNodeCompare {
        bool operator()(ListNode *const &l1, ListNode *const &l2) const {
            return l1->val > l2->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }

        // use a heap
        vector<ListNode *> heap;
        for (ListNode *head: lists) {
            if (head != nullptr)
                heap.push_back(head);
        }

        print_v(heap);
        std::make_heap(heap.begin(), heap.end(), ListNodeCompare{});
        print_v(heap);

        ListNode dummyHead{-1, nullptr}, *curr = &dummyHead;
        while (!heap.empty()) {
            ListNode *newNode = new ListNode;
            curr->next = newNode;
            curr = newNode;
            std::pop_heap(heap.begin(), heap.end(), ListNodeCompare{});
            newNode->val = heap.back()->val;
            if (heap.back()->next == nullptr) {
                heap.pop_back();
            } else {
                heap.back() = heap.back()->next;
                std::push_heap(heap.begin(), heap.end(), ListNodeCompare{});
            }
        }

        return dummyHead.next;
    }
};

void test1() {
    //    [1,4,5],[1,3,4],[2,6]
    make_list_node(int, a, 1, 4, 5);
    make_list_node(int, b, 1, 3, 4);
    make_list_node(int, c, 2, 6);
    print_var(a0, b0, c0);
    vector<ListNode *> lists{&a0, &b0, &c0};
    auto res = Solution().mergeKLists(lists);
    print_var(*res);
}

void test2() {
    vector<ListNode *> lists{};
    auto res = Solution().mergeKLists(lists);
    print_var(res);
}

int main() {
    test1();
    test2();
}
