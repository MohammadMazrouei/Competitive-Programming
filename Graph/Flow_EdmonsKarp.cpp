#include <bits/stdc++.h>
using namespace std;

// Maximum Flow (Edmons-Karp), O(n * m^2)
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
    vector<int> par;

    Flow(int _n) : n(_n), adj(_n) {}

    void add_edge(int u, int v, T c) {
        adj[u].push_back(edges.size());
        edges.emplace_back(u, v, c, 0);
        adj[v].push_back(edges.size());
        edges.emplace_back(v, u, 0, 0);
    }

    bool bfs(int s, int t) {
        par.assign(n, -1);
        queue<int> q;
        par[s] = -2;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : adj[v]) {
                auto [_, u, c, f] = edges[i];
                if (c - f > 0 && par[u] == -1) {
                    par[u] = i;
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
        for (int cur = t; cur != s;) {
            auto [v, _, c, f] = edges[par[cur]];
            flow = min(flow, c - f);
            cur = v;
        }
        for (int cur = t; cur != s;) {
            auto [v, _, c, f] = edges[par[cur]];
            edges[par[cur]].flow += flow;
            edges[par[cur] ^ 1].flow -= flow;
            cur = v;
        }
        return flow;
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
