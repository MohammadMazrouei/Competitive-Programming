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

    vector<int> vis(n);
    vector<pair<int, int>> bridges;
    vector<int> tin(n, -1), low(n, -1);
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
    auto find_bridges = [&](int n) -> void {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(dfs, i, -1);
            }
        }
    };
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
