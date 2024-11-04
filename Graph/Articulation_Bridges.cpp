#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find Articulation Bridges in Udirected Graph, O(n + m)
    vector<bool> vis(n);
    vector<int> tin(n), low(n);
    vector<array<int, 2>> bridges;
    int timer = 0;
    auto dfs = [&](auto &&self, int v, int p) -> void {
        vis[v] = true;
        tin[v] = low[v] = timer++;
        for (auto u : adj[v]) {
            if (u == p) {
                continue;
            }
            if (vis[u]) {
                low[v] = min(low[v], tin[u]);
            } 
            else {
                self(self, u, v);
                low[v] = min(low[v], low[u]);
                if (low[u] > tin[v]) {
                    bridges.push_back({v, u});
                }
            }
        }
    };
    auto find_bridges = [&]() -> void {
        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                dfs(dfs, v, -1);
            }
        }
    };

    find_bridges();
    int sz = bridges.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
        cout << bridges[i][0] + 1 << ' ' << bridges[i][1] + 1 << '\n';
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
