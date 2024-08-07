#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union, O(1)
struct DSU {
    vector<int> par, sz;
    int c;
    
    DSU(int n) : c(n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }

    void make(int a) {
        par[a] = a;
        sz[a] = 1;
        c++;
    }
    int find(int a) {
        return (par[a] == a ? a : (par[a] = find(par[a])));
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    void merge(int a, int b) {
        if ((a = find(a)) == (b = find(b))) {
            return;
        }
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        par[a] = b;
        sz[b] += sz[a];
        c--;
    }
    int size(int a) {
        return sz[find(a)];
    }
    int count() {
        return c;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            dsu.merge(a, b);
        }
        else if (t == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (dsu.same(a, b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
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
