#include <bits/stdc++.h>
using namespace std;

// RMQ, build -> O(n*log(n)), query -> O(1)
// with global array is faster (2s vs 3s for n = 1e7)
// constexpr int n = 1e7, lg = 25; int t[n][lg];
template <typename T, typename Cmp = less<T>>
struct SparseTable {
    int n;
    vector<vector<T>> t;
    const Cmp cmp = Cmp();

    SparseTable() {}
    SparseTable(const vector<T> &v) {
        build(v);
    }

    inline T f(const T &a, const T &b) const {
        return min(a, b, cmp);
    }
    void build(const vector<T> &v) {
        n = v.size();
        const int lg = __lg(n) + 2;
        t.assign(n, vector<T>(lg));

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
        assert(l >= 0 && l <= r && r < n);
        int k = __lg(r - l + 1);
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
    
    SparseTable<int, greater<int>> st(a);
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
