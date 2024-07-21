#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Offline RMQ (Arpa's Trick), O(n + q)
    vector<vector<array<int, 2>>> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[r].push_back({l, i});
    }

    vector<int> par(n, -1);
    auto find_set = [&](auto &&self, int v) -> int {
        return par[v] == -1 ? v : par[v] = self(self, par[v]);
    };

    vector<int> ans(q);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] > a[i]) {
            par[s.top()] = i;
            s.pop();
        }
        s.push(i);
        for (auto [l, ind] : queries[i]) {
            ans[ind] = a[find_set(find_set, l)];
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " \n"[i == q - 1];
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
