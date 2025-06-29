# Segment Tree

A **Segment Tree** is a binary tree used for efficient range queries and updates on arrays.

This folder contains:
- Basic Segment Tree implementation
- Segment Tree with Lazy Propagation (for range updates)

---

## Files

| File                        | Description                                       |
|----------------------------|---------------------------------------------------|
| `segment_tree.cpp`         | Point updates and range sum queries               |
| `segment_tree_lazy.cpp`    | Supports range updates using lazy propagation     |

---

## Supported Operations

### `segment_tree.cpp`
- Build from array
- Point update
- Range sum query

### `segment_tree_lazy.cpp`
- Build from array
- **Range update**
- Range sum query with **lazy propagation**

---

## Time Complexity

| Operation         | Time       |
|------------------|------------|
| Build Tree       | O(n)       |
| Point Update     | O(log n)   |
| Range Query      | O(log n)   |
| Range Update     | O(log n) *(with lazy)* |

---

## Sample Usage (from `main()`)

```cpp
int arr[] = {1, 3, 5, 7, 9, 11};
build(0, 5, 1);          // Builds segment tree
cout << query(1, 3, 1);  // Queries sum in range [1, 3]
update(1, 10, 1, 3, 0);  // Range update in segment_tree_lazy.cpp
