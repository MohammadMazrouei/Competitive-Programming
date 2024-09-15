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

    // Depth First Search, O(n + m)
    vector<bool> vis(n);
    vector<int> in(n), out(n), order;
    order.reserve(n);
    int timer = 0;
    auto dfs = [&](auto &&self, int v) -> void {
        vis[v] = true;
        in[v] = timer++;
        order.push_back(v);
        for (auto u : adj[v]) {
            if (!vis[u]) {
                self(self, u);
            }
        }
        out[v] = timer;
    };

    for (int v = 0; v < n; v++) {
        if (!vis[v]) {
            dfs(dfs, v);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << order[i] + 1 << " \n"[i == n - 1];
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
