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

    // Find Cycle in Undirected Graph, O(n + m)
    vector<bool> vis(n);
    vector<int> par(n, -1), cycle;
    int cycle_start, cycle_end;
    auto dfs = [&](auto &&self, int v, int p) -> bool {
        vis[v] = true;
        for (auto u : adj[v]) {
            if(u == p) {
                continue; 
            }
            if (vis[u]) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
            par[u] = v;
            if (self(self, u, par[u])) {
                return true;
            }
        }
        return false;
    };
    auto find_cycle = [&]() -> bool {
        cycle.clear();
        cycle_start = -1;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && dfs(dfs, v, par[v])) {
                break;
            }
        }
        if (cycle_start == -1) {
            return false;
        } 

        for (int v = cycle_end; v != cycle_start; v = par[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        return true;
    };

    if (find_cycle()) {
        cout << "YES\n";
        for (auto v : cycle) {
            cout << v + 1 << " \n"[v == cycle.back()];
        }
    }
    else {
        cout << "NO\n";
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
