#include <bits/stdc++.h>
using namespace std;

// Return last alive person, O(n)
int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    return res + 1;
}

// Returns the mth killed person, O(k*log(n))
int64_t josephus(int64_t n, int64_t k, int64_t m) {
    assert(m <= n);
    if (k <= 1) {
        return m;
    }
    m = n - m;
    int64_t i = m;
    while (i < n) {
        int64_t r = (i - m + k - 2) / (k - 1);
        if ((i + r) > n) {
            r = n - i;
        }
        else if (!r) {
            r = 1;
        }
        i += r;
        m = (m + (r * k)) % i;
    } 
    return m + 1;
}

void solve() {
    int n, k;
    cin >> n >> k;

    cout << josephus(n, k) << '\n';
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
