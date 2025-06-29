// segment_tree_lazy.cpp
// Segment Tree with Lazy Propagation for range updates

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int seg[4 * N], lazy[4 * N], a[N];

// Build the tree
void build(int l, int r, int idx) {
    if (l == r) {
        seg[idx] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * idx);
    build(mid + 1, r, 2 * idx + 1);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

// Push down lazy updates
void push(int l, int r, int idx) {
    if (lazy[idx] != 0) {
        seg[idx] += (r - l + 1) * lazy[idx];
        if (l != r) {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

// Range update: add val to [ql, qr]
void update(int l, int r, int idx, int ql, int qr, int val) {
    push(l, r, idx);

    if (qr < l || ql > r)
        return;
    if (ql <= l && r <= qr) {
        lazy[idx] += val;
        push(l, r, idx);
        return;
    }

    int mid = (l + r) / 2;
    update(l, mid, 2 * idx, ql, qr, val);
    update(mid + 1, r, 2 * idx + 1, ql, qr, val);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

// Range query: sum in [ql, qr]
int query(int l, int r, int idx, int ql, int qr) {
    push(l, r, idx);

    if (qr < l || ql > r)
        return 0;
    if (ql <= l && r <= qr)
        return seg[idx];

    int mid = (l + r) / 2;
    return query(l, mid, 2 * idx, ql, qr) + query(mid + 1, r, 2 * idx + 1, ql, qr);
}

int main() {
    int n = 6;
    int arr[] = {1, 3, 5, 7, 9, 11};
    for (int i = 0; i < n; ++i)
        a[i] = arr[i];

    build(0, n - 1, 1);

    cout << "Initial sum of [1, 3]: " << query(0, n - 1, 1, 1, 3) << endl;

    update(0, n - 1, 1, 1, 3, 10);  // add 10 to range [1, 3]

    cout << "After range update, sum of [1, 3]: " << query(0, n - 1, 1, 1, 3) << endl;

    return 0;
}
