#include <bits/stdc++.h>
using namespace std;

// Range Update & Range Query, O(log(n))
template <typename T>
struct FenwickTree {
    int n;
    vector<T> f_mul, f_add;
    
    FenwickTree() {}
    FenwickTree(int _n) : n(_n) {
        f_mul.assign(n, T{});
        f_add.assign(n, T{});
    }
    FenwickTree(const vector<T> &v) {
        n = v.size();
        f_mul.assign(n, T{});
        f_add.assign(n, T{});
        for (int i = 0; i < n; i++) {
            modify(i, i, v[i]);
        }
    }

    void add(int x, T mul, T add) {
        for (int i = x; i < n; i = i | (i + 1)) {
            f_mul[i] += mul;
            f_add[i] += add;
        }
    }
    void modify(int l, int r, const T &v) {
        assert(l >= 0 && l <= r && r < n);
        add(l, v, -v * (l - 1));
        add(r, -v, v * r);
    }
    T get(int x) {
        T mul{}, add{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            mul += f_mul[i];
            add += f_add[i];
        }
        return mul * x + add;
    }
    T get(int l, int r) {
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
            fen.modify(l, r, v);
        }
        else if (op == 2) {
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
