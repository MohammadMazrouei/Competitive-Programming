#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // Find All Shortest Path, O(n^3)
    // Graph may have negative weight but no have negative weight cycle
    // if graph have negative weight cycle, exist a vertex v such that dist[v][v] < 0
    constexpr int64_t INF = 1e18;
    vector dist(n, vector<int64_t>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = min<int64_t>(dist[u][v], w);
        dist[v][u] = min<int64_t>(dist[v][u], w);
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    auto floyd_warshall = [&]() -> void {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    };
    floyd_warshall();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " \n"[j == n - 1];
        }
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
