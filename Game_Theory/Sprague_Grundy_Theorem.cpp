#include <bits/stdc++.h>
using namespace std;

// Calculate Mex, O(n)
int mex(vector<int> &a) {
    int n = a.size();
    vector<bool> f(n + 1);
    for (int x : a) {
        if (x <= n) {
            f[x] = 1;
        }
    }
    int mex = 0;
    while (f[mex]) {
        mex++;
    }
    return mex;
}

/*
Chips on The Graph
A directed acyclic graph is given. There are chips at some vertices of the graph. 
In one move, a player can take a chip and move it along some edge to a new vertex. 
The one who cannot make a move loses.
*/
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    vector<int> chips(k);
    for (int i = 0; i < k; i++) {
        cin >> chips[i];
    }

    vector<int> g(n, -1); // Grundy Number
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int v) -> void {
        vis[v] = true;
        vector<int> vec;
        for (auto u : adj[v]) {
            if (g[u] == -1) {
                self(self, u);
            }
            vec.push_back(g[u]);
        }
        g[v] = mex(vec);
    };
    for (int v = 0; v < n; v++) {
        if (g[v] == -1) {
            dfs(dfs, v);
        }
    }

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum ^= g[chips[i]];
    }

    cout << (sum ? "First\n" : "Second\n");
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
