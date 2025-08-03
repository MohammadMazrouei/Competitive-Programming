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

    // Breadth First Search, O(n+m)
    constexpr int INF = 1e9;
    vector<int> dist(n, INF), par(n, -1);
    auto bfs = [&](int s) -> void {
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : adj[v]) {
                if (dist[v] + 1 < dist[u]) {
                    q.push(u);
                    dist[u] = dist[v] + 1;
                    par[u] = v;
                }
            }
        }
    };
    bfs(0);

    for (int i = 0; i < n; i++) {
        int d = dist[i] != INF ? dist[i] : -1;
        cout << d << " \n"[i == n - 1]; 
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
