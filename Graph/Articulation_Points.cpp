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

    // Find Articulation Points in Undirected Graph, O(n + m)
    vector<bool> vis(n);
    vector<int> tin(n), low(n), art_points;
    int timer = 0;
    auto dfs = [&](auto &&self, int v, int p) -> void {
        vis[v] = true;
        tin[v] = low[v] = timer++;
        int children = 0;
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
                if (low[u] >= tin[v] && p != -1) {
                    art_points.push_back(v);
                }
                children++;
            }
        }
        if (p == -1 && children > 1) {
            art_points.push_back(v);
        }
    };
    auto find_art_points = [&]() {
        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                dfs(dfs, v, -1);
            }
        }
        // Some points may be added several times
        sort(art_points.begin(), art_points.end());
        art_points.erase(unique(art_points.begin(), art_points.end()), art_points.end());
    };

    find_art_points();
    int sz = art_points.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
        cout << art_points[i] + 1 << " \n"[i == sz - 1];
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
