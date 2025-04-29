#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate sum of every subset, O(2^n)
    vector<int64_t> sums(1 << n);
    for (int mask = 1; mask < (1 << n); mask++) {
        int b = __builtin_ctz(mask);
        sums[mask] = sums[mask & (mask - 1)] + a[b];
    }
    for (int i = 0; i < (1 << n); i++) {
        cout << sums[i] << " \n"[i == (1 << n) - 1];
    }

    /*
    Iterating through all masks with their submasks, O(3^n)
    for (int mask = 0; mask < (1 << n); mask++)
        for (int sub_mask = mask; sub_mask; sub_mask = (sub_mask - 1) & mask)
    */
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
