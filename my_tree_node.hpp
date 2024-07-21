/**
 * Tree Node generic definitions and my_print framework support.
 *
 * Defines an generic version of the Leetcode TreeNode definitions.
 * Usage:
 *      using TreeNode = TreeNode_generic<int>;
 *
 * Supports printing of a tree structure, to ease the debug process.
 *      print_v(*tree_head);
 * Turns into:
 *                                  ┌───┐
 *                                  │ 1 │
 *                                  └───┘
 *                             ┌──────┴───────┐
 *                           ┌───┐          ┌───┐
 *                           │ 2 │          │ 3 │
 *                           └───┘          └───┘
 *                       ┌─────┴          ┌───┴───┐
 *                     ┌───┐            ┌───┐   ┌───┐
 *                     │ 4 │            │ 6 │   │ 7 │
 *                     └───┘            └───┘   └───┘
 *               ┌───────┴────────┐               ┴───┐
 *             ┌───┐            ┌───┐              ┌────┐
 *             │ 8 │            │ 9 │              │ 15 │
 *             └───┘            └───┘              └────┘
 *        ┌──────┴──────┐                          ┌──┴───┐
 *     ┌────┐        ┌────┐                     ┌────┐ ┌────┐
 *     │ 16 │        │ 17 │                     │ 30 │ │ 31 │
 *     └────┘        └────┘                     └────┘ └────┘
 *     ┌──┴───┐      ┌──┴───┐
 *  ┌────┐ ┌────┐ ┌────┐ ┌────┐
 *  │ 32 │ │ 33 │ │ 34 │ │ 35 │
 *  └────┘ └────┘ └────┘ └────┘
 *
 * Another example:
 *                                     ┌────────────┐
 *                                     │ 1111111111 │
 *                                     │ 222222     │
 *                                     │ 333333     │
 *                                     │ 4445       │
 *                                     └────────────┘
 *                          ┌─────────────────┴─────────────────┐
 *                      ┌──────┐                           ┌────────┐
 *                      │ 2222 │                           │ 333    │
 *                      │ 4124 │                           │ 512314 │
 *                      └──────┘                           │ 14124  │
 *                                                         │ 51251  │
 *                                                         │ 5123   │
 *                                                         └────────┘
 *              ┌───────────┴────────────┐                  ┌───┴───┐
 *  ┌──────────────────────┐ ┌───────────────────────┐ ┌────────┐ ┌───┐
 *  │                      │ │                       │ │ 6      │ │ 7 │
 *  │        {3, 21, 2001} │ │        {10, 28, 2000} │ │        │ └───┘
 *  │  index  0  1   2     │ │  index  0   1   2     │ │        │
 *  └──────────────────────┘ └───────────────────────┘ │ 123123 │
 *                                                     └────────┘
 *
 *  There are a lot of ways to customize the looks of the tree, by using a custom PrintConfig, the above variant
 *  prints out a "boxed" version of the tree, and the boxing char are using wchar_t.
 *  There might be some fiddle around to get wchar_t to properly print, checkout util_test.cpp
 *  for examples.
 *
 *  You may also prints out the tree without wide chars, or without boxing entirely.
 *
 *              +-----+
 *              | 100 |
 *              +-----+
 *         /-------+-------\
 *      +-----+         +-----+
 *      | 200 |         | 300 |
 *      +-----+         +-----+
 *     /---+---\       /---+---\
 *  +-----+ +-----+ +-----+ +-----+
 *  | 400 | | 500 | | 600 | | 700 |
 *  +-----+ +-----+ +-----+ +-----+
 *
 *        100
 *     /---+---\
 *    200     300
 *   /-+-\   /-+-\
 *  400 500 600 700
 *
 *  Also support quick definitions of a TreeNode structure.
 *  Usage:
 *      // The first argument is a sentinel value.
 *      // The second argument is a list of value representing the by-level traversal of the tree.
 *      // When values in the list equals to the sentinel, it is replaced by an empty tree node.
 *      // The returned value is an unique_ptr of the TreeNode_generic.
 *      auto small_tree = make_tree_node<int>(-1, {1, 2, 3, 4, -1, 6, 7, -1, -1, -1, -1, 12, -1, -1, 15});
 *  Turns into:
 *           ┌───┐
 *           │ 1 │
 *           └───┘
 *      ┌──────┴───────┐
 *    ┌───┐          ┌───┐
 *    │ 2 │          │ 3 │
 *    └───┘          └───┘
 *    ┌─┴         ┌────┴────┐
 *  ┌───┐       ┌───┐     ┌───┐
 *  │ 4 │       │ 6 │     │ 7 │
 *  └───┘       └───┘     └───┘
 *             ┌──┴───┐     ┴──┐
 *          ┌────┐ ┌────┐   ┌────┐
 *          │ 12 │ │ 13 │   │ 15 │
 *          └────┘ └────┘   └────┘
 *
 *
 */
