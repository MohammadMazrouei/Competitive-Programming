#include <bits/stdc++.h>
using namespace std;

// Sqrt Decomposition, build -> O(n), update & query -> O(sqrt(n))
template <typename T>
struct SqrtDecomposition {
    int n, sq;
    vector<T> a, b, lazy;

    SqrtDecomposition(int _n) : n(_n) {
        sq = sqrt(n) + 1;
        a.assign(n, 0);
        b.assign(sq, numeric_limits<T>::max());
        lazy.assign(sq, 0);
    }
    SqrtDecomposition(const vector<T> &_a) : n(_a.size()) {
        sq = sqrt(n) + 1;
        a.assign(_a.begin(), _a.end());
        b.assign(sq, numeric_limits<T>::max());
        lazy.assign(sq, 0);
        for (int i = 0; i < n; i++) {
            b[i / sq] = min(b[i / sq], a[i]);
        }
    }

    void modify(int l, int r, const T &v) {
        assert(l >= 0 && l <= r && r < n);
        int lc = l / sq, rc = r / sq;
        if (lc == rc) {
            for (int i = l; i <= r; i++) {
                a[i] += v;
                b[lc] = min(b[lc], a[i]);
            }
        }
        else {
            for (int i = l, end = (lc + 1) * sq; i < end; i++) {
                a[i] += v;
                b[lc] = min(b[lc], a[i]);
            }
            for (int i = lc + 1; i < rc; i++) {
                lazy[i] += v;
            }
            for (int i = rc * sq; i <= r; i++) {
                a[i] += v;
                b[rc] = min(b[rc], a[i]);
            }
        }
    }

    T get(int l, int r) {
        assert(l >= 0 && l <= r && r < n);
        T res = numeric_limits<T>::max();
        int lc = l / sq, rc = r / sq;
        if (lc == rc) {
            for (int i = l; i <= r; i++) {
                res = min(res, a[i] + lazy[lc]);
            }
        }
        else {
            for (int i = l, end = (lc + 1) * sq; i < end; i++) {
                res = min(res, a[i] + lazy[lc]);
            }
            for (int i = lc + 1; i < rc; i++) {
                res = min(res, b[i] + lazy[i]);
            }
            for (int i = rc * sq; i <= r; i++) {
                res = min(res, a[i] + lazy[rc]);
            }
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SqrtDecomposition<int64_t> sq(a);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            sq.modify(l, r, v);
        }
        else if (op == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sq.get(l, r) << '\n';
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
