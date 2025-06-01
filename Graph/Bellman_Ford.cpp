#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
struct Edge {
    int64_t u, v, w;
}; 

const int64_t INF = 4e18;
vector<Edge> edges;
vector<int> neg_path;
int64_t d[N], p[N];

// false -> exist negative cycle 
bool bellman_ford(int s, int n) { // O(n*m)  
    fill(d, d + n, INF);
    fill(p, p + n, -1);
    neg_path.clear();

    d[s] = 0;
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (d[e.u] < INF) {
                if (d[e.v] > d[e.u] + e.w) {
                    d[e.v] = max(-INF, d[e.u] + e.w);
                    p[e.v] = e.u;
                    x = e.v;
                }
            }
        }
        if (x == -1) {
            return false;
        }
    }

    int y = x;
    for (int i = 0; i < n; i++) {
        y = p[y];
    }
    for (int cur = y; ; cur = p[cur]) {
        neg_path.push_back(cur);
        if (cur == y && int(neg_path.size()) > 1) {
            break;
        }
    }
    reverse(neg_path.begin(), neg_path.end());

    return true;
}

void solve() {
        
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