#pragma once

#include "my_util.hpp"

template<typename T>
struct TreeNode_generic {
    T val;
    TreeNode_generic<T> *left;
    TreeNode_generic<T> *right;

    TreeNode_generic() : val{}, left(nullptr), right(nullptr) {}

    TreeNode_generic(T x) : val(std::move(x)), left(nullptr), right(nullptr) {}

    TreeNode_generic(T x, TreeNode_generic<T> *left, TreeNode_generic<T> *right) : val(std::move(x)), left(left),
                                                                                   right(right) {}
};

struct DefaultTreeNodePrettyPrintConfig {
    static constexpr int pad_left = 1;
    static constexpr int pad_right = 1;
    static constexpr int pad_mid = 1;
    static constexpr int min_str_length = 1;

    static constexpr char left_pad_char = ' ';
    static constexpr char right_pad_char = ' ';
    static constexpr char left_internal_pad_char = ' ';
    static constexpr char right_internal_pad_char = ' ';
    static constexpr char left_connection_char = '/';
    static constexpr char center_connection_char = '+';
    static constexpr char right_connection_char = '\\';
    static constexpr char connection_char = '-';
};

struct BoxedTreeNodePrettyPrintConfig {
    static constexpr int pad_left = 1;
    static constexpr int pad_right = 1;
    static constexpr int pad_mid = 1;
    static constexpr int min_str_length = 1;

    static constexpr wchar_t left_pad_char = ' ';
    static constexpr wchar_t right_pad_char = ' ';
    static constexpr wchar_t left_internal_pad_char = ' ';
    static constexpr wchar_t right_internal_pad_char = ' ';
    static constexpr wchar_t left_connection_char = BoxDrawingWideChar::top_left;
    static constexpr wchar_t center_connection_char = BoxDrawingWideChar::horizontal_top;
    static constexpr wchar_t right_connection_char = BoxDrawingWideChar::top_right;
    static constexpr wchar_t connection_char = BoxDrawingWideChar::top;
};

template<typename T, typename CharT, typename PrintConfig>
struct TreeNode_prettyPrint {
    const TreeNode_generic<T> *node;
    const PrintConfig *config;
    TreeNode_prettyPrint *parentNode, *leftNode, *rightNode;
    std::basic_string<CharT> str;
    int strLength, strHeight;   // number of characters the str renders horizontally and vertically
    int leftPad, rightPad;      // for filling incomplete tree
    int length;                 // prints exactly length amount of character (without padding)
    int anchor;                 // marks the center of this node, where the connection would point to
    int depth;                  // metadata marks the depth of the current node

    TreeNode_prettyPrint(const TreeNode_generic<T> *root, const PrintConfig *config, bool boxed = true)
            : TreeNode_prettyPrint{root, config, nullptr, boxed, 0} {
    }

    ~TreeNode_prettyPrint() {
        delete leftNode;
        delete rightNode;
    }

    void setLength() {
        _setLength(length);
    }

    void setPadding() {
        _setPadding(config->pad_left, config->pad_right);
    }

