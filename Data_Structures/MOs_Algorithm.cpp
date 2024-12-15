#include <bits/stdc++.h>
using namespace std;

// MO's Algorithm, O((n + q) * sqrt(n) * F)
const int B = 440;
struct Query {
    int l, r, id;
    bool operator<(const Query &other) const {
        if (l / B == other.l / B) {
            return ((l / B) & 1) ? r > other.r : r < other.r;
        }
        return l / B < other.l / B;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<Query> qr;
    for (int i = 0; i < n; i++) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
        qr[i].l--, qr[i].r--;
    }
    sort(qr.begin(), qr.end());

    int res = 0;
    vector<int> cnt(n);
    auto add = [&](int i) -> void {
        int x = a[i];
        if (x <= n) {
            res -= cnt[x] == x;
            cnt[x]++;
            res += cnt[x] == x;
        }
    };
    auto rem = [&](int i) -> void {
        int x = a[i];
        if (x <= n) {
            res -= cnt[x] == x;
            cnt[x]--;
            res += cnt[x] == x;
        }
    };
    auto query = [&]() -> int {
        return res;
    };

    vector<int> ans(q);
    int l = 1, r = 0;
    for (int i = 0; i < q; i++) {
        int L = qr[i].l, R = qr[i].r;
        while (l < L) rem(l++);
        while (l > L) add(--l);
        while (r < R) add(++r);
        while (r > R) rem(r--);
        ans[qr[i].id] = query();
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
