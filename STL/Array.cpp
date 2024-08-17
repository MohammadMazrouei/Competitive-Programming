#include <bits/stdc++.h>
using namespace std;

void solve() {
    array<int, 6> arr = {1, 2, 3, 4, 5, 6};

    // begin, end, rbegin, rend
    // front, back, [], at
    // size, empty

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