    void render(std::basic_ostream<CharT> &os) {
        std::deque<TreeNode_prettyPrint *> queue{this};
        std::vector<size_t> strPos;
        while (!queue.empty()) {
            os << '\n';
            int numThisDepth = queue.size();

            // first pass initialize strPos, and collect how many lines we need
            int heightThisDepth = 1;
            strPos.resize(numThisDepth, 0);
            for (int i = 0; i < numThisDepth; ++i) {
                strPos[i] = queue[i]->_render_str(os, std::string_view::npos);
                heightThisDepth = std::max(heightThisDepth, queue[i]->strHeight);
            }
            os << '\n';

            // print the remaining lines
            for (int h = 1; h < heightThisDepth; ++h) {
                for (int i = 0; i < numThisDepth; ++i) {
                    strPos[i] = queue[i]->_render_str(os, strPos[i]);
                }
                os << '\n';
            }

            // print connections
            for (int i = 0; i < numThisDepth; ++i) {
                queue[i]->_render_connection(os);
            }

            // move to next depth
            for (int i = 0; i < numThisDepth; ++i) {
                auto top = queue.front();
                if (top->leftNode != nullptr) {
                    queue.push_back(top->leftNode);
                }
                if (top->rightNode != nullptr) {
                    queue.push_back(top->rightNode);
                }
                queue.pop_front();
            }
        }
    }

private:
    // *****************************************************************************************************************
    // Private APIs
    // *****************************************************************************************************************
    TreeNode_prettyPrint(const TreeNode_generic<T> *node,
                         const PrintConfig *config,
                         TreeNode_prettyPrint *parentNode,
                         bool boxed,
                         int depth)
            : node{node}, config{config}, parentNode{parentNode}, leftPad{0}, rightPad{0}, anchor{0}, depth{depth} {
        assert(node != nullptr);
        std::string res = print_to_string(node->val);
        if (boxed) {
            if constexpr (std::is_same_v<CharT, char>) {
                str = make_boxed<CharT, BoxDrawingChar, true, false, false>(res);
            } else {
                str = make_boxed<CharT, BoxDrawingWideChar, true, false, false>(
                        std::basic_string<CharT>(res.begin(), res.end()));
            }
        } else {
            if constexpr (std::is_same_v<CharT, char>) {
                str = res;
            } else {
                str = std::basic_string<CharT>(res.begin(), res.end());
            }
        }

        // the height of the node is one plus how many newlines there are
        strHeight = std::count(str.begin(), str.end(), '\n') + 1;

        // the length of the node is the maximum length of all lines
        strLength = std::max(config->min_str_length, (int) get_max_line_length<CharT>(str));

        if (node->left == nullptr && node->right == nullptr) {
            length = strLength;
            leftNode = rightNode = nullptr;
        } else {
            // initial setup of length, later length will be recalculated
            length = 0;
            if (node->left != nullptr) {
                leftNode = new TreeNode_prettyPrint{node->left, config, this, boxed, depth + 1};
                length += leftNode->length;
            } else {
                leftNode = nullptr;
                length += config->min_str_length;
            }
            length += config->pad_mid;
            if (node->right != nullptr) {
                rightNode = new TreeNode_prettyPrint{node->right, config, this, boxed, depth + 1};
                length += rightNode->length;
            } else {
                rightNode = nullptr;
                length += config->min_str_length;
            }
            length = std::max(length, strLength);
        }
    }

    void _setLength(int totalLength) {
        assert(totalLength >= strLength);
        length = totalLength;

        if (leftNode != nullptr && rightNode != nullptr) {
            int additionalPad = totalLength - leftNode->length - config->pad_mid - rightNode->length;
            int left_totalLength = leftNode->length + additionalPad / 2;
            int right_totalLength = rightNode->length + (additionalPad - additionalPad / 2);
            leftNode->_setLength(left_totalLength);
            rightNode->_setLength(right_totalLength);
            anchor = std::max((getLeftAnchor() + getRightAnchor()) / 2, strLength / 2);
        } else if (leftNode != nullptr) {
            int left_totalLength = totalLength - config->pad_mid - config->min_str_length;
            leftNode->_setLength(left_totalLength);
            int rightAnchor = left_totalLength + config->pad_mid + (config->min_str_length) / 2;
            anchor = std::max((getLeftAnchor() + rightAnchor) / 2, strLength / 2);
        } else if (rightNode != nullptr) {
            int right_totalLength = totalLength - config->pad_mid - config->min_str_length;
            rightNode->_setLength(right_totalLength);
            int leftAnchor = (config->min_str_length) / 2;
            anchor = std::max((leftAnchor + getRightAnchor()) / 2, strLength / 2);
        } else {
            anchor = std::max(totalLength / 2, strLength / 2);
        }

        assert(anchor >= strLength / 2);
        assert(anchor < totalLength);
    }

    void _setPadding(int left, int right) {
        leftPad += left;
        rightPad += right;

        if (leftNode != nullptr && rightNode != nullptr) {
            leftNode->_setPadding(left, config->pad_mid);
            rightNode->_setPadding(0, right);
        } else if (leftNode != nullptr) {
            leftNode->_setPadding(left, right + config->pad_mid + config->min_str_length);
        } else if (rightNode != nullptr) {
            rightNode->_setPadding(left + config->pad_mid + config->min_str_length, right);
        } else {
            // reached a leaf node, need to transfer everything as padding
            // find the nearest left node in the next depth
            TreeNode_prettyPrint *targetNode = getNearestNodeInLeftWithDepth(1);
            if (targetNode != nullptr) {
                assert(targetNode->depth == depth + 1);
                int targetDepth = depth + 1;
                targetNode->transferLengthAsLeftPadding(leftPad + length + rightPad, targetDepth);
            } else {
                targetNode = getNearestNodeInRightWithDepth(1);
                if (targetNode != nullptr) {
                    assert(targetNode->depth == depth + 1);
                    int targetDepth = depth + 1;
                    targetNode->transferLengthAsRightPadding(leftPad + length + rightPad, targetDepth);
                } else {
//                    print_line("could not transfer length of a leaf node, depth = ", depth, " (ignore if == maxDepth)");
                }
            }
        }
    }

