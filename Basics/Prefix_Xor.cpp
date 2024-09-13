#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] ^ a[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        int ans = p[r] ^ p[l];
        cout << ans << '\n';
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
