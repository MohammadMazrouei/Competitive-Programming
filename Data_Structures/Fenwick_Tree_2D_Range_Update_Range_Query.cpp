#include <bits/stdc++.h>
using namespace std;

// Range Update & Range Query, O(log(n)*log(m))
template <typename T>
struct FenwickTree2D {
    int n, m;
    vector<vector<array<T, 2>>> f_mul, f_add;

    FenwickTree2D() : n(0), m(0) {}
    FenwickTree2D(int _n, int _m) : n(_n), m(_m) {
        f_mul.assign(n, vector<array<T, 2>>(m, {T{}, T{}}));
        f_add.assign(n, vector<array<T, 2>>(m, {T{}, T{}}));
    }
    // O(n*m) Construction
    FenwickTree2D(const vector<vector<T>>& v) {
        n = v.size();
        m = v[0].size();
        f_mul.assign(n, vector<array<T, 2>>(m, {T{}, T{}}));
        f_add.assign(n, vector<array<T, 2>>(m, {T{}, T{}}));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f_add[i][j][1] = v[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            int r = i | (i + 1);
            if (r < n) {
                for (int j = 0; j < m; j++) {
                    f_add[r][j][1] += f_add[i][j][1];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r = j | (j + 1);
                if (r < m) {
                    f_add[i][r][1] += f_add[i][j][1];
                }
            }
        }
    }

    void add_y(int x, int y, T mul, T add, vector<vector<array<T, 2>>>& f) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < m; j = j | (j + 1)) {
                f[i][j][0] += mul;
                f[i][j][1] += add;
            }
        }
    }
    void add_x(int x, int l2, int r2, T mul, T add) {
        add_y(x, l2, mul, -mul * (l2 - 1), f_mul);
        add_y(x, r2, -mul, mul * r2, f_mul);
        add_y(x, l2, add, -add * (l2 - 1), f_add);
        add_y(x, r2, -add, add * r2, f_add);
    }
    void add(int l1, int r1, int l2, int r2, const T& v) {
        assert(l1 >= 0 && l1 <= r1 && r1 < n);
        assert(l2 >= 0 && l2 <= r2 && r2 < m);
        add_x(l1, l2, r2, v, -v * (l1 - 1));
        add_x(r1, l2, r2, -v, v * r1);
    }
    T get_y(int x, int y, const vector<vector<array<T, 2>>>& f) const {
        T mul{}, add{};
        for (int i = y; i >= 0; i = (i & (i + 1)) - 1) {
            mul += f[x][i][0];
            add += f[x][i][1];
        }
        return mul * y + add;
    }
    T get_x(int x, int y) const {
        T mul{}, add{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            mul += get_y(i, y, f_mul);
            add += get_y(i, y, f_add);
        }
        return mul * x + add;
    }
    T get(int l1, int r1, int l2, int r2) const {
        assert(l1 >= 0 && l1 <= r1 && r1 < n);
        assert(l2 >= 0 && l2 <= r2 && r2 < m);
        l1--, l2--;
        return get_x(r1, r2) - get_x(l1, r2) - get_x(r1, l2) + get_x(l1, l2);
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
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            l1--, r1--, l2--, r2--;
            cout << fen.get(l1, r1, l2, r2) << '\n';
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
