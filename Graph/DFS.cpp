#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n);
    auto dfs = [&](int v, auto&& dfs) -> void {
        vis[v] = 1;
        for (auto u : adj[v]) {
            if (!vis[u]) {
                dfs(u, dfs);
            }
        }
    };

    dfs(0, dfs);
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
