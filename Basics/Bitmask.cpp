#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate sum of every subset, O(2^n * n)
    vector<int64_t> sums;
    for (int mask = 0; mask < (1 << n); mask++) {
        int64_t sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                sum += a[i];
            }
        }
        sums.push_back(sum);
    }
    for (auto x : sums) {
        cout << x << " \n"[sums.back() == x];
    }

    /*
    Iterating through all masks with their submasks, O(n^3)
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
