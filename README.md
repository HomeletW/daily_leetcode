# daily_leetcode

### my_print.hpp

A custom printing utility framework.

- Support printing of STL containers like vector, maps, sets, pairs, tuples.
- Support customized print by specializing struct UtilPrint<T>.
- Support printing of variables with the name and it's value through macros "print_v" and it's variants.
- Support printing of heading in the form of "====== text ======". Text support in headings supports anything that UtilPrint can support.
- Also support multi-line heading contents.

Example `print_v(a, b, vec_c);`   becomes
```
a: 1
b: 2
c: {hello, world}
```

### my_list_node.hpp

List Node generic definitions and my_print framework support. Defines a generic version of the Leetcode ListNode definitions.

Usage:
```c++
using ListNode = ListNode_generic<int>;
```

#### my_print integration

`print_v(node_head)` becomes:

```
node_head: 1 -> 2 -> 3 -> END
```

#### Construction utility

Support a macro definitions to quickly define a list, makes testing and debug a lot easier. 
_The list defined this way is allocated on stack_, so there is no need to manage the memory.

```c++
Define ListNode_generic<int> with head "a0" with the content.

    make_list_node(int, a, 5, 4, 3, 2);

Macro expands into:

    ListNode_generic<int> a3{2, &a4}, a2{3, &a3}, a1{4, &a2}, a0{5, &a1};
```

### my_tree_node.hpp

Tree Node generic definitions and my_print framework support.
Defines a generic version of the Leetcode TreeNode definitions.

```c++
using TreeNode = TreeNode_generic<int>;
```

#### my_print integration: 

`print_v(*tree_head);` becomes:

```
                                  ┌───┐
                                  │ 1 │
                                  └───┘
                             ┌──────┴───────┐
                           ┌───┐          ┌───┐
                           │ 2 │          │ 3 │
                           └───┘          └───┘
                       ┌─────┴          ┌───┴───┐
                     ┌───┐            ┌───┐   ┌───┐
                     │ 4 │            │ 6 │   │ 7 │
                     └───┘            └───┘   └───┘
               ┌───────┴────────┐               ┴───┐
             ┌───┐            ┌───┐              ┌────┐
             │ 8 │            │ 9 │              │ 15 │
             └───┘            └───┘              └────┘
        ┌──────┴──────┐                          ┌──┴───┐
     ┌────┐        ┌────┐                     ┌────┐ ┌────┐
     │ 16 │        │ 17 │                     │ 30 │ │ 31 │
     └────┘        └────┘                     └────┘ └────┘
     ┌──┴───┐      ┌──┴───┐
  ┌────┐ ┌────┐ ┌────┐ ┌────┐
  │ 32 │ │ 33 │ │ 34 │ │ 35 │
  └────┘ └────┘ └────┘ └────┘
```

#### Construction utility

Also support quick definitions of a TreeNode structure.

```
Usage:
    // The first argument is a sentinel value.
    // The second argument is a list of value representing the by-level traversal of the tree.
    // When values in the list equals to the sentinel, it is replaced by an empty tree node.
    // The returned value is an unique_ptr of the TreeNode_generic.
    auto small_tree = make_tree_node<int>(-1, {
                     1, 
              2,              3, 
        4,        -1,     6,      7, 
        -1, -1, -1, -1, 12, 13, -1, 15
    });
Turns into:
           ┌───┐
           │ 1 │
           └───┘
      ┌──────┴───────┐
    ┌───┐          ┌───┐
    │ 2 │          │ 3 │
    └───┘          └───┘
    ┌─┴         ┌────┴────┐
  ┌───┐       ┌───┐     ┌───┐
  │ 4 │       │ 6 │     │ 7 │
  └───┘       └───┘     └───┘
             ┌──┴───┐     ┴──┐
          ┌────┐ ┌────┐   ┌────┐
          │ 12 │ │ 13 │   │ 15 │
          └────┘ └────┘   └────┘
```
