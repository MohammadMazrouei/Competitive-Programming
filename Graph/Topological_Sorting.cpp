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
    }

    // Topological Sorting, O(n + m)
    // An order of vertices in DAG that every edge leads from 
    // the vertex with a smaller index to a vertex with a larger one.
    vector<bool> vis(n);
    vector<int> ord;
    auto dfs = [&](auto &&self, int v) -> void {
        vis[v] = true;
        for (auto u : adj[v]) {
            if (!vis[u]) {
                self(self, u);
            }
        }
        ord.push_back(v);
    };
    auto topological_sorting = [&]() -> void {
        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                dfs(dfs, v);
            }
        }
        reverse(ord.begin(), ord.end());
    };
    topological_sorting();

    for (int i = 0; i < n; i++) {
        cout << ord[i] + 1 << " \n"[i == n - 1];
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