    size_t _render_str(std::basic_ostream<CharT> &os, size_t lastStrPos) {
        std::basic_string_view<CharT> strThisLine = get_next_line<CharT>(str, lastStrPos);
        int intPadLeft = anchor - (strLength / 2), intPadRight = length - intPadLeft - strLength;
        int strPadLeft = (strLength - strThisLine.size()) / 2,
                strPadRight = strLength - strPadLeft - strThisLine.size();
        for (int i = 0; i < leftPad; ++i) os << config->left_pad_char;
        for (int i = 0; i < intPadLeft; ++i) os << config->left_internal_pad_char;
        for (int i = 0; i < strPadLeft; ++i) os << ' ';
        os << strThisLine;
        for (int i = 0; i < strPadRight; ++i) os << ' ';
        for (int i = 0; i < intPadRight; ++i) os << config->right_internal_pad_char;
        for (int i = 0; i < rightPad; ++i) os << config->right_pad_char;
        return lastStrPos;
    }

    void _render_connection(std::basic_ostream<CharT> &os) {
        for (int i = 0; i < leftPad; ++i) os << config->left_pad_char;
        if (leftNode != nullptr && rightNode != nullptr) {
            int leftAnchor = getLeftAnchor();
            int rightAnchor = getRightAnchor();
            int i = 0;
            for (; i < leftAnchor; ++i) os << config->left_internal_pad_char;
            for (; i <= rightAnchor; ++i) {
                if (i == leftAnchor) {
                    os << config->left_connection_char;
                } else if (i == rightAnchor) {
                    os << config->right_connection_char;
                } else if (i == anchor) {
                    os << config->center_connection_char;
                } else {
                    os << config->connection_char;
                }
            }
            for (; i < length; ++i) os << config->right_internal_pad_char;
        } else if (leftNode != nullptr) {
            int leftAnchor = getLeftAnchor();
            int i = 0;
            for (; i < leftAnchor; ++i) os << config->left_internal_pad_char;
            for (; i <= anchor; ++i) {
                if (i == leftAnchor) {
                    os << config->left_connection_char;
                } else if (i == anchor) {
                    os << config->center_connection_char;
                } else {
                    os << config->connection_char;
                }
            }
            for (; i < length; ++i) os << config->right_internal_pad_char;
        } else if (rightNode != nullptr) {
            int rightAnchor = getRightAnchor();
            int i = 0;
            for (; i < anchor; ++i) os << config->left_internal_pad_char;
            for (; i <= rightAnchor; ++i) {
                if (i == rightAnchor) {
                    os << config->right_connection_char;
                } else if (i == anchor) {
                    os << config->center_connection_char;
                } else {
                    os << config->connection_char;
                }
            }
            for (; i < length; ++i) os << config->right_internal_pad_char;
        } else {
            int i = 0;
            for (; i < length / 2; ++i) os << config->left_internal_pad_char;
            for (; i < length; ++i) os << config->right_internal_pad_char;
        }
        for (int i = 0; i < rightPad; ++i) os << config->right_pad_char;
    }

    int getLeftAnchor() const {
        if (leftNode == nullptr) {
            assert(false && "invalid argument");
            return -1;
        } else {
            return leftNode->anchor;
        }
    }

    int getRightAnchor() const {
        if (rightNode == nullptr) {
            assert(false && "invalid argument");
            return -1;
        } else if (leftNode == nullptr) {
            return config->min_str_length + config->pad_mid + rightNode->anchor;
        } else {
            return leftNode->length + config->pad_mid + rightNode->anchor;
        }
    }

    TreeNode_prettyPrint *getNearestNodeInLeftWithDepth(int depthDiff) {
        if (depthDiff == 0) {
            return this;
        } else {
            if (leftNode != nullptr) {
                // goes left if possible
                TreeNode_prettyPrint *result = leftNode->getNearestNodeInLeftWithDepth(depthDiff - 1);
                if (result != nullptr) {
                    return result;
                }
            }

            if (rightNode != nullptr) {
                // this works because the begin node is always a leaf node
                TreeNode_prettyPrint *result = rightNode->getNearestNodeInLeftWithDepth(depthDiff - 1);
                if (result != nullptr) {
                    return result;
                }
            }

            // couldn't find in this subtree, try recurse to parent
            // find the first ancestor that is not a right child and has a right node
            TreeNode_prettyPrint *parent = this, *curr;
            do {
                curr = parent;
                parent = parent->parentNode;
                ++depthDiff;
            } while (parent != nullptr && (parent->rightNode == curr || parent->rightNode == nullptr));
            if (parent == nullptr) {
                return nullptr;
            } else {
                // going down one level, so -1
                return parent->rightNode->getNearestNodeInLeftWithDepth(depthDiff - 1);
            }
        }
    }

