#include <vector>

class IntervalTree {
private:
    struct Node {
        long long value;
        long long promise;
        bool delayed = false;
    };

    std::vector<Node> tree;
    int max_size;

public:

    IntervalTree(int n) {
        int k = 0;
        while ((1 << k) < n) ++k;
        max_size = 1 << k;
        tree.resize(2 * max_size);
        for (int i = max_size; i < 2 * max_size; ++i) {
            tree[i].value = 0;
        }
        for (int i = max_size - 1; i > 0; --i) {
            tree[i].value = tree[2 * i].value + tree[2 * i + 1].value;
        }
    }

    void Assign(int l, int r, long long x) {
        processAssign(1, 0, max_size - 1, l, r, x);
    }

    long long getSum(int l, int r) {
        return processGetSum(1, 0, max_size - 1, l, r);
    }

private:

    void processAssign(int v, int tl, int tr, int l, int r, long long x) {
        if (tl == l && tr == r) {
            tree[v].promise = x;
            tree[v].delayed = true;
            tree[v].value = x * (tr - tl + 1);
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        if (l <= tm) processAssign(2 * v, tl, tm, l, std::min(r, tm), x);
        if (r >= tm + 1) processAssign(2 * v + 1, tm + 1, tr, std::max(l, tm + 1), r, x);
        tree[v].value = tree[2 * v].value + tree[2 * v + 1].value;
    }

    long long processGetSum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return tree[v].value;
        }
        int tm = (tl + tr) >> 1;
        long long ans = 0;
        push(v, tl, tr);
        if (l <= tm) ans += processGetSum(2 * v, tl, tm, l, std::min(r, tm));
        if (r >= tm + 1) ans += processGetSum(2 * v + 1, tm + 1, tr, std::max(l, tm + 1), r);
        return ans;
    }

    void push(int v, int tl, int tr) {
        if (!tree[v].delayed) return;
        int tm = (tl + tr) >> 1;
        long long x = tree[v].promise;
        tree[2 * v].value = x * (tm - tl + 1);  // [tl, tm]
        tree[2 * v].promise = x;
        tree[2 * v].delayed = true;
        tree[2 * v + 1].value = x * (tr - tm);  // [tm + 1, tr]
        tree[2 * v + 1].promise = x;
        tree[2 * v + 1].delayed = true;
        tree[v].delayed = false;
    }

};