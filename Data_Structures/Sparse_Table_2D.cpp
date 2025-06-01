#include <bits/stdc++.h>
using namespace std;

// Sparse Table 2D for RMQ
// build -> O(n*m*log(n)*log(m)), query -> O(1)
template <typename T, typename Compare = less<T>>
struct SparseTable2D {
    int n, m;
    vector<vector<vector<vector<T>>>> t;
    Compare cmp = Compare();

    SparseTable2D() : n(0), m(0) {}
    SparseTable2D(const vector<vector<T>>& v) {
        build(v);
    }

    void build(const vector<vector<T>>& v) {
        n = v.size();
        m = v[0].size();
        const int lg_n = __bit_width(n);
        const int lg_m = __bit_width(m);
        t.assign(n, vector(m, vector(lg_n, vector<T>(lg_m))));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[i][j][0][0] = v[i][j];
            }
        }
        for (int k1 = 0; k1 < lg_n; k1++) {
            for (int k2 = 0; k2 < lg_m; k2++) {
                if (k1 + k2 == 0) {
                    continue;
                }
                for (int i = 0; i + (1 << k1) - 1 < n; i++) {
                    for (int j = 0; j + (1 << k2) - 1 < m; j++) {
                        if (!k1) {
                            t[i][j][k1][k2] = min(t[i][j][k1][k2 - 1], t[i][j + (1 << (k2 - 1))][k1][k2 - 1], cmp);
                        } else {
                            t[i][j][k1][k2] = min(t[i][j][k1 - 1][k2], t[i + (1 << (k1 - 1))][j][k1 - 1][k2], cmp);
                        }
                    }
                }
            }
        }
    }
    T get(int l1, int r1, int l2, int r2) const { 
        assert(l1 >= 0 && l1 <= r1 && r1 < n);
        assert(l2 >= 0 && l2 <= r2 && r2 < m);
        int k1 = __bit_width(r1 - l1 + 1) - 1;
        int k2 = __bit_width(r2 - l2 + 1) - 1;
        return min({t[l1][l2][k1][k2],
                    t[r1 - (1 << k1) + 1][l2][k1][k2],
                    t[l1][r2 - (1 << k2) + 1][k1][k2],
                    t[r1 - (1 << k1) + 1][r2 - (1 << k2) + 1][k1][k2]}, cmp);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    SparseTable2D<int> t(a);
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--, r1--, l2--, r2--;
        cout << t.get(l1, r1, l2, r2) << '\n';
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
