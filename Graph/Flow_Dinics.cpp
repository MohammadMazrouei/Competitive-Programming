#include <bits/stdc++.h>
using namespace std;

// Maximum Flow (Dinics), O(n^2 * m)
template <typename T>
struct Flow {
    struct Edge {
        int from, to;
        T cap, flow;
        Edge(int _from, int _to, T _cap, T _flow) : from(_from), to(_to), cap(_cap), flow(_flow) {}
    };

    const int n;
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<int> h, cur;

    Flow(int _n) : n(_n), adj(_n) {}

    void add_edge(int u, int v, T c) {
        adj[u].push_back(edges.size());
        edges.emplace_back(u, v, c, 0);
        adj[v].push_back(edges.size());
        edges.emplace_back(v, u, 0, 0);
    }
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : adj[v]) {
                auto [_, u, c, f] = edges[i];
                if (c - f > 0 && h[u] == -1) {
                    h[u] = h[v] + 1;
                    q.push(u);
                    if (u == t) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    T dfs(int v, int t, T flow) {
        if (v == t) {
            return flow;
        }
        T r = flow;
        for (int &i = cur[v]; i < int(adj[v].size()); i++) {
            const int j = adj[v][i];
            auto [_, u, c, f] = edges[j];
            if (c - f > 0 && h[u] == h[v] + 1) {
                T a = dfs(u, t, min(r, c - f));
                edges[j].flow += a;
                edges[j ^ 1].flow -= a;
                r -= a;
                if (r == 0) {
                    return flow;
                }
            }
        }
        return flow - r;
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            flow += dfs(s, t, numeric_limits<T>::max());
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
