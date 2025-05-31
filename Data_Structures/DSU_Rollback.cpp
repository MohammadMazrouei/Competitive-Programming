#include <bits/stdc++.h>
using namespace std;

// DSU with Rollback, O(log(n))
struct DSU {
    int c; // components
    vector<int> par, sz;
    vector<pair<int&, int>> history;
    vector<int> mark;
    
    DSU() : c(0) {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        c = n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
        history.clear();
        mark.clear();
    }

    int find(int a) {
        return (par[a] == a ? a : find(par[a]));
    }
    void merge(int a, int b) {
        mark.push_back(history.size());
        if ((a = find(a)) == (b = find(b))) {
            return;
        }
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        history.emplace_back(c, c);
        history.emplace_back(par[a], par[a]);
        history.emplace_back(sz[b], sz[b]);
        c--;
        par[a] = b;
        sz[b] += sz[a];
    }
    void undo() {
        if (mark.empty()) {
            return;
        }
        while ((int)history.size() > mark.back()) {
            history.back().first = history.back().second;
            history.pop_back();
        }
        mark.pop_back();
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            dsu.merge(a, b);
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << (dsu.find(a) == dsu.find(b) ? "YES\n" : "NO\n");
        } else if (op == 3) {
            dsu.undo();
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
