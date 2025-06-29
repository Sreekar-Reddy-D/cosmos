// segment_tree.cpp
// Basic Segment Tree for range sum and point updates

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int seg[4 * N], a[N];

// Build the segment tree
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

// Point update: a[pos] += val
void update(int l, int r, int idx, int pos, int val) {
    if (l == r) {
        seg[idx] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(l, mid, 2 * idx, pos, val);
    else
        update(mid + 1, r, 2 * idx + 1, pos, val);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

// Query sum in range [ql, qr]
int query(int l, int r, int idx, int ql, int qr) {
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

    cout << "Sum of range [1, 3]: " << query(0, n - 1, 1, 1, 3) << endl;
    update(0, n - 1, 1, 1, 10);  // a[1] += 10
    cout << "After update, sum of range [1, 3]: " << query(0, n - 1, 1, 1, 3) << endl;

    return 0;
}
