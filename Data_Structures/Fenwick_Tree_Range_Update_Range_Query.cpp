#include <bits/stdc++.h>
using namespace std;

// Range Update & Range Query, O(log(n))
template <typename T>
struct FenwickTree {
    int n;
    vector<T> f_mul, f_add;
    
    FenwickTree() : n(0) {}
    FenwickTree(int _n) : n(_n) {
        f_mul.assign(n, T{});
        f_add.assign(n, T{});
    }
    FenwickTree(const vector<T>& v) {
        n = v.size();
        f_mul.assign(n, T{});
        f_add.assign(n, T{});
        for (int i = 0; i < n; i++) {
            add(i, i, v[i]);
        }
    }

    void modify(int x, T mul, T add) {
        for (int i = x; i < n; i = i | (i + 1)) {
            f_mul[i] += mul;
            f_add[i] += add;
        }
    }
    void add(int l, int r, const T& v) {
        assert(l >= 0 && l <= r && r < n);
        modify(l, v, -v * (l - 1));
        modify(r, -v, v * r);
    }
    T get(int x) const {
        T mul{}, add{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            mul += f_mul[i];
            add += f_add[i];
        }
        return mul * x + add;
    }
    T get(int l, int r) const {
        assert(l >= 0 && l <= r && r < n);
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    FenwickTree<int> fen(a);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            fen.add(l, r, v);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << fen.get(l, r) << '\n';
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
