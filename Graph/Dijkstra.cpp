#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Single Source Shortest Path, O(m*log(n))
    constexpr int64_t INF = 1e18;
    vector<int64_t> dist(n, INF), cnt(n, 0);
    vector<int> par(n, -1);
    auto dijkstra = [&](int s) -> void {
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
        pq.emplace(0, s);
        dist[s] = 0;
        cnt[s] = 1;
        while (!pq.empty()) {
            auto [dist_v, v] = pq.top();
            pq.pop();

            if (dist_v != dist[v]) {
                continue;
            }
            for (auto [u, w] : adj[v]) {
                if (dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    par[u] = v;
                    cnt[u] = cnt[v];
                    pq.emplace(dist[u], u);
                }
                else if (dist[v] + w == dist[u]) {
                    cnt[u] = (cnt[u] + cnt[v]); // MOD
                }
            }
        }
    };

    int s;
    cin >> s;
    s--;
    dijkstra(s);
    for (int i = 0; i < n; i++) {
        int64_t d = dist[i] != INF ? dist[i] : -1;
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
