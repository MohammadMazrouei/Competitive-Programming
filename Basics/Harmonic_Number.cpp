#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Complexity = n/1 + n/2 + ... + n/n = n * (1/1 + 1/2 + ... + 1/n) = n * H(n) [Here H(n) is nth Harmonic Number]
    // O(n*log(n)) Because H(n) is Around O(log(n))
    int sum = 0, complexity = n * log(n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sum++;
        }
    }
    cout << complexity << '\n';
    cout << sum << '\n';
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
