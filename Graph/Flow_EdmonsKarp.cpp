#include <bits/stdc++.h>
using namespace std;

// Maximum Flow (Edmons-Karp), O(n * m^2)
template <typename T>
struct Flow {
    const int n;
    vector<vector<int>> adj;
    vector<vector<T>> c, f;
    vector<int> par;

    Flow(int _n) : n(_n), adj(_n) {
        c.assign(n, vector<T>(n));
        f.assign(n, vector<T>(n));
    }

    bool bfs(int s, int t) {
        par.assign(n, -1);
        par[s] = -2;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : adj[v]) {
                if (c[v][u] - f[v][u] > 0 && par[u] == -1) {
                    par[u] = v;
                    q.push(u);
                    if (u == t) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    T augment(int s, int t) {
        T flow = numeric_limits<T>::max();
        for (int cur = t; cur != s; cur = par[cur]) {
            flow = min(flow, c[par[cur]][cur] - f[par[cur]][cur]);
        }
        for (int cur = t; cur != s; cur = par[cur]) {
            int v = par[cur], u = cur;
            f[v][u] += flow;
            f[u][v] -= flow;
        }
        return flow;
    }

    void add_edge(int u, int v, T cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += cap;
    }
    T max_flow(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            flow += augment(s, t);
        }
        return flow;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    Flow<int64_t> f(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        f.add_edge(u, v, c);
    }

    int64_t flow = f.max_flow(0, n - 1);
    cout << flow << '\n';
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
