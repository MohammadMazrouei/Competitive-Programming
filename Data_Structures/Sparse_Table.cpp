#include <bits/stdc++.h>
using namespace std;

// RMQ, build -> O(n*log(n)), query -> O(1)
// with global array is faster (1.9s vs 2.9s for n = 1e7)
// constexpr n = 1e7, lg = 25; int t[n][lg];
template <typename T>
struct SparseTable {
    int n, lg;
    vector<vector<T>> t;

    SparseTable(vector<T> &v) {
        n = v.size();
        lg = __lg(n) + 2;
        t.resize(n);
        for (int i = 0; i < n; i++) {
            t[i].resize(lg);
        }
        build(v);
    }

    inline T f(const T &a, const T &b) {
        return min(a, b);
    }
    void build(vector<T> &v) {
        for (int i = 0; i < n; i++) {
            t[i][0] = v[i];
        }
        for (int k = 1; k < lg; k++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                t[i][k] = f(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    T get(int l, int r) { 
        assert(l >= 0 && r < n);
        //int k = __builtin_clzll(1) - __builtin_clzll(r - l + 1);
        int k = __builtin_clz(1) - __builtin_clz(r - l + 1);
        return f(t[l][k], t[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    SparseTable<int> st(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << st.get(l, r) << '\n';
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
