#include <bits/stdc++.h>
using namespace std;

void solve() {
    // O(n / 64)
    bitset<20> bs, bs2(1234), bs3("10101100");

    // [], size, count
    // &, |, ^, ~, <<, >>
    // to_string, to_ulong, to_ullong
    // all, any, none
    // set, reset, flip, test

    cout << bs3 << '\n';
    cout << bs3._Find_first() << '\n';
    cout << bs3._Find_next(1) << ' ' << bs3._Find_next(2) << '\n';
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
