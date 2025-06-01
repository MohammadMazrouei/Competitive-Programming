#include <bits/stdc++.h>
using namespace std;

// Sparse Table for RMQ
// build -> O(n*log(n)), query -> O(1)
template <typename T, typename Compare = less<T>>
struct SparseTable {
    int n;
    vector<vector<T>> t;
    Compare cmp = Compare();

    SparseTable() : n(0) {}
    SparseTable(const vector<T>& v) {
        build(v);
    }

    void build(const vector<T>& v) {
        n = v.size();
        const int lg = __bit_width(n);
        t.assign(n, vector<T>(lg));

        for (int i = 0; i < n; i++) {
            t[i][0] = v[i];
        }
        for (int k = 1; k < lg; k++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1], cmp);
            }
        }
    }
    T get(int l, int r) const { 
        assert(l >= 0 && l <= r && r < n);
        int k = __bit_width(r - l + 1) - 1;
        return min(t[l][k], t[r - (1 << k) + 1][k], cmp);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    SparseTable<int> t(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << t.get(l, r) << '\n';
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