    TreeNode_prettyPrint *getNearestNodeInRightWithDepth(int depthDiff) {
        if (depthDiff == 0) {
            return this;
        } else {
            if (rightNode != nullptr) {
                // goes right if possible
                TreeNode_prettyPrint *result = rightNode->getNearestNodeInRightWithDepth(depthDiff - 1);
                if (result != nullptr) {
                    return result;
                }
            }

            if (leftNode != nullptr) {
                // this works because the begin node is always a leaf node
                TreeNode_prettyPrint *result = leftNode->getNearestNodeInRightWithDepth(depthDiff - 1);
                if (result != nullptr) {
                    return result;
                }
            }

            // couldn't find in this subtree, try recurse to parent
            // find the first ancestor that is not a right child and has a right node
            TreeNode_prettyPrint *parent = this, *curr;
            do {
                curr = parent;
                parent = parent->parentNode;
                ++depthDiff;
            } while (parent != nullptr && (parent->leftNode == curr || parent->leftNode == nullptr));
            if (parent == nullptr) {
                return nullptr;
            } else {
                // going down one level, so -1
                return parent->leftNode->getNearestNodeInRightWithDepth(depthDiff - 1);
            }
        }
    }

    void transferLengthAsLeftPadding(int transferLength, int &targetDepth) {
        if (depth == targetDepth) {
            ++targetDepth;
            leftPad += transferLength;
        }
        if (leftNode != nullptr) {
            leftNode->transferLengthAsLeftPadding(transferLength, targetDepth);
        }
        if (rightNode != nullptr) {
            rightNode->transferLengthAsLeftPadding(transferLength, targetDepth);
        }
    }

    void transferLengthAsRightPadding(int transferLength, int &targetDepth) {
        if (depth == targetDepth) {
            ++targetDepth;
            rightPad += transferLength;
        }
        if (rightNode != nullptr) {
            rightNode->transferLengthAsRightPadding(transferLength, targetDepth);
        }
        if (leftNode != nullptr) {
            leftNode->transferLengthAsRightPadding(transferLength, targetDepth);
        }
    }
};

template<typename PrintConfig, typename T, typename CharT>
static std::basic_ostream<CharT> &pretty_print_tree(
        std::basic_ostream<CharT> &os,
        const TreeNode_generic<T> *root,
        PrintConfig config = {}, bool boxed = true) {
    if (root == nullptr) {
        os << '\n';
        return os;
    }

    // construct PrintNode
    TreeNode_prettyPrint<T, CharT, PrintConfig> rootPrint{root, &config, boxed};
    rootPrint.setLength();
    rootPrint.setPadding();
    rootPrint.render(os);

    return os;
}

template<typename T>
static void free_tree_node(TreeNode_generic<T> *root) {
    if (root != nullptr) {
        free_tree_node(root->left);
        free_tree_node(root->right);
        delete root;
    }
}

template<typename T>
static std::unique_ptr<TreeNode_generic<T>, decltype(&free_tree_node<T>)> make_tree_node(
        const T &sentinel, const std::vector<T> &values) {
    if (empty(values)) {
        return {nullptr, &free_tree_node<T>};
    }

    std::vector<TreeNode_generic<T> *> stack;
    stack.resize(values.size(), nullptr);
    for (int i = values.size() - 1; i >= 0; --i) {
        if (values[i] != sentinel) {
            stack[i] = new TreeNode_generic<T>{values[i]};
            int leftIndex = i * 2 + 1, rightIndex = i * 2 + 2;
            if (leftIndex < values.size()) {
                stack[i]->left = stack[leftIndex];
            }
            if (rightIndex < values.size()) {
                stack[i]->right = stack[rightIndex];
            }
        } else {
            stack[i] = nullptr;
        }
    }

    return {stack.front(), &free_tree_node<T>};
}

template<typename T>
struct UtilPrint<TreeNode_generic<T>> {
    static std::ostream &my_print(std::ostream &os, const TreeNode_generic<T> &v) {
        return pretty_print_tree<DefaultTreeNodePrettyPrintConfig, T, char>(os, std::addressof(v));
    }
};
