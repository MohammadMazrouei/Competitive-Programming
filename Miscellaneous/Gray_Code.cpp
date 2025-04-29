#include <bits/stdc++.h>
using namespace std;
   
// Decimal to Gray
int to_gray(int x) {
    return x ^ (x >> 1);
}

// Gray to Decimal
int from_gray(int g) {
    int x = g;
    while (g >>= 1) {
        x ^= g;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;

    int g = to_gray(n);
    int x = from_gray(n);
    cout << g << ' ' << x << '\n';
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
