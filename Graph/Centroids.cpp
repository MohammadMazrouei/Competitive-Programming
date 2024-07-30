#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Find The Centroids of a Tree, O(n + m)
    // A node such that when the tree is rooted at it, no other nodes have a subtree of size greater than n/2
    vector<int> sz(n), centroids;
    auto dfs = [&](auto &&self, int v, int p) -> void {
        sz[v] = 1;
        for (auto u : adj[v]) {
            if (u == p) {
                continue;
            }
            self(self, u, v);
            sz[v] += sz[u];
        }
    };
    auto find_centroids = [&]() -> void {
        int v = 0;
        dfs(dfs, v, -1);
        while (true) {
            int tmp = -1;
            for (auto u : adj[v]) {
                if (sz[u] > sz[v]) {
                    continue;
                }
                if (2 * sz[u] >= n) {
                    tmp = u;
                }
            }
            if (tmp == -1) {
                break;
            }
            v = tmp;
        }
        dfs(dfs, v, -1);
        for (auto u : adj[v]) {
            if (2 * sz[u] == n) {
                centroids.push_back(u);
                centroids.push_back(v);
                return;
            }
        }
        centroids.push_back(v);
    };

    find_centroids();
    for (auto centroid : centroids) {
        cout << centroid + 1 << '\n';
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
