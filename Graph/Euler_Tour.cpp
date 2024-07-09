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

    // add x to node v and get sum subtree v: add(v, x) -> add(in[v], x), sum(v) -> sum(in[v], out[v])
    // add x to node v and get sum path v to root=0: add(v, x) -> add(in[v], x) add(out[v], -x), sum(v) -> sum(0, in[v])
    vector<int> in(n), out(n);
    int timer = 0;
    auto dfs = [&](auto &&self, int v, int p) -> void {
        in[v] = timer++;
        for (auto u : adj[v]) {
            if (u == p) {
                continue;
            }
            self(self, u, v);
        }
        out[v] = timer;
    };
    dfs(dfs, 0, -1);
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
