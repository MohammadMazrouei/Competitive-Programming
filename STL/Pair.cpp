#include <bits/stdc++.h>
using namespace std;

void solve() {
    pair<string, int> p("way1", 1), p2 = make_pair("way2", 2), p3 = {"way3", 3};
    p.first = "way4";
    p.second = 4;
    get<0>(p) = "way5";
    get<1>(p) = 5;

    string s; int n;
    tie(s, n) = p;
    auto [s2, n2] = p;

    cout << p.first << ' ' << p.second << '\n';
    cout << get<0>(p) << ' ' << get<1>(p) << '\n';
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
