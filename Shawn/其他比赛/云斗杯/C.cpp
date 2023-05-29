//给定一个长度为n的序列，有m种操作，每个物品可以操作序列中l~r（包括l,r）的元素，并且当且仅当这个范围内还有没有被操作过的元素才可以使用这个操作，使用每个操作还可以获得对应的收益，求最大收益

#include <iostream>
#include <vector>
#include <algorithm>

const int N = 1e5 + 10;

using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) {
        tree.resize(4 * n);
        lazy.resize(4 * n, false);
    }

    void push_down(int node) {
        if (lazy[node]) {   
            tree[node * 2] = tree[node];
            tree[node * 2 + 1] = tree[node];
            lazy[node * 2] = true;
            lazy[node * 2 + 1] = true;
            lazy[node] = false;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (start > r || end < l) {
            return;
        }
        if (start >= l && end <= r && !lazy[node]) {
            tree[node] = val;
            lazy[node] = true;
            return;
        }
        push_down(node);
        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, val);
        update(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0;
        }
        if (start >= l && end <= r) {
            return tree[node];
        }
        push_down(node);
        int mid = (start + end) / 2;
        return max(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
    }

private:
    vector<int> tree;
    vector<bool> lazy;
};

int main() {
    int n, m;
    cin >> n >> m;
    SegmentTree tree(n);
    for (int i = 0; i < m; i++) {
        int l, r, val;
        cin >> val >> l >> r;
        tree.update(1, 1, n, l, r, val);
    }
    cout << tree.query(1, 1, n, 1, n) << endl;
    return 0;
}