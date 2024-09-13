#include <bits/stdc++.h>
using namespace std;

void solve() {
    tuple<int, int, int, string> t(10, 20, 30, "t1"), t2 = make_tuple(11, 21, 31, "t2"), t3 = {12, 22, 32, "t3"};
    get<3>(t) = "hi";

    // auto new_tuple = tuple_cat(t1, t2), Concat t1 & t2 in new_tuple

    int a, b, c; string s;
    tie(a, b, c, s) = t;
    auto [a2, b2, c2, s2] = t;

    cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << ' ' << get<string>(t) << '\n';
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
