#include <bits/stdc++.h>
using namespace std;

void solve() {
    // --- Initialization ---
    tuple<int, int, string> t1(1, 10, "t1"), 
                            t2 = {2, 20, "t2"},
                            t3 = make_tuple(3, 30, "t3");

    // --- Unpack elements ---
    int a1, b1; string s1;
    tie(a1, b1, s1) = t1;
    auto [a2, b2, s2] = t2;

    // --- Element access ---
    cout << get<0>(t1) << ' ' << get<1>(t1) << ' ' << get<2>(t1) << '\n';

    // concatenated_tuple is now: tuple<int, int, string, int, int, string>
    auto concatenated_tuple = tuple_cat(t1, t2); 
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
