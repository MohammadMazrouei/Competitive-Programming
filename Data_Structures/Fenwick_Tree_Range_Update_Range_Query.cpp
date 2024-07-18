#include <bits/stdc++.h>
using namespace std;

// Range_Update & Range_Query, O(log(n))
template <typename T>
struct FenwickTree {
    int n;
    vector<T> f1, f2;
    
    FenwickTree() {}
    FenwickTree(int _n) : n(_n) {
        f1.assign(n, T{});
        f2.assign(n, T{});
    }
    FenwickTree(const vector<T> &v) {
        n = v.size();
        f1.assign(n, T{});
        f2.assign(n, T{});
        for (int i = 0; i < n; i++) {
            add(i, i, v[i]);
        }
    }

    void modify(int x, T mul, T add) {
        for (int i = x; i < n; i = i | (i + 1)) {
            f1[i] += mul;
            f2[i] += add;
        }
    }
    void add(int l, int r, T v) {
        assert(l >= 0 && l < n && r >= 0 && r < n);
        modify(l, v, -v * (l - 1));
        modify(r, -v, v * r);
    }
    T get(int x) {
        T mul{}, add{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            mul += f1[i];
            add += f2[i];
        }
        return mul * x + add;
    }
    T get(int l, int r) {
        assert(l >= 0 && l < n && r >= 0 && r < n);
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
        int t;
        cin >> t;

        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            fen.add(l, r, v);
        }
        else if (t == 2) {
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
