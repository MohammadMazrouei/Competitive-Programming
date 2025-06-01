#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int LG = 19; 
    vector par(LG, vector<int>(n));
    vector<int> h(n);
    auto dfs = [&](auto &&self, int v, int p) -> void {
        par[0][v] = p;
        for (auto u : adj[v]) {
            if (u == p) {
                continue;
            }
            h[u] = h[v] + 1;
            self(self, u, v);
        }
    };
    dfs(dfs, 0, 0);
    for (int i = 1; i < LG; i++) {
        for (int j = 0; j < n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    auto lca = [&](int u, int v) {
        if (h[u] < h[v]) {
            swap(u, v);
        }
        for (int i = LG - 1; i >= 0; i--) {
            if (h[u] - (1 << i) >= h[v]) {
                u = par[i][u];
            }
        }
        for (int i = LG - 1; i >= 0; i--) {
            if (par[i][u] != par[i][v]) {
                u = par[i][u];
                v = par[i][v];
            }
        }
        return u == v ? u : par[0][u];
    };
    auto dist = [&](int u, int v) {
        int lc = lca(u, v);
        return h[u] + h[v] - 2 * h[lc];
    };

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int lc = lca(u, v);
        int d = dist(u, v);
        cout << lc + 1 << ' ' << d << '\n';
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
