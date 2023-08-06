#include <vector>

class IntervalTree {
private:
    struct Node {
        long long value;
    };

    std::vector<Node> tree;
    int max_size;

public:

    IntervalTree(int n) {
        int k = 0;
        while ((1 << k) < n) ++k;
        max_size = 1 << k;
        tree.resize(2 * max_size);
        for (int i = n; i < 2 * n; ++i) {
            tree[i].value = 0;
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i].value = tree[2 * i].value + tree[2 * i + 1].value;
        }
    }

    void Update(int pos, int delta) {
        processUpdate(1, 0, max_size - 1, pos, delta);
    }

    long long getSum(int l, int r) {
        return processGetSum(1, 0, max_size - 1, l, r);
    }

private:

    void processUpdate(int v, int tl, int tr, int pos, int delta) {
        tree[v].value += delta;
        if (tl == pos && tr == pos) return;
        int tm = (tl + tr) >> 1;
        if (pos <= tm) processUpdate(2 * v, tl, tm, pos, delta);
        if (pos >= tm + 1) processUpdate(2 * v + 1, tm + 1, tr, pos, delta);
    }

    long long processGetSum(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return tree[v].value;
        }
        int tm = (tl + tr) >> 1;
        long long ans = 0;
        if (l <= tm) ans += processGetSum(2 * v, tl, tm, l, std::min(r, tm));
        if (r >= tm + 1) ans += processGetSum(2 * v + 1, tm + 1, tr, std::max(l, tm + 1), r);
        return ans;
    }

};