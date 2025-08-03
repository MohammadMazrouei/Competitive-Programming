#include <bits/stdc++.h>
using namespace std;

// Range Update & Point Query, O(log(n))
template <typename T>
struct FenwickTree { 
    int n;
    vector<T> f;
    
    FenwickTree() : n(0) {}
    FenwickTree(int _n) : n(_n) {
        f.assign(n, T{});
    }
    FenwickTree(const vector<T>& v) {
        n = v.size();
        f.assign(n, T{});
        for (int i = 0; i < n; i++) {
            modify(i, i, v[i]);
        }
    }

    void modify(int x, const T& v) {
        for (int i = x; i < n; i = i | (i + 1)) {
            f[i] += v;
        }
    }
    void modify(int l, int r, const T& v) {
        assert(l >= 0 && l <= r && r < n);
        modify(l, v);
        modify(r + 1, -v);
    }
    T get(int x) const {
        assert(x >= 0 && x < n);
        T res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            res += f[i];
        }
        return res;
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
        } else if (op == 2) {
            int x;
            cin >> x;
            x--;
            cout << fen.get(x) << '\n';
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
