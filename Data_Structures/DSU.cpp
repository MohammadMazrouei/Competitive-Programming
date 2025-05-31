#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union, O(alpha(n))
struct DSU {
    int c; // components
    vector<int> par, sz;
    
    DSU() : c(0) {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        c = n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    int find(int a) {
        return (par[a] == a ? a : (par[a] = find(par[a])));
    }
    bool merge(int a, int b) {
        if ((a = find(a)) == (b = find(b))) {
            return false;
        }
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        c--;
        par[a] = b;
        sz[b] += sz[a];
        return true;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            dsu.merge(a, b);
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << (dsu.find(a) == dsu.find(b) ? "YES\n" : "NO\n");
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
