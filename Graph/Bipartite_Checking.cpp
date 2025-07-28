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

    // Check an undirected graph is bipartite, O(n + m)
    vector<int> color(n, -1);
    vector<vector<int>> c(2);
    auto is_bipartite = [&]() -> bool {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                c[color[i]].push_back(i);
                q.push(i); 
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (auto u : adj[v]) {
                        if (color[u] == -1) {
                            color[u] = color[v] ^ 1;
                            c[color[u]].push_back(u);
                            q.push(u);
                        } else if (color[u] == color[v]) {
                            return false;
                        }
                    }
                }

            }
        }
        return true;
    };

    if (is_bipartite()) {
        cout << "YES\n";
        for (auto v : c[0]) {
            cout << v + 1 << " \n"[v == c[0].back()];
        }
        for (auto v : c[1]) {
            cout << v + 1 << " \n"[v == c[1].back()];
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
