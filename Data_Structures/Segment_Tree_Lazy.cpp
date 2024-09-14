#include <bits/stdc++.h>
using namespace std;

// Segment Tree with Lazy Propagation, build -> O(n), update & query -> O(log(n))
struct SegmentTreeLazy {
    struct Node {
        int64_t sum = 0, mn = 4e18, cnt = 0;
        int64_t add = 0;

        template <typename M>
        void init(const M &v) {
            sum = mn = v;
            cnt = 1;
            add = 0;
        }
        template <typename M>
        void apply([[maybe_unused]] int l, [[maybe_unused]] int r, const M &v) {
            sum += (int64_t)v * (r - l + 1);
            mn += v;
            if (l != r) {
                add += v;
            }
        }
    };

    int n;
    vector<Node> tree;

    Node merge(const Node &a, const Node &b) const {
        Node res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.cnt = (res.mn == a.mn ? a.cnt : 0) + (res.mn == b.mn ? b.cnt : 0);
        return res;
    }

    inline void pull(int x) {
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    inline void push(int l, int r, int x) {
        int m = (l + r) / 2;
        if (tree[x].add != 0) {
            tree[2 * x].apply(l, m, tree[x].add);
            tree[2 * x + 1].apply(m + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        pull(x);
    }

    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].init(v[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m, v);
        build(2 * x + 1, m + 1, r, v);
        pull(x);
    }

    template <typename M>
    void modify(int x, int l, int r, int ll, int rr, const M &v) {
        if (l > rr || r < ll) {
            return;
        }
        if (l >= ll && r <= rr) {
            tree[x].apply(l, r, v);
            return;
        }
        push(l, r, x);
        int m = (l + r) / 2;
        modify(2 * x, l, m, ll, rr, v);
        modify(2 * x + 1, m + 1, r, ll, rr, v);
        pull(x);
    }

    Node get(int x, int l, int r, int ll, int rr) {
        if (l > rr || r < ll) {
            return Node();
        }
        if (l >= ll && r <= rr) {
            return tree[x];
        }
        push(l, r, x);
        int m = (l + r) / 2;
        return merge(get(2 * x, l, m, ll, rr), get(2 * x + 1, m + 1, r, ll, rr));
    }

    int find_first_knowingly(int x, int l, int r, const function<bool(const Node&)> &f) {
        if (l == r) {
            return l;
        }
        push(l, r, x);
        int m = (l + r) / 2;
        if (f(tree[2 * x])) {
            return find_first_knowingly(2 * x, l, m, f);
        } 
        return find_first_knowingly(2 * x + 1, m + 1, r, f);
    }

    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const Node&)> &f) {
        if (l > rr || r < ll) {
            return -1;
        }
        if (l >= ll && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(l, r, x);
        int m = (l + r) / 2;
        int res = find_first(2 * x, l, m, ll, rr, f);
        if (res == -1) {
            res = find_first(2 * x + 1, m + 1, r, ll, rr, f);
        }
        return res;
    }

    int find_last_knowingly(int x, int l, int r, const function<bool(const Node&)> &f) {
        if (l == r) {
            return l;
        }
        push(l, r, x);
        int m = (l + r) / 2;
        if (f(tree[2 * x + 1])) {
            return find_last_knowingly(2 * x + 1, m + 1, r, f);
        } 
        return find_last_knowingly(2 * x, l, m, f);
    }

    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const Node&)> &f) {
        if (l > rr || r < ll) {
            return -1;
        }
        if (l >= ll && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(l, r, x);
        int m = (l + r) / 2;
        int res = find_last(2 * x + 1, m + 1, r, ll, rr, f);
        if (res == -1) {
            res = find_last(2 * x, l, m, ll, rr, f);
        }
        return res;
    }

    SegmentTreeLazy(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    template <typename M>
    SegmentTreeLazy(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(4 * n);
        build(1, 0, n - 1, v);
    }

    template <typename M>
    void modify(int ll, int rr, const M &v) {
        assert(ll >= 0 && ll <= rr && rr < n);
        modify(1, 0, n - 1, ll, rr, v);
    }

    Node get(int ll, int rr) {
        assert(ll >= 0 && ll <= rr && rr < n);
        return get(1, 0, n - 1, ll, rr);
    }

    Node get(int p) {
        assert(p >= 0 && p < n);
        return get(1, 0, n - 1, p, p);
    }

    // find_first and find_last find first/last element satisfy f
    // auto f = [&](const auto &info) { return info.mn == 0; };

    int find_first(int ll, int rr, const function<bool(const Node&)> &f) {
        assert(ll >= 0 && ll <= rr && rr < n);
        return find_first(1, 0, n - 1, ll, rr, f);
    }

    int find_last(int ll, int rr, const function<bool(const Node&)> &f) {
        assert(ll >= 0 && ll <= rr && rr < n);
        return find_last(1, 0, n - 1, ll, rr, f);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTreeLazy seg(a);
    auto f = [&](const auto &info) { return info.mn == 0; };
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            seg.modify(l, r, v);
        }
        else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto node = seg.get(l, r);
            cout << node.sum << ' ' << node.mn << ' ' << node.cnt << '\n';
        }
        else if (t == 3) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << seg.find_first(l, r, f) + 1 << '\n';
        }
        else if (t == 4) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << seg.find_last(l, r, f) + 1 << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
