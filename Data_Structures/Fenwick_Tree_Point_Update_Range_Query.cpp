#include <bits/stdc++.h>
using namespace std;

// Point Update & Range Query, O(log(n))
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
        f.assign(v.begin(), v.end());;
        for (int i = 0; i < n; i++) {
            int r = i | (i + 1);
            if (r < n) {
                f[r] += f[i];
            }
        }
    }
    
    void modify(int x, const T& v) {
        assert(x >= 0 && x < n);
        for (int i = x; i < n; i = i | (i + 1)) {
            f[i] += v;
        }
    }
    T get(int x) const {
        T res{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            res += f[i];
        }
        return res;
    }
    T get(int l, int r) const {
        assert(l >= 0 && l <= r && r < n);
        return get(r) - get(l - 1);
    }
    // Lower bound on prefix sum array (every element must be non-negative)
    int select(const T& k) const {
        T sum{};
        int x = 0, pw = __bit_floor(n);
        for (int len = pw; len > 0; len >>= 1) {
            if (x + len <= n && sum + f[x + len - 1] < k) {
                sum += f[x + len - 1];
                x += len;
            }
        }
        assert(x >= 0 && x <= n);
        return x;
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
            int x, v;
            cin >> x >> v;
            x--;
            fen.modify(x, v);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << fen.get(l, r) << '\n';
        } else if (op == 3) {
            int k;
            cin >> k;
            cout << fen.select(k) << '\n';
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
