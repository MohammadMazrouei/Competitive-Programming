#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    pair<int, string> p1(1, "p1"), 
                      p2 = {2, "p2"},
                      p3 = make_pair(3, "p3");

    // --- Unpack elements ---
    int a1; string s1;
    tie(a1, s1) = p1;
    auto [a2, s2] = p2;

    // --- Element access ---
    cout << p1.first << ' ' << p1.second << '\n';
    cout << get<0>(p1) << ' ' << get<1>(p1) << '\n';
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
