#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    array<int, 4> arr = {1, 2, 3, 4};

    // --- Iterators ---
    // begin(), end()
    // rbegin(), rend()

    // --- Capacity ---
    // size(), empty()

    // --- Element access ---
    // front(), back()
    // [index], at(index)

    // --- Operations ---
    // fill(value)

    arr.fill(10);
    for (auto x : arr) {
        cout << x << '\n';
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
