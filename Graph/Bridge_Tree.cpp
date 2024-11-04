#include <bits/stdc++.h>
using namespace std;

// Bridge Tree for Undirected Graph, O(n + m)
struct Bridge_Tree {
    int n, sz, timer;
    vector<vector<int>> adj, g;
    vector<bool> vis;
    vector<int> tin, low, comp;
    vector<pair<int, int>> bridges;

    void dfs(int v, int p) {
        vis[v] = true;
        tin[v] = low[v] = timer++;
        for (auto u : adj[v]) {
            if (u == p) {
                continue;
            }
            if (vis[u]) {
                low[v] = min(low[v], tin[u]);
            } 
            else {
                dfs(u, v);
                low[v] = min(low[v], low[u]);
            }
        }
    };

    void dfs2(int v, int c) {
        comp[v] = c;
        for (auto u : adj[v]) {
            if (comp[u] != -1) {
                continue;
            }
            if (low[u] > tin[v]) {
                bridges.emplace_back(v, u);
                dfs2(u, ++sz);
            } 
            else {
                dfs2(u, c);
            }
        }
    }

    Bridge_Tree(const vector<vector<int>> &_adj) : n(_adj.size()), adj(_adj) {
        vis.resize(n);
        tin.resize(n); 
        low.resize(n);
        comp.resize(n, - 1);
        sz = timer = 0;

        for (int v = 0; v < n; v++) {
            if (!vis[v]) {
                dfs(v, -1);
                dfs2(v, sz);
                sz++;
            }
        }
        g.resize(sz);
        for (auto [u, v] : bridges) {
            u = comp[u], v = comp[v];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
};

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

    Bridge_Tree bt(adj);
    cout << bt.sz << '\n';
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
