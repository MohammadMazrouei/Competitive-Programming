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
    // O(n) Construction
    FenwickTree(const vector<T>& v) {
        n = v.size();
        f.resize(n);
        f[0] = v[0];
        for (int i = 1; i < n; i++) {
            f[i] = v[i] - v[i - 1];
        }
        for (int i = 0; i < n; i++) {
            int r = i | (i + 1);
            if (r < n) {
                f[r] += f[i];
            }
        }
    }

    void add(int x, const T& v) {
        for (int i = x; i < n; i = i | (i + 1)) {
            f[i] += v;
        }
    }
    void add(int l, int r, const T& v) {
        assert(l >= 0 && l <= r && r < n);
        add(l, v);
        add(r + 1, -v);
    }
    T get(int x) const {
        assert(x >= 0 && x < n);
        T res{};
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
            fen.add(l, r, v);
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
