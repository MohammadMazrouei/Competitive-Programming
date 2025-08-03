#include <bits/stdc++.h>
using namespace std;

// Range Update & Point Query, O(log(n)*log(m))
template <typename T>
struct FenwickTree2D {
    int n, m;
    vector<vector<T>> f;

    FenwickTree2D() : n(0), m(0) {}
    FenwickTree2D(int _n, int _m) : n(_n), m(_m) {
        f.assign(n, vector<T>(m, T{}));
    }
    // O(n*m) Construction
    FenwickTree2D(const vector<vector<T>>& v) {
        n = v.size();
        m = v[0].size();
        f.assign(n, vector<T>(m, T{}));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                T up = (i > 0) ? v[i - 1][j] : T{};
                T left = (j > 0) ? v[i][j - 1] : T{};
                T corner = (i > 0 && j > 0) ? v[i - 1][j - 1] : T{};
                f[i][j] = v[i][j] - up - left + corner;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = j | (j + 1);
                if (r < m) {
                    f[i][r] += f[i][j];
                }
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int r = i | (i + 1);
                if (r < n) {
                    f[r][j] += f[i][j];
                }
            }
        }
    }

    void add(int x, int y, const T& v) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < m; j = j | (j + 1)) {
                f[i][j] += v;
            }
        }
    }
    void add(int l1, int r1, int l2, int r2, const T& v) {
        assert(l1 >= 0 && l1 <= r1 && r1 < n);
        assert(l2 >= 0 && l2 <= r2 && r2 < m);
        add(l1, l2, v);
        add(l1, r2 + 1, -v);
        add(r1 + 1, l2, -v);
        add(r1 + 1, r2 + 1, v);
    }
    T get(int x, int y) const {
        assert(x >= 0 && x < n);
        assert(y >= 0 && y < m);
        T res{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                res += f[i][j];
            }
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    FenwickTree2D<int> fen(a);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l1, r1, l2, r2, v;
            cin >> l1 >> r1 >> l2 >> r2 >> v;
            l1--, r1--, l2--, r2--;
            fen.add(l1, r1, l2, r2, v);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            cout << fen.get(x, y) << '\n';
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
