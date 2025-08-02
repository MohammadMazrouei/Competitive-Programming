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

    // Find one cycle in directed graph, O(n + m)
    vector<int> color(n), par(n, -1), cycle;
    int cycle_start, cycle_end;
    auto dfs = [&](auto&& self, int v) -> bool {
        color[v] = 1;
        for (auto u : adj[v]) {
            if (color[u] == 0) {
                par[u] = v;
                if (self(self, u)) {
                    color[v] = 2;
                    return true;
                }
            } else if (color[u] == 1) {
                cycle_end = v;
                cycle_start = u;
                color[v] = 2;
                return true;
            }
        }
        color[v] = 2;
        return false;
    };
    auto find_cycle = [&]() -> bool {
        cycle.clear();
        cycle_start = -1;
        for (int i = 0; i < n; i++) { 
            if (color[i] == 0 && dfs(dfs, i)) {
                break;
            }
        }

        if (cycle_start == -1) {
            return false;
        }
        for (int i = cycle_end; i != cycle_start; i = par[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        return true;
    };

    if (find_cycle()) {
        cout << "YES\n";
        for (auto v : cycle) {
            cout << v + 1 << " \n"[v == cycle.back()];
        }
    } else {
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
