#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int64_t> d(n + 1);
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        d[l] += x;
        d[r + 1] -= x;
    }
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " \n"[i == n - 1];
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
